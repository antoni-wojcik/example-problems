//
//  strreplace.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 16/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//


// EEEEEEE!!!! NIE WIEM!
// TODO ZROBIĆ JESZCZE RAZ

#include <iostream>
#include <string>
using namespace std;

char* strreplace(const char* str) {
    char result[30];
    bool next = true;
    strcpy(result, str);
    for(int i = 0; i < 30; i++) {
        if(!(result[i] == '\n')) {
            if(next) {
                toupper(result[i]);
                next = false;
            } else if(result[i] == ' ') next = true;
        } else break;
    }
    
    return result;
}

int main() {
    string line;
    const char *in;
    getline(cin, line);
    in = line.c_str();
    cout << "A" << strreplace(in) << endl;
    
    return 0;
}
