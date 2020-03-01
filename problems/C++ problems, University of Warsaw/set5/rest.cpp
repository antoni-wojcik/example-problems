//
//  rest.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 16/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <iostream>
using namespace std;

class Rest {
private:
    int r;
public:
    Rest() : r(0) {}
    Rest(int i) {
        r = i%17;
    }
    Rest& operator++() {
        r = (++r)%17;
        return *this;
    }
    Rest operator+(const Rest& p) const {
        return Rest(r + p.r);
    }
    Rest operator+(const int i) const {
        return Rest(r + i);
    }
    Rest operator*(const Rest& p) const {
        return Rest(r * p.r);
    }
    Rest operator*(const int i) const {
        return Rest(r * i);
    }
    Rest& operator+=(const Rest& p) {
        r = (r+p.r)%17;
        return *this;
    }
    Rest& operator+=(const int i) {
        r = (r+i)%17;
        return *this;
    }
    
    friend ostream& operator<<(ostream&, const Rest&);
    friend istream& operator>>(istream&, Rest&);
};

ostream& operator<<(ostream& str, const Rest& r) {
    return str << r.r;
}

istream& operator>>(istream& str, Rest& r) {
    return str >> r.r;
}


int main() {
    int temp;
    cin >> temp;
    Rest r1(temp);
    cin >> temp;
    Rest r2(temp);
    
    cout <<  "Suma modulo 17: " << (r1+r2) << "\nIloczyn modulo 17: " << (r1*r2) << endl;
    
    return 0;
}
