#pragma once

#include <memory>

namespace cl
{
	/// \addtogroup clanCore_Math clanCore Math
	/// \{

	class DataBuffer;
	class Base64Encoder_Impl;

	/// \brief Base64 encoder class.
	class Base64Encoder
	{
	public:
		/// \brief Constructs a base64 encoder.
		Base64Encoder();

		/// \brief Returns the data in encoded form.
		DataBuffer &get_result();

		/// \brief Resets the encoder.
		void reset();

		/// \brief Feeds the encoder with more data.
		void feed(const void *data, int size, bool append_result = true);

		/// \brief Ends the base64 encoding.
		void finalize(bool append_result = true);

		/// \brief Base64 encodes data and returns it as an 8 bit string.
		static std::string encode(const void *data, int size);

		/// \brief Encode
		///
		/// \param data = String Ref8
		///
		/// \return String8
		static std::string encode(const std::string &data);

		/// \brief Encode
		///
		/// \param data = Data Buffer
		///
		/// \return String8
		static std::string encode(const DataBuffer &data);

	private:
		std::shared_ptr<Base64Encoder_Impl> impl;
	};

	/// \}
}
