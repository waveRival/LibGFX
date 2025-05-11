#pragma once

#include <vector>
#include <string>
#include <memory>

namespace gfx
{
	/// \addtogroup clanApp_System clanApp System
	/// \{

	/// \brief Base class for the application object
	///
	/// All applications using the clanApp module need to inherit from this class. See ApplicationInstance for more information.
	class Application
	{
	public:
		virtual ~Application() { }

		/// \brief Main loop update handler
		///
		/// Once the target environment has been initialized this function is called continously to update and render the application.
		/// If the function returns false the main loop will end and the application will exit.
		virtual bool update() { return true; }

		/// \brief Set update handler to wait a certain amount of milliseconds between each update
		static void use_timeout_timing(int timeout_ms);

		/// \brief Returns the command line arguments passed to the application
		static const std::vector<std::string> &main_args();
	};

	class ApplicationInstancePrivate
	{
	public:
		ApplicationInstancePrivate(bool catch_exceptions = true);
		virtual std::unique_ptr<Application> create() = 0;
	};

	/// \brief Helper class to create cross platform applications
	///
	/// To use this class, inherit from Application and make a single global instance of ApplicationInstance<YourClass>.
	///
	/// \code
	/// class MyApplication : public clan::Application
	/// {
	/// public:
	///   bool update() override;
	/// };
	///
	/// ApplicationInstance<MyApplication> clanapp;
	/// \endcode
	/// If you do not want exceptions to be automatically caught, pass "false" to the optional catch_exceptions parameter in Application\n
	/// Your program does not have to use this class. For more advanced usage use a normal main function for the target platform and interface with the RunLoop class in clanDisplay\n
	template<typename ApplicationClass>
	class ApplicationInstance : ApplicationInstancePrivate
	{
	public:
		/// \brief Constructor
		ApplicationInstance(bool catch_exceptions = true) : ApplicationInstancePrivate(catch_exceptions)
		{
		}

	private:
		std::unique_ptr<Application> create() override
		{
			return std::make_unique<ApplicationClass>();
		}
	};

	/// \}
}
