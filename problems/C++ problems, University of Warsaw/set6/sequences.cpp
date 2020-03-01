//
//  sequences.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 18/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

class Sequence {
public:
    virtual double operator[](int) = 0;
};

class Arithmetic : public Sequence {
    double a, delta;
public:
    Arithmetic(double a, double delta) : a(a), delta(delta) {}
    double operator[](int i) {
        return a + i*delta;
    }
};

class Fibonacci : public Sequence {
    double operator[](int i) {
        if(i < 2) return i;
        else return operator[](i-1) + operator[](i-2);
    }
};

int main() {
    Sequence *arithmetic = new Arithmetic(2.,3.);
    Sequence *fibonacci = new Fibonacci;
    for(int n = 0; n < 10; ++n)
        cout << (*arithmetic)[n] << " ";
    cout << endl;
    for(int n = 0; n < 10; ++n)
        cout << (*fibonacci)[n] << " ";
    cout << endl;
    delete fibonacci;
    delete arithmetic;
    return 0;
}
