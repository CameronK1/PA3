//
// Created by Cameron on 10/9/2020.
//

#include "CancerData.h"

void CancerData::displayBoth()
{
    ifstream infile;

    infile.open("bothcancerdata2018.csv");

    // Checking if successfully opened
    if (!infile.is_open())
        cout << "File failed to open" << endl;
    else
    {
        // File line
        string fLine;

        string name;
        float risk;

        // Getting each line in the file
        while (getline(infile, fLine))
        {
            int index = 0;

            for (char c : fLine)
            {
                // Checking for commas and splitting
                if (c == ',')
                {
                    break;
                }

                index++;
            }

            // Getting the name of the country
            for (int i = 0; i < index; i++)
            {
                name += fLine[i];
            }

            // Getting the risk for each country
            for (int i = index + 1; i < fLine.length(); i++)
            {
                risk += fLine[i];
            }


            // Saving info
            Info info = {name, risk};
        }
        cout << "Both: " << name << " " << " " << risk << endl;
    }
    // Closing infile
    infile.close();
}

void CancerData::displayMen()
{
    ifstream infile;

    infile.open("mencancerdata2018.csv");

    // Checking if successfully opened
    if (!infile.is_open())
        cout << "File failed to open" << endl;
    else
    {
        // File line
        string fLine;

        string name;
        float risk;

        // Getting each line in the file
        while (getline(infile, fLine))
        {
            int index = 0;

            for (char c : fLine)
            {
                // Checking for commas and splitting
                if (c == ',')
                {
                    break;
                }

                index++;
            }

            // Getting the name of the country
            for (int i = 0; i < index; i++)
            {
                name += fLine[i];
            }

            // Getting the risk for each country
            for (int i = index + 1; i < fLine.length(); i++)
            {
                risk += fLine[i];
            }


            // Saving info
            Info info = {name, risk};
        }
        cout << "Men: " << name << " " << " " << risk << endl;
    }
    // Closing infile
    infile.close();
}

void CancerData::displayWomen()
{
    ifstream infile;

    infile.open("womencancerdata2018.csv");

    // Checking if successfully opened
    if (!infile.is_open())
        cout << "File failed to open" << endl;
    else
    {
        // File line
        string fLine;

        string name;
        float risk = 0;

        // Getting each line in the file
        while (getline(infile, fLine))
        {
            int index = 0;

            for (char c : fLine)
            {
                // Checking for commas and splitting
                if (c == ',')
                {
                    break;
                }

                index++;
            }

            // Getting the name of the country
            for (int i = 0; i < index; i++)
            {
                name += fLine[i];
            }

            // Getting the risk for each country
            for (int i = index + 1; i < fLine.length(); i++)
            {
                risk += fLine[i];
            }


            // Saving info
            Info info = {name, risk};
        }
        cout << "Women: " << name << " " << " " << risk << endl;
    }
    // Closing infile
    infile.close();
}

CancerData::CancerData(string country, float rate)
{
    Info info;
    country = info.name;
    rate = info.risk;
}