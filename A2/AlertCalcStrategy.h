#ifndef ALERT_CALC_STRATEGY
#define ALERT_CALC_STRATEGY

#include "PatientAlertLevels.h"


class Patient;

class AlertCalcStrategy
{
public: 
	virtual AlertLevel calculateAlert(Patient& patient) = 0;
};

#endif 