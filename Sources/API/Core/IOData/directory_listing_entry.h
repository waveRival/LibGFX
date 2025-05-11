#pragma once

#include <memory>

namespace cl
{
	class DirectoryListingEntry_Impl;

	/// \brief Virtual File System (VFS) directory listing entry class.
	class DirectoryListingEntry
	{
	public:
		DirectoryListingEntry();
		virtual ~DirectoryListingEntry();

		/// \brief Returns the file name of the item in the listing.
		std::string get_filename();

		/// \brief Returns true if item is a directory.
		bool is_directory();

		/// \brief Returns true if item is hidden.
		bool is_hidden();

		/// \brief Returns true if item is writable.
		bool is_writable();

		/// \brief Returns true if item is readable.
		bool is_readable();

		void set_filename(const std::string &);
		void set_directory(bool);
		void set_hidden(bool);
		void set_writable(bool);
		void set_readable(bool);

	private:
		std::shared_ptr<DirectoryListingEntry_Impl> impl;
	};
}
