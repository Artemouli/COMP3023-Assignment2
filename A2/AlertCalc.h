#ifndef AlERT_CALC
#define ALERT_CALC

#include "AlertCalcStrategy.h"
#include "Patient.h"

class AmogusSus : public AlertCalcStrategy
{
public:
	AlertLevel calculateAlert(Patient& patient) override;
};


class ERush : public AlertCalcStrategy
{
public:
	AlertLevel calculateAlert(Patient& patient) override;
};

class NoCapSyndrome : public AlertCalcStrategy
{
public:
	AlertLevel calculateAlert(Patient& patient) override;
};

class TiccToccBrainDamage : public AlertCalcStrategy
{
public:
	AlertLevel calculateAlert(Patient& patient) override;
};


#endif