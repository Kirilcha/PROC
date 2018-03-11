#ifndef __shape_atd__
#define __shape_atd__

#include "Box_Atd.h"
#include "Sphere_Atd.h"

namespace simple_shapes 
{
	// структура, обобщающая все имеющиеся фигуры
	struct shape 
	{
		// значения ключей для каждой из фигур
		enum key {BOX, SPHERE};
		key k; // ключ
		// используемые альтернативы
		union 
		{ // используем включение
			box r;
			Sphere t;
		};
	};
} 
#endif
