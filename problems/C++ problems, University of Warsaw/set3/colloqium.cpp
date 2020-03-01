//
//  colloqium.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 16/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Person {
    string name;
    vector<double> results;
};

int main() {
    vector<double> max_val;
    vector<Person> people;
    
    string file_name;
    //cin >> file_name;
    file_name = "results.txt";
    ifstream file(file_name);
    string line;
    
    if(file.is_open()) {
        getline(file, line);
        istringstream str(line);
        double temp;
        while(str >> temp)
            max_val.push_back(temp);
        str.clear();
        while(getline(file, line)) {
            str.str(line);
            Person p;
            str >> p.name;
            while(str >> temp)
                p.results.push_back(temp);
            people.push_back(p);
            str.clear();
        }
    }
    
    for(int i = 0; i < people.size(); i++) {
        cout << people[i].name << " ";
        double sum = 0;
        for(int j = 0; j < people[i].results.size(); j++) {
            sum += people[i].results[j];
        }
        cout << sum << "\n";
    }
    
    int peps = people.size();
    
    for(int i = 0; i < max_val.size(); i++) {
        cout << "Zadanie " << (i+1) << ".: ";
        double sum = 0;
        for(int j = 0; j < peps; j++) {
            sum += people[j].results[i];
        }
        cout << (sum/(double)peps) << "\n";
    }
    
    return 0;
}
