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
        std::string lname;
        std::string fname;
        std::vector<std::string> diagnoses;
        std::vector<std::string> vitals;
        // TODO: load your file here
        while (inFile.peek() != -1)
        {
            std::getline(inFile, uid, '/');

            //converts bday
            std::getline(inFile, birthday, '/');
            std::tm t{ };
            std::istringstream ss(birthday);
            ss >> std::get_time(&t, "%d-%m-%Y");

            //last and first name
            std::getline(inFile, lname, ',');
            std::getline(inFile, fname, '/');
            //std::getline(inFile, diagnoses, '/');

            Patient* newP = new Patient(fname, lname, t);

            std::string diagnosisLine;
            std::getline(inFile, diagnosisLine, '/');


            //converts diagnosis into a stream to stream it into different values for the diagnoses vector
            std::istringstream diagnosisStream(diagnosisLine);
            std::string diagnosisLS;
            while (std::getline(diagnosisStream, diagnosisLS, ','))
            {
                diagnoses.push_back(diagnosisLS);
            }


            std::cout << "uid " << uid << std::endl;
            std::cout << "birthday " << birthday << std::endl;
            std::cout << "name " << lname << std::endl;
            std::cout << "name " << fname << std::endl;
            for (int i = 0; i < diagnoses.size(); i++)
            {
                std::cout << "diagnosis " << diagnoses.at(i) << std::endl;
            }
        }
    }

    return patients;
}
