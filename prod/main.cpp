#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const double pi = 3.14159265;
class Figure {
public:
	virtual double area() = 0;
	virtual double perimeter() = 0;
    virtual void draw()=0;
    virtual string show()=0;
};
class Rectangle : public Figure {
protected:
	int w, h;
public:
	Rectangle() {}
	void read()
	{
		cin >> w >> h;
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
                cout << "#";
            }
            cout << endl;
        }
    }
    virtual string show()
    {
        return "Rectangle";
    }
};
class HollowRectangle: public Rectangle{
public:
    HollowRectangle() {}

    virtual void draw()
    {
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                 if(i==0 || j==0 || i==h-1 || j==w-1)
                 {
                     cout << "#";
                 }
                else
                    cout << ".";
            }
                cout << endl;
        }
    }

};
class Circle : public Figure {
protected:
	int r;
public:
	Circle() {}
	void read()
	{
		cin >> r;
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
                    cout << "#";
                }
                else { 
                    cout << "."; 
                }
            }
            cout << endl;
        }
    }
    virtual string show()
    {
        return "Circle";
    }
};
class HollowCircle: public Circle{
public:
    HollowCircle() {}
    virtual void draw()
    {
        for (int i = 0; i <= 2*r; i++)
        {
        for (int j = 0; j <= 2*r; j++)
        {
            double ds = sqrt((i - r)*(i - r) + (j - r)*(j - r));
            if (ds==r)
            {
                cout << "#";
            }
            else
            {
                cout << ".";
            }
        }
            cout << endl;
        }
       
    }
};
class Triangle: public Figure {
protected: int h;
public:
    Triangle() {}
    void read()
    {
        cin >> h;
    }
    virtual void draw()
    {
        for(int i=1; i<=h;i++)
        {
            for(int j=h; j>i; j--)
            {
                cout << ".";
            } 
            for(int k=1; k<=2*i-1;k++)
            {
                cout << "#";
            }
                
            for(int j=2*h;j>h+i; j--)
            {
                cout << ".";
            }
            cout << endl;
        }
    }
    virtual double area(){
        cout << h*sqrt(pow(h,2)+pow((h-1/2),2));
    }
    virtual double perimeter()
    {
        cout << h+(h+1/2)+sqrt(pow(h,2)+pow((h-1/2),2));
    }
    virtual string show() {
        return "Triangle";
    }

};
class HollowTriangle: public Triangle{
public:
    HollowTriangle() {}
     virtual void draw()
     {

          for(int i=1; i<=h;i++)
          {
            for(int j=h; j>i; j--)
            {
                cout << ".";
            } 
            for(int k=1; k<=2*i-1;k++)
            {
                if(k==1 || k==i*2-1){
                cout << "#";
                }
                else if(i==h){
                    cout << "#";
                }
                else {
                    cout << ".";
                }
            }
            for(int j=2*h;j>h+i; j--){
                cout << ".";
            }
            cout << endl;
          }
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
void draw_array(vector<Figure*> array)
{
    for(int it=0; it<array.size(); it++)
    {
        array[it]->draw();
        cout << endl;
    }
}
int count_rectangles(vector<Figure*> array)
{
    int counter=0;
    for(int i=0;i<array.size();i++)
    {
        if(array[i]->show()=="Rectangle")
        {
            counter++;
        }
    }
    return counter;
}
int count_circles(vector<Figure*> array)
{
        int counter=0;
        for(int i=0;i<array.size();i++)
        {
            if(array[i]->show()=="Circle")
            {
            counter++;
            }
        }
        return counter;

}
int count_triangles(vector<Figure*> array)
{
    int counter=0;
    for(int i=0;i<array.size();i++)
    {
        if(array[i]->show()=="Triangle")
        {
            counter++;
        }
    }
    return counter;
}
int main() {
    
    int n;
    cin >> n;
    vector<Figure*> array(n);
    for(int i=0; i<array.size(); i++)
    {
        string type;
        cin >> type;
        if(type=="Rectangle"){
            Rectangle *r = new Rectangle;
            r->read();
            array[i]=r;
        }
        else if(type=="Circle")
        {
            Circle *c = new Circle;
            c->read();
            array[i]=c;
        }
        else if(type=="HollowRectangle")
        {
           HollowRectangle* hr = new HollowRectangle;
           hr->read();
           array[i]=hr;
        }
        else if(type=="HollowCircle")
        {
            HollowCircle* cr = new HollowCircle;
            cr->read();
            array[i]=cr;
        }
        else if(type=="Triangle")
        {
            Triangle *tr = new Triangle;
            tr->read();
            array[i]=tr;
        }
        else if(type=="HollowTriangle")
        {
            HollowTriangle *htr = new HollowTriangle;
            htr->read();
            array[i]=htr;
        }
    }
    draw_array(array);
    return 0;
}
