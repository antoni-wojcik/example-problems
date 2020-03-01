//
//  insertionsort.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 19/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include "insertionsort.hpp"
#include <vector>

template <typename T>
void insertionsort(vector<T>& t) {
    for(int i = 1; i < t.size(); i++) {
        for(int j = i; j > 0; j--) {
            if(t[j] < t[j-1]) swap(t[j], t[j-1]);
            else break;
        }
    }
}
