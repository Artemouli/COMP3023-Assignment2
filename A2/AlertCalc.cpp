
#include "AlertCalc.h"
#include "Patient.h"
#include "Vitals.h"
#include <iostream>

AlertLevel level;

void AmogusSus::calculateAlert(Patient& patient)
{
	if (patient.vitals().back()->HR() > 220) { patient.setAlertLevel(AlertLevel::Red); }
	else if (patient.vitals().back()->HR() > 210) { patient.setAlertLevel(AlertLevel::Orange); }
	else if (patient.vitals().back()->HR() > 200) {	patient.setAlertLevel(AlertLevel::Yellow); }
	else  { patient.setAlertLevel(AlertLevel::Green); }
}

void ERush::calculateAlert(Patient& patient)
{
	if (patient.vitals().back()->BT() > 38 && patient.vitals().back()->BA() > 110) { patient.setAlertLevel(AlertLevel::Red); }
	else if (patient.vitals().back()->BT() > 38 && patient.vitals().back()->BA() > 100) { patient.setAlertLevel(AlertLevel::Yellow); }
	else { patient.setAlertLevel(AlertLevel::Green); }
}

void NoCapSyndrome::calculateAlert(Patient& patient)
{
	if (patient.vitals().back()->SPO2() < 90) { patient.setAlertLevel(AlertLevel::Red); }
	else if (patient.vitals().back()->SPO2() < 92) { patient.setAlertLevel(AlertLevel::Orange); }
	else if (patient.vitals().back()->SPO2() < 94) { patient.setAlertLevel(AlertLevel::Yellow); }
	else { patient.setAlertLevel(AlertLevel::Green); }
}

void TiccToccBrainDamage::calculateAlert(Patient& patient)
{
	if (patient.age() < 35 && patient.vitals().back()->BA() < 10) { patient.setAlertLevel(AlertLevel::Red); }
	else if(patient.age() >= 35 && patient.vitals().back()->BA() < 20) { patient.setAlertLevel(AlertLevel::Red); }
	else { patient.setAlertLevel(AlertLevel::Green); }
}