#include "../misc/safeInclusion.cpp"

#ifndef CELLDECISION_H
#define CELLDECISION_H

#include "../headers/Decision.h"

class CellDecision : public Decision
{
	public:
		std::string getUIString();
		std::string getType();
		
	protected:
};

#endif
