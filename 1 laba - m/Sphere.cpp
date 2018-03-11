#include <fstream>

#include "Sphere_atd.h"

using namespace std;

namespace simple_shapes 
{
	// ¬вод параметра шара из потока
	void In(Sphere &t, ifstream &ifst) 
	{
		ifst >> t.rad;
	}
	void Out(Sphere &t, ofstream &ofst)
	{
		ofst << "It is Sphere: r = " 
			<< t.rad << endl;
	}
}

