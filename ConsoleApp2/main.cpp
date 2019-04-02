#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_POINT_COUNT 25

int index_of_point = 0;

//My cool structs
typedef struct {
	int x;
	int y;
} Point;

typedef struct {
	Point points[MAX_POINT_COUNT];
} Polygon;

//My cool method
//Method for adding new point
void addNewPointTo(Polygon &object, int x, int y){
	object.points[index_of_point].x = x;
	object.points[index_of_point].y = y;
	index_of_point++;
}

//Method for geting polygon area
double getPolygoneArea(Polygon object)
{ 
	printf("-------------------\n");
	/*double a = sqrt((object.points[0].x - object.points[1].x)^2+(object.points[0].y - object.points[1].y)^2);
	double b = sqrt((object.points[1].x - object.points[2].x)^2+(object.points[1].y - object.points[2].y)^2);
	double c = sqrt((object.points[2].x - object.points[3].x)^2+(object.points[2].y - object.points[3].y)^2);
	double p = a+b+c;*/
	double area = 0;         // Accumulates area in the loop
	int j = index_of_point-1;  // The last vertex is the 'previous' one to the first

	for (int i=0; i<index_of_point; i++){ 
		area = area +  (object.points[j].x - object.points[i].x) * (object.points[j].y - object.points[i].y); 
		j = i;  //j is previous vertex to i
	}
	return abs(area/2);
}

//Mathod for getting distance between points
double getDistanceBetweenPoints(Point point1, Point point2){
	double square_difference_x = (point2.x - point1.x) * (point2.x - point1.x);
    double square_difference_y = (point2.y - point1.y) * (point2.y - point1.y);
    double sum = square_difference_x + square_difference_y;
    double value = sqrt(sum);
    return value;
}

int main(){
	Polygon polygon;

	/*addNewPointTo(polygon, 1,1); //1
	addNewPointTo(polygon, 2,1); //2
	addNewPointTo(polygon, 3,2); //3
	addNewPointTo(polygon, 2,3); //4
	addNewPointTo(polygon, 1,3); //5
	addNewPointTo(polygon, 0,2); //6*/
	addNewPointTo(polygon, 0,0); //1
	addNewPointTo(polygon, 0,2); //2
	addNewPointTo(polygon, 2,3); //3
	addNewPointTo(polygon, 3,2); //2
	addNewPointTo(polygon, 3,0);
	//addNewPointTo(polygon, 4,2);

	for(int  i = 0;i < index_of_point; i++){
		printf("x: %i y: %i\n", polygon.points[i].x, polygon.points[i].y);
	}

	Point p1, p2;
	p1.x = 10;
	p1.y = 10;
	
	p2.x = 100;
	p2.y = 200;
	printf("Distance between two points:%f\n", getDistanceBetweenPoints(p1, p2));
	printf("Area of polygon :%f\n", getPolygoneArea(polygon));
	system("pause");
	return 0;
}
