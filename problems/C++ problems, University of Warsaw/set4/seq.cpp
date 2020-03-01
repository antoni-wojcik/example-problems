//
//  seq.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 16/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char* argv[]) {
    int n = atoi(argv[1]);
    
    vector<int> ints;
    
    string i_name = argv[2], o_name = argv[3];
    ifstream i_file(i_name);
    if(i_file.is_open()) {
        int temp;
        while(i_file >> temp) ints.push_back(temp);
    } else {
        cout << "ERROR: FILE DOES NOT EXIST: " << i_name << endl;
        return -1;
    }
    i_file.close();
    
    if(n > 0) n = (int)ints.size() - n;
    n %= ints.size();
    rotate(ints.begin(), ints.begin() + n, ints.end());
    
    ofstream o_file(o_name);
    for(int i = 0; i < ints.size(); i++) o_file << ints[i] << " ";
    o_file.close();
    system(("open " + o_name).c_str());
    
    return 0;
}
