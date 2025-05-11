#pragma once

#include <memory>

namespace cl
{
	/// \addtogroup clanCore_Crypto clanCore Crypto
	/// \{

	class DataBuffer;
	class SHA256_Impl;

	/// \brief SHA-256 hash function class.
	class SHA256
	{
	public:
		/// \brief Constructs a SHA-256 hash generator.
		SHA256();

		static const int hash_size = 32;

		/// \brief Returns the calculated hash.
		std::string get_hash(bool uppercase = false) const;

		/// \brief Get hash
		///
		/// \param out_hash = where to write to
		void get_hash(unsigned char out_hash[hash_size]) const;

		/// \brief Resets the hash generator.
		void reset();

		/// \brief Enable a HMAC based calculation
		///
		/// Call this function before the initial add(). It is reset by reset()
		///
		/// \param key_data = The HMAC key
		/// \param key_size = The size of the key_data
		void set_hmac(const void *key_data, int key_size);

		/// \brief Adds data to be hashed.
		void add(const void *data, int size);

		/// \brief Add
		///
		/// \param data = Data Buffer
		void add(const DataBuffer &data);

		/// \brief Finalize hash calculation.
		void calculate();

	private:
		std::shared_ptr<SHA256_Impl> impl;
	};

	/// \}
}
