//
//  pre-numbers.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 19/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#define CALC_ADD
#define CALC_MEAN

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    vector<int> tab;
    string line;
    getline(cin, line);
    istringstream str(line);
    int temp;
    while(str >> temp) tab.push_back(temp);
    str.clear();
    
#ifdef CALC_ADD
    #define AT_LEAST_ONE
    int sum = 0;
    for(int i = 0; i < tab.size(); i++) sum += tab[i];
    cout << sum << "\n";
#endif
#ifdef CALC_MEAN
    #define AT_LEAST_ONE
    int sum2 = 0;
    for(int i = 0; i < tab.size(); i++) sum2 += tab[i];
    cout << (double)sum2/(double)tab.size() << "\n";
#endif
#ifdef CALC_MAX
    #define AT_LEAST_ONE
    int max = tab[0];
    for(int i = 0; i < tab.size(); i++) if (max < tab[i]) max = tab[i];
    cout << max << "\n";
#endif
#ifdef CALC_MIN
    #define AT_LEAST_ONE
    int min = tab[0];
    for(int i = 0; i < tab.size(); i++) if (min > tab[i]) min = tab[i];
    cout << min << "\n";
#endif
    
#ifndef AT_LEAST_ONE
    #error prosze zdefiniowac warunki
#endif
    
    return 0;
}
