#pragma once

#include <memory>

namespace cl
{
	/// \addtogroup clanCore_ErrorReporting clanCore ErrorReporting
	/// \{

	class Exception;
	class ExceptionDialog_Impl;

	/// \brief Displays a modal dialog with exception details.
	class ExceptionDialog
	{
	public:
		/// \brief Displays a modal dialog with the details of the specified exception.
		static void show(const std::exception_ptr &exception);
	};

	/// \}
}
