//
//  rat.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 16/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Rat {
    int p, q;
    void primise() {
        int sign = 1;
        if(p < 0) {
            sign = -1;
            p = -p;
        } else if(p == 0) {
            q = 1;
            return;
        }
        if(p == q) {
            p = 1;
            q = 1;
        }
        if(p > q) {
            for(int i = 2; i <= q; i++) {
                if(p%i == 0 && q%i == 0) {
                    p /= i;
                    q /= i;
                    --i;
                }
            }
        } else {
            for(int i = 2; i <= p; i++) {
                if(p%i == 0 && q%i == 0) {
                    p /= i;
                    q /= i;
                    --i;
                }
            }
        }
        p *= sign;
    }
public:
    Rat() : p(0), q(1) {}
    Rat(int p) : p(p), q(1) {}
    Rat(int p, int q) {
        if(q < 0) {
            this->p = -p;
            this->q = -q;
        } else {
            this->p = p;
            this->q = q;
        }
        primise();
    }
    int numerator() {
        return p;
    }
    int denominator() {
        return q;
    }
    operator double() const {
        return (double)p/(double)q;
    }
    Rat operator-() const {
        return Rat(-p, q);
    }
    bool operator<(Rat& r) const {
        return ((double)p/(double)q) < ((double)r.p/(double)r.q);
    }
    Rat& operator++() {
        ++p;
        return *this;
    }
    Rat operator+(const Rat& r) const {
        return Rat(p*r.q + r.p*q, q*r.q);
    }
    Rat operator*(const Rat& r) const {
        return Rat(p*r.p, q*r.q);
    }
    Rat& operator+=(const Rat& r) {
        p += r.p;
        q += r.q;
        primise();
        return *this;
    }
    Rat& operator*=(const Rat& r) {
        p *= r.p;
        q *= r.q;
        primise();
        return *this;
    }
    
    friend ostream& operator<<(ostream&, const Rat&);
    friend istream& operator>>(istream&, Rat&);
};

ostream& operator<<(ostream& str, const Rat& r) {
    return str << r.p << "/" << r.q;
}
istream& operator>>(istream& str, Rat& r) {
    string s;
    str >> s;
    replace(s.begin(), s.end(), '/', ' ');
    istringstream sstr(s);
    sstr >> r.p >> r.q;
    sstr.clear();
    if(r.q < 0) {
        r.p = -r.p;
        r.q = -r.q;
    }
    r.primise();
    return str;
}

int main() {
    Rat r1, r2;
    cin >> r1 >> r2;
    cout << (double)r1 << " " << (double)r2 << "\n";
    cout << -r1 << " " << -r2 << "\n";
    if(r1 < r2) cout << r1 << " " << r2 << "\n";
    else cout << r2 << " " << r1 << "\n";
    cout << (r1+r2) << " " << (r1*r2) << endl;
    
    return 0;
}
