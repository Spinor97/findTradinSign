#ifndef parseCSV_HPP
#define parseCSV_HPP

#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>

struct TradeColumns {
	std::string index;
	std::tm timestamp;
	int milli;
	double volume;
	double price;
	std::string condition;
};

struct QuoteColumns {
	std::string index;
	std::tm timestamp;
	int milli;
	double volumeBid;
	double volumeAsk;
	double priceBid;
	double priceAsk;
};

std::vector<TradeColumns> readTradeCSV(const std::string& filename);

std::vector<QuoteColumns> readQuotesCSV(const std::string& filename);

#endif parseCSV_HPP