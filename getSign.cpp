#include "getSign.hpp"

bool firLessSec(std::tm& t1, int m1, std::tm& t2, int m2) {
	if (std::mktime(&t1) < std::mktime(&t2)) {
		return true;
	}
	else if (std::mktime(&t1) == std::mktime(&t2)) {
		if (m1 < m2) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

std::pair<std::vector<int>, std::vector<int>> getSign(std::vector<TradeColumns>& T, std::vector<QuoteColumns>& Q, std::vector<int>& tm) {
	int i = 0; int j = 0;
	std::vector<int> rtn;

	while ((i < T.size()) && (j < Q.size())) {
		
		if (firLessSec(T[i].timestamp, T[i].milli, Q[j].timestamp, Q[j].milli)) {
			++i;
			int cnt = tm.size() - 1;
			
			while (tm.at(cnt) < 0) {
				--cnt;
				//std::cout << cnt << '\n';
			}
			if (cnt >= 0) {
				j = tm.at(cnt) + 1;
			}

			rtn.push_back(-2);
			tm.push_back(-1);
			//std::cout << rtn[0];
		}
		else {//std::cout << times << ' ';
			if (T[i].price == Q[j].priceBid) {
				if (T[i].volume == Q[j].volumeBid - Q[j + 1].volumeBid) {
					++i;
					rtn.push_back(-1);
					tm.push_back(j);
				}
				else if ((T[i].volume == Q[j].volumeBid) && (Q[j + 1].priceBid < Q[j].priceBid)) {
					++i;
					rtn.push_back(-1);
					tm.push_back(j);
				}
			}
			else {
				if (T[i].volume == Q[j].volumeAsk - Q[j + 1].volumeAsk) {
					++i;
					rtn.push_back(1);
					tm.push_back(j);
				}
				else if ((T[i].volume == Q[j].volumeAsk) && (Q[j + 1].priceAsk > Q[j].priceAsk)) {
					++i;
					rtn.push_back(1);
					tm.push_back(j);
				}
			}
		}
		
		++j;
	}

	return std::make_pair(rtn, tm);
}