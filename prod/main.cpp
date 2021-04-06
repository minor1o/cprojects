#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;
ofstream fout("res.txt");
const double pi = 3.14159265;
class Figure {
public:
	virtual double area() = 0;
	virtual double perimeter() = 0;
    virtual void draw()=0;
};
class Rectangle : public Figure {
private:
	int w, h;
public:
	Rectangle() {}
	void read()
	{
		cin >> w >> h;
        this->w=w; this->h=h;
	}
	virtual double area()
	{
		return w*h;
	}
    virtual double perimeter()
    {
        return 2*(w+h);
    }
    virtual void draw()
    {
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                fout << "#";
            }
            fout << endl;
        }
            fout.close();
    }
};

class Circle : public Figure {
private:
	int r;
public:
	Circle() {}
	void read()
	{
		cin >> r;
        this->r={r}; 
	}
	virtual double area()
	{
		return pi * r*r;
	}
    virtual double perimeter()
    {
        return 2*pi*r;
    }
    virtual void draw()
    {
        for(int i=0; i<(2*r+1); i++)
        {
            for(int j=0; j<(2*r+1); j++)
            {
                if( (pow((i-r),2)+pow((j-r),2)) <=pow(r,2)){
                    fout << "#";
                }
                else { 
                    fout << "."; 
                }
            }
            fout << endl;
        }
        fout.close();
    }
};


double array_area(vector<Figure*> array)
{
    double area;
    for(int i=0; i<array.size();i++)
    {
        area+=array[i]->area();
    }
    return area;
}
double array_perimeter(vector<Figure*> array)
{
    double perimeter;
    for(int i=0; i<array.size(); i++)
    {
        perimeter+=array[i]->perimeter();
    }
    return perimeter;
}

int main() {
    
    Figure* f;
    string type;
    cin >> type;
    if(type=="Rectangle"){
        Rectangle*r = new Rectangle;
        r->read();
        f=r;
    }
    else if(type=="Circle"){
        Circle*c = new Circle;
        c->read();
        f=c;
    }
    f->draw();
    return 0;
}