#pragma once

#include <memory>

namespace cl
{
	/// \addtogroup clanCore_Crypto clanCore Crypto
	/// \{

	class DataBuffer;
	class AES192_Decrypt_Impl;

	/// \brief AES-192 decryption class (running in Cipher Block Chaining mode)
	class AES192_Decrypt
	{
	public:
		/// \brief Constructs a AES-192 generator (running in Cipher Block Chaining mode)
		AES192_Decrypt();

		/// \brief Get decrypted data
		///
		/// This is the databuffer used internally to store the decrypted data.
		/// You may call "set_size()" to clear the buffer, inbetween calls to "add()"
		/// You may call "set_capacity()" to optimise storage requirements before the add() call
		DataBuffer get_data() const;

		static const int iv_size = 16;
		static const int key_size = 24;

		/// \brief Resets the decryption
		void reset();

		/// \brief Sets the initialisation vector
		///
		/// This should be a random number\n
		/// This must be called before the initial add()
		void set_iv(const unsigned char iv[iv_size]);

		/// \brief Sets the cipher key
		///
		/// This must be called before the initial add()
		void set_key(const unsigned char key[key_size]);

		/// \brief Enable AES Padding
		///
		/// Example (use_pkcs7==true) : ... 0x03 0x03 0x03 (3 octets of padding)
		/// Example (use_pkcs7==false) : ... 0x02 0x02 0x02 (3 octets of padding, the last octet is the length)
		///
		/// \param value = true = Enable padding (default)
		/// \param use_pkcs7 = true = This uses the PKCS#7/RFC3369 method (Enabled by default). false = use the TLS method (rfc2246)
		void set_padding(bool value = true, bool use_pkcs7 = true);

		/// \brief Adds data to be decrypted
		void add(const void *data, int size);

		/// \brief Add data to be decrypted
		///
		/// \param data = Data Buffer
		void add(const DataBuffer &data);

		/// \brief Finalize decryption
		///
		/// IMPORTANT, to avoid timing attacks, if this function fails, you should still validate the data (via a hash or otherwise), then throw an error
		///
		/// \return false = AES Padding value is invalid.
		bool calculate();

	private:
		std::shared_ptr<AES192_Decrypt_Impl> impl;
	};

	/// \}
}
