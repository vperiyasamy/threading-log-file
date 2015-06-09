// #include <iostream>
// #include <fstream>
// #include <chrono>
// #include <thread>
// #include <string>
// #include <ctime>
#include "log_file.h"

// class LogFile {
// public:
// 	bool displayFlag;
// 	std::ofstream log_file;
// 	std::stringstream line;
// 	std::string log_string;
// 	static void log(std::string tag, std::string message);
// 	static void error(std::string tag, std::string message); 
// 	static std::chrono::high_resolution_clock::time_point startLog();

// private:
// };

bool displayFlag;
std::ofstream log_file;
std::stringstream line;
std::string log_string;

std::chrono::high_resolution_clock::time_point LogFile::startLog() {
	std::chrono::high_resolution_clock::time_point program_start; //start accurate to microsecond
	std::chrono::system_clock::time_point start_time; // start used to print time stamp
	time_t tt; // used to print ctime stamp

	program_start = std::chrono::high_resolution_clock::now();
	start_time = std::chrono::system_clock::now();

	tt = std::chrono::system_clock::to_time_t(start_time);
	const char *date = ctime(&tt);
	std::string date_stamp(date);

	log_file.open("log.txt", std::ios_base::app);
	log_file << "Program started: " << date_stamp << std::endl;

	return program_start;
}

LogFile::log(std::chrono::high_resolution_clock::time_point program_start, std::string tag, std::string message) {
	std::chrono::high_resolution_clock::time_point current;
	current = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(current - program_start).count();

	line << "LOG; " << "+" << duration << " microseconds; " << tag << "; " << message << ";\n";
	log_string = line.str();

	log_file.open("log.txt", std::ios_base::app);
	log_file << log_string;

	if(displayFlag) {
		std::cout << log_string;
		std::flush(std::cout);
	}
	//std::time_t now_c = std::chrono::system_clock::to_time_t(time_point);
}

LogFile::error(std::chrono::high_resolution_clock::time_point program_start, std::string tag, std::string message) {
	std::chrono::high_resolution_clock::time_point current;
	current = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(current - program_start).count();

	line << "ERROR; " << "+" << duration << " microseconds; " << tag << "; " << message << ";\n";
	log_string = line.str();

	log_file.open("log.txt", std::ios_base::app);
	log_file << log_string;

	if(displayFlag) {
		std::cout << log_string;
		std::flush(std::cout);
	}
	//std::time_t now_c = std::chrono::system_clock::to_time_t(time_point);
}