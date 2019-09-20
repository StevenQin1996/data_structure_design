
#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include "Shapes.h"
using namespace std;
//Shape *s;

//string showcolor[] = {"BLACK", "RED","GREEN", "YELLOW", "BLUE", "MAGENTA", "CYAN", "WHITE"}//changethis change the array of color from index in enum Color to actual COLOR 
string Shape::showcolor()const//changethis change the array of color from index in enum Color to actual COLOR 
{
    if(hue == 0)
        return "BLACK";
    else if(hue == 1)
        return "RED";
    else if(hue == 2)
        return "GREEN";
    else if(hue == 3)
        return "YELLOW";
    else if(hue == 4)
        return "BLUE";
    else if(hue == 5)
        return "MAGENTA";
    else if (hue ==6)
        return "CYAN";
    else if (hue ==7 )
        return "WHITE";
    else 
        return "INVALID";
}

Color Shape::colorAtPoint(Shape **list, int numberofShapes,double dx, double dy)//determ what's the color of the shape that point is inside of
{
   for (int i =0; i<numberofShapes; i++)//go through the list of Shape
    {
        if (list[i]->inside(dx, dy))// find the first shape contains that point
        {
             return list[i]->color() ;//cout the color
        }
    }
    return list[numberofShapes]->color();//this is a shape;
        
}

double Box::area() const//caculator the area for the shape
{
    double top_down = abs(box_top-box_bottom);// get the height
    double right_left = abs(box_right-box_left);//get the width
    double sum = top_down*right_left;// area = height * height
    //cout<<"Box_area: "<<sum<<endl;
    return sum;
}

double Box::perimeter() const//caculator the perimeter for the shape
{
    double top_down = abs(box_top-box_bottom);// get height
    double right_left = abs(box_right-box_left);//get width
    double answer = (top_down+right_left)*2;// perimeter = 2 * (height + width)
    //cout<<"Box_perimeter: "<<answer<<endl;
    return answer;
}

void Box::move(double dx, double dy)//shift left and right  for x distance, and coordinates top and bottom for y distance
{
    box_right += dx;
    box_left += dx;
    box_bottom += dy;
    box_top += dy; 
}

void Box::render(ostream& os) const//output os
{
    os<<"Box("<<showcolor()<<","<<box_left<<","<<box_top<<","<<box_right<<","<<box_bottom<<")";
}

bool Box::inside(double dx, double dy)const//check wheter the point is inside the shape//check
{
    return ((box_left <= dx) && (dx <= box_right) && (box_bottom <= dy) && (dy<= box_top));//check if the point is in between the lines
     
}   

double Box::thickness()const//Thickness is the area of the shape divided by the perimeter of the shape
{
    return area()/perimeter();
}


double Circle::area() const//return area of circle
{
   //cout<<"Circle area: "<<M_PI*Circle_radius*Circle_radius<<endl;
   return M_PI*Circle_radius*Circle_radius; 
}

double Circle::perimeter() const//return perimeter of circle
{
    //cout<<"Circle_perimeter: "<<2*M_PI*Circle_radius<<endl;
    return 2*M_PI*Circle_radius;
}

void Circle::move(double x, double y)//shift the center for x for distance x, y for distance y
{
    Circle_centerx+=x;
    Circle_centery+=y;
}

void Circle::render(ostream& os)const//output os
{
    os<<"Circle("<<showcolor()<<","<<Circle_centerx<<","<<Circle_centery<<","<<Circle_radius<<")";
}

bool Circle::inside(double dx, double dy) const//check if the point is inside the Shape.//check
{
    return ((abs(sqrt(pow((dx-Circle_centerx),2)+pow((dy-Circle_centery),2)))) <= Circle_radius);//if the distance from the point to the center is less than the radius, the point is inside
}

double Circle::thickness()const//Thickness is the area of the shape divided by the perimeter of the shape
{
    return area()/perimeter();
}

double Triangle::area()const// return area of trangle 
{
    //cout<<T_X1<<","<<T_X2<<","<<T_X3<<","<<T_Y1<<","<<T_Y2<<","<<T_Y3<<endl;
    double answer = abs(((T_X1*(T_Y2-T_Y3))+(T_X2*(T_Y3-T_Y1))+(T_X3*(T_Y1-T_Y2)))/2);
    //cout<<"Triangle area: "<<answer<<endl;
    return answer;
}

double Triangle::perimeter()const// output the area of triangle by summing up the distance of all three sides
{
    double side1 = abs(sqrt((T_X1-T_X2)*(T_X1-T_X2)+(T_Y1-T_Y2)*(T_Y1-T_Y2)));//sqru(x^2 - y^2)
    //cout<<"side1: "<<side1<<endl;
    double side2 = abs(sqrt((T_X2-T_X3)*(T_X2-T_X3)+(T_Y2-T_Y3)*(T_Y2-T_Y3)));
    //cout<<"side2: "<<side2<<endl;
    double side3 = abs(sqrt((T_X3-T_X1)*(T_X3-T_X1)+(T_Y3-T_Y1)*(T_Y3-T_Y1)));
    //cout<<"side3: "<<side3<<endl;
    double sum = side1+side2+side3;
    //cout<<"Triangle perimeter: "<<sum<<endl;
    return sum;
}

void Triangle::move(double x, double y)// shift all the x coordinates by x, all the y coordinates by y
{
    T_X1 += x;
    T_Y1 += y;
    T_X2 += x;
    T_Y2 += y;
    T_X3 += x;
    T_Y3 += y;
}

void Triangle::render(ostream& os)const//output triangle
{
    os<<"Triangle("<<showcolor()<<","<<T_X1<<","<<T_Y1<<","<<T_X2<<","<<T_Y2<<","<<T_X3<<","<<T_Y3<<")";
}

bool Triangle::inside(double x, double y) const//determ whether the point is inside the Shape//check
{
    double answer = abs(((x*(T_Y2-T_Y3))+(T_X2*(T_Y3-y))+(T_X3*(y-T_Y2)))/2) + abs(((T_X1*(y-T_Y3))+(x*(T_Y3-T_Y1))+(T_X3*(T_Y1-y)))/2) + abs(((T_X1*(T_Y2-y))+(T_X2*(y-T_Y1))+(x*(T_Y1-T_Y2)))/2);//link the point with three vertex and can make three small triangle. sum up the area of these three triangle, if it equal to the area of the triangle, the point is in side.
    if (answer == /*Triangle::*/area() /*&& ((abs(((x*(T_Y2-T_Y3))+(T_X2*(T_Y3-y))+(T_X3*(y-T_Y2)))/2)!=0) && (abs(((T_X1*(y-T_Y3))+(x*(T_Y3-T_Y1))+(T_X3*(T_Y1-y)))/2)!= 0) && (abs(((T_X1*(T_Y2-y))+(T_X2*(y-T_Y1))+(x*(T_Y1-T_Y2)))/2)!=0))*/)
    {
         return true;
    }
    else return false;
}

double Triangle::thickness()const//Thickness is the area of the shape divided by the perimeter of the shape
{
    return area()/perimeter();
}

Polygon::Polygon(Color c, double* pts, int size):Shape(c)//constructor of Polygon
{
    Polygon_size = size;// assign how many vertexics this polygon contain
    int a=0;
    int b=0;
    Polygon_X = new double[size];//array contain all X coordinates
    Polygon_Y = new double[size];//array contain all Y coordinates

    for (int i =0; i< Polygon_size*2; i+=2)//put all X coordinators from pts[] into Polygon_X[]
    {
        Polygon_X[a] = pts[i];
        a++;
    }

    for (int i=1; i<Polygon_size*2; i+=2)////put all Y coordinators from pts[] into Polygon_Y[]
    {
        Polygon_Y[b] = pts[i];
        b++;
    }
}

Polygon::~Polygon()//deconstructor
{
    delete[] Polygon_X;
    delete[] Polygon_Y;
}

double Polygon::area() const//return the sum of the polygon
{
    double sum = 0;
    int j = Polygon_size-1;
    for (int i =0; i<Polygon_size; i++)
    {
       sum += (Polygon_X[j]+Polygon_X[i])*(Polygon_Y[j]-Polygon_Y[i]);
       j=i;
       //cout<<sum<<endl;
    }
    //cout<<"Polygon area: "<<abs(sum/2)<<endl;
    return abs(sum/2);
}
double Polygon::perimeter() const//return the perimeter of the Polygon
{
    double answer = 0;
    int j=Polygon_size-1;
    for(int i=0;i<Polygon_size;i++)
    {
        //cout<<answer<<endl;
        answer += sqrt( ((Polygon_X[i] - Polygon_X[j])*(Polygon_X[i] - Polygon_X[j])) + ((Polygon_Y[i] - Polygon_Y[j])*(Polygon_Y[i] - Polygon_Y[j])) );
        j=i;
    }
    //cout<<"Polygon perimeter: "<<abs(answer)<<endl;
    return abs(answer);
}
void Polygon::move(double x, double y)//shift all the X coordinators in the array by distance x, Y coordinators in the array by distance y 
{
    for (int i =0; i<Polygon_size ; i++)
    {
            Polygon_X[i] += x;
            Polygon_Y[i] += y;
    }   
}

void Polygon::render(ostream& os) const//outout os
{
    os<<"Polygon("<<showcolor()<<","<<Polygon_size<<",";
    for (int i =0; i<Polygon_size-1; i++)
        os<<Polygon_X[i]<<","<<Polygon_Y[i]<<",";
    os<<Polygon_X[Polygon_size-1]<<","<<Polygon_Y[Polygon_size-1]<<")";
}

bool Polygon::inside( double dx, double dy)const
{
  int i, j, c = 0;
  for (i = 0, j = Polygon_size-1; i < Polygon_size; j = i++) {
    if ( ((Polygon_Y[i]>dy) != (Polygon_Y[j]>dy)) &&//check if the point in the half-plane to the left of the extended edge
     (dx < (Polygon_X[j]-Polygon_X[i]) * (dy-Polygon_Y[i]) / (Polygon_Y[j]-Polygon_Y[i]) + Polygon_X[i]) )//check if the point's Y coordinate within the edge's Y-range
       c = !c;
  }
  return c;
}

double Polygon::thickness()const//Thickness is the area of the shape divided by the perimeter of the shape
{
    return area()/perimeter();
}

double Line::perimeter()const// similar to Triangle::perimeter, only need to find one side;
{
    double side1 = abs(sqrt(pow((startX-endX),2)+pow((startY-endY),2)));//sqru(x^2 - y^2)
    return side1;
}
void Line::move(double dx, double dy)//similar to Triangle::move
{
    startX += dx;
    endX += dx;
    startY += dy;
    endY += dy;
}

void Line::render(ostream& os)const
{
    os<<"Line("<<showcolor()<<","<<startX<<","<<startY<<","<<endX<<","<<endY<<")";
}

bool Line::inside(double dx, double dy) const//return true is the point is on the line
{
    double answer = abs(sqrt(pow((dx-endX),2)+pow((dy-endY),2))) + abs(sqrt(pow((dx-startX),2)+pow((dy-startY),2)));//sqru(x^2 - y^2)
    return (answer == perimeter());//the shortest distance between two point is the straight line connecting these two points
}
double RoundBox::area() const//return area
{
    double top_down = abs(RoundBox_top-RoundBox_bottom-2*RoundBox_radius);// get the height
    double right_left = abs(RoundBox_right-RoundBox_left-2*RoundBox_radius);//get the width
    double sum = top_down*right_left;// area = height * height
    //cout<<"Box_area: "<<sum<<endl;
    sum += RoundBox_radius*abs(top_down)*2 + RoundBox_radius*abs(right_left)*2;//area of the box plus the extra four box.
    sum += M_PI*pow(RoundBox_radius,2);//add the four round corner which is a circle. 
    return sum;
}
double RoundBox::perimeter()const//return premeiter
{
    double top_down = abs(RoundBox_top-RoundBox_bottom-2*RoundBox_radius);// get the height
    double right_left = abs(RoundBox_right-RoundBox_left-2*RoundBox_radius);//get the width
    double answer = (top_down+right_left)*2;// perimeter = 2 * (height + width)
    //cout<<"RoundBox_perimeter: "<<answer<<endl;
    answer += 2*M_PI*RoundBox_radius;//add the four round corner which is a circle. 
    return answer;
}
void RoundBox::move(double dx, double dy)//shift left and right  for x distance, and coordinates top and bottom for y distance
{
    RoundBox_right += dx;
    RoundBox_left += dx;
    RoundBox_bottom += dy;
    RoundBox_top += dy; 
}
void RoundBox::render(std::ostream& os)const// output os
{
    os<<"RoundBox("<<showcolor()<<","<<RoundBox_left<<","<<RoundBox_top<<","<<RoundBox_right<<","<<RoundBox_bottom<<","<<RoundBox_radius<<")";
}
bool RoundBox::inside(double dx, double dy) const//determ whether the point is inside the Shape
{
    //make circle with each bounds as center
    Circle C1(WHITE,RoundBox_left+RoundBox_radius,RoundBox_top-RoundBox_radius, RoundBox_radius);
    Circle C2(WHITE,RoundBox_right-RoundBox_radius,RoundBox_top-RoundBox_radius, RoundBox_radius);
    Circle C3(WHITE,RoundBox_left+RoundBox_radius,RoundBox_bottom+RoundBox_radius, RoundBox_radius);
    Circle C4(WHITE,RoundBox_right-RoundBox_radius,RoundBox_bottom+RoundBox_radius, RoundBox_radius);

    if ((RoundBox_left < dx) && (dx < RoundBox_right) && (RoundBox_bottom+RoundBox_radius <= dy) && (dy <= (RoundBox_top-RoundBox_radius)))
        return true;
    else if (((RoundBox_left+RoundBox_radius) <= dx) && (dx <= RoundBox_right-RoundBox_radius) && (RoundBox_bottom <= dy) && (dy<= RoundBox_top))
        return true;
    else if (C1.inside(dx,dy)||C2.inside(dx,dy)||C3.inside(dx,dy)||C4.inside(dx,dy))//all circles are in the roundbox
        return true;
    else 
        return false;
}

double RoundBox::thickness() const //Thickness is the area of the shape divided by the perimeter of the shape
{
    return area()/perimeter();
}

Group::Group(Color c, int n, Shape** l) : Shape(c)//constructor
{
    numberofShapes = n;
    list= l;
    for (int i=0; i<numberofShapes; i++)
    {
        list[i] ->color(c);//change each of the shape color to the group color
    }
    
}

Group::~Group()
{
    for(int i = 0; i < numberofShapes; i++) // deletes all allocated shape
        delete list[i];
}

void Group::shapes(int n, Shape** l)
{
    for (int i =0; i<numberofShapes; i++)
        delete list[i];//delete the old list
    
    numberofShapes = n;//asign new number of shapes to the list
    list = l;//point list to the new list
}

void Group::color(Color c)
{
    Shape::color(c);

    for(int i = 0; i < numberofShapes; i++) // sets the color of each shape in the Group
        list[i]->color(c);
}

double Group::area() const//sum up the area of each Shape in the group
{
    double answer=0;
    for (int count = 0; count< numberofShapes; count++)
    {
        answer += list[count]->area();
    }
    return answer;
}

double Group::perimeter() const//similar to area
{
    double answer=0;

    for (int count = 0; count< numberofShapes; count++)
    {
        answer += list[count]->perimeter();
    }
    return answer;
}

void Group::move(double dx, double dy)
{
    for (int count = 0; count< numberofShapes; count++)
    {
        list[count] -> move(dx,dy);//move all the shape with dx,dy 
    }   
}

bool Group::inside(double dx, double dy) const//
{
    for (int count =0; count< numberofShapes; count++)
    {
        if(list[count] -> inside(dx,dy))//put dx,dy into each shape contained in the list
            return true;
    }
    return false;
}

void Group::render(std::ostream& os)const// output os
{
    os << "Group(" << showcolor() << "," << numberofShapes;
    for (int i=0; i< numberofShapes; i++)
    {
        os<<",";
        list[i]->render(os);
    }
    os<<")";
}

/*int main()
{
        std::string name[]={"BLACK","RED","GREEN","YELLOW","BLUE","MAGENTA","CYAN","WHITE"};
    for (int i=0; i<8; i++) {
        Color j = (Color)((i+1)%8);
    Shape * s1[]={new Box(RED,2,5,9,3),new Circle(CYAN,2,2,2)};
    Group * g = new Group((Color)i,2,s1);
    std::stringstream ss;
    g->render(ss);
    cout << ss.str() << endl;
    g->color(j);
    ss.str("");
    g->render(ss);
    cout << ss.str() << endl; 
    Shape * s2[]={new Box(CYAN,1,2,2,1),g,new RoundBox(CYAN,2,2,2,2,2)};
    Group h((Color)i,3,s2);
    ss.str("");
    h.render(ss);
    cout << ss.str() << endl;
    //assert(ss.str() == "Group(" + name[i] + ",3,Box(" + name[i] + ",1,2,2,1),Group(" + name[i] + ",2,Box("+name[i]+",2,5,9,3),Circle("+name[i]+",2,2,2)),RoundBox("+name[i]+",2,2,2,2,2))");
    
    //cout<<"a: "<<ss.str()<<endl;
    h.color(j);
    ss.str("");
    h.render(ss);
    cout << ss.str() << endl;

     cout << endl << endl;
    }
}*/