#include "Drawing_Array.h"

Drawing::Drawing(){
        figuras = new ListArray<Shape*>();
}


Drawing::~Drawing(){
        delete figuras;
}


void Drawing::add_front(Shape* shape){
        figuras->prepend(shape);
}


void Drawing::add_back(Shape* shape){
        figuras->append(shape);
}


void Drawing::print_all(){
        for(int i = 0; i < figuras->size(); i++){
		Shape* figura = figuras->get(i);
		figura->print();
	}
}


double Drawing::get_area_all_circles(){
	double area = 0.0;
	for(int i = 0; i < figuras->size(); i++){
		Shape* figura = figuras->get(i);
		Circle* circle = dynamic_cast<Circle*>(figura);
		if(circle){
			area += circle->area();
		}
	}
	return area;
}


void Drawing::move_squares(double incX, double incY){
        for(int i = 0; i < figuras->size(); i++){
		Shape* figura = figuras->get(i);
		Square* square = dynamic_cast<Square*>(figura);
		if(square){
			square->translate(incX, incY);
		}
	}
}















