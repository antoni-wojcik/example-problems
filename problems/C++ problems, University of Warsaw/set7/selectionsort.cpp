//
//  selectionsort.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 19/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include "selectionsort.hpp"
#include <vector>
using namespace std;

template <typename T>
void selectionsort(vector<T>& t) {
    T min;
    int idx;
    for(int i = 0; i < t.size(); i++) {
        min = t[i];
        idx = i;
        for(int j = i+1; j < t.size(); j++) {
            if(t[j] < min){
                idx = j;
                min = t[j];
            }
        }
        swap(t[idx], t[i]);
    }
}
