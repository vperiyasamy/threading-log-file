#include "log_file.h"
#include <string>
#include <thread>
#include <chrono>

void task(std::chrono::high_resolution_clock::time_point start, std::string tag, std::string message) {
    for(int i = 0; i < 10; i++) {
        LogFile::log(start, tag, message);
    }
}

int main(int argc, char *argv[]) {

    std::chrono::high_resolution_clock::time_point program_start;
    program_start = LogFile::startLog();

}