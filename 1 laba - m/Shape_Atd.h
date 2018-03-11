#ifndef __shape_atd__
#define __shape_atd__

#include "Box_Atd.h"
#include "Sphere_Atd.h"

namespace simple_shapes 
{
	// ���������, ���������� ��� ��������� ������
	struct shape 
	{
		// �������� ������ ��� ������ �� �����
		enum key {BOX, SPHERE};
		key k; // ����
		// ������������ ������������
		union 
		{ // ���������� ���������
			box r;
			Sphere t;
		};
	};
} 
#endif
