#pragma once

#include <memory>

namespace cl
{

	class DirectoryListingEntry;
	class FileSystemProvider;
	class DirectoryListing_Impl;

	/// \brief Virtual File System (VFS) directory listing class.
	class DirectoryListing
	{
	public:
		/// \brief Constructs a null instance.
		DirectoryListing();

		/// \brief Constructs a virtual directory listening object.
		DirectoryListing(FileSystemProvider *provider, const std::string &path);

		virtual ~DirectoryListing();

		/// \brief Returns true if this object is invalid.
		bool is_null() const { return !impl; }

		/// \brief Throw an exception if this object is invalid.
		void throw_if_null() const;

		/// \brief Returns the file name of the current item in the listing.
		std::string get_filename();

		/// \brief Returns true if item is a directory.
		bool is_directory();

		/// \brief Returns true if item is hidden.
		bool is_hidden();

		/// \brief Returns true if item is writable.
		bool is_writable();

		/// \brief Returns true if item is readable.
		bool is_readable();

		/// \brief Advance to next item in listing.
		bool next();

	private:
		std::shared_ptr<DirectoryListing_Impl> impl;
	};

}
