//
//  fibonacci.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 15/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <iostream>
using namespace std;


void fib_print(int n) {
    int curr = 1, prev = 0, temp;
    for(int i = 0; i < n; i++) {
        cout << prev << " ";
        temp = curr;
        curr += prev;
        prev = temp;
    }
    
}

int main() {
    int n;
    cin >> n;
    
    fib_print(n);
    
    cout << endl;
    
    return 0;
}
