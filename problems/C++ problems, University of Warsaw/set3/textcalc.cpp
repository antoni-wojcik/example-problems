//
//  textcalc.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 16/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#define INPUT_FILE_NAME "in_calc.txt"
#define OUTPUT_FILE_NAME "out_calc.txt"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
using namespace std;

double textcalc(string expr) {
    istringstream str(expr);
    double x, y, result = 0.0;
    char type;
    str >> x >> type >> y;
    
    if(type == '+') result = x + y;
    else if(type == '-') result = x - y;
    else if(type == '*') result = x * y;
    else if(type == '/') result = x / y;
    else if(type == '%') result = (int)x % (int)y;
    else if(type == '^') result = pow(x, y);
    else {
        cout << "WRONG SYMBOL IN THE EXPRESSION: " << expr << "\n";
        exit(-1);
    }
    
    return result;
}

int main() {
    string input;
    ifstream i_file(INPUT_FILE_NAME);
    ofstream o_file(OUTPUT_FILE_NAME);
    if(i_file.is_open()) {
        while(getline(i_file, input)) {
            o_file << input << " = " << textcalc(input) << "\n";
        }
    } else {
        cout << "FILE DOES NOT EXIST\n";
        return -1;
    }
    i_file.close();
    o_file.close();
    system(("open " + (string)OUTPUT_FILE_NAME).c_str());
    return 0;
}
