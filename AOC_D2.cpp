#include "C:/Users/50002696/source/repos/stdc++.h"
using namespace std;

int main() {
	vector<string> v;
	fstream newfile;
	newfile.open("D:/Data/day2_ - Copy.txt", ios::in);
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

	
	string segment;
	vector<string> seglist;
	vector<int> vintf;
	
	for (auto& i : vstring) {
		int j = 0;
		//cout << i << endl;
		stringstream test(i);
		while (getline(test, segment, ' '))
		{
			if (j == 0) {
				seglist.push_back(segment); //Spit string at '_' character
			}
			else {
				vintf.push_back(stoi(segment));
			}
			j++;
		}
		
	}


	// Problem: 1
	int f=0, d=0;
	for (int i = 0; i < seglist.size(); i++) {
		if (seglist.at(i) == "forward") {
			f += vintf.at(i);
		} 
		else if(seglist.at(i) == "up") {
			d -= vintf.at(i);
		}
		else if (seglist.at(i) == "down") {
			d += vintf.at(i);
		}
	}

	cout << f * d << endl;

	// Problem: 2
	int f1 = 0, d1 = 0, aim=0;
	for (int i = 0; i < seglist.size(); i++) {
		if (seglist.at(i) == "forward") {
			f1 += vintf.at(i);
			d1 += aim * vintf.at(i);
		}
		else if (seglist.at(i) == "up") {
			aim -= vintf.at(i);
		}
		else if (seglist.at(i) == "down") {
			aim += vintf.at(i);
		}
	}

	cout << "=============" << endl;
	cout << f1 * d1 << endl;
}