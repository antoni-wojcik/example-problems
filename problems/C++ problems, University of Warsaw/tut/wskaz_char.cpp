//
//  wskaz_char.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 02/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    const char **v;
    const char *t[] = { "abcd", "efghi", "jklmno" };
    
    v = t;
    
    cout << "v+2    = " << v+2 << "\n";
    cout << "v[2]   = " << v[2] << "\n";
    cout << "*(v+2) = " << *(v+2) << "\n";
    
    cout << "t[1][2]     = " << t[1][2] << "\n";
    cout << "*(*(t+1)+2) = " << *(*(t+1)+2) << "\n";
    return 0;
}
