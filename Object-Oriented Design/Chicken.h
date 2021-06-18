#pragma once
#include <iostream>
#include "Poultry.h"

using namespace std;

enum ChickenType {
    C_Plymouth_Rock, C_Orpington, C_Leghorn, C_Silkie
};


// Library classes
class Chicken : public Poultry {
public:
    virtual void printChicken() = 0;
    static Chicken* Create(ChickenType type);
    static ChickenType getChickenType(int id)
    {
        switch (id)
        {
        case 1:
            return C_Plymouth_Rock;
            break;
        case 2:
            return C_Orpington;
            break;
        case 3:
            return C_Leghorn;
            break;
        case 4:
            return C_Silkie;
            break;
        default:
            break;
        }
    }
protected:
    void printFeature()
    {
        Poultry_Feature feature = getFeature();
        cout << printGender(feature.gender) << " and " << feature.age << ((feature.age > 1) ? " days" : " day") << endl;
    }
    string printGender(Gender gender)
    {
        switch (gender)
        {
        case female:
            return "hen";
            break;
        case male:
            return "Rooster";
            break;
        case other:
            return "Unknown Gender";
            break;
        default:
            break;
        }
    }
};

class Plymouth_Rock : public Chicken {
public:
    void printChicken() {
        cout << "This is a plymouth rock, ";
        printFeature();
    }
};

class Orpington : public Chicken {
public:
    void printChicken() {
        cout << "This is an orpington, ";
        printFeature();
    }
};

class Leghorn : public Chicken {
public:
    void printChicken() {
        cout << "This is a leghorn, ";
        printFeature();
    }
};

class Silkie : public Chicken {
public:
    void printChicken() {
        cout << "This is a silkie, ";
        printFeature();
    }
};

// Factory method to create objects of different types.
// Change is required only in this function to create a new object type
Chicken* Chicken::Create(ChickenType type) {
    switch (type)
    {
    case C_Plymouth_Rock:
        return new Plymouth_Rock();
        break;
    case C_Orpington:
        return new Orpington();
        break;
    case C_Leghorn:
        return new Leghorn();
        break;
    case C_Silkie:
        return new Silkie();
        break;
    default:
        return NULL;
        break;
    }
    return NULL;
}