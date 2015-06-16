// LogFile.cpp

#include "LogFile.h"

bool LogFile::displayFlag = false; // to determine if we should print to cout
std::fstream LogFile::log_file("log.txt", std::ios_base::app); // file object to open log.txt
// std::stringstream LogFile::line; // string stream to capture info
// std::string LogFile::log_string; // to be written to file/cout
std::chrono::high_resolution_clock::time_point LogFile::program_start; //used as reference for microsecond execution
std::mutex LogFile::mutex_lock; // to prevent multithreading file i/o error
// std::stringstream LogFile::buffer; // buffer to write to file
// int LogFile::write_count; // count to write to file every 10 times

// This method only called once to set up logging
void LogFile::startLog(bool displayOn) {

	std::chrono::system_clock::time_point start_time; // start used to print time stamp
	time_t tt; // used to print ctime stamp

	displayFlag = displayOn;

	program_start = std::chrono::high_resolution_clock::now();
	start_time = std::chrono::system_clock::now();

	tt = std::chrono::system_clock::to_time_t(start_time);
	const char *date = ctime(&tt);
	std::string date_stamp(date);

	std::stringstream line;
	line << "Program started: " << date_stamp << "\n";
	std::string log_string = line.str();

	std::ofstream("log.txt", std::ios::out).close();
	//log_file.open("log.txt", std::ios_base::trunc);
	log_file.open("log.txt", std::ios_base::app);
	log_file << log_string;
	log_file.close();

	if(displayFlag) {
		std::cout << log_string;
		std::flush(std::cout);
	}
}

void LogFile::log(std::string tag, std::string message) {

	std::chrono::high_resolution_clock::time_point current;
	current = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(current - program_start).count();

	std::stringstream line;
	line << "LOG; " << "+" << duration << " microseconds; " << tag << "; " << message << ";\n";
	std::string log_string = line.str();

	mutex_lock.lock(); // lock mutex to prevent other threads from messing with file

	log_file.open("log.txt", std::ios_base::app);
	log_file << log_string;
	log_file.close();

	if(displayFlag) {
		std::cout << log_string;
		std::flush(std::cout);
	}

	mutex_lock.unlock();
}

// same as log, but will print error instead
void LogFile::error(std::string tag, std::string message) {

	std::chrono::high_resolution_clock::time_point current;
	current = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(current - program_start).count();

	std::stringstream line;
	line << "ERROR; " << "+" << duration << " microseconds; " << tag << "; " << message << ";\n";
	std::string log_string = line.str();

	mutex_lock.lock(); // lock mutex to prevent other threads from messing with file

	log_file.open("log.txt", std::ios_base::app);
	log_file << log_string;
	log_file.close();

	if(displayFlag) {
		std::cout << log_string;
		std::flush(std::cout);
	}
	
	mutex_lock.unlock();
}

// void LogFile::writeToFile() {

// 	write_count = 0;
// 	std::string buffer_string = buffer.str();

// }