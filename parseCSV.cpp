#include "parseCSV.hpp"

std::vector<TradeColumns> readTradeCSV(const std::string& filename) {
	std::vector<TradeColumns> data;
	std::ifstream file(filename);

	if (!file.is_open()) {
		std::cerr << "Error openning file: " << filename << std::endl;
		return data;
	}


	std::string line;
	getline(file, line);

	while (getline(file, line)) {
		std::istringstream iss(line);
		TradeColumns record;
		std::string entry;
 
		getline(iss, record.index, ',');
		getline(iss, entry, '.');

		std::tm tm = {};
		std::istringstream timeStream(entry);
		timeStream >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
		record.timestamp = tm;

		if (getline(iss, entry, ',')) {
			record.milli = std::stoi(entry);
		}

		if (getline(iss, entry, ',')) {
			record.volume = std::stod(entry);
		}

		if (getline(iss, entry, ',')) {
			record.price = std::stod(entry);
		}
		
		getline(iss, record.condition, ',');
		data.push_back(record);
	}
	return data;
}

std::vector<QuoteColumns> readQuotesCSV(const std::string& filename) {
	std::vector<QuoteColumns> data;
	std::ifstream file(filename);

	if (!file.is_open()) {
		std::cerr << "Error openning file: " << filename << std::endl;
		return data;
	}


	std::string line;
	getline(file, line);

	while (getline(file, line)) {
		std::istringstream iss(line);
		QuoteColumns record;
		std::string entry;

		getline(iss, record.index, ',');
		getline(iss, entry, '.');

		std::tm tm = {};
		std::istringstream timeStream(entry);
		timeStream >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
		record.timestamp = tm;

		if (getline(iss, entry, ',')) {
			record.milli = std::stoi(entry);
		}

		if (getline(iss, entry, ',')) {
			record.volumeBid = std::stod(entry);
		}

		if (getline(iss, entry, ',')) {
			record.volumeAsk = std::stod(entry);
		}

		if (getline(iss, entry, ',')) {
			record.priceBid = std::stod(entry);
		}

		if (getline(iss, entry, ',')) {
			record.priceAsk = std::stod(entry);
		}
		data.push_back(record);
	}
	return data;
}