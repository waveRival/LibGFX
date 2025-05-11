#pragma once

namespace cl
{
	/// \addtogroup clanCore_I_O_Data clanCore I/O Data
	/// \{

	/// \brief File operation helpers.
	class FileHelp
	{
	public:
		/// \brief Copy a file.
		///
		/// \param from Where to copy from
		/// \param to Where to copy to
		/// \param copy_always true = Copy, even if destination already exists. false = Do not copy if destination exists (throw a Exception)
		static void copy_file(const std::string &from, const std::string &to, bool copy_always);

		/// \brief Delete a file.
		///
		/// \param filename File to delete
		static void delete_file(const std::string &filename);

		/// \brief Check if a file exists.
		///
		/// \param filename File to check for existance
		static bool file_exists(const std::string &filename);
	};

	/// \}
}
