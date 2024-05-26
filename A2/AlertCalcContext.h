#ifndef ALERT_CALC_CONTEXT
#define ALERT_CALC_CONTEXT

#include <iostream>
#include <iomanip>
#include <sstream>

#include "AlertCalcStrategy.h"
#include "Patient.h"

class AlertCalcContext 
{
public:
	void setStrategy(AlertCalcStrategy* strategy)
	{
		// this->alertCalc = strategy;
		// add to vector
		this->alertCalc.push_back(strategy);
	}

	AlertLevel executeStrategy(Patient& patient)
	{		
		// for loop that goes through vector and calculates each alert
		for (int i = 0; i < alertCalc.size(); i++)
		{
			checkAlertLevel(alertCalc.at(i)->calculateAlert(patient));
		} 
		return currentAlertLevel;
		//alertCalc->calculateAlert(patient);
	}

	// checks the alert level, and then sets the patients alert level according to the order of priority (e.g. green < yellow, yellow < red, etc)
	// the enum is compared as an int
	// green = 0
	// yellow = 1
	// orange = 2
	// red = 3
	void checkAlertLevel(AlertLevel inputAlert)
	{
		// converts the inputAlert and currentAlertLevel to their underlying int values, then sets the currentAlertLevel if the inputAlert is higher
		if (static_cast<int>(inputAlert) > static_cast<int>(currentAlertLevel))
		{
			currentAlertLevel = inputAlert;
		}
	}

private:
	//AlertCalcStrategy* alertCalc;
	AlertLevel currentAlertLevel = AlertLevel::Green;
	std::vector<AlertCalcStrategy*> alertCalc;
};

#endif