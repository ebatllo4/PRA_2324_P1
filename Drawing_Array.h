#ifndef DRAWING_H
#define DRAWING_H

#include "Shape.h"
#include "ListArray.h"

class Drawing{
        private:
                List<Shape*>* figuras;
        public:
                Drawing();
                ~Drawing();
                void add_front(Shape* shape);
                void add_back(Shape* shape);
                void print_all();
                double get_area_all_circles();
                void move_squares(double incX, double incY);
};

#endif
