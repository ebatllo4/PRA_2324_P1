#include <iostream>
#include "Rectangle.h"

class Square : public Rectangle {
	public:
		Square();
		Square(std::string color, Point2D* vertices);
		friend std::ostream& operator<<(std::ostream &out, const Square &square);
		virtual void set_vertices(Point2D* vertices) override;
		virtual void print() override;

	private:
		static bool check(Point2D* vertices);
};


