//
//  intersection.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 18/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    vector<int> tab1;
    string line;
    getline(cin, line);
    istringstream str(line);
    int temp;
    while(str >> temp) tab1.push_back(temp);
    str.clear();
    
    vector<int> tab2;
    getline(cin, line);
    str = istringstream(line);
    while(str >> temp) tab2.push_back(temp);
    str.clear();
    
    vector<int> result;
    sort(tab1.begin(), tab1.end());
    sort(tab2.begin(), tab2.end());
    int i = 0, j = 0, s1 = tab1.size(), s2 = tab2.size();
    int x = -1;
    while(i < s1 && j < s2) {
        if(tab1[i] == tab2[j] && (x == -1 || tab1[i] != result[x])) {
            result.push_back(tab1[i]);
            x++;
            i++;
            j++;
        }
        else if(tab1[i] > tab2[j]) j++;
        else if(tab1[i] < tab2[j]) i++;
        cout << tab1[i] << " " << i << " " << tab2[j] << " " << j << "\n";
    }
    
    for(int i = 0; i < result.size(); i++) cout << result[i] << " ";
    cout << endl;
    
    return 0;
}
