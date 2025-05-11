#pragma once

#include <memory>

namespace cl
{
	/// \addtogroup clanCore_Crypto clanCore Crypto
	/// \{

	class DataBuffer;
	class Random_Impl;
	class Random;

	/// \brief Random class
	///
	/// Uses the operating system cryptographically secure pseudorandom number generator
	class Random
	{
	public:
		/// \brief Constructs the object
		///
		/// cache_size = Random number cache size
		Random(int cache_size = 1024);

		/// \brief Get the random bytes
		///
		/// out_dest_ptr = Where to write to
		/// num_bytes = Number of bytes to copy
		void get_random_bytes(unsigned char *out_dest_ptr, int num_bytes);

		/// \brief Get the random bytes excluding bytes containing 0
		///
		/// out_dest_ptr = Where to write to
		/// num_bytes = Number of bytes to copy
		void get_random_bytes_nzero(unsigned char *out_dest_ptr, int num_bytes);

		/// \brief Get the random boolean
		///
		/// out_dest_ptr = Where to write to
		/// num_bytes = Number of bytes to copy
		bool get_random_bool();

	private:
		std::shared_ptr<Random_Impl> impl;
	};

	/// \}
}
