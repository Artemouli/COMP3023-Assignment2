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
		this->alertCalc = strategy;
		//add to vector
		//this->alertCalc.push_back(strategy);;
	}

	void executeStrategy(Patient& patient)
	{
		/*for (int i = 0; i < alertCalc.size(); i++)
		{
			std::cout << i << " " << alertCalc.at(i) << std::endl;
		} */
		alertCalc->calculateAlert(patient);
		//for loop that goes through vector and calculates each alert
	}

private:
	AlertCalcStrategy* alertCalc;
	//std::vector<AlertCalcStrategy*> alertCalc;
};

#endif