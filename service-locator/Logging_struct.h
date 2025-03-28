#pragma once

#ifndef LOGGING_STRUCT__H
#define LOGGING_STRUCT__H
#include <string>

struct Logging
{
	/*
		# Logging (struct)

		## About
		An interface and base-class for logging structures.

		## Notes
		* This is used to allow the service locator to store pointers of any 
		type that derives from this.
	*/

	/* Methods */
	virtual void log(const std::string& message) = 0;
};
#endif