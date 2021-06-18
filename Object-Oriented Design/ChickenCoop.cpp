#include "ChickenCoop.h"
#include <thread>

void ChickenCoop::startProduce()
{
    cout << "run eggsProduce" << endl;
    setEggsFlag(false);
    unsigned int milliseconds = 1000;
    Sleep(milliseconds * 3);
    setEggsFlag(true);
    startProduce();
}

void ChickenCoop::startSimulation()
{
    std::thread produce(startProduce);
}