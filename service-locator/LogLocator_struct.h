#pragma once

#ifndef LOG_LOCATOR_STRUCT__H
#define LOG_LOCATOR_STRUCT__H
#include "Logging_struct.h"
#include <map>

struct LogLocator
{
	/*
		# Log Locator (struct)

		## About
		A service locator specializing in logging structures. Can be used to fetch 
		log objects pointers if you know their registered alias string.
		
		## Notes
		* This is a reference implementation of a service locator structure.
		* This design pattern is instantiated into the program scope so that it 
		is accessible throughout the program, so it's best as a singleton.
	*/

	/* Static Elements */
	static LogLocator* instance;

	/* Instance Elements */
	std::map<std::string, Logging*> logs;

	/* Static Methods */
	inline static LogLocator* getInstance()
	{
		/*
			## About
			Handles fetching a pointer to the single instance of this class.
			
			## Notes
			* This should  be the only way an object with this class is created 
			to guarantee singleton nature.
		*/

		if (LogLocator::instance == 0)
		{
			LogLocator::instance = new LogLocator();
		};

		return instance;
	};
	inline static void deleteInstance()
	{
		/*
			## About
			Handles deletion of the instance of this object.

			## Notes
			* Although the pointer would delete at the end of program 
			termination (if we rely on the OS for cleanup), it's still good 
			practice to have a manual way to clear the memory.

			* I also prefer to call this for explicit memory cleanup at the end 
			of the program.
		*/

		if (LogLocator::instance != 0)
		{
			delete LogLocator::instance;
			LogLocator::instance = 0;
		};
	}

	/* Instance Methods */

	// Constructors & Destructor
	LogLocator()
	{
		/*
			Technically this should never be called directly. While it could be 
			made private, I prefer to allow programmers to have full control 
			over my implementations. So I'm leaving this public, just in case 
			there's ever a reason someone would want to invoke it directly.
		*/

		this->logs.clear();
	};
	virtual ~LogLocator()
	{
		this->logs.clear();
	};

	// Interface Methods
	inline void registerLogService(const std::string& name, Logging* ptr)
	{
		/*
			Registers a new log pointer and associates it with 
			a given name string.
		*/

		logs[name] = ptr;
	};
	inline void unregisterLogService(const std::string& name)
	{
		/*
			Removes a log pointer.
		*/

		if (this->logs.find(name) != this->logs.end())
		{
			this->logs.erase(name);
		};
	};
	
	inline Logging* getLog(const std::string& name)
	{
		/*
			Given a name string, returns the associated log pointer. Otherwise 
			returns 0.
		*/

		if (this->logs.find(name) != logs.end())
		{
			return logs[name];
		};

		return 0;
	};
};
#endif