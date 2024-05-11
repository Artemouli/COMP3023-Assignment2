
#include "AlertCalc.h"
#include "Patient.h"
#include "Vitals.h"
#include <iostream>

AlertLevel level;

void NoCapSyndrome::calculateAlert(Patient& patient)
{
	if (patient.vitals().back()->SPO2() < 94 && patient.vitals().back()->SPO2() >= 92) { patient.setAlertLevel(AlertLevel::Yellow); }
	else if (patient.vitals().back()->SPO2() < 92 && patient.vitals().back()->SPO2() >= 90) { patient.setAlertLevel(AlertLevel::Orange); }
	else if (patient.vitals().back()->SPO2() < 90) { patient.setAlertLevel(AlertLevel::Red); }
	else { patient.setAlertLevel(AlertLevel::Green); }
}

void TiccToccBrainDamage::calculateAlert(Patient& patient)
{
	std::cout << "no ticc tocc test " << std::endl;
}