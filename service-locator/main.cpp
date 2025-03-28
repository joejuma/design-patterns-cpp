#include <cstdlib>
#include <iostream>

#include "Logging_struct.h"
#include "ExampleLog_struct.h"
#include "LogLocator_struct.h"

int main(int argc, char* argv[])
{
	// Create the log service locator.
	LogLocator* logLocator = LogLocator::getInstance();

	// Create an object of a class derived from Logging.
	ExampleLog exampleLog;

	// Register the log with the service locator.
	logLocator->registerLogService("example", &exampleLog);

	// Try fetching the log pointer.
	Logging* logService = logLocator->getLog("example");

	// Check if you got a null-pointer...
	if (logService == 0)
	{
		std::cerr << "[ERROR] The log locator returned an unexpected null-pointer.\n";
	}
	// If you didn't get a null-pointer,
	else
	{
		// Try invoking the log method!
		logService->log("Hello world!");
	};

	// Clean up the log service, just to be clean.
	LogLocator::deleteInstance();

	// Zero your pointers just to be safe as well.
	logLocator = 0;
	logService = 0;

	// And exampleLog will take care of itself!

	// Finish up and terminate the program.
	std::cout << "Press [ENTER] to exit the program.\n";
	std::cin.get();
	return 0;
}