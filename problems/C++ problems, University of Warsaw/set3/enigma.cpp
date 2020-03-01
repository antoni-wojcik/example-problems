//
//  enigma.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 16/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, const char* argv[]) {
    int n = atoi(argv[1]);
    int mode = 1;
    if(!strcmp(argv[2], "/e"));
    else if(!strcmp(argv[2], "/d")) mode = 0;
    else {
        cout << "ERROR: INCORRECT MODE: " << argv[2] << endl;
        return(-1);
    }
    const char* i_file_name = argv[3];
    string o_file_name = argv[4];
    
    ifstream i_file(i_file_name);
    
    string text = "", line;
    
    if(i_file.is_open()) {
        while(getline(i_file, line)) text.append(line + "\n");
    }else {
        cout << "ERROR: FILE DOES NOT EXIST: " << i_file_name << endl;
        return -1;
    }
    i_file.close();
    
    ostringstream out;
    
    if(mode) {
        for(string::size_type i = 0; i < text.size(); i++) {
            out << (int)(text[i]^n) << " ";
        }
    } else {
        istringstream in(text);
        int temp;
        while(in >> temp) out << (char)(temp^n);
    }
    
    ofstream o_file(o_file_name);
    o_file << out.str();
    o_file.close();
    system(("open " + o_file_name).c_str());

    return 0;
}
