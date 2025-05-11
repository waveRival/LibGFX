#pragma once

#include <memory>

namespace cl
{
	/// \addtogroup clanCore_Crypto clanCore Crypto
	/// \{

	class DataBuffer;
	class Secret_Impl;

	/// \brief Key class
	///
	/// This class zero's the key from memory when the class is destroyed
	class Secret
	{
	public:
		/// \brief Constructs a key (unset)
		Secret();

		/// \brief Constructs a key to a specified length
		///
		/// The data is not initialised
		///
		/// \param new_key_length = Length of the key
		Secret(unsigned int new_key_length);

		/// \brief Get the key size
		///
		/// \return The key size
		unsigned int get_size() const;

		/// \brief Get the key data
		///
		/// \return The key
		unsigned char *get_data() const;

	private:
		std::shared_ptr<Secret_Impl> impl;
	};

	/// \}
}
