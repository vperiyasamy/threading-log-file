
#ifndef LogFile_H
#define LogFile_H


#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>
#include <string>
#include <ctime>

class LogFile {
public:
	// bool displayFlag;
	static std::ofstream log_file;
	static std::stringstream line;
	static std::string log_string;
	static std::chrono::high_resolution_clock::time_point program_start;

	void log(std::string tag, std::string message);
	
	void error(std::string tag, std::string message); 
	
	// LogFile(bool displayOn);
	void startLog(bool displayOn);

private:
	static bool displayFlag;
};

#endif /* LogFile_H */