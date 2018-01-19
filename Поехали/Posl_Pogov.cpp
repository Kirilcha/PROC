#include "Posl_Pogov.h"
#include <fstream>

using namespace std;

void readPosl(Poslovica_P &posl, ifstream &ifst)
{
	ifst.getline(posl.strana, 100, '\n');
}

void OutPosl(Poslovica_P &posl, ofstream &ofst)
{
	ofst << " Страна данной пословицы/поговорки: " << posl.strana << endl;
}