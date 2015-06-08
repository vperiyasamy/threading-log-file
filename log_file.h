#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <string>
#include <ctime>

class LogFile {
public:
	bool displayFlag;
	std::ofstream log_file;
	std::stringstream line;
	std::string log_string;
	static void log(std::string tag, std::string message);
	static void error(std::string tag, std::string message); 
	static std::chrono::high_resolution_clock::time_point startLog();

private:
};