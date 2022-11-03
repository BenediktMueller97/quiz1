/**
 * @file main.cpp
 * @author Benedikt Müller (benedikt.mueller_1@studmail.w-hs.de)
 * @version 0.1
 * @date 2022-10-25
 * @brief Class for calculate the area of circles, triangles and squares/rectangles.
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string.h>
using namespace std;

/**
 * @brief The size of the Array is equals to the argument counter.
 */
int sizeArray = 0;

/**
 * @brief Dont know how to include a math lab, this is the nearest possible value for PI in C++.
 */
double pi = 3.1415926535897;

/**
 * @brief The pointers for a shape flag.
 */
const char* shape_flags[] = {"-s", "--shape"};

/**
 * @brief The pointers for a radius flag.
 */
const char* radius_flags[] = {"-r" , "--radius"};

/**
 * @brief The pointers for a width flag.
 */
const char* width_flags[] = {"-w" , "--width"};

/**
 * @brief The pointers for a height flag.
 */
const char* height_flags[] = {"-h" , "--height"};

/**
 * @brief Calculation of the area from a rectangle.
 * @param height The value of the height of the rectangle/square.
 * @param width The value of the width of the rectangle/square.
 * @return double The area value of the rectangle/square.
 */
double calc_Rectangle(double height, double width)
{
    return height * width;
}

/**
 * @brief Calculation of the area from a circle.
 * @param radius The value of the radius of the circle.
 * @return double The area value of the circle.
 */
double calc_Circle(char radius)
{
    return radius * radius * pi;
}

/**
 * @brief Calculation of the area from a triangle.
 * @param height The value of the height of the triangle.
 * @param width The value of the width of the triangle.
 * @return double The area value of the triangle.
 */
double calc_Triangle(double height, double width)
{
    return 0.5 * width * height;
}

/**
 * @brief A short algorithmus to find the height "-h" flag and returning the value.
 * @param y Iteration
 * @param array The array with the pointers
 * @return double The height
 */
double findHeight(int y, char* array[])
{
    double height = 0;
    bool gefunden = false;
    for(y; y < sizeArray && !gefunden; y++){
        if(strcmp(array[y],height_flags[0]) == 0){
            height = strtod(array[y+1],NULL);
            gefunden = true;
        }
    }
    return height;
}

/**
 * @brief A short algorithmus to find the width "-w" flag and returning the value.
 * @param y Iteration
 * @param array The array with the pointers
 * @return double The width
 */
double findWidth(int x, char* array[])
{
    double width = 0;
    bool gefunden = false;
    for(x; x < sizeArray && !gefunden; x++){
        if(strcmp(array[x],width_flags[0]) == 0){
            width = strtod(array[x+1],NULL);
            gefunden = true;
        }
    }
    return width;
}

/**
 * @brief A short algorithmus to find the width "-s" flag and returning the shape.
 * @param y Iteration
 * @param array The array with the pointers
 * @return double The shape
 */
string findShape(char* array[])
{
    string shape = array[0];
    bool gefunden = false;
    for(int x = 0; x < sizeArray && !gefunden; x++){
        if(strcmp(array[x],shape_flags[0]) == 0){
            shape = array[x+1];
            gefunden = true;
        }
    }
    return shape;
}

/**
 * @brief A short algorithmus to find the width "-r" flag and returning the radius.
 * @param y Iteration
 * @param array The array with the pointers
 * @return double The radius
 */
double findRadius(char* array[])
{
    double radius = 0;
    bool gefunden = false;
    for(int x = 0; x < sizeArray && !gefunden; x++){
        if(strcmp(array[x],radius_flags[0]) == 0){
            radius = strtod(array[x+1],NULL);
            gefunden = true;
        }
    }
    return radius;
}

int main(int argc, char* argv[])
{
    sizeArray = argc;
    double flaeche = 0;
    int i = 0;

    //The shape var for the comparing.
    string shape = findShape(argv);
    if(shape == "circle"){
        flaeche = calc_Circle(findRadius(argv));
    }else if(shape == "triangle"){
        flaeche = calc_Triangle(findHeight(i,argv),findWidth(i,argv));
    }else if(shape == "square" || shape == "rectangle"){
        flaeche = calc_Rectangle(findHeight(i,argv),findWidth(i,argv));
    }
    
    //Formatting the input and the calculated area.
    cout << "The size of the ";
    cout << shape;
    cout << " is: ";
    cout << flaeche << endl;
}



