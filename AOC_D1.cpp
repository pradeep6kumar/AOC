#include "C:/Users/50002696/source/repos/stdc++.h"
using namespace std;

// What I have learned, we can use stoi to convert string of numbers to integers
// how to open and close file using c++
	// define fstream with a handle
	// handle.open(path, ios::in) or handle.open(path, ios::out) -> output
	// check if its open using handle.is_open
	// define a local string
	// run a while loop where getline(handle, localString) will eventually blank or newline
	// keep pushing back the in the vector
	// then close the handle handle.close()



int main() {
	vector<string> v;
	fstream newfile;
	newfile.open("D:/Data/day1 - Copy.txt", ios::in);
	if (newfile.is_open()) {
		string tp;
		while (getline(newfile, tp)) {
			//cout << tp << endl;
			v.push_back(tp);
		}

		newfile.close();
	}
	vector<int> vint;
	
	for (int i = 0; i < v.size(); i++) {
		vint.push_back(stoi(v.at(i)));
	}
	
	//## Problem1
	vector<int> p;
	for (int i = 0; i < v.size()-1; i++) {
		p.push_back((vint.at(i + 1) - vint.at(i)) > 0);
	}
	int sums = 0;
	for (auto& i : p) {
		sums += i;
	}

	cout << sums << endl;

	//## Problem2
	vector<int> vint2;
	int runLength = v.size() - 3;

	for (int i = 0; i <= runLength; i++) {
		vint2.push_back(vint.at(i) + vint.at(i + 1) + vint.at(i + 2));
	}

	vector<int> p2;
	for (int i = 0; i < runLength ; i++) {
		p2.push_back((vint2.at(i + 1) - vint2.at(i)) > 0);
	}
	int sums2 = 0;
	for (auto& i : p2) {
		sums2 += i;
	}
	cout << sums2 << endl;
	
}