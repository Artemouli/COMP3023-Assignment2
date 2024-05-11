
#include "AlertCalc.h"
#include "Patient.h"
#include <iostream>

void NoCapSyndrome::calculateAlert(Patient& patient)
{
	std::cout << "no cap test" << std::endl;
}

void TiccToccBrainDamage::calculateAlert(Patient& patient)
{
	std::cout << "no ticc tocc test " << std::endl;
}