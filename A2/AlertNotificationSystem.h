#ifndef ALERT_NOTIFICATION_SYSTEM
#define ALERT_NOTIFICATION_SYSTEM

#include <iostream>
#include <memory>

#include "GPNotificationSystemFacade.h"
#include "HospitalAlertSystemFacade.h"

class AlertNotificationSystem {
public:
	AlertNotificationSystem() 
	{
		gpNotification = std::make_unique<GPNotificationSystemFacade>();
		hospitalNotification = std::make_unique<HospitalAlertSystemFacade>();
	}
	void sendNotification(Patient* patient)
	{
		gpNotification->sendGPNotificationForPatient(patient);
		hospitalNotification->sendAlertForPatient(patient);
	}
private:
	std::unique_ptr<GPNotificationSystemFacade> gpNotification;
	std::unique_ptr<HospitalAlertSystemFacade> hospitalNotification;
};

#endif