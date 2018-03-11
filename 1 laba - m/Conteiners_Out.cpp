#include <fstream>

#include "Conteiner_Atd.h"
#include "Shape_Atd.h"

using namespace std;
namespace simple_shapes 
{
	void Out(shape &s, ofstream &ofst);

	// Вывод только прямоугольников
	void OutBox(container &c, ofstream &ofst) 
	{
		ofst << "Only box." << endl;
		for (int i = 0; i < c.len; i++) 
		{
			ofst << i << ": ";
			if (c.cont[i]->k == shape::BOX)
				Out(*(c.cont[i]), ofst);
			else
				ofst << endl;
		}
	}
}