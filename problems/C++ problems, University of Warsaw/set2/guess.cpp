//
//  guess.cpp
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
    
    int min = 0, max = 100, ans = 2, rand_val;
    
    while (ans && min != max) {
        rand_val = rand() % (max-min) + min;
        cout << min << " " << max << "\n";
        cout << "\nIs it: " << rand_val << "?" << endl;
        cin >> ans;
        switch(ans) {
            case -1:
                max = rand_val-1;
                break;
            case 1:
                min = rand_val+1;
                break;
            default:
                cout << "The answer is: " << rand_val << endl;
                return 0;
        }
    }
    cout << "The answer is: " << min << endl;
    return 0;
}
