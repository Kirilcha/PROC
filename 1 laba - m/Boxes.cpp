#include <fstream>

#include "Box_Atd.h"

using namespace std;

namespace simple_shapes 
{
  // Ввод параметров прямоугольника из файла
  void In(box &r, ifstream &ifst)
  {
    ifst >> r.x >> r.y >> r.z;
  }
  // Вывод параметров прямоугольника 
  void Out(box &r, ofstream &ofst) 
  {
    ofst << "It is Box: x = " << r.x 
	<< ", y = " << r.y <<", z = " << r.z << endl;
  }
} 


