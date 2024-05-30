#include "Patient.h"

#include "Vitals.h"

#include "AlertCalcContext.h"
#include "AlertCalcStrategy.h"
#include "AlertCalc.h"
#include "AlertNotificationSystem.h"

#include <iostream>
#include <iomanip>
#include <sstream>


using namespace std;

const std::string Diagnosis::AMOGUS_SUS = "AmogusSus";
const std::string Diagnosis::E_RUSH = "ERush";
const std::string Diagnosis::NOCAP_SYNDROME = "NocapSyndrome";
const std::string Diagnosis::TICCTOCC_BRAIN_DAMAGE = "TicctoccBrainDamage";



Patient::Patient(const std::string& firstName, const std::string& lastName, std::tm birthday) :
    Person(firstName, lastName, birthday),
    _alertLevel(AlertLevel::Green)
{
}

int Patient::age() const
{	
    // an inaccurate age estimate but fine for assignment purposes
    return 2024 - (1900 + _birthday.tm_year);
}

std::string Patient::uid() const
{
    std::stringstream ss;
    ss << static_cast<char>(std::tolower(_lastName.at(0)))
       << static_cast<char>(std::tolower(_firstName.at(0)))
       << std::setfill('0') << std::setw(2) << (_birthday.tm_mon + 1) 
       << _birthday.tm_year;
    return ss.str();
}

std::string Patient::humanReadableID() const
{

    return "" + _lastName + ", " + _firstName + " (" + uid() + ")";
}

std::ostream& operator<<(std::ostream& os, const Patient& p)
{
    os << p.uid() << "/" << std::put_time(&p._birthday, "%d-%m-%Y") << "/" << p._lastName << "," << p._firstName << "/";
    
    auto diagnoses = p.diagnoses();
    for (auto itr = diagnoses.begin(); itr != diagnoses.end(); ++itr) {
        if (itr != diagnoses.begin()) os << ";";
        os << *itr;
    }

    os << "/";

    auto vitals = p.vitals();
    for (auto itr = vitals.begin(); itr != vitals.end(); ++itr) {
        if (itr != vitals.begin()) os << ";";
        os << **itr;
    }

    return os;
}

void Patient::addDiagnosis(const std::string& diagnosis)
{
    _ASSERT(diagnosis == Diagnosis::AMOGUS_SUS ||
        diagnosis == Diagnosis::E_RUSH ||
        diagnosis == Diagnosis::NOCAP_SYNDROME ||
        diagnosis == Diagnosis::TICCTOCC_BRAIN_DAMAGE);
    _diagnosis.push_back(diagnosis);
}

const std::string& Patient::primaryDiagnosis() const
{
    return _diagnosis.front();
}

const std::vector<std::string>& Patient::diagnoses() const
{
    return _diagnosis;
}

void Patient::addVitals(const Vitals* v, bool alertCheck)
{
    // std::string callingFunction
    // calling function is for documenting what the calling function is 
    // calling function is always the full name of the function (e.g. class name::function name
    // when called by PatientManagement, the string is: PatientManagementSystem::addVitalsRecord

    _vitals.push_back(v);
    
    // TODO: calculate alert levels
    
    AlertCalcContext context;
    AmogusSus amogusSus;
    ERush eRush;
    NoCapSyndrome noCap;
    TiccToccBrainDamage ticcTocc;

    // check to ensure that historical data isnt being loaded
    if (alertCheck == true)
    {
        /*if (primaryDiagnosis() == Diagnosis::NOCAP_SYNDROME) { context.setStrategy(&noCap); }
        else if (primaryDiagnosis() == Diagnosis::TICCTOCC_BRAIN_DAMAGE) { context.setStrategy(&ticcTocc); }
        else if (primaryDiagnosis() == Diagnosis::AMOGUS_SUS) { context.setStrategy(&amogusSus); }
        else if (primaryDiagnosis() == Diagnosis::E_RUSH) { context.setStrategy(&eRush); } */

        // goes through the diagnoses and adds them to the context
        for (int i = 0; i < diagnoses().size(); i++)
        {
            if (diagnoses().at(i) == Diagnosis::NOCAP_SYNDROME) { context.setStrategy(&noCap); }
            else if (diagnoses().at(i) == Diagnosis::TICCTOCC_BRAIN_DAMAGE) { context.setStrategy(&ticcTocc); }
            else if (diagnoses().at(i) == Diagnosis::AMOGUS_SUS) { context.setStrategy(&amogusSus); }
            else if (diagnoses().at(i) == Diagnosis::E_RUSH) { context.setStrategy(&eRush); }
        } 
        setAlertLevel(context.executeStrategy(*this));
    }
}

const std::vector<const Vitals*> Patient::vitals() const
{
    return _vitals;
}

void Patient::setAlertLevel(AlertLevel level)
{
    _alertLevel = level;
    AlertNotificationSystem alertNotification;

    if (_alertLevel > AlertLevel::Green) {
        cout << "Patient: " << humanReadableID() << " has an alert level: ";
        switch (_alertLevel) {
        case AlertLevel::Yellow:
            cout << "Yellow";
            break;
        case AlertLevel::Orange:
            cout << "Orange";
            break;
        case AlertLevel::Red:
            cout << "Red";
            break;
        }
        cout << endl;
        alertNotification.sendNotification(this);
    }
}
