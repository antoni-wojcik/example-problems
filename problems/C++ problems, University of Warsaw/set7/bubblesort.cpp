//
//  bubblesort.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 19/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include "bubblesort.hpp"
#include <vector>
using namespace std;

template <typename T>
void bubblesort(vector<T>& t) {
    int n = t.size() - 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i; j++) {
            if(t[j] > t[j+1]) swap(t[j], t[j+1]);
        }
    }
}
