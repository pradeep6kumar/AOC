#include "C:/Users/50002696/source/repos/stdc++.h"
using namespace std;

int get0ValueAtIndex(string str, int index) {
	return str[index]=='0';
}

int main() {
	vector<string> v;
	fstream newfile;
	// what is fstream
	// ios::in and ios::out
	// getline with streams
	newfile.open("D:/Data/day3_ - Copy.txt", ios::in);
	if (newfile.is_open()) {
		string tp;
		while (getline(newfile, tp)) {
			//cout << tp << endl;
			v.push_back(tp);
		}

		newfile.close();
	}

	
	vector<string> vstring;

	for (int i = 0; i < v.size(); i++) {
		vstring.push_back(v.at(i));
	}
	//cout << vstring.at(0) << endl;

	//Problem 1
	vector<pair<int, int>> mp0;
	vector<pair<int, int>> mp1;

	for (int i = 0; i < vstring.size(); i++) {
		for (int j = 0; j < vstring.at(i).size(); j++) {
			mp0.push_back({ j, mp0[j].second + get0ValueAtIndex(vstring.at(i), j) });
			mp1.push_back({ j, mp1[j].second + 1 - get0ValueAtIndex(vstring.at(i), j) });
		}
	}
	//cout <<  mp0[0].second << endl;
	
	string strs;
	for (int i = 0; i < mp0.size(); i++) {
		if (mp0[i] > mp1[i]) {
			//cout << mp0[i] << "--" << mp1[i] << endl;
			strs += '0';
		}
		else {
			strs += '1';
		}
	}

	cout << strs << endl;
	
}