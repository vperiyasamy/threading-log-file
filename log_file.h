
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
	//bool displayFlag;
	std::ofstream log_file;
	std::stringstream line;
	std::string log_string;
	std::chrono::high_resolution_clock::time_point program_start;

	void log(std::chrono::high_resolution_clock::time_point program_start, std::string tag, std::string message);
	
	void error(std::chrono::high_resolution_clock::time_point program_start, std::string tag, std::string message); 
	
	void startLog();

private:
	bool displayFlag;
};

#endif /* LogFile_H */