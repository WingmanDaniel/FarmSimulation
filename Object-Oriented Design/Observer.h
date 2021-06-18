#pragma once
#include <iostream>
#include <vector>
#include "ChickenCoop.h"
using namespace std;

class Observer {

public:
    Observer(ChickenCoop* mod) {
        model = mod;
        model->attach(this);
    }
    virtual void update() = 0;
protected:
    ChickenCoop* getSubject() {
        return model;
    }
private:
    ChickenCoop* model;
};


void ChickenCoop::notify() {
    for (int i = 0; i < views.size(); i++)
        views[i]->update();
}

class EggsObserver : public Observer {
public:
    EggsObserver(ChickenCoop* mod) : Observer(mod) {}
    void update() {
        if (getSubject()->getEggsFlag())
        {
            cout << getSubject()->getName() << ": Time to collect eggs" << endl;
            getSubject()->setEggsFlag(false);
        }

    }
};

class HungerObserver : public Observer {
public:
    HungerObserver(ChickenCoop* mod) : Observer(mod) {}
    void update() {
        if (getSubject()->getHungerFlag())
        {
            cout << getSubject()->getName() << ": Time to feed chickens" << endl;
            getSubject()->setHungerFlag(false);
        }
    }
};