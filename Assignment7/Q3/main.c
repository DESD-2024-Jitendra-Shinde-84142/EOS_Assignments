#include<stdio.h>
#include"circle.h"
#include"square.h"
#include"rectangle.h"

int main()
{
	float Area_cl = circle_area(5.5);
	printf("Area of circle = %f\n",Area_cl);
	float Area_sq = square_area(6);
	printf("Area of sqaure = %f\n",Area_sq);
	float Area_rc = rec_area(6, 5);
	printf("Area of rectangle = %f\n",Area_rc);
	return 0;
}
