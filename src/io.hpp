#pragma once
#include <glog/logging.h>

#include <fstream>
#include <string>
namespace simple_compiler {
namespace io {
std::string read_file(const std::string& file_name);
void write_file(const std::string& file_name, const std::string& data);
}  // namespace io

}  // namespace simple_compiler