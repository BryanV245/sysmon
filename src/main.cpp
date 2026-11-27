#include <iostream>
#include "CpuMonitor.hpp"
int main() {
    std::cout << "Welcome to SysMon++!" << std::endl;
    std::cout << "Linux System Monitor v0.1.0" << std::endl;
    


    CpuMonitor cpuMonitor;                           //creates a CpuMonitor object

    CpuStats stats = cpuMonitor.readStats();         //calls the CPU reader
    


    //displays the results from the CPU reader
    std::cout << "CPU Statistics:\n";
    std::cout << "----------------------\n";
    std::cout << "User:    " << stats.user << '\n';
    std::cout << "Nice:    " << stats.nice << '\n';
    std::cout << "System:  " << stats.system << '\n';
    std::cout << "Idle:    " << stats.idle << '\n';
    std::cout << "IOWait:  " << stats.iowait << '\n';
    std::cout << "IRQ:     " << stats.irq << '\n';
    std::cout << "SoftIRQ: " << stats.softirq << '\n';
    std::cout << "Steal:   " << stats.steal << '\n';    
    

    return 0;
}
