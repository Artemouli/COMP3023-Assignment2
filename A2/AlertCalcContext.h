#ifndef ALERT_CALC_CONTEXT
#define ALERT_CALC_CONTEXT

#include "AlertCalcStrategy.h"
#include "Patient.h"

class AlertCalcContext 
{
public:
	void setStrategy(AlertCalcStrategy* strategy)
	{
		this->alertCalc = strategy;
	}

	void executeStrategy(Patient& patient)
	{
		alertCalc->calculateAlert(patient);
	}

private:
	AlertCalcStrategy* alertCalc;
};

#endif