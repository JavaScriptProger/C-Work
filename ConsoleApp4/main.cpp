#include <stdio.h>
#include <stdlib.h>
#include <math.h>

class Point
{
public:
	Point(double x, double y){
		this->x = x;
		this->y = y;
	};

	double getX(){
		return this->x;
	};

	double getY(){
		return this->y;
	};

private:
	double x;
	double y;
};

class Line
{
public:
	Line(Point *a, Point *b){
		p1 = new Point(a->getX(), a->getY());
		p2 = new Point(b->getX(), b->getY());
		L();
	};

	double getDistance(){
		return l;
	};

private:
	Point *p1;
	Point *p2;
	double l;

	void L(){
		l = sqrt(pow(p1->getX() - p2->getY(), 2) + pow(p1->getX() - p2->getY(), 2));
	};
};

class Polygon
{
public:
	Polygon(Point *a, Point *b, Point *c){
		p1 = new Point(a->getX(), a->getY());
		p2 = new Point(b->getX(), b->getY());
		p3 = new Point(c->getX(), c->getY());

		double at[3];
		at[0] = p1->getX();
		at[1] = p2->getX();
		at[2] = p3->getX();

		double bt[3];
		bt[0] = p1->getY();
		bt[1] = p2->getY();
		bt[2] = p3->getY();

		L(at, bt, 3);
	};

	double getArea(){
		return l;
	};

private:
	Point *p1;
	Point *p2;
	Point *p3;
	double l;

	void L(double *X, double *Y, int points) {
		double  area=0. ;
		int     i, j=points-1  ;

		for (i=0; i<points; i++) {
		area+=(X[j]+X[i])*(Y[j]-Y[i]); j=i; }

		l = area*0.5; 
	}
};

class Stack {
public:
	void add(int value){
		if(this->index >= 10){
			printf("Warning! You can add only 10 elelments into stack!\n");
			return;
		} else {
			this->arr[index] = value;
			this->index++;
		}
	};

	int get(){
		if(this->index < 0){
			printf("Warning!\n");
			return 1;
		} else {
			this->index--;
			return this->arr[this->index];
		}
	};
private:
	int arr[10];
	int index;
};

int main(){
	Point *point1 = new Point(0,0);
	Point *point2 = new Point(0,1);
	Point *point3 = new Point(1,0);
	Line *line = new Line(point1,point2);
	Polygon *polygon = new Polygon(point1,point2,point3);

	printf("Distance: %lf\n", line->getDistance());
	printf("Area: %lf\n", polygon->getArea());
	
	Stack *myStack = new Stack();
	myStack->add(1);
	myStack->add(2);
	myStack->add(3);
	myStack->add(4);
	myStack->add(5);
	myStack->add(6);
	myStack->add(7);
	myStack->add(8);
	myStack->add(9);
	myStack->add(10);
	myStack->add(11);

	for(int i=0;i<10;i++){
		printf("Element:%i\n", myStack->get());
	}

	system("pause");
	return 0;
}
