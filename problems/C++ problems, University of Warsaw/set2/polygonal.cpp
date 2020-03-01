//
//  polygonal.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 15/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

struct Point {
    double x, y;
    
    double distance_to_next(Point& p) {
        return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));
    }
};

void read_data(vector<Point>* points, string file_name) {
    Point p;
    
    ifstream file(file_name);
    if(file.is_open()) {
        while(true) {
            file >> p.x;
            file >> p.y;
            if(file.eof()) break;
            points->push_back(p);
        }
    } else {
        cout << "ERROR: COULD NOT OPEN A FILE: " << file_name << endl;
        throw -1;
    }
    file.close();
}

int main() {
    vector<Point> points;
    try {
        read_data(&points, "polygonal_data.txt");
    } catch (int err_code){
        if (err_code==-1) return -1;
    }
    
    long p_size = points.size() - 1;
    if(p_size > 0) {
        double distance = 0;
        for(long i = 0; i < p_size; i++) {
            distance += points[i].distance_to_next(points[i+1]);
        }
        cout << distance << endl;
    }
    
    return 0;
    
}
