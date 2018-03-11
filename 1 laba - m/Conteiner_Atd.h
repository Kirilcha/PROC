#ifndef __conteiner__
#define __conteiner__

namespace simple_shapes 
{
// —сылка на описание геометрической фигуры. 
struct shape;

// ѕростейший контейнер на основе одномерного массива
  struct container
  {
    //const int max_len=100; //максимальна€ длина
	enum {max_len = 100};
    int len; // текуща€ длина
    shape *cont[max_len];
  };
}
#endif