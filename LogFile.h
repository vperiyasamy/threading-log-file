
#ifndef LogFile_H
#define LogFile_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>
#include <string>
#include <ctime>
#include <mutex>

class LogFile {
public:
	static std::fstream log_file;
	static std::stringstream line;
	static std::string log_string;
	static std::chrono::high_resolution_clock::time_point program_start;

	static void log(std::string tag, std::string message);
	
	static void error(std::string tag, std::string message); 
	
	static void startLog(bool displayOn);

private:
	static bool displayFlag;
	static std::mutex mutex_lock;
};

#endif /* LogFile_H */