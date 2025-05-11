#pragma once

namespace cl
{
	/// \brief Class for handling HTML urls.
	class HTMLUrl
	{
	public:
		HTMLUrl();
		HTMLUrl(const std::string &url, const HTMLUrl &base = HTMLUrl());
		std::string to_string() const;

		std::string scheme;

		// http scheme:
		std::string host;
		std::string port;
		std::string path;
		std::string query;

		// data scheme:
		std::string content_type;
		std::string encoding;
		std::string data;

	private:
		std::string read_scheme(std::string &input, std::string::size_type &pos);
	};
}
