#include "UtilTello.h"


std::string UtilTello::exec(const char* cmd)
{
	std::array<char, 128> buffer;
	std::string result;
	std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd, "r"), _pclose);
	if (!pipe)
	{
		throw std::runtime_error("popen() failed!");
	}
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
	{
		result += buffer.data();
	}
	return result;
}

void UtilTello::AppendToBuffer(const char* str, char* inputBuffer)
{
	// Get the current time
	time_t currentTime;
	time(&currentTime);

	// Declare a structure to hold the local time
	struct tm timeInfo;
	localtime_s(&timeInfo, &currentTime);

	// Format the time as a string
	char timeStr[12]; // Adjust the size as needed for the time format
	strftime(timeStr, sizeof(timeStr), "[%H:%M:%S]", &timeInfo);

	// Append the formatted time to the buffer
	int len = strlen(timeStr);
	memcpy(&inputBuffer[strlen(inputBuffer)], timeStr, len);
	inputBuffer[strlen(inputBuffer)] = ' '; // Add a space between time and the original string

	// Append the original string
	len = strlen(str);
	memcpy(&inputBuffer[strlen(inputBuffer)], str, len);
	inputBuffer[strlen(inputBuffer)] = '\n';
	inputBuffer[strlen(inputBuffer)] = '\0';
}

void UtilTello::AppendToBufferW(const wchar_t* str, wchar_t* inputBuffer)
{
	// Get the current time
	time_t currentTime;
	time(&currentTime);

	// Declare a structure to hold the local time
	struct tm timeInfo;
	localtime_s(&timeInfo, &currentTime);

	// Format the time as a string
	wchar_t timeStr[12 + sizeof(wchar_t)]; // Adjust the size as needed for the time format
	wcsftime(timeStr, sizeof(timeStr), L"[%H:%M:%S]", &timeInfo);

	// Append the formatted time to the buffer
	int len = wcslen(timeStr) * sizeof(wchar_t);
	memcpy(&inputBuffer[wcslen(inputBuffer)], timeStr, len);
	inputBuffer[wcslen(inputBuffer)] = ' '; // Add a space between time and the original string

	// Append the original string
	len = wcslen(str) * sizeof(wchar_t);
	memcpy(&inputBuffer[wcslen(inputBuffer)], str, len);
	inputBuffer[wcslen(inputBuffer)] = '\n';
	inputBuffer[wcslen(inputBuffer)] = '\0';
}
