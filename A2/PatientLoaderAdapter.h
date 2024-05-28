#ifndef PATIENT_LOADER_ADAPTER
#define PATIENT_LOADER_ADAPTER

#include "AbstractPatientDatabaseLoader.h"
// Adaptee
#include "PatientFileLoader.h"

class PatientLoaderAdapter : public AbstractPatientDatabaseLoader
{
public:
	virtual void initialiseConnection() override 
	{
		patientFileLoader = new PatientFileLoader("patients.txt");
		//initialise connection with patient file
	};
	virtual void loadPatients(std::vector<Patient*>& patientIn) override
	{
		patientFileLoader->loadPatientFile();
	};
	virtual void closeConnection() override
	{
		delete patientFileLoader;
		// close connection
	};
private:
	PatientFileLoader* patientFileLoader;
};

#endif