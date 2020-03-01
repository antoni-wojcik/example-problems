//
//  pimc.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 15/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

inline double rand_d() {
    return (double)rand()/(double)RAND_MAX;
}

int main() {
    srand(time(NULL));
    int n;
    cin >> n;
    int sum = 0;
    double x, y;
    for(int i = 0; i < n; i++) {
        x = rand_d();
        y = rand_d();
        if(x*x+y*y <= 1.0) sum++;
    }
    cout << (4*(double)sum/(double)n) << endl;
    
    return 0;
}
