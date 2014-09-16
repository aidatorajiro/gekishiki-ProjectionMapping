#include "utils.h"
using namespace std;

vector<string> utils::regexpmatch(const char *str, const char *regex, size_t nmatch) {
	vector<string> returnstring;
	regex_t        preg;
	regmatch_t     pmatch[nmatch];
	regcomp(&preg, regex, REG_EXTENDED|REG_NEWLINE);
	regexec(&preg, str, nmatch, pmatch, 0);
	for (int i = 0; i < nmatch; i++) {
		if (pmatch[i].rm_so > -1 && pmatch[i].rm_eo > -1) {
			returnstring.push_back(string(str, pmatch[i].rm_so, pmatch[i].rm_eo - pmatch[i].rm_so));
		} else {
			returnstring.push_back("");
		}
	}
	regfree(&preg);
	return returnstring;
}

vector<string> utils::split(const string &str, char delim) {
	vector<string> res;
	size_t current = 0, found;
	while((found = str.find_first_of(delim, current)) != string::npos){
		res.push_back(string(str, current, found - current));
		current = found + 1;
	}
	res.push_back(string(str, current, str.size() - current));
	return res;
}

int utils::stoi(string str) {
	return atoi(str.c_str());
}

string utils::itos(int number) {
	stringstream ss;
	ss << number;
	return ss.str();
}

bool utils::isValueInRange(int value, int sta, int end) {
    if (sta > end) {
        return (value >= end) && (value <= sta);
    } else {
        return (value >= sta) && (value <= end);
    }
}

string utils::replaceAll(string String1, string String2, string String3) {
    string::size_type  Pos( String1.find( String2 ) );
	
    while( Pos != string::npos )
    {
        String1.replace( Pos, String2.length(), String3 );
        Pos = String1.find( String2, Pos + String3.length() );
    }
	
    return String1;
}