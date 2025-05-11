#pragma once

#include <memory>

namespace cl
{
	/// \addtogroup clanCore_Crypto clanCore Crypto
	/// \{

	class DataBuffer;
	class MD5_Impl;

	/// \brief MD5 hash function class.
	class MD5
	{
	public:
		/// \brief Constructs a MD5 hash generator.
		MD5();

		static const int hash_size = 16;

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
		std::shared_ptr<MD5_Impl> impl;
	};

	/// \}
}
