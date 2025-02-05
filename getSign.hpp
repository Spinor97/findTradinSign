#ifndef getSign_HPP
#define getSign_HPP

#include <vector>
#include "parseCSV.hpp"

bool firLessSec(std::tm& t1, int m1, std::tm& t2, int m2);

std::pair<std::vector<int>, std::vector<int>> getSign(std::vector<TradeColumns>& T, std::vector<QuoteColumns>& Q, std::vector<int>& tm);

#endif