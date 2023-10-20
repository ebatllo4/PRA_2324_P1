#include "Rectangle.h"


bool Rectangle::check(Point2D* v){
	double costat1 = Point2D::distance(v[0], v[1]);
	double costat2 = Point2D::distance(v[1], v[2]);
	double costat3 = Point2D::distance(v[2], v[3]);
	double costat4 = Point2D::distance(v[3], v[0]);
	double diagonal1 = Point2D::distance(v[0], v[2]);
    	double diagonal2 = Point2D::distance(v[1], v[3]);
	return costat1 == costat3 && costat2 == costat4 && diagonal1 == diagonal2;
}
        
Rectangle::Rectangle(){
	color = "red";
	vs = new Point2D[4];
	vs[0] = Point2D(-1, 0.5);
	vs[1] = Point2D(1, 0.5);
	vs[2] = Point2D(1, -0.5);
	vs[3] = Point2D(-1, -0.5);
}


Rectangle::Rectangle(std::string color, Point2D* vertices){
	this->color = color;
	if(!check(vertices)){
		throw std::invalid_argument("No es un rectangulo!");
	}else{
		vs = vertices;
	}
}


Rectangle::Rectangle(const Rectangle &r){
	color = r.color;
	vs = new Point2D[N_VERTICES];
	for(int i = 0; i < N_VERTICES; i++){
		vs[i] = r.vs[i];
	}
}

		
Rectangle::~Rectangle(){
	delete[] vs;	
}

		
Point2D Rectangle::get_vertex(int ind) const{
	if(ind < 0 || ind > 4){
		throw std::out_of_range("No existe el vértice introducido");
	}else{
		return vs[ind];
	}
}

		
Point2D Rectangle::operator[](int ind) const{
	if(ind < 0 || ind > 4){
                throw std::out_of_range("No existe el vértice introducido");        }else{
                return vs[ind];
	}
}

		
void Rectangle::set_vertices(Point2D* vertices){
	 if(!check(vertices)){
                throw std::invalid_argument("No es un rectangulo!");
        }else{
		vs = vertices;
	}
}

		
Rectangle& Rectangle::operator=(const Rectangle &r){
	delete[] vs;
	vs = new Point2D[N_VERTICES];
	for(int i=0; i < N_VERTICES; i++){
		vs[i] = r[i];
	}
	return *this;
}

		
std::ostream& operator<<(std::ostream &out, const Rectangle &r){
	out<< "El rectangulo es de color " << r.color << "\n Coordenadas de sus vertices:\n Vertice 1: " << r.vs[0] << "\n Vertice 2: " << r.vs[1] << "\n Vertice 3: " << r.vs[2] << "\nVertice 4: " << r.vs[3] << "\n";
	return out;
}

		
double Rectangle::area() const{
	return Point2D::distance(vs[1], vs[0]) * Point2D::distance(vs[3], vs[0]);
}

		
double Rectangle::perimeter() const{
	return (Point2D::distance(vs[1], vs[0]) * 2) + (Point2D::distance(vs[3], vs[0]) * 2);
}

		
void Rectangle::translate(double incX, double incY){
	for(int i = 0; i < 4; i++){
		vs[i].x += incX;
		vs[i].y += incY;
	}
}

		
void Rectangle::print(){
	std::cout<<"Propiedades del rectangulo:\n";
	std::cout<<"Color: "<< color << "\n";
	std::cout<<"Coordenadas de los vertices:\n";
	for(int i = 0; i < N_VERTICES; i++){
		std::cout<< "Vertice " << i << ": (" << vs[i].x << ", " << vs[i].y <<")\n";
	}
}



