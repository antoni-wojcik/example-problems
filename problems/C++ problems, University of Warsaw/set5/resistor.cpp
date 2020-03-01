//
//  resistor.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 16/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <iostream>
using namespace std;

class Resistor {
private:
    double res;
public:
    void set(double);
    
    double resistance();
    
    friend Resistor serial(Resistor&, Resistor&);
    friend Resistor parallel(Resistor&, Resistor&);
};

inline void Resistor::set(double r) {
    res = r;
}

inline double Resistor::resistance() {
    return res;
}

Resistor serial(Resistor& r1, Resistor& r2) {
    Resistor r;
    r.set(r1.resistance() + r2.resistance());
    return r;
}

Resistor parallel(Resistor& r1, Resistor& r2) {
    Resistor r;
    r.set(1.0 / (1.0 / r1.resistance() + 1.0 / r2.resistance()));
    return r;
}

int main() {
    Resistor r1, r2;
    double temp;
    cin >> temp;
    r1.set(temp);
    cin >> temp;
    r2.set(temp);
    cout << "Połączenie szeregowe: " << serial(r1, r2).resistance() << "\n";
    cout << "Połączenie równoległe: " << parallel(r1, r2).resistance() << endl;
    
    return 0;
}
