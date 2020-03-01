//
//  vecfind.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 19/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

typedef int type;

template <typename T>
int vecfind(const vector<T>&, const T&, int);

int main() {
    int l;
    cin >> l;
    
    vector<type> tab;
    string line;
    getline(cin, line);
    istringstream str(line);
    type temp;
    while(str >> temp) tab.push_back(temp);
    str.clear();
    
    int idx = 0;
    do {
        idx = vecfind(tab, l, idx+1);
        if(idx != -1) cout << idx << " ";
    } while(idx != -1);
    cout << endl;
    
    return 0;
}

template <typename T>
int vecfind(const vector<T>& v, const T& f, int idx_0) {
    for(int i = idx_0; i < v.size(); i++) {
        if(v[i] == f) return i;
    }
    return -1;
}
