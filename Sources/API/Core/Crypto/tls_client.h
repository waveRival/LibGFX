#pragma once

#include <memory>

namespace cl
{
	/// \addtogroup clanCore_Crypto clanCore Crypto
	/// \{

	class DataBuffer;
	class TLSClient_Impl;

	/// \brief Transport Layer Security (TLS) client class
	class TLSClient
	{
	public:
		/// \brief Constructs a TLS client
		TLSClient();

		/// \brief Return a pointer to decrypted data available for consumption.
		const void *get_decrypted_data() const;

		/// \brief Returns how much decrypted data is available.
		int get_decrypted_data_available() const;

		/// \brief Return a pointer to encrypted data available for consumption.
		const void *get_encrypted_data() const;

		/// \brief Returns how much encrypted data is available.
		int get_encrypted_data_available() const;

		/// \brief Adds data to be encrypted.
		int encrypt(const void *data, int size);

		/// \brief Adds data to be decrypted.
		int decrypt(const void *data, int size);

		/// \brief Marks decrypted data as consumed.
		void decrypted_data_consumed(int size);

		/// \brief Marks encrypted data as consumed.
		void encrypted_data_consumed(int size);

	private:
		std::shared_ptr<TLSClient_Impl> impl;
	};

	/// \}
}
