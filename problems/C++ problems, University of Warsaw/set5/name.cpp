//
//  name.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 16/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Name {
    string name, surname;
public:
    Name() : name(""), surname("") {}
    Name(string& name, string& surname) : name(name), surname(surname) {}
    string initials() const {
        string temp;
        temp.push_back(name[0]);
        temp.push_back(surname[0]);
        return temp;
    }
    bool operator<(const Name n) const {
        if(!surname.compare(n.surname)) {
            if(surname.size() > n.surname.size()) {
                for(string::size_type i = 0; i < n.surname.size(); i++) {
                    if(surname[i] < n.surname[i]) return true;
                    else if(surname[i] > n.surname[i]) return false;
                }
                return false;
            } else {
                for(string::size_type i = 0; i < surname.size(); i++) {
                    if(surname[i] < n.surname[i]) return true;
                    else if(surname[i] > n.surname[i]) return false;
                }
                return true;
            }
        } else {
            if(name.size() > n.name.size()) {
                for(string::size_type i = 0; i < n.name.size(); i++) {
                    if(name[i] < n.name[i]) return true;
                    else if(name[i] > n.name[i]) return false;
                }
                return false;
            } else {
                for(string::size_type i = 0; i < name.size(); i++) {
                    if(name[i] < n.name[i]) return true;
                    else if(name[i] > n.name[i]) return false;
                }
                return true; //return true if both surname and name are the same
            }
        }
    }
    
    friend ostream& operator<<(ostream&, const Name&);
    friend istream& operator>>(istream&, Name&);
};

ostream& operator<<(ostream& str, const Name& n) {
    return str << n.name << " " << n.surname << " " << n.initials();
}
istream& operator>>(istream& str, Name& n) {
    return str >> n.name >> n.surname;
}

int main() {
    Name n1, n2;
    cin >> n1 >> n2;
    if(n1 < n2) cout << n1 << endl;
    else cout << n2 << endl;
    
    return 0;
}
