#include "PatientFileLoader.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Patient.h"
#include "Vitals.h"

PatientFileLoader::PatientFileLoader(const std::string& file) :
    _file(file)
{
}

std::vector<Patient*> PatientFileLoader::loadPatientFile()
{
    std::vector<Patient*> patients;

    std::ifstream inFile(_file);
    if (inFile.is_open()) 
    {
        std::string uid;
        std::string birthday;
        std::string name;
        std::string diagnoses;
        std::string vitals;
        // TODO: load your file here
        while (inFile.peek() != -1)
        {
            std::getline(inFile, uid, '/');
            std::getline(inFile, birthday, '/');
            std::getline(inFile, name, '/');
            std::getline(inFile, diagnoses, '/');
            std::getline(inFile, vitals);


            std::cout << "uid " << uid << std::endl;
            std::cout << "birthday " << birthday << std::endl;
            std::cout << "name " << name << std::endl;
            std::cout << "diagnoses " << diagnoses << std::endl;
            std::cout << "vitals " << vitals << std::endl;
        }
    }

    return patients;
}
