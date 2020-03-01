//
//  cipher.cpp
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
    if(!strcmp(argv[2], "/d")) n = -n;
    else if(!strcmp(argv[2], "/e"));
    else {
        cout << "ERROR: INCORRECT MODE: " << argv[2] << endl;
        return(-1);
    }
    const char* i_file_name = argv[3], *o_file_name = argv[4];
    
    ifstream i_file(i_file_name);
    
    string text = "", line;
    
    if(i_file.is_open()) {
        while(getline(i_file, line)) text.append(line + "\n");
    }else {
        cout << "ERROR: FILE DOES NOT EXIST: " << i_file_name << endl;
        return -1;
    }
    i_file.close();
    
    //shift the consonants:
    //first find where the consonants are
    vector<string::size_type> cons;
    char c;
    for(string::size_type i = 0; i < text.size(); i++) {
        c = text[i];
        if(c == 'b' || c == 'd' || c == 'g' || c == 'h' || c == 'k' || c == 'l' || c == 'm' || c == 'n' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'v' || c == 'w' || c == 'x' || c == 'z') cons.push_back(i);
    }
    vector<string::size_type> cons_new = cons;
    if(n > 0) n = (int)cons.size() - n;
    else n = -n;
    n %= cons.size();
    rotate(cons_new.begin(), cons_new.begin()+n, cons_new.end());
    
    string text_new = text;
    
    for(int i = 0; i < cons.size(); i++) {
        text_new[cons[i]] = text[cons_new[i]];
    }
    
    ofstream o_file(o_file_name);
    o_file << text_new;
    o_file.close();
    system(("open " + (string)o_file_name).c_str());
    
    return 0;
    
}
