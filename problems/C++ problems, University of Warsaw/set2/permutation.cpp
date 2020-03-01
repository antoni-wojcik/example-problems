//
//  permutation.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 15/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <iostream>
using namespace std;

void swap_elements(int& e1, int& e2) {
    int temp = e2;
    e2 = e1;
    e1 = temp;
}

void permute(int* tab, int size, const int n) {
    if(size == 1) {
        for(int i = 0; i < n; i++) cout << tab[i] << " ";
        cout << "\n";
        return;
    }
    for(int i = 0; i < size; i++) {
        swap_elements(tab[n-size], tab[n-size+i]);
        permute(tab, size-1, n);
        swap_elements(tab[n-size], tab[n-size+i]);
    }
}

int main() {
    int n;
    cin >> n;
    int tab[n];
    for(int i = 0; i < n; i++) {
        tab[i] = i+1;
    }
    permute(tab, n, n);
    cout << endl;
    
    return 0;
}
