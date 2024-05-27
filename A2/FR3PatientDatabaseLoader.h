#ifndef FR3_PATIENT_DATABASE_LOADER
#define FR3_PATIENT_DATABASE_LOADER

#include "AbstractPatientDatabaseLoader.h"
#include <vector>

class patient;

class FR3PatientDatabaseLoader : public AbstractPatientDatabaseLoader
{
public:
    // initialise the database connection
    void initialiseConnection() override;

    // load patients from that database.
    // This method should allocated dynamic (i.e. new-ed) Patients into
    // the vector reference. The fucntion caller must take responsibilty for
    // cleaning up the memory.
    void loadPatients(std::vector<Patient*>& patientIn) override;

    void closeConnection() override;
};

#endif