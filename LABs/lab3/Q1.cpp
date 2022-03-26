#include <cstdlib>
#include <iostream>
#define PI 3.14
using namespace std;

class Shape
{
protected:
    float volume;

public:
    Shape() { volume = 0; }
    virtual void computeVolume() = 0;
    void printVolume()
    {
        cout << volume << endl;
    }
};
class Cuboid : public Shape
{
    // Add code here
public:
    Cuboid(double thelength,double thewidth,double theheight):Shape(),length(thelength)\
	,width(thewidth),height(theheight){
	};
	void computeVolume(){
		volume = length*width*height;
	};
	
private:
	double length;
	double width;
	double height;
};
class Pyramid : public Shape
{
    // Add code here
public:
	Pyramid(double thebase,double theheight):Shape(),base(thebase),height(theheight){
	};
	void computeVolume(){
		volume = base*height/3;
	};
private:
	double base;
	double height;
};
class Sphere : public Shape
{
    // Add code here
public:
    Sphere(double theradius):Shape(),radius(theradius){
	};
	void computeVolume(){
		volume =  4 * radius*radius*radius * 3.14 /3;
	};
private:
	double radius;
};

int main()
{
    float a, b, c;
    Shape *shape;

    cin >> a >> b >> c; // Enter the height and width of Rectangle
    Cuboid cub(a, b, c);

    cin >> a >> b; // Enter the bottom and height of Triangle
    Pyramid pyr(a, b);

    cin >> a; // Enter the radius of Circle
    Sphere sph(a);

    shape = &cub;
    shape->computeVolume();
    shape->printVolume();

    shape = &pyr;
    shape->computeVolume();
    shape->printVolume();

    shape = &sph;
    shape->computeVolume();
    shape->printVolume();

    return 0;
}
