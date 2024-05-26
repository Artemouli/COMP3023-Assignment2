
#include "AlertCalc.h"
#include "Vitals.h"
#include <iostream>


AlertLevel AmogusSus::calculateAlert(Patient& patient)
{
	if (patient.vitals().back()->HR() > 220) { return AlertLevel::Red; }
	else if (patient.vitals().back()->HR() > 210) { return AlertLevel::Orange; }
	else if (patient.vitals().back()->HR() > 200) {	return AlertLevel::Yellow; }
	else  { return AlertLevel::Green; }
}

AlertLevel ERush::calculateAlert(Patient& patient)
{
	if (patient.vitals().back()->BT() > 38 && patient.vitals().back()->BA() > 110) { return AlertLevel::Red; }
	else if (patient.vitals().back()->BT() > 38 && patient.vitals().back()->BA() > 100) { return AlertLevel::Yellow; }
	else { return AlertLevel::Green; }
}

AlertLevel NoCapSyndrome::calculateAlert(Patient& patient)
{
	if (patient.vitals().back()->SPO2() < 90) { return AlertLevel::Red; }
	else if (patient.vitals().back()->SPO2() < 92) { return AlertLevel::Orange; }
	else if (patient.vitals().back()->SPO2() < 94) { return AlertLevel::Yellow; }
	else { return AlertLevel::Green; }
	std::cout << "wow " << patient.vitals().back()->BA() << std::endl;
}

AlertLevel TiccToccBrainDamage::calculateAlert(Patient& patient)
{
	if (patient.age() < 35 && patient.vitals().back()->BA() < 10) { return AlertLevel::Red; }
	else if(patient.age() >= 35 && patient.vitals().back()->BA() < 20) { return AlertLevel::Red; }
	else { return AlertLevel::Green; }
	std::cout << "incredible " << patient.vitals().back()->BT() << std::endl;
}