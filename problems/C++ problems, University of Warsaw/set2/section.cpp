//
//  section.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 15/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL));
    
    double x;
    int n;
    cin >> x >> n;
    
    double results[n];
    double sum = 0;
    
    for(int i = 0; i < n; i++) {
        results[i] = (double)rand()/(double)RAND_MAX;
        sum += results[i];
    }
    for(int i = 0; i < n; i++) {
        cout << results[i]/sum*x << " ";
    }
    cout << endl;
    
    
    return 0;
}
