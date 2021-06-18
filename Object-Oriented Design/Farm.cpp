#include <ctype.h>
#include "ChickenCoop.h"
#include "Observer.h"
#include <thread>
#include "Guide.h"



ChickenCoop newChickenCoop = ChickenCoop("Chicken Coop No.7");

void simulationOne()
{
    newChickenCoop.startProduce();
}

void simulationTwo()
{
    newChickenCoop.startFeed();
}

int main()
{
    Guide guideSteps;
    guideSteps.guideOne();
    while (true)
    {
        
        int ID;
        cin >> ID;
        if (ID < 1 || ID > 4)
        {
            cout << "Sorry, this type is not avaliable so for, Bye-Bye";
            return 0;
        }
        ChickenType type = Chicken::getChickenType(ID);
        guideSteps.guideTwo();
        int amount;
        cin >> amount;
        newChickenCoop.createAChicken(type, amount);
        guideSteps.guideFour();
        char confirm;
        cin >> confirm;
        if (toupper(confirm) == 'N')
            break;
        guideSteps.guideFive();
    }
    guideSteps.guideSix();
    EggsObserver eggsObs(&newChickenCoop);
    HungerObserver HungerObs(&newChickenCoop);
    thread produce(simulationOne);
    thread feed(simulationTwo);
    produce.join();
    feed.join();
    while (true)
    {

    }
    return 0;
}
