//
//  palindrom.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 15/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool palindrom(string& text) {
    string::size_type size = text.size(), half_size = (size+1)/2;
    for(string::size_type i = 0; i < half_size; i++) {
        if(text[i] != text[size-i-1]) return false;
    }
    
    return true;
}

void get_text_from_file(string& file_name, string& text) {
    ifstream i_file(file_name);
    
    string line;
    if(i_file.is_open()) while(getline(i_file, line)) {
        text.append(line+" ");
    } else {
        cout << "ERROR: FILE DOES NOT EXIST: " << file_name << "\n";
        exit(-1);
    }
    i_file.close();
}

void break_text(string& text, vector<string>& out) {
    const char* s_cl = ".?!";
    
    string::size_type dot_idx;
    while(text.size()) {
        dot_idx = text.find_first_of(s_cl);
        out.push_back(text.substr(0, dot_idx+1));
        text.erase(0, dot_idx+2);
    }
}

string prepare_sentence(string& s) {
    string::size_type size;
    size = s.size();
    string prep = "";
    wchar_t c;
    
    for(string::size_type i = 0; i < size; i++) {
        c = s[i];
        if(c >= 'a' && c <= 'z') prep += c;
        else if(c >= 'A' && c <= 'Z') prep += (c-'A'+'a');
        else if(c == "Ą"[0] || c == "ą"[0]) prep += "ą";
        else if(c == "Ę"[0] || c == "ę"[0]) prep += "ę";
        else if(c == "Ć"[0] || c == "ć"[0]) prep += "ć";
        else if(c == "Ł"[0] || c == "ł"[0]) prep += "l";
        else if(c == "Ż"[0] || c == "ż"[0]) prep += "ż";
        else if(c == "Ź"[0] || c == "ź"[0]) prep += "ź";
    }
    
    return prep;
}

int main() {
    setlocale(LC_CTYPE, "en_US.UTF-8");
    string i_name = "text.txt", o_name = "palindrom_out.txt";
    string text;
    get_text_from_file(i_name, text);
    
    vector<string> sentences;
    break_text(text, sentences);
    string prepared_s;
    ofstream o_file(o_name);
    
    for(int i = 0; i < sentences.size(); i++) {
        prepared_s = prepare_sentence(sentences[i]);
        if(palindrom(prepared_s)) o_file << sentences[i] << "\n";
    }
    o_file.close();
    
    system(("open " + o_name).c_str());
    
    return 0;
}

