#include "CpuMonitor.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept> 
#include <string> 

CpuStats CpuMonitor::readStats() const {
  std::ifstream file("/proc/stat");      //opens the linux CPU statistics file

  if (!file.is_open()) { 
    throw std::runtime_error("Failed to open /proc/stat");
  }


  std::string line;
  std::getline(file, line);              //reads the first line

  std::istringstream stream(line);       //parses the numbers

  std::string cpuLabel;
  CpuStats stats;

  stream >> cpuLabel
    >> stats.user
    >> stats.nice
    >> stats.system
    >> stats.idle
    >> stats.iowait
    >> stats.irq
    >> stats.softirq
    >> stats.steal;

  if (cpuLabel != "cpu" || stream.fail()) {
    throw std::runtime_error("Failed to parse CPU stats:");
  }

  return stats;
}
