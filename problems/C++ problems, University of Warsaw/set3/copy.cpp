//
//  copy.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 16/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void copy(istream& i, ostream& o) {
    o << i.rdbuf();
}

int main(int argc, const char* argv[]) {
    bool f_in = false, f_out = false;
    string i_name, o_name;
    
    if (argc == 2 || argc == 4 || argc > 5) {
        cout << "ERROR: INCORRECT ARGUMENTS\n";
        return -1;
    }
    if (argc == 3) {
        if (!strcmp(argv[1], "-i")) {
            f_in = true;
            i_name = argv[2];
        } else if (!strcmp(argv[1], "-o")) {
            f_out = true;
            o_name = argv[2];
        }
    } else if (argc == 5) {
        if (!strcmp(argv[1], "-i")) {
            f_in = true;
            i_name = argv[2];
            if (!strcmp(argv[3], "-o")) {
                f_out = true;
                o_name = argv[4];
            } else {
                cout << "ERROR: INCORRECT ARGUMENTS: SECOND\n";
                return -1;
            }
        } else if (!strcmp(argv[1], "-o")) {
            f_out = true;
            o_name = argv[2];
            if (!strcmp(argv[3], "-i")) {
                f_in = true;
                i_name = argv[4];
            } else {
                cout << "ERROR: INCORRECT ARGUMENTS: SECOND\n";
                return -1;
            }
        }
    }
    
    if(f_in) cout << "IN: " << i_name << "\n";
    if(f_out) cout << "OUT: " << o_name << "\n";
    
    if(f_in && f_out) {
        ifstream i_file(i_name);
        ofstream o_file(o_name);
        if(i_file.is_open()) copy(i_file, o_file);
        else {
            cout << "ERROR: FILE DOES NOT EXIST: " << i_name << "\n";
            return -1;
        }
        i_file.close();
        o_file.close();
    } else if(f_in) {
        ifstream i_file(i_name);
        ostringstream o_str;
        if(i_file.is_open()) copy(i_file, o_str);
        else {
            cout << "ERROR: FILE DOES NOT EXIST: " << i_name << "\n";
            return -1;
        }
        i_file.close();
        cout << o_str.str();
        o_str.clear();
    } else if(f_out) {
        string text = "", line;
        while(getline(cin, line) && line.size() != 0) text.append(line + "\n");
        istringstream i_str(text);
        ofstream o_file(o_name);
        copy(i_str, o_file);
        i_str.clear();
        o_file.close();
    } else {
        string text = "", line;
        while(getline(cin, line) && line.size() != 0) text.append(line + "\n");
        istringstream i_str(text);
        ostringstream o_str;
        copy(i_str, o_str);
        i_str.clear();
        cout << o_str.str();
        o_str.clear();
    }
    
    return 0;
}
