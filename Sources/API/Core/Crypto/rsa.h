#pragma once

namespace cl
{
	/// \addtogroup clanCore_Crypto clanCore Crypto
	/// \{

	class Random;
	class Secret;
	class DataBuffer;

	/// \brief RSA class
	///
	/// Important: This class has NOT been tested thoroughly by a cryptography expert.
	class RSA
	{
	public:
		/// \brief Create a keypair
		///
		/// \param random = Random number generator
		/// \param out_private_exponent = Private exponent (to decrypt with)
		/// \param out_public_exponent = Public exponent (to encrypt with)
		/// \param out_modulus = Modulus
		/// \param key_size_in_bits = key size in bits
		/// \param public_exponent_value = public exponent value
		static void create_keypair(Random &random, Secret &out_private_exponent, DataBuffer &out_public_exponent, DataBuffer &out_modulus, int key_size_in_bits = 1024, int public_exponent_value = 65537);

		/// \brief Encrypt
		///
		/// \param block_type = 0 (private key), 1 (private key) or 2 (public key)
		/// \param random = Random number generator
		/// \param in_public_exponent = Public exponent
		/// \param in_modulus = Modulus
		/// \param in_data = Data to encrypt (maximum length is in_modulus.get_size() - 11)
		/// \return Encrypted data
		static DataBuffer encrypt(int block_type, Random &random, const DataBuffer &in_public_exponent, const DataBuffer &in_modulus, const Secret &in_data);

		/// \brief Encrypt
		///
		/// \param block_type = 0 (private key), 1 (private key) or 2 (public key)
		/// \param random = Random number generator
		/// \param in_public_exponent = Public exponent
		/// \param in_public_exponent_size = size in bytes of in_public_exponent
		/// \param in_modulus = Modulus
		/// \param in_modulus_size = size in bytes of in_modulus
		/// \param in_data = Data to encrypt 
		/// \param in_data_size = size in bytes of in_data (maximum size is in_modulus_size - 11)
		/// \return Encrypted data
		static DataBuffer encrypt(int block_type, Random &random, const void *in_public_exponent, unsigned int in_public_exponent_size, const void *in_modulus, unsigned int in_modulus_size, const void *in_data, unsigned int in_data_size);

		/// \brief Decrypt
		///
		/// Warning: An exception may be thrown when decrypting if in_data is not valid.
		/// Be careful handling this, to prevent "timing attacks"
		///
		/// \param in_private_exponent = Private exponent
		/// \param in_modulus = Modulus
		/// \param in_data = Data to decrypt (length equals in_modulus.get_size())
		/// \return Decrypted data
		static Secret decrypt(const Secret &in_private_exponent, const DataBuffer &in_modulus, const DataBuffer &in_data);

		/// \brief Decrypt
		///
		/// Warning: An exception may be thrown when decrypting if in_data is not valid.
		/// Be careful handling this, to prevent "timing attacks"
		///
		/// \param in_private_exponent = Private exponent
		/// \param in_modulus = Modulus
		/// \param in_modulus_size = size in bytes of in_modulus
		/// \param in_data = Data to encrypt 
		/// \param in_data_size = size in bytes of in_data (length equals in_modulus_size)
		/// \return Decrypted data
		static Secret decrypt(const Secret &in_private_exponent, const void *in_modulus, unsigned int in_modulus_size, const void *in_data, unsigned int in_data_size);
	};

	/// \}
}
