#pragma once

#ifndef EXAMPLE_LOG_STRUCT__H
#define EXAMPLE_LOG_STRUCT__H
#include "Logging_struct.h"
#include <iostream>

struct ExampleLog : Logging
{
	/*
		# Example Log (struct)

		## About
		An example implementation of the Logging interface.
	*/

	/* Methods */
	inline void log(const std::string& message)
	{
		std::cout << message << "\n";
	};
};

#endif