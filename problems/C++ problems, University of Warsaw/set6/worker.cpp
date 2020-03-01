//
//  worker.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 18/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Worker {
protected:
    string surname;
    int salary;
    virtual ostream& print(ostream& str) const {
        return str << surname << " earns " << salary << " PLN and works hard\n";
    }
public:
    Worker(string surname, int salary) : surname(surname), salary(salary) {}
    void increase(int val) {
        salary += val;
    }
    friend ostream& operator<<(ostream&, const Worker&);
};

ostream& operator<<(ostream& str, const Worker& w) {
    w.print(str);
    return str;
}

class Chief : public Worker {
    string car_brand;
    virtual ostream& print(ostream& str) const {
        return str << surname << " earns " << salary << " PLN and drives " << car_brand << "\n";
    }
public:
    Chief(string surename, int salary, string car_brand) : Worker(surename, salary), car_brand(car_brand) {}
};

int main() {
    Worker* worker = new Worker("Smith", 2000.);
    Worker* chief = new Chief("Brown", 20000., "Fiat 126p");
    cout << *worker << endl << *chief << endl;
    chief->increase(5000.);
    cout << *chief << endl;
    delete chief;
    delete worker;
    return 0;
}
