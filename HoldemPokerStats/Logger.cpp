#include <cassert>

#include "Logger.h"

Logger::Logger()
{
}

Logger::~Logger()
{
}

bool Logger::Init()
{
	return true;
}

bool Logger::DeInit()
{
	return true;
}

LoggerManager::LoggerManager()
{
	mLoggingDest = LogDest::Max;
}

LoggerManager::~LoggerManager()
{
	mLoggingDest = LogDest::Max;
}

bool LoggerManager::Init()
{
	assert( mLoggingDest != LogDest::Max );
	return true;
}

bool LoggerManager::DeInit()
{
	return true;
}

bool LoggerManager::SetStream( LogDest log )
{
	mLoggingDest = log;
	return true;
}
