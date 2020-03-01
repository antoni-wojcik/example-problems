//
//  tabula.cpp
//  UWTut
//
//  Created by Antoni Wójcik on 19/07/2019.
//  Copyright © 2019 Antoni Wójcik. All rights reserved.
//

#include <iostream>
#include <sstream>

namespace tab {
    class TabulaPelna : public std::exception {
    public:
        const char* what() const throw() {
            return "ERROR: Tablica pelna!";
        }
    };

    class TabulaVacua : public std::exception {
    public:
        const char* what() const throw() {
            return "ERROR: Tablica pusta!";
        }
    };

    template <typename T>
    class Tabula {
        int max_size;
        int size;
        int reserved_size;
        T* tab;
        
        void resize() {
            T* new_tab = new T[size];
            for(int i = 0; i < size; i++) new_tab[i] = tab[i];
            delete [] tab;
            tab = new_tab;
            reserved_size = size;
        }
        
    public:
        Tabula(int max_size = 100) : max_size(max_size), size(0), reserved_size(0) {}
        int MaxLength() const {
            return max_size;
        }
        int Length() const {
            return size;
        }
        bool IsEmpty() const {
            return size == 0;
        }
        bool IsFull() const {
            return size == max_size;
        }
        void Add(T item) {
            if(size < max_size) {
                if(reserved_size == size) {
                    resize();
                    tab[size] = item;
                    size++;
                    reserved_size = size;
                } else {
                    tab[size] = item;
                    size++;
                }
            } else throw TabulaPelna();
        }
        void DeleteLast() {
            if(size > 0) size--;
            else throw TabulaVacua();
        }
        void Clear() {
            size = 0;
            resize();
        }
        
        T& operator[](int i) const {
            return tab[i];
        }
        
        ~Tabula() {
            if(reserved_size > 0) delete [] tab;
        }
        
        template <typename U>
        friend std::ostream& operator<<(std::ostream& str, const Tabula<U>& tab);
    };

    template <typename T>
    std::ostream& operator<<(std::ostream& str, const Tabula<T>& tab) {
        for(int i = 0; i < tab.size; i++) str << tab[i] << " ";
        return str;
    }
}

using namespace std;
using namespace tab;

int main() {
    int k, m, n;
    cin >> k >> m >> n;
    Tabula<int> tab(k);
    
    try {
        string line;
        getline(cin, line);
        istringstream str(line);
        int temp;
        while(str >> temp) tab.Add(temp);
        str.clear();
    
        tab[m] = n;
        cout << tab;
        cout << endl;
        tab.Clear();
    } catch(TabulaPelna e) {
        cerr << e.what() << endl;
    } catch(TabulaVacua e) {
        cerr << e.what() << endl;
    }
    
    return 0;
}
