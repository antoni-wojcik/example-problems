//
//  bubblesort.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 19/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>
#include "bubblesort.hpp"
#include "insertionsort.hpp"
#include "selectionsort.hpp"
using namespace std;

typedef double type;

int main() {
    vector<type> tab;
    string line;
    getline(cin, line);
    istringstream str(line);
    type temp;
    while(str >> temp) tab.push_back(temp);
    str.clear();
    
    selectionsort<type>(tab);
    
    for(int i = 0; i < tab.size(); i++) cout << tab[i] << " ";
    cout << endl;
    
    return 0;
}
