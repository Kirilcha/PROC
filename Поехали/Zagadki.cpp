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
<<<<<<< HEAD
	ofst << "\n ����� �� �������: " << zagad.otvet << endl;
=======
	ofst << " ����� �� �������: " << zagad.otvet << endl;
>>>>>>> master
=======
	ofst << " ����� �� �������: " << zagad.otvet << endl;
>>>>>>> 2-1-4
}