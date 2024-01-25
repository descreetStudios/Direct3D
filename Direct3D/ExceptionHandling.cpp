#include "ExceptionHandling.h"
#include <sstream>

ExceptionHandling::ExceptionHandling(int line, const char* file) noexcept
	:
	line(line),
	file(file)
{}

const char* ExceptionHandling::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* ExceptionHandling::GetType() const noexcept
{
	return "Exception";
}

int ExceptionHandling::GetLine() const noexcept
{
	return line;
}

const std::string& ExceptionHandling::GetFile() const noexcept
{
	return file;
}

std::string ExceptionHandling::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}