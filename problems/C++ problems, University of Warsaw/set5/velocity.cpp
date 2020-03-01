//
//  velocity.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 16/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

class Velocity {
private:
    double v;
public:
    Velocity() : v(0.0) {}
    Velocity(double v) : v(v) {}
    double gamma() {
        return 1.0/sqrt(1-v*v);
    }
    friend Velocity operator+(const Velocity&, const Velocity&);
    Velocity& operator+=(const Velocity& u) {
        v = (v+u.v)/(1.0+v*u.v);
        return *this;
    }
    friend ostream& operator<<(ostream&, const Velocity&);
    friend istream& operator>>(istream&, Velocity&);
};

Velocity operator+(const Velocity& v1, const Velocity& v2) {
    return Velocity((v1.v + v2.v)/(1+v1.v*v2.v));
}

ostream& operator<<(ostream& str, const Velocity& v) {
    return str << v.v;
}

istream& operator>>(istream& str, Velocity& v) {
    return str >> v.v;
}

int main() {
    Velocity v1, v2;
    cin >> v1 >> v2;
    Velocity v;
    v = v1 + v2;
    cout << "beta = " << v << "\ngamma = " << v.gamma() << endl;
    
    return 0;
}
