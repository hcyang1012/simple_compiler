#include "io.hpp"

#include <fstream>
#include <string>

namespace simple_compiler {
namespace io {

std::string read_file(const std::string& file_name) {
  std::ifstream if_file(file_name, std::ifstream::in);
  if (!if_file.is_open()) {
    LOG(FATAL) << "Can't open the file << " << file_name;
  }

  std::string result;
  std::string line;
  while (std::getline(if_file, line)) {
    result += line;
  }
  return result;
}

void write_file(const std::string& file_name, const std::string& data) {
  std::ofstream of_file(file_name, std::ofstream::out);
  if (!of_file.is_open()) {
    LOG(FATAL) << "Can't open the file << " << file_name;
  }
  of_file << data;
}
}  // namespace io
}  // namespace simple_compiler