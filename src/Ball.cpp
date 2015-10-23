/*
 *    Copyright 2015 Westview Robotics
 *
 *    This file is part of FRC Team 3341 Targeting.
 *
 *    FRC Team 3341 Targeting is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    FRC Team 3341 Targeting is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with FRC Team 3341 Targeting.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "Ball.hpp"
#include <math.h>

Ball::Ball()
{
    newBall(cv::Point(0, 0), 0);
}

Ball::Ball(cv::Point center, double radius)
{
    newBall(center, radius);
}

void Ball::newBall(cv::Point center, double radius)
{
    _center = center;
    _radius = radius;
    _area = M_PI * pow(radius, 2);
}

void Ball::newBall()
{
    newBall(cv::Point(0, 0), 0);
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

// If ball is not found
bool Ball::getIsNull()
{
    return _radius == 0;
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
