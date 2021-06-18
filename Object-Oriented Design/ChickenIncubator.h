#pragma once
# include "Chicken.h"

// Client class
class ChickenIncubator {
public:

    // Chicken Coop doesn't explicitly create objects
    // but passes type to factory method "Create()"
    ChickenIncubator(ChickenType type)
    {
        pChicken = Chicken::Create(type);
        Poultry_Feature feature;
        feature.age = 1;
        feature.gender = pChicken->getGender(rand() % 2);
        pChicken->setFeature(feature);
    }
    ~ChickenIncubator() {
        if (pChicken) {
            delete[] pChicken;
            pChicken = NULL;
        }
    }
    Chicken* getChicken() {
        return pChicken;
    }

private:
    Chicken* pChicken;
};