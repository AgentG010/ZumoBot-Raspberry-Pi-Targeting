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

#include <iostream>
#include <math.h>

#include "LProcessor.hpp"

// Loads ball into LProcessor
void LProcessor::determineL(Ball b) 
{
    ball = b;
}

double LProcessor::getAzimuth()
{
    return azimuth;
}

double LProcessor::getDistance()
{
    return distance;
}

void LProcessor::determineAzimuth()
{
    azimuth = (((double) imgWidth / 2.0) - (double) ball.getCenter().x) / focalLength;
    azimuth *= 180.0 / M_PI;
}

void LProcessor::determineDistance()
{
    distance = RADIUS * focalLength / ball.getRadius();
}

void LProcessor::outputData()
{
    std::cout << "Final Results" << std::endl;
    std::cout << "================================================================" << std::endl;
    std::cout << "Radius [In Pixels]: " << ball.getRadius() << std::endl;
    std::cout << "X Position: " << ball.getCenter().x << std::endl;
    std::cout << "Y Position: " << ball.getCenter().y << std::endl;
    std::cout << "Area: " << ball.getArea() << std::endl;
    std::cout << "Calculated Azimuth [In Degrees]: " << azimuth << std::endl;
    std::cout << "Calculated Distance [In Meters]: " << distance << std::endl;
}


