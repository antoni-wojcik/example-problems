//
//  factor.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 15/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int div = 2;
    while(n != 1) {
        if(!(n%div)) {
            cout << div << " ";
            n /= div;
        } else div++;
    }
    cout << endl;
    
    return 0;
}
