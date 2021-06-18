#pragma once

enum Gender {
    female, male, other
};

struct Poultry_Feature
{
    Gender gender;
    int age;
};

class Poultry
{
public:
    void setFeature(Poultry_Feature tempFeature)
    {
        feature.gender = tempFeature.gender;
        feature.age = tempFeature.age;
    }

    Gender getGender(int number) {
        switch (number)
        {
        case 0:
            return female;
            break;
        case 1:
            return male;
            break;
        default:
            return other;
            break;
        }
    }

    Poultry_Feature getFeature()
    {
        return feature;
    }
private:
    Poultry_Feature feature;
};