#ifndef toCSV_HPP
#define toCSV_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

template <typename T>
void saveVectorToCSV(const std::vector<T>& vec, const std::string& filename);

#endif