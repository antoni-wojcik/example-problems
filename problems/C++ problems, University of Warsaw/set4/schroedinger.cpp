//
//  schroedinger.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 16/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#define DIRAC_CONSTANT 1.0545718e-34
#define PRECISION 1.0e+30

#include <iostream>
#include <cmath>
using namespace std;

double r;

template <typename F>
double solve(F, double, double);
double eqn(double x) {
    return x*tan(x) - sqrt(r*r - x*x);
}

int main() {
    double m, a, V_0;
    cin >> m >> a >> V_0;
    r = a/(2*DIRAC_CONSTANT) * sqrt(2*m*V_0);
    double x_0 = solve(eqn, 0, r);
    double result = x_0*x_0/(r*r);
    cout << result << endl;
    
    return 0;
}

template <typename F>
double solve(F f, double a, double b) {
    double c = b, f_c;
    while(((b-a) >= PRECISION)) {
        c = (a+b)/2.0;
        f_c = f(c);
        if(f_c == 0.0) break;
        else if(f(a)*f_c < 0) b = c;
        else a = c;
    }
    
    return c;
}
