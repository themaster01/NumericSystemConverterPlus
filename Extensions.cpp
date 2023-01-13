#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static string reverseStr(string str) {
	int i = str.length();
	string result = "";
	
	for (; i >= 0; i--) {
		result += str[i];
	}

	return result;
}


static vector<int> digitSplitter(unsigned long long  num) {

	vector<int> vec;
	vec.resize(to_string(num).length());
	int i = 0;

	unsigned long long tst = num;

	while (tst > 0) {
		vec[i] = tst % 10;
		i++;
		tst /= 10;
	}
	
	return vec;
}



static unsigned long long power(int num, int pwr) {

	int i = 1;
	unsigned long long c = num;
	
	if (pwr == 0) {
		return 1;
	}
	else if (pwr == 1) {
		return num;
	}

	for (; i < pwr; i++) {
		c *= num;
	}
	return c;
}