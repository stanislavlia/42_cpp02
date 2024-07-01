#include "Point.hpp"

//collection of possible solutions - https://www.quora.com/How-do-I-check-whether-a-given-point-lies-inside-a-triangle-whose-coordinates-are-given

//Chosen solution
// Suppose ABC is a triangle whose coordinates of the vertices A, B and C are given.
// We can find the lengths of sides AB, BC and CA using distance formula of coordinate geometry.
// Suppose O is a point whose vertices are given. Find OA, OB and OC using the same distance formula.
// If (OA + OB +OC) < (AB + BC+ CA) then O lies inside the triangle.


//The Newton-Raphson method is used to find the square root of a number S by iterating
float Fixed::sqrt() const
{
    if (_num_value < 0) {
        std::cerr << "Error: Attempt to compute square root of a negative number." << std::endl;
        return -1; 
    }

    float x = this->toFloat(); 
    float last_x = 0.0f;
    float epsilon = 0.000001;

    // Using a simple convergence criterion |x - last_x| > epsilon where epsilon is a small number
    while (abs(x - last_x) > epsilon) {
        last_x = x;
        x = (x + this->toFloat() / x) / 2;
    }

    return x;
};


float compute_distance(Point p1, Point p2)
{
    Fixed   y_sqr_distance((p1.getX() - p2.getX()) * ((p1.getX() - p2.getX())));
    Fixed   x_sqr_distance((p1.getY() - p2.getY()) * (p1.getY() - p2.getY()));

    return (Fixed(x_sqr_distance + y_sqr_distance).sqrt());

};

bool bsp( Point const a, Point const b, Point const c, Point const point)
{

    float oa = compute_distance(point, a);
    float ob = compute_distance(point, b);
    float oc = compute_distance(point, c);

    float ab = compute_distance(a, b);
    float bc = compute_distance(b, c);
    float ca = compute_distance(c, a);

    if (((oa + ob + oc) - (ab + bc + ca)))
        return true;
    return false;
};




    

