#pragma once

#include <memory>
#include "file.h"

namespace cl
{
	/// \addtogroup clanCore_I_O_Data clanCore I/O Data
	/// \{

	class IODevice;
	class DirectoryListingEntry;

	/// \brief Virtual File System (VFS) file source.
	class FileSystemProvider
	{
	public:
		virtual ~FileSystemProvider() { return; }

		/// \brief Open file from this source.
		/** param: filename = The filename to use
			param: mode = File::OpenMode modes
			param: access = File::AccessFlags flags
			param: share = File::ShareFlags flags
			param: flags = File::Flags flags
			\return The IODevice*/
		virtual IODevice open_file(const std::string &filename,
			File::OpenMode mode = File::open_existing,
			unsigned int access = File::access_read | File::access_write,
			unsigned int share = File::share_all,
			unsigned int flags = 0) = 0;

		/// \brief Initiate directory listing.
		virtual bool initialize_directory_listing(const std::string &path) = 0;

		/// \brief Update directory listing item.
		virtual bool next_file(DirectoryListingEntry &entry) = 0;

		/// \brief Return the path of this file source.
		virtual std::string get_path() const = 0;

		/// \brief Get the identifier of this file source
		///
		/// The exact format of this identifier depends on the implementation of the underlying filesystem and mounts
		/// \return the identifier
		virtual std::string get_identifier() const = 0;
	};

	/// \}
}
