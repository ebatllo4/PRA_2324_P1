#include <cmath>
#include "Circle.h"


Circle::Circle(){
	color = "red";
	center = Point2D(0,0);
	radius = 1;	
}


Circle::Circle(std::string color, Point2D center, double radius){
	this->color = color;
	this->center = center;
	this->radius = radius;
}


Point2D Circle::get_center() const{
	return center;
} 


void Circle::set_center(Point2D p){
	center = p;
}


double Circle::get_radius() const{
	return radius;
}


void Circle::set_radius(double r){
	radius = r;
}


double Circle::area() const{
	double pi = 3.141592;
	return 2 * pi * pow(radius, 2);
}


double Circle::perimeter() const{
	double pi = 3.141592;
	return 2 * pi * radius;
}


void Circle::translate(double incX, double incY){
	center.x += incX;
	center.y += incY;	
}


std::ostream& operator<<(std::ostream &out, const Circle &c){
	out<< "Propiedades del circulo:\n Color:" << c.color << "\n Coordenadas del centro: x = " << c.center.x << ", y = " << c.center.y  << "\n. Radio: " << c.radius << std::endl;
	return out;
}


void Circle::print(){
    std::cout << "Propiedades del círculo:\n";
    std::cout << "Color: " << color << "\n";
    std::cout << "Coordenadas del centro: (" << center.x << ", " << center.y << ")\n";
    std::cout << "Radio: " << radius << "\n";
}
