//
//  exact-sum.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 18/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int sum(vector<int>& tab, int x, int y) {
    int s = 0;
    for(int i = x; i < y; i++) s += tab[i];
    return s;
}

int main() {
    bool found = false;
    int n;
    cin >> n;
    
    vector<int> tab;
    string line;
    getline(cin, line);
    istringstream str(line);
    int temp;
    while(str >> temp) tab.push_back(temp);
    str.clear();
    
    int x = 0, y = 0, size = tab.size(), s;
    while(x < size && !found) {
        s = sum(tab, x, y);
        if(s == n) found = true;
        else if(s > n) x++;
        else y++;
    }
    
    for(int i = x; i < y; i++) cout << tab[i] << " ";
    cout << endl;
    
    return 0;
}
