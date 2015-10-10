#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <fstream>
#include <ostream>
#include <vector>

// This should be able to log to either files, screen or error system, network, all of the above

// You use it in three ways, everything you put into it trys to get logged imidiatly, or you flush it once in awhile
//	last it just stores data and a logger manager kicks it out when done.

// We should be able to give this its own memory manager to work with

// TRAVIS_HACK, today we are just going to make it kick out to a file, and the screen

enum class LogDest{ Screen = 1, File = 2, Remote = 4, Max = 8 };

struct Logger
{
	std::vector< char >	mBuffer;

	Logger();
	~Logger();

	bool Init();
	bool DeInit();
	bool Flush();
};

struct LoggerManager
{
	LogDest		mLoggingDest;
	Logger		mLogger;

	LoggerManager();
	~LoggerManager();
	// Bad hack for now, just pass in the file name
	bool Init( );
	bool DeInit();
	bool SetStream( LogDest log );
};

#endif //__LOGGER_H__