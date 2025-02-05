#include "parseCSV.hpp"
#include "getSign.hpp"
#include "toCSV.hpp"
#include<chrono>


std::vector<int> sliceVec(const std::vector<int>& v, const int& k) {
	std::vector<int> rtn;
	int i = 0;
	for (; i < k; ++i) {
		rtn.push_back(v.at(i));
	}
	return rtn;
}

int main() {
	
	std::string filename = "C:\\Users\\desmo\\Desktop\\fetchTickdb\\resourse\\ESZ4 Index_trades_2024-12-11_sliced1.csv";
	auto t1 = std::chrono::high_resolution_clock::now();
	auto opt = readTradeCSV(filename);
	auto t2 = std::chrono::high_resolution_clock::now();
	std::cout << "Parsing trade takes " << t1 - t2 << std::endl;
	int i = 0;
	for (; i < 5; ++i) {
		std::cout << std::put_time(&opt[i].timestamp, "%Y-%m-%d %H:%M:%S") << " " << opt[i].milli << " " 
			<< opt[i].volume << " " << opt[i].price << " " << opt[i].condition << '\n';
	}

	std::string filnameq = "C:\\Users\\desmo\\Desktop\\fetchTickdb\\resourse\\ESZ4 Index_quotes_2024-12-11.csv";
	t1 = std::chrono::high_resolution_clock::now();
	auto qtt = readQuotesCSV(filnameq);
	t2 = std::chrono::high_resolution_clock::now();
	std::cout << "Parsing trade takes " << t1 - t2 << std::endl;
	int j = 0;
	for (; j < 5; ++j) {
		std::cout << std::put_time(&qtt[j].timestamp, "%Y-%m-%d %H:%M:%S") << " " << qtt[j].milli << " " 
			<< qtt[j].volumeBid << " " << qtt[j].volumeAsk << " " << qtt[j].priceBid << " " << qtt[j].priceAsk << '\n';
	}

	std::cout << std::put_time(&qtt[80].timestamp, "%Y-%m-%d %H:%M:%S") << ' ' << qtt[80].milli << '\n';
	std::cout << firLessSec(opt[0].timestamp, opt[0].milli, qtt[80].timestamp, qtt[80].milli);
	
	std::vector<int> tm;

	auto sign_pos = getSign(opt, qtt, tm);
	//sign.push_back(1);
	std::cout << "Signs get";

	int idx = 0;
	for (;i < 10; ++i) {
		std::cout << sign_pos.first[i] << std::endl;
	}

	saveVectorToCSV(sign_pos.first, "C:\\Users\\desmo\\Desktop\\fetchTickdb\\resourse\\ESZ4 Index_trades_2024-12-11_sign.csv");
	saveVectorToCSV(sign_pos.second, "C:\\Users\\desmo\\Desktop\\fetchTickdb\\resourse\\ESZ4 Index_trades_2024-12-11_pos.csv");

	/*for (auto el : sign) {
		std::cout << "The sign is " << el << '\n';
	}*/

	return 0;
}