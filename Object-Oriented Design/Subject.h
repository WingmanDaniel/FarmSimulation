#pragma once
#include <iostream>
#include <vector>
#include "Observer.h"

using namespace std;

class Subject {
    // 1. "independent" functionality
    vector < class Observer* > views; // 3. Coupled only to "interface"
    int value;
public:
    void attach(Observer* obs) {
        views.push_back(obs);
    }
    void setVal(int val) {
        value = val;
        notify();
    }
    int getVal() {
        return value;
    }
    void notify() {
        // 5. Publisher broadcasts
        for (int i = 0; i < views.size(); i++)
            views[i]->update();
    }
};
