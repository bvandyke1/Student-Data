/* Title: Area of a Circle
   Author: Brandon VanDyke
   Date: 04/15/19
   Purpose: Read text from the circles.txt file and calculate 
            the area, circumference, radius, and diameter  */
   
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

double functionRadius(int x1, int y1, int x2, int y2);
//"declare" radius function so that main can refer to it
double functionArea(double circleRadius);
//"declare" area function so that main can refer to it 
double functionCircumference(double circleRadius);
//"declare" circumference function so that main can refer to it 

int main()
{
    ifstream infile;
    //declare file stream variable for input from file 
    int x1, y1, x2, y2;
    //declare coordinates as int variables for use in the radius calculation, to be read from file
    int Count;
    //declare variable for the iteration of the loop
    
    infile.open("circles.txt");
    //open the circles.txt file 
    
    for (Count = 1; Count <= 4; Count++)   {
    //for loop that is used to cycle through each line of the file     
        infile >> x1 >> y1 >> x2 >> y2;
        /*insert values into each coordinate, to be read from file 
        and overwritten for calculation during each loop iteration*/
        
        cout << fixed << setprecision(2)
             << "The radius for circle " << Count << " is " << functionRadius(x1, y1, x2, y2)
             << ", the diameter is " << functionRadius(x1, y1, x2, y2) * 2 << ", the area is "
             << functionArea(functionRadius(x1, y1, x2, y2)) << ", and the circumference is " 
             << functionCircumference(functionRadius(x1, y1, x2, y2)) << "." << endl;
        /*output each calculation for the radius, diameter, circumference, and area, based
        on the coordinates in the file*/
    }
    
    infile.close();
    //close the file
    
    return 0;
}

double functionRadius(int x1, int y1, int x2, int y2)   {
//function for calculating the radius, using the coordinates from the file     
    double circleRadius = sqrt((pow(x2-x1,2)) + (pow(y2-y1,2)));
    //calculate the radius with the formula used on a Cartesian plane
    
    return circleRadius;
    //return the calculated value for radius when called upon
    
}

double functionArea(double circleRadius)   {
//function used to find the area of a circle, calling on the radius from functionRadius    
    double pi = 3.1415;
    //declare pi for use in this function 
    double circleArea = (pi * pow(circleRadius, 2));
    //declare and calculate the area 
    
    return circleArea;
    //return the calculated value for area when this function is called 
}

double functionCircumference(double circleRadius)  {
//function used to find the circumference of a circle, calling on radius from functionRadius    
    double pi = 3.1415;
    //declare pi for use in this function 
    double circleCircumference = (2 * pi * circleRadius);
    //declare and calculate the circumference 
    
    return circleCircumference;
    //return the calculated value for circumference when this function is called 
}

