#include "Square.h"

bool Square::check(Point2D* v){
	double c1 = Point2D::distance(v[0], v[1]);
	double c2 = Point2D::distance(v[1], v[2]);
	double c3 = Point2D::distance(v[2], v[3]);
	double c4 = Point2D::distance(v[3], v[0]);
	return c1 == c2 && c1 == c3 && c1 == c4;
}


Square::Square(){
	color = "red";
	vs = new Point2D[4];
	vs[0] = Point2D(-1,1);
	vs[1] = Point2D(1,1);
	vs[2] = Point2D(1,-1);
	vs[3] = Point2D(-1,-1);
}


Square::Square(std::string color, Point2D* vertices){
	this->color = color;
	if(!check(vertices)){
		throw std::invalid_argument("No es un cuadrado!");
	}else{
		vs = vertices;
	}
}


void Square::set_vertices(Point2D* vertices){
	if(!check(vertices)){
		throw std::invalid_argument("No es un cuadrado!");
	}else{
		vs = vertices;
	}
}


std::ostream& operator<<(std::ostream &out, const Square &s){
	out<< "El rectangulo es de color " << s.color << "\n Coordenadas de sus vertices:\n Vertice 1: " << s.vs[0] << "\n Vertice 2: " << s.vs[1] << "\n Vertice 3: " << s.vs[2] << "\nVertice 4: " << s.vs[3] << "\n";
        return out;
}


void Square::print(){
        std::cout<<"Propiedades del rectangulo:\n";
        std::cout<<"Color: "<< color << "\n";
        std::cout<<"Coordenadas de los vertices:\n";
        for(int i = 0; i < N_VERTICES; i++){
                std::cout<< "Vertice " << i << ": (" << vs[i].x << ", " << vs[i].y <<")\n";
        }
}
