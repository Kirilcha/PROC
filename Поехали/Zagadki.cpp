#include "Zagadki.h"
#include <fstream>
using namespace std;

void readZagad(Zagadki &zagad, ifstream &ifst)
{
	ifst.getline(zagad.otvet, 100, '\n');
}

void OutZagad(Zagadki &zagad, ofstream &ofst)
{
<<<<<<< HEAD
	ofst << "\n ����� �� �������: " << zagad.otvet << endl;
=======
	ofst << " ����� �� �������: " << zagad.otvet << endl;
>>>>>>> master
}