#include "C:/Users/50002696/source/repos/stdc++.h"
using namespace std;

vector<int> split(string str, string delim) {
	
	string str1;
	int current = 0;
	int prev = 0;
	vector<int> v;
	int value;

	while (true) {
		prev = 0;
		current = str.find_first_of(delim, prev);
		str1 = str.substr(prev, current);
		current += 1;
		str = str.substr(current);
		value = stoi(str1);
		v.push_back(value);

		if (str.size() == 1) {
			value = stoi(str);
			v.push_back(value);
			break;
		}
		
	}

	return v;
	
}

int decrease(int value, int breakpt) {
	

	if(breakpt <= 0){
		return 1;
	}
	else if (value == 0) {
		return decrease(6, breakpt - 1) + decrease(8, breakpt - 1);
	}
	else {
		return decrease(value - 1, breakpt - 1);
	}

}




int main() {
	vector<string> v;
	fstream newfile;
	// what is fstream
	// ios::in and ios::out
	// getline with streams
	newfile.open("D:/Data/day6.txt", ios::in);
	if (newfile.is_open()) {
		string tp;
		while (getline(newfile, tp)) {
			//cout << tp << endl;
			v.push_back(tp);
		}

		newfile.close();
	}



	//cout << v.at(0) << endl;
	vector<int> vf = split(v.at(0), ",");

	

	// Problem 1:
	int sums = 0;
	for (auto& i : vf) {
		//cout << sums << endl;
		sums += decrease(i, 18);
	}
	cout << sums << endl;

	
	map<int,  long long> mp;
	for (int i = 0; i <= 9; i++) {
		if(mp.find(i) == mp.end()) {
			mp[i] = 0;
		}

	}

	// Problem: 2
	
	for (auto& i : vf) {
		mp[i] += 1;
	}

	int days = 256;
	long long reproduceFish = 0;

	for (int i = 0; i < days; i++) {
		reproduceFish = mp[0];
		for (int j = 0; j < 9; j++) {
			mp[j] = mp[(j + 1)];
		}
		mp[8] += reproduceFish;
		mp[6] += reproduceFish;
	}
	long  long sumsf = 0;
	for (auto& i : mp) {
		cout << i.first << " , " << i.second << endl;
		sumsf += i.second;
	}
	cout << sumsf << endl;
	
	
}