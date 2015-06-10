#include "log_file.h"
#include <thread>

void task(std::string tag) {
    for(int i = 0; i < 10; i++) {
        LogFile::log(tag, std::to_string(i + 1));
    }
}

int main(int argc, char *argv[]) {

    // std::chrono::high_resolution_clock::time_point program_start;
    // program_start = LogFile::startLog();

    // pass boolean to decide whether to display to cout also
    bool displayOn = true;
    LogFile::startLog(displayOn);

    std::thread t1(task, "A");
    std::thread t2(task, "B");
    std::thread t3(task, "C");
    std::thread t4(task, "D");
    std::thread t5(task, "E");
    std::thread t6(task, "F");
    std::thread t7(task, "G");
    std::thread t8(task, "H");
    std::thread t9(task, "I");
    std::thread t10(task, "J");

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