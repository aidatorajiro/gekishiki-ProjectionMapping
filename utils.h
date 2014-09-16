#include <iostream>
#include <regex.h>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

namespace utils {
	vector<string> regexpmatch(const char *str, const char *regex, size_t nmatch);
	vector<string> split(const string &str, char delim);
	int stoi(string str);
	string itos(int number);
	bool isValueInRange(int value, int sta, int end);
	string replaceAll(string String1, string String2, string String3);
};