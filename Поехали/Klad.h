#ifndef _Klad_
#define _Klad_

#include "Aforizm.h"
#include "Posl_Pogov.h"
#include <string>


struct Kladez
{
	enum key { AFORIZM = 1, POSL_P };
	key key;
	std::string fraza;
	union
	{
		Aforizm afor;
		Poslovica_P poslov;
	};
};
#endif