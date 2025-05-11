#pragma once

#include <string>
#include <memory>

namespace cl
{
	/// \addtogroup clanCore_ErrorReporting clanCore ErrorReporting
	/// \{

	class CrashReporter_Impl;

	/// \brief Generates crash reports (aka. minidumps or core dumps) when the application crashes, or when requested.
	class CrashReporter
	{
	public:
		/// \brief Constructs a crash reporter that creates crash dumps in the specified directory.
		///
		/// If uploader_executable is a non-empty string the executable will be launched if the application crashes.
		CrashReporter(const std::string &reports_directory, const std::string &uploader_executable = std::string());
		~CrashReporter();

		/// \brief Hooks the current thread to the crash reporter.
		///
		/// The crash reporter will only work for hooked threads.
		static void hook_thread();

		/// \brief Force a crash.
		///
		/// This is useful for failing asserts.
		static void invoke();

		/// \brief Generate a crash report for the current thread without terminating.
		static void generate_report();

	private:
		std::shared_ptr<CrashReporter_Impl> impl;
	};

	/// \}
}
