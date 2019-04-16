#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/*(class Point 
{
private:
	int x;
	int y;

public:
	Point(int x, int y):x(x),y(y){};
	Point(){};

	friend Point operator + (Point const &l, Point const &r);
	Point operator - (Point const &t)
	{
		return Point(x - t.x, y - t.y);
	};

	Point operator = (Point const &t)
	{
		x = t.x;
		y = t.y;
		return *this;
	};

	void print(){
		printf("x: %i, y: %i\n", x, y);
	}
};

Point operator +(Point const &l,Point const &r)
{
	return Point(l.x + r.x, l.y + r.y);
};
*/
class Poly
{
public:
	Poly(){
		c = -1;
		for(int i = 0;i<10;i++) k[i] = 0;
	};	

	void set(int a){
		c++;
		k[c] = a;
	};

	Poly operator + (Poly const &tmp)
	{
		Poly t;
		for(int i = 0;i<10;i++) {
			t.set(k[i] + tmp.k[i]);
		}
		return t;
	};
	//operator =
	Poly operator = (Poly const &t)
	{
		for(int i = 0;i<10;i++) {
			k[i] = t.k[i];
		}
		return *this;
	};

	int sum(int x){
		int r = 0;
		for(int i = 0;i<10;i++) {
			r += k[i] * pow((double) x,i);
		}
		return r;
	};
private:
	int k[10];
	int c;
};

class Point
{
public:
	int x;
	int y;

	void printP(){
		printf("x: %i, y:%i \n", x, y);
	};
};

class Line : public Point
{
public:
	int x2;
	int y2;

	void printL(){
		printf("x1: %i, y1:%i, x2: %i, y2:%i \n", this->x, this->y, Point::y, x2, y2);
	};
};

class Polygon : public Line
{
public:
	int x3;
	int y3;

	void printPl(){
		printf("x1: %i, y1:%i, x2: %i, y2:%i,  x3: %i, y3:%i \n", Point::x, y, x2, y2, x3, y3);
	};
};

class A 
{
public:
	int x;

	virtual void print()=0;
};

class APlus : public A
{
public:
	void print(){
		printf("%i\n", x+1);
	};
};

class AMinus : public A
{
public:
	void print(){
		printf("%i\n", x-1);
	};
};

class Shape
{
public:
	virtual double getArea()=0;
};

class Rect : public Shape
{
public:
	int size;

	double getArea(){
		return size * size;
	};
};

class Circle : public Shape
{
public:
	int radius;

	double getArea(){
		return 3.15 * pow((double) radius, 2);
	};
};


int main(){
	/*Point p1(1,2);
	Point p2(2,3);
	Point c;

	c = p1 + p2;
	c.print();
	c = c - p1;
	c.print();

	Poly poly;
	poly.set(1);
	poly.set(2);
	poly.set(3);
	poly.set(4);
	poly.set(5);
	poly.set(6);
	poly.set(7);
	poly.set(8);
	poly.set(9);
	poly.set(10);
	printf("%i\n", poly.sum(2));*/
/*	Point p;  
	p.x = 0;
	p.y = 0;
	Line l;
	l.x = p.x;
	l.y = p.y;
	l.x2 = 10;
	l.y2 = 10;
	Polygon pl;
	pl.x = l.x;
	pl.y = l.y;
	pl.x2 = l.x2;
	pl.y2 = l.y2;
	pl.x3 = 20;
	pl.y3 = 20;

	p.printP();
	l.printL();
	pl.printPl();*/

	A*x;

	APlus y;
	y.x = 10;
	y.print();

	AMinus z;
	z.x = 10;
	z.print();

	x=&y;
	x->print();

	Rect rect;
	rect.size = 10;
	printf("%f\n", rect.getArea());

	Circle circle;
	circle.radius = 10;
	printf("%f\n", circle.getArea());
	
	system("pause");
	return 0;
}
