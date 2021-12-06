#include <bits/stdc++.h>

using namespace std;

void printIt(vector<string> v){

    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << endl;
    }
}


std::vector<std::string> split(const std::string& source, const std::string& delimiters = " ") {
        std::size_t prev = 0;
        std::size_t currentPos = 0;
        std::vector<std::string> results;
 
        while ((currentPos = source.find_first_of(delimiters, prev)) != std::string::npos) {
            //cout << "currentPos: " <<  currentPos << " prev: " << prev << endl;
            
            if (currentPos > prev) {
                results.push_back(source.substr(prev, currentPos - prev));
            }
            prev = currentPos + 1;
        }
        if (prev < source.length()) {
            results.push_back(source.substr(prev));
        }
        return results;
    }

vector<pair<int, int>> newRange(pair<int, int>p1, pair<int, int> p2){
    int x1 = p1.first;
    int y1 = p1.second;

    int x2 = p2.first;
    int y2 = p2.second;

    vector<pair<int,int>> start;
    start.push_back({x1, y1});
    
    while(true){
        if (x1 == x2 and y1 == y2){
            return start;
        } 

        if(x1 > x2){
            x1 -= 1;
        } else if(x1 < x2){
            x1 += 1;
        }

        if(y1 > y2){
            y1 -= 1;
        } else if(y1 < y2){
            y1 += 1;
        }

        start.push_back({x1, y1});

    }


}


int main(){

    // declare a vector
    vector<string> v;

    // declare a fstream object
	fstream newfile;

    //fstream object dot open with ios::in
	newfile.open("day5.txt", ios::in);
	if (newfile.is_open()) {
		string tp;
        //getline on tp
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

    //printIt(vstring);
    vector<pair<int, int>> v1, v2;
    
    //cout << vstring.size() << endl;
    for(int i = 0; i < vstring.size(); i++){

        vector<string> vec = split(vstring.at(i), " -> ");
        vector<string> vp1 = split(vec.at(0), ",");
        vector<string> vp2 = split(vec.at(1), ",");
        vector<int> vx, vy;

        int n1, n2;
        for(int j = 0; j < vp1.size(); j++){
            n1 =stoi(vp1.at(j));
            n2 = stoi(vp2.at(j));
            //cout << n1 << " " << n2 << endl;
            vx.push_back(n1);
            vy.push_back(n2);
        }
        v1.push_back(make_pair(vx.at(0), vx.at(1)));
        v2.push_back(make_pair(vy.at(0), vy.at(1)));

        //cout << v1.at(i).first << ", "<<v1.at(i).second << " " << v2.at(i).first << ", "<<v2.at(i).second << " " << endl;
    }
    cout << v1.size() << ", " << v2.size() << endl;
     //v1.at(i).first, v1.at(i).second;
    //v2.at(i).first, v2.at(i).second;
    map<pair<int, int>, int> mp;
    vector<pair<int,int>> fpair;
    for(int i = 0 ; i < v1.size(); i++){
        pair<int, int> p1, p2;
        // COMMENT THE BELOW IF STATEMENT FOR ANSWER 2
        if((v1.at(i).first == v2.at(i).first) or (v1.at(i).second == v2.at(i).second)){
            p1 = make_pair(v1.at(i).first, v1.at(i).second);
            p2 = make_pair(v2.at(i).first, v2.at(i).second);
            vector<pair<int, int>> vpair = newRange(p1, p2);

            for(auto &i: vpair){
                if(mp.find(i) == mp.end()){
                    mp[i] = 1;
                } else {
                    mp[i] +=1;
                }
            }
            //cout << "vpair size: " << vpair.size() << endl;
            //copy(vpair.begin(), vpair.end(), back_inserter(fpair));
        }
    }
    
    //Problem1 
    int answer=0;
    for(auto &i: mp){
        if(i.second >=2){
            answer+=1;
        }
    }
    cout << answer << endl;
    // To get the second answer comment the if statement;



}