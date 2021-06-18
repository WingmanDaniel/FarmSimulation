#pragma once
#include <iostream>
#include <vector>
#include "ChickenIncubator.h"
#include <windows.h>

class ChickenCoop
{
public:
    ChickenCoop(const char* name) {
        nameChickenCoop = name;
    }
    ~ChickenCoop() {
    }
    void createAChicken(ChickenType type, int amount)
    {
        for (int index = 0; index < amount; index++)
        {
            ChickenIncubator* pIncubatorC = new ChickenIncubator(type);
            Chicken* pChicken = pIncubatorC->getChicken();
            pChicken->printChicken();
            this->chickenVector.push_back(pChicken);
        }

    }
    void attach(class Observer* obs) {
        views.push_back(obs);
    }

    void setEggsFlag(bool flag) {
        eggsFlag = flag;
        notify();
    }

    bool getEggsFlag() {
        return eggsFlag;
    }

    void setHungerFlag(bool flag) {
        hungerFlag = flag;
        notify();
    }

    bool getHungerFlag() {
        return hungerFlag;
    }

    void startProduce()
    {
        unsigned int milliseconds = 1000;
        Sleep(milliseconds * 7);
        setEggsFlag(true);
        
        startProduce();
    }
    void startFeed()
    {
        unsigned int milliseconds = 1000;
        Sleep(milliseconds * 5);
        setHungerFlag(true);
        startFeed();
    }

    void notify();

    string getName()
    {
        return nameChickenCoop;
    }
private:
    string nameChickenCoop;
    vector<Chicken*> chickenVector;
    int food;
    int eggs;
    vector <class Observer*> views;
    bool eggsFlag;
    bool hungerFlag;

};

