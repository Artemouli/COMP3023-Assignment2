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
        std::vector<int> vitals;
        // TODO: load your file here
        while (inFile.peek() != -1)
        {
            std::getline(inFile, uid, '/');

            // converts bday
            std::getline(inFile, birthday, '/');
            std::tm t{ };
            std::istringstream ss(birthday);
            ss >> std::get_time(&t, "%d-%m-%Y");

            // last and first name
            std::getline(inFile, lname, ',');
            std::getline(inFile, fname, '/');

            Patient* newP = new Patient(fname, lname, t);


            // gets the line of diagnoses
            std::string diagnosisLine;
            std::getline(inFile, diagnosisLine, '/');

            // converts diagnosis into a stream to stream it into different values for the diagnoses vector
            std::istringstream diagnosisStream(diagnosisLine);
            std::string diagnosisLS;
            while (std::getline(diagnosisStream, diagnosisLS, ','))
            {
                newP->addDiagnosis(diagnosisLS);
            }

            // gets the line of vitals
            std::string vitalLine;
            std::getline(inFile, vitalLine);
            
            // converts vitals into a stream to stream it into different values for the vitals vector
            std::istringstream vitalsStream(vitalLine);
            std::string vitalLS;
            while (std::getline(vitalsStream, vitalLS, ';'))
            {
                // individual vitals
                std::istringstream indivVitals(vitalLS);
                std::string vital;
                while (std::getline(indivVitals, vital, ','))
                {
                    int intVital = stoi(vital);
                    vitals.push_back(intVital);
                }
                Vitals* inputVitals =  new Vitals(vitals.at(0), vitals.at(1), vitals.at(2), vitals.at(3));
                vitals.clear();
                newP->addVitals(inputVitals);
            } 

            std::cout << newP->humanReadableID() << std::endl;
            std::cout << newP->age() << std::endl;

            for (int i = 0; i < newP->diagnoses().size(); i++)
            {
                std::cout << newP->diagnoses().at(i) << std::endl;
            }

            for (int i = 0; i < newP->vitals().size(); i++)
            {
                std::cout << "HR  " << newP->vitals().at(i)->HR() << std::endl;
                std::cout << "SP02  " << newP->vitals().at(i)->SPO2() << std::endl;
                std::cout << "BT  " << newP->vitals().at(i)->BT() << std::endl;
                std::cout << "BA  " << newP->vitals().at(i)->BA() << std::endl;
            }
        }
    }

    return patients;
}
