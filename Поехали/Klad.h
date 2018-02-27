#ifndef _Klad_
#define _Klad_

#include "Aforizm.h"
#include "Zagadki.h"
#include "Posl_Pogov.h"
#include <string>


struct Kladez
{
<<<<<<< HEAD
	enum key { AFORIZM, POSL_P, ZAGADKI };
	key key;
	int ocenka;
=======
	enum key { AFORIZM = 1, POSL_P, ZAGADKI };
	key key;
	int kol;
>>>>>>> 2-1-4
	std::string fraza;
	union
	{
		Aforizm afor;
		Poslovica_P poslov;
		Zagadki zagad;
	};
};
#endif