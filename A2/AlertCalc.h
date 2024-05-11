#ifndef AlERT_CALC
#define ALERT_CALC

#include "AlertCalcStrategy.h"
class Patient;


class NoCapSyndrome : public AlertCalcStrategy
{
public:
	void calculateAlert(Patient& patient) override;
};

class TiccToccBrainDamage : public AlertCalcStrategy
{
public:
	void calculateAlert(Patient& patient) override;
};

#endif