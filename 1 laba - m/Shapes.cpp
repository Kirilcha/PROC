#include <fstream>

#include "Shape_Atd.h"
#include "Conteiner_Atd.h"

using namespace std;

namespace simple_shapes 
{
	// ��������� ��������� ������� ������� 
	void In(box &r, ifstream &ist);
	void In(Sphere  &t, ifstream &ist);
	void Out(box &r, ofstream &ofst);
	void Out(Sphere  &t, ofstream &ofst);

	// ���� ���������� ���������� ������ �� �����
	shape* In(ifstream &ifst)
	{
		shape *sp;
		int k;
		ifst >> k;
		switch(k) {
		case 1:
			sp = new shape;
			sp->k = shape::key::BOX;
			In(sp->r, ifst);
			return sp;
		case 2:
			sp = new shape;
			sp->k = shape::key::SPHERE;
			In(sp->t, ifst);
			return sp;
		default:
			return 0;
		}
	}

	// ����� ���������� ������� ������ � �����
	void Out(shape &s, ofstream &ofst) 
	{
		switch(s.k) 
		{
		case shape::key::BOX:
			Out(s.r, ofst);
			break;
		case shape::key::SPHERE:
			Out(s.t, ofst);
			break;
		default:
			ofst << "Incorrect figure!" << endl;
		}
	}
} 


