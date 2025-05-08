#include "csv.h"

#include <iostream>
#include <string>

using namespace csv;

int main() {

	std::string filename = R"(E:\zsl\test_deps\csv\data.csv)";
	CSVFormat format;
	format.delimiter(',').header_row(0);


	CSVReader reader(filename, format);
	CSVRow row;
	reader.read_row(row);
	std::cout << row.to_json_array() << std::endl;
	//for(auto &row : reader) {
	//	// Do stuff with rows here
	//	std::cout << row.to_json_array() << std::endl;
	//}


	std::string csv_string = "Actor,Character\r\n"
		"Will Ferrell,Ricky Bobby\r\n"
		"John C. Reilly,Cal Naughton Jr.\r\n"
		"Sacha Baron Cohen,Jean Giard\r\n";

	auto rows = parse(csv_string);
	for(auto &r : rows) {
		// Do stuff with row here
		std::cout << r.to_json_array() << std::endl;
	}

}