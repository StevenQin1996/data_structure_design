#include <iostream>// prevent value semantics means we need to prevent copy, equal,  put it in private in base class. 
#include <cmath> 

enum Color { BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, INVALID };

class Shape
{
	private:
		Color hue;//use hue to define Enum color
		void operator =(Shape&);//stop using = operator to copy the class Shape
		Shape(Shape& s); // Shape constructor
	public:
		Shape(Color newcolor):hue(newcolor){};//everything in the primeter needs to be in here.
		virtual ~Shape(){};//deconstructor
		
		Color color() const { return hue; }//Color setter
		void color(Color c) { hue = c; }//Color getter
		
		virtual double area() const= 0;// then all the function will be able to share this function
		virtual double perimeter() const= 0;//you can have arguement in this 
		virtual void move(double dx, double dy) = 0;
		virtual void render(std::ostream& os) const= 0;// if you call this, will go and get ostream and see what's in there
		std:: string showcolor() const;//this change the array of color from index to actual COLOR
		
		virtual bool inside(double, double)const = 0;
		virtual double thickness()const = 0;
		static Color colorAtPoint(Shape**,int, double, double);//determ what's the color of the shape that point is inside of
};

class Box: public Shape
{
	private: 
		double box_left;
		double box_top;
		double box_right;
		double box_bottom;
	
	public:
		
		Box(Color c, double l, double t, double r, double b) : Shape(c), box_left(l),box_top(t), box_right(r), box_bottom(b){}//set input data into this class Box

		void left(double number){box_left = number;}//get left 
		double left()const{return box_left;}//set for box_left
		//same for top, right, bottom

		void top(double number){box_top = number;}
		double top()const{return box_top;}

		void right(double number){box_right = number;}
		double right()const{return box_right;}

		void bottom(double number){box_bottom = number;}
		double bottom()const{return box_bottom;}

		double area() const;//return area
		double perimeter()const;//return cost
		void move(double x, double y);//shift left and right  for x distance, and coordinates top and bottom for y distance
		void render(std::ostream& os)const;// output os

		bool inside(double x, double y) const;//determ whether the point is inside the Shape

		double thickness() const; //Thickness is the area of the shape divided by the perimeter of the shape

		
};

class Circle: public Shape
{
	friend class RoundBox;
	private:
		double Circle_centerx;
		double Circle_centery;
		double Circle_radius;
	public: 
		
		Circle(Color c, double x, double y, double r) : Shape(c), Circle_centerx(x),Circle_centery(y),Circle_radius(r){}//put input data into this class Circle

		void centerX(double number){Circle_centerx = number;}//get x coordinate for center
		double centerX()const{return Circle_centerx;}//set x coordinator for center;

		void centerY(double number){Circle_centery = number;}//get y coordinate for center
		double centerY()const{return Circle_centery;}//set y coordinator for center;

		void radius(double number){Circle_radius = number;}//set radius coordinator for Circle;
		double radius()const{return Circle_radius;}//set radius for Circle;

		double area()const;// return Circle_area.
		double perimeter()const;//return Circle_perimeter
		void move(double x, double y);//shift the center for x for distance x, y for distance y
		void render(std::ostream& os)const;//cout os

		bool inside(double x, double y) const;//determ whether the point is inside the Shape

		double thickness() const; //Thickness is the area of the shape divided by the perimeter of the shape
};

class Triangle: public Shape
{
	friend class Polygon;
	private:
		double T_X1;//x coordinator for the first vertex (same for the rest)
		double T_Y1;//y coordinator for the first vertex (same for the rest)
		double T_X2;
		double T_Y2;
		double T_X3;
		double T_Y3;
	public:

		Triangle(Color c, double x1,double y1,double x2,double y2, double x3,double y3): Shape(c), T_X1(x1),T_Y1(y1),T_X2(x2),T_Y2(y2),T_X3(x3),T_Y3(y3){}
		
		void cornerX1(int number){T_X1 = number;}//get triangle's vertex1-x coordinate
		double cornerX1()const{return T_X1;}//set triangle's corner-1-x coordinate
		
		void cornerY1(int number){T_Y1 = number;}//get triangle's vertex1-y coordinate
		double cornerY1()const{return T_Y1;}//set triangle's vertex1-y coordinate

		void cornerX2(int number){T_X2 = number;}
		double cornerX2()const{return T_X2;}

		void cornerY2(int number){T_Y2 = number;}
		double cornerY2()const{return T_Y2;}

		void cornerX3(int number){T_X3 = number;}
		double cornerX3()const{return T_X3;}
		void cornerY3(int number){T_Y3 = number;}
		double cornerY3()const{return T_Y3;}

		double area()const;// return Triangle_area;
		double perimeter()const;//return Triangle_perimeter
		void move(double x, double y);//move all the vertex x coordinator by distance x, y coordinator for distance y;
		void render(std::ostream& os)const;//out put os

		bool inside(double x, double y) const;//determ whether the point is inside the Shape

		double thickness() const; //Thickness is the area of the shape divided by the perimeter of the shape
};

class Polygon : public Shape
{
	private:
		int Polygon_size;//how many vertex
		double *Polygon_X;//points to the array for all X coordinators
		double *Polygon_Y;//points to the array for all X coordinators
	public:

		Polygon(Color c, double* pts, int size);//Polygon constructor
		~Polygon();//polygon deconstrustor

		int points() const {return Polygon_size;}//set how many vertices

		void vertexX(int index, double number){Polygon_X[index] = number;}//get the coordinatesX
		double vertexX(int index)const{return Polygon_X[index];}//set the new coordinatesX

		void vertexY(int index, double number){Polygon_Y[index] = number;}//getter the new coordinatesY
		double vertexY(int index)const{return Polygon_Y[index];}//set the new coordinatesY

		double area() const;//return Polygon_area
		double perimeter() const;//return Polygon_perimeter
		void move(double, double);//shift all vertex's x coordinator by distance x, and Y coordinators by distance y
		void render(std::ostream& os) const;// output os
		bool inside(double, double) const;//determ whether the point is inside the Shape

		double thickness() const; //Thickness is the area of the shape divided by the perimeter of the shape
};

class Line : public Shape
{
	private:
		double startX;//x coordinator for the start vertex (same for the rest)
		double startY;//x coordinator for the end vertex (same for the rest)
		double endX;// y for the start vertex
		double endY;//y for the end vertex

	public:
		Line(Color c, double x1, double y1,double x2, double y2): Shape(c), startX(x1),startY(y1),endX(x2),endY(y2){}

		void end1X(double number){startX = number;}//get triangle's vertex1-x coordinate
		double end1X()const{return startX;}//set triangle's corner-1-x coordinate
		
		void end1Y(double number){startY = number;}//get triangle's vertex1-y coordinate
		double end1Y()const{return startY;}//set triangle's vertex1-y coordinate

		void end2X(double number){endX = number;}
		double end2X()const{return endX;}

		void end2Y(double number){endY = number;}
		double end2Y()const{return endY;}

		double area() const{return 0;}
		double perimeter() const;//return lINE_perimeter
		void move(double, double);//shift ALL x coordinator by distance x, and Y coordinators by distance y
		void render(std::ostream& os) const;// output os
		
		bool inside(double, double) const;//check if it is on the line
		double thickness() const{return 0;} //0;

};

class RoundBox: public Shape
{
	private: 
		double RoundBox_left;
		double RoundBox_top;
		double RoundBox_right;
		double RoundBox_bottom;
		double RoundBox_radius;
	public:
		
		RoundBox(Color c, double l, double t, double r, double b,  double rad) : Shape(c), RoundBox_left(l),RoundBox_top(t),RoundBox_right(r),RoundBox_bottom(b),RoundBox_radius(rad){}//set input data into this class Box

		
		void left(double number){RoundBox_left = number;}//get left 
		double left()const{return RoundBox_left;}//set for box_left
		//same for top, right, bottom
		void top(double number){RoundBox_top = number;}
		double top()const{return RoundBox_top;}
		void right(double number){RoundBox_right = number;}
		double right()const{return RoundBox_right;}
		void bottom(double number){RoundBox_bottom = number;}
		double bottom()const{return RoundBox_bottom;}
		void radius(double number){ RoundBox_radius = number;}
		double radius()const{return RoundBox_radius;}

		double area() const;//return area
		double perimeter()const;//return cost
		void move(double x, double y);//shift left and right  for x distance, and coordinates top and bottom for y distance
		void render(std::ostream& os)const;// output os

		bool inside(double x, double y) const;//determ whether the point is inside the Shape

		double thickness() const; //Thickness is the area of the shape divided by the perimeter of the shape

};