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
	ofst << "\n Ответ на загадку: " << zagad.otvet << endl;
=======
	ofst << " Ответ на загадку: " << zagad.otvet << endl;
>>>>>>> master
=======
	ofst << " Ответ на загадку: " << zagad.otvet << endl;
>>>>>>> 2-1-4
}