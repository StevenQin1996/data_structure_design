#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include "Shapes.h"
using namespace std;


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
    else 
        return "WHITE";
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
   // cout<<"side1: "<<side1<<endl;
    double side2 = abs(sqrt((T_X2-T_X3)*(T_X2-T_X3)+(T_Y2-T_Y3)*(T_Y2-T_Y3)));
   // cout<<"side2: "<<side2<<endl;
    double side3 = abs(sqrt((T_X3-T_X1)*(T_X3-T_X1)+(T_Y3-T_Y1)*(T_Y3-T_Y1)));
   // cout<<"side3: "<<side3<<endl;
    double sum = side1+side2+side3;
   // cout<<"Triangle perimeter: "<<sum<<endl;
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
   // cout<<"Polygon area: "<<abs(sum/2)<<endl;
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
   // cout<<"Polygon perimeter: "<<abs(answer)<<endl;
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

/*int main()
{
    double pts[] = {1,1,7,2,3,5,6,8,4,3};
    Shape * list[100];
    int count = 0;
    list[count++] = new Box(BLUE,0,1,1,0);
    list[count++] = new Box(CYAN,2,9,4,3);
    list[count++] = new Circle(WHITE,5,5,3);
    list[count++] = new Triangle(BLACK,1,1,5,1,3,3);
    list[count++] = new Polygon(GREEN,pts,5);
    
    double distance = 0;
    double area = 0;
    stringstream ss;

    for (int i=0; i<count; i++) {
        distance += list[i]->perimeter();
        area += list[i]->area();
        list[i]->render(ss);
        ss << "\n";
    }

    for (int i=0; i<count; i++) {
        list[i]->move(10,10);
        list[i]->render(ss);
        ss << "\n";
    }

    cout << "distance: " << distance << " area: " << area << "\n";
    cout << "drawing: " << ss.str();
    for (int i=0; i<count; i++)
        delete list[i];
}*/