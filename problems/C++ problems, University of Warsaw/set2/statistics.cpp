//
//  statistics.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 15/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

double mean(double* tab, int size) {
    double sum = 0;
    for(int i = 0; i < size; i++) {
        sum += tab[i];
    }
    return sum/(double)size;
}

double std_dev(double* tab, int size) {
    double sum = 0;
    double mean_val = mean(tab, size);
    for(int i = 0; i < size; i++) {
        sum += (tab[i] - mean_val) * (tab[i] - mean_val);
    }
    return sqrt(sum/(double)(size*(size-1)));
}

int main() {
    int n;
    cin >> n;
    double data[n];
    for(int i = 0; i < n; i++) {
        cin >> data[i];
    }
    cout << "Mean: " << mean(data, n) << "\n";
    cout << "Standard deviation: " << std_dev(data, n) << endl;
    
    return 0;
}
