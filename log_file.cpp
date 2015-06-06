#include <iostream>
#include <chrono>
#include <thread>
#include <string>

class LogFile {
public:
	bool displayFlag;
	static void log(std::string tag, std::string message);
	static void error(std::string tag, std::string message); 

private:
};

LogFile::log(std::string tag, std::string message) {
	std::chrono::high_resolution_clock::time_point time_point;
	time_point = std::chrono::high_resolution_clock::now();

	std::time_t now_c = std::chrono::system_clock::to_time_t(time_point);
}