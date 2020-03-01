//
//  functions.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 18/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

class Function {
public:
    virtual double operator()(double) = 0;
    virtual double operator()(double, int) = 0;
};

class Sinus : public Function {
    double k;
public:
    Sinus(double k) : k(k) {}
    double operator()(double x) {
        return sin(k*x);
    }
    double operator()(double x, int n) {
        int a = n%4;
        if(a == 0)      return  pow(k, n)*sin(k*x);
        else if(a == 1) return  pow(k, n)*cos(k*x);
        else if(a == 2) return -pow(k, n)*sin(k*x);
        else            return -pow(k, n)*cos(k*x);
    }
};

class Exponential : public Function {
    double m;
public:
    Exponential(double m) : m(m) {}
    double operator()(double x) {
        return exp(m*x);
    }
    double operator()(double x, int n) {
        return pow(m, n)*exp(m*x);
    }
};

int main() {
    Sinus sine(3.);
    Exponential exponential(2.);
    Function &sinus = sine;
    Function &expo = exponential;
    cout << sinus(2., 1) << endl;
    cout << expo(1.) << endl;
    return 0;
}
