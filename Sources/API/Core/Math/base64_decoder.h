#pragma once

#include <memory>

namespace cl

	/// \addtogroup clanCore_Math clanCore Math
	/// \{

	class DataBuffer;
	class Base64Decoder_Impl;

	/// \brief Base64 decoder class.
	class Base64Decoder
	{
	public:
		/// \brief Constructs a base64 decoder.
		Base64Decoder();

		/// \brief Returns the decoded data.
		DataBuffer &get_result();

		/// \brief Resets the decoder.
		void reset();

		/// \brief Feeds the decoder with base64 encoded data.
		void feed(const void *data, int size, bool append_result = true);

		/// \brief Decode base64 data and return it in a buffer.
		static DataBuffer decode(const void *data, int size);

		/// \brief Decode
		///
		/// \param data = String Ref8
		///
		/// \return Data Buffer
		static DataBuffer decode(const std::string &data);

		/// \brief Decode
		///
		/// \param data = Data Buffer
		///
		/// \return Data Buffer
		static DataBuffer decode(const DataBuffer &data);

	private:
		std::shared_ptr<Base64Decoder_Impl> impl;
	};

	/// \}
}
