//
//  bits.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 03/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <cstdio>
#include <iostream>
using namespace std;

void bitsInt(int k) {
    int bits = 8*sizeof(k);
    unsigned int mask = 1<<(bits-1);
    
    for (int i = 0; i < bits; i++) {
        cout << (k & mask ? 1 : 0);
        mask >>= 1;
    }
    
    cout << "\n";
}

int main() {
    bitsInt(100100003);
    return 1; 
}
