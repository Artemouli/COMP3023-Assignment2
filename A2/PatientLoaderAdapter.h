#ifndef PATIENT_LOADER_ADAPTER
#define PATIENT_LOADER_ADAPTER


#include <iostream>
#include <memory>

#include "AbstractPatientDatabaseLoader.h"
// Adaptee
#include "PatientFileLoader.h"


class PatientLoaderAdapter : public AbstractPatientDatabaseLoader
{
public:
	virtual void initialiseConnection() override 
	{
		//initialise connection with patient file
		patientFileLoader = std::make_unique<PatientFileLoader>("patients.txt");
	};
	virtual void loadPatients(std::vector<Patient*>& patientIn) override
	{
		std::vector<Patient*> patients = patientFileLoader->loadPatientFile();

		for (int i = 0; i < patients.size(); i++)
		{
			patientIn.push_back(patients.at(i));
		}

	};
	virtual void closeConnection() override
	{
		// close connection
	};
private:
	std::unique_ptr<PatientFileLoader> patientFileLoader;
};

#endif