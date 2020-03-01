//
//  main.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 01/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <iostream>
using namespace std;

void printTable(int* tab[], int dim1, int dim2) {
    for (int w = 0; w < dim1; w++) {
        for (int k = 0; k < dim2; k++) cout << tab[w][k] << " ";
        cout << "\n";
    }
}

int main(int argc, const char * argv[]) {
    int tt[3][4] = {{1,2,3,4}, {7,6}, {1}};
    
    const int dim1 = 3;
    const int dim2 = 4;
    
    int* tab[dim1];
    for (int i = 0; i < dim1; i++) {
        tab[i] = tt[i];
    }
    
    printTable(tab, dim1, dim2);
}
