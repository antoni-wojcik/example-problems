//
//  letters.cpp
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

int main() {
    string i_name = "augustinus.txt";
    string text;
    get_text_from_file(i_name, text);
    
    int counter[26];
    for(int i = 0; i < 26; i++) {
        counter[i] = 0;
    }
    
    for(string::size_type i = 0; i < text.size(); i++) {
        if(text[i] >= 'a' && text[i] <= 'z') counter[text[i]-'a']++;
    }
    
    for(int i = 0; i < 26; i++) {
        cout << counter[i] << " ";
    }
    cout << endl;
    
    return 0;
}
