#include "toCSV.hpp"

template<typename T>
void saveVectorToCSV(const std::vector<T>& vec, const std::string& filename) {
    // Open the file in write mode
    std::ofstream file(filename);

    // Check if the file was successfully opened
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << " for writing." << std::endl;
        return;
    }

    // Write vector elements to the file, separated by commas
    for (size_t i = 0; i < vec.size(); ++i) {
        file << vec[i] << "\n";
        /*if (i != vec.size() - 1) {
            file << ","; // Add a comma between elements
        }*/
    }

    // Close the file
    file.close();

    std::cout << "Vector saved to " << filename << " successfully." << std::endl;
}

template void saveVectorToCSV(const std::vector<int>& vec, const std::string& filename);

void toCSV(std::vector<int> df) {
	std::fstream fout{ "C:\\Users\\desmo\\Desktop\\fetchTickdb\\tradingSign\\tradingSign.csv", std::ios::out || std::ios::app };
	
	int l = df.size();
	for (int i = 0; i < l; ++i) {
		int s = df[i];
		fout << s;
	}
}