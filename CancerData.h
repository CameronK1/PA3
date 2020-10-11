//
// Created by Cameron on 10/9/2020.
//

#ifndef INC_223PA3_CANCERDATA_H
#define INC_223PA3_CANCERDATA_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Info
{
    string name;
    float risk;
};

class CancerData
{
private:
    string country;
    float rankNumber;
    float rate;

public:

    // Explicit constructor
    explicit CancerData(string country, float rate);

    // Destructor
    ~CancerData();

    // Displaying both
    void displayBoth();

    // Displaying men
    void displayMen();

   // Displaying women
   void displayWomen();

   CancerData();

};


#endif //INC_223PA3_CANCERDATA_H
