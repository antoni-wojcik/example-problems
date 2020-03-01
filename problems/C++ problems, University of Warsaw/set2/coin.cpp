//
//  coin.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 15/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <ctime>
using namespace std;

double toss(double prob) {
    return (double)rand()/(double)RAND_MAX <= prob;
}

int main() {
    double prob;
    int n;
    
    srand(time(NULL));
    
    cin >> prob >> n;
    for(int i = 0; i < n; i++) {
        if(toss(prob)) cout << "orzel ";
        else cout << "reszka ";
    }
    
    cout << endl;
    
    return 0;
}
