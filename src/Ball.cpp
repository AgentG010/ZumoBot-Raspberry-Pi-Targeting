#include "Ball.hpp"
#include <math.h>

Ball::Ball()
{

}

Ball::Ball(cv::Point center, double radius)
{
    _center = center;
    _radius = radius;
    _area = M_PI * pow(radius, 2);
}

////////////////////////////////////////////////////////////////////////////////
//// Getters
////////////////////////////////////////////////////////////////////////////////

double Ball::getRadius()
{
    return _radius;
}

cv::Point Ball::getCenter()
{
    return _center;
}

double Ball::getArea() const
{
    return _area;
}

////////////////////////////////////////////////////////////////////////////////
//// Operators
////////////////////////////////////////////////////////////////////////////////

bool Ball::operator < (const Ball& ball) const
{
    return (_area < ball.getArea());
}

bool Ball::operator > (const Ball& ball) const
{
    return (_area > ball.getArea());
}
