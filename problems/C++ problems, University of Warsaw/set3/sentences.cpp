//
//  sentences.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 16/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void get_text_from_file(string& file_name, string& text) {
    ifstream i_file(file_name);
    
    string line;
    if(i_file.is_open()) while(getline(i_file, line)) {
        text.append(line+"\n");
    } else {
        cout << "ERROR: FILE DOES NOT EXIST: " << file_name << "\n";
        exit(-1);
    }
    i_file.close();
}


string text_transform(string& s) {
    string mod;
    
    const char* s_cl = ".?!";
    string::size_type dot_idx;
    string temp;
    while(s.size()) {
        dot_idx = s.find_first_of(s_cl);
        temp = s.substr(0, dot_idx+2);
        s.erase(0, dot_idx+2);
        temp[0] = toupper(temp[0]);
        for(string::size_type i = 1; i < temp.size(); i++) {
            temp[i] = tolower(temp[i]);
        }
        mod.append(temp);
    }
    
    return mod;
}

int main() {
    string i_name = "in_2.txt", o_name = "out_2.txt";
    string text;
    get_text_from_file(i_name, text);
    
    ofstream o_file("out_2.txt");
    o_file << text_transform(text);
    
    system(("open " + o_name).c_str());
    
    return 0;
}
