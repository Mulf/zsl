#include "zatlab/data_import_and_analysis/data_import_and_export.h"
//#include "csv.h"
#include <fstream>
#include <filesystem>

namespace _ {
std::vector<std::string> split(const std::string &str, char delimiter) {
	std::vector<std::string> tokens;
	size_t start = 0;
	size_t end = str.find(delimiter);

	while(end != std::string::npos) {
		tokens.push_back(str.substr(start, end - start));
		start = end + 1;
		end = str.find(delimiter, start);
	}

	tokens.push_back(str.substr(start));
	return tokens;
}

zsl::vector_d str2num(const std::vector<std::string> &strs) {
	zsl::vector_d v{strs.size(), zsl::vector_d::allocator_type{}};
	for(size_t i = 0; i < strs.size(); i++) {
		v[i] = std::stod(strs[i]);
	}
	return v;
}

}


namespace zsl {

vector_d readvector(const std::string &filename) {
	if(!std::filesystem::exists(filename)) {
		Z_THROW(ZErrorCode::FILE_NOT_EXIST, "Cannot find file: " + filename);
	}

	std::ifstream ifs{filename};
	if(!ifs.is_open()) {
		Z_THROW(ZErrorCode::FILE_FAIL_TO_OPEN, "");
	}

	std::vector<std::string> lines{};
	std::string line{};
	while(std::getline(ifs, line)) {
		lines.push_back(line);
	}

	if(lines.size() == 1) {
		auto strs = _::split(lines[0], ',');
		return _::str2num(strs);
	}
	
	return _::str2num(lines);
}

vector2_d readmatrix(const std::string &filename) {
	if(!std::filesystem::exists(filename)) {
		Z_THROW(ZErrorCode::FILE_NOT_EXIST, "Cannot find file: " + filename);
	}

	vector2_d A{};
	std::ifstream ifs{filename};
	std::string line{};
	if(!ifs.is_open()) {
		Z_THROW(ZErrorCode::FILE_FAIL_TO_OPEN, "");
	}
	while(std::getline(ifs, line)) {
		auto elems = _::split(line, ',');
		vector_d v{elems.size(), vector_d::allocator_type{}};
		for(size_t i = 0; i < elems.size(); i++) {
			v[i] = std::stod(elems[i]);
		}
		A.push_back(std::move(v));
	}

	return A;
}


void writevector(const vector_d &v, const std::string &filename) {
	std::ofstream ofs{filename};
	if(!ofs.is_open()) {
		Z_THROW(ZErrorCode::FILE_FAIL_TO_OPEN, "");
	}

	for(auto c : v) {
		ofs << c << '\n';
	}
	ofs.close();
}

void writematrix(const vector2_d &A, const std::string &filename) {
	std::ofstream ofs{filename};
	if(!ofs.is_open()) {
		Z_THROW(ZErrorCode::FILE_FAIL_TO_OPEN, "");
	}

	for(auto v : A) {
		for(size_t i = 0; i < v.size(); i++) {
			if(i == 0)
				ofs << v[i];
			else
				ofs << ',' << v[i];
		}
		ofs << '\n';
	}
	ofs.close();
}

}