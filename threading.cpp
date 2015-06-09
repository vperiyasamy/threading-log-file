#include "log_file.h"
#include <string>
#include <thread>
#include <chrono>

void task(std::chrono::high_resolution_clock::time_point start, std::string tag) {
    for(int i = 0; i < 10; i++) {
        LogFile::log(start, tag, std::to_string(i + 1));
    }
}

int main(int argc, char *argv[]) {

    std::chrono::high_resolution_clock::time_point program_start;
    program_start = LogFile::startLog();

    std::thread t1(task, program_start, "A");
    std::thread t2(task, program_start, "B");
    std::thread t3(task, program_start, "C");
    std::thread t4(task, program_start, "D");
    std::thread t5(task, program_start, "E");
    std::thread t6(task, program_start, "F");
    std::thread t7(task, program_start, "G");
    std::thread t8(task, program_start, "H");
    std::thread t9(task, program_start, "I");
    std::thread t10(task, program_start, "J");

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    t9.join();
    t10.join();

}