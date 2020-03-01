//
//  comments.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 15/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    char comment;
    string i_name, o_name;
    cin >> comment >> i_name >> o_name;
    
    ifstream i_file(i_name);
    ofstream o_file(o_name);
    
    string line;
    
    if(i_file.is_open()) {
        cout << "OPENED FILE: " << i_name << "\n";
        while(getline(i_file, line)) {
            if(line[0] != comment) o_file << line << "\n";
        }
    } else {
        cout << "ERROR: FILE DOES NOT EXIST: " << i_name << "\n";
        return -1;
    }
    
    i_file.close();
    o_file.close();
    
    system(("open " + o_name).c_str());
    
    return 0;
    
}
