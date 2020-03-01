//
//  inttrapez.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 16/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

template <typename F>
double inttrapez(F, double, double, int);
double fun(double x) {
    return sin(x);
}
double area(double a, double b, double h) {
    return (a+b)*h/2.0;
}

int main() {
    int n;
    cin >> n;
    cout << inttrapez(fun, 0.0, M_PI, n) << endl;
    return 0;
}

template <class F>
double inttrapez(F f, double a, double b, int n) {
    double result = 0.0;
    double dx = (b-a)/(double)n;
    for(int i = 0; i < n; i++) {
        result += area(f(a+i*dx), f(a+(i+1)*dx), dx);
    }
    return result;
}
