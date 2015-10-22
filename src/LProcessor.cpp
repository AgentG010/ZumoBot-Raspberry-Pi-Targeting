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
#include "L.hpp"

// Loads ball into LProcessor
void LProcessor::determineL(Ball* b) 
{
    ball = *b;
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

// TODO: fix data output
void LProcessor::outputData()
{
    //std::string dir[2] = {"Left Facing", "Right Facing"};
    //std::cout << "Final Results" << std::endl;
    //std::cout << "================================================================" << std::endl;
    //std::cout << "L1: " << "Horizontal Length [In Pixels]: " << firstL.getHorizontalLength() << ", Vertical Length [In Pixels]: " << firstL.getVerticalLength() << ", Orientation: " << dir[firstL.getOrientation()] << std::endl;
    //if (lCount > 1)
    //    std::cout << "L2: " << "Horizontal Length [In Pixels]: " << secondL.getHorizontalLength() << ", Vertical Length [In Pixels]: " << secondL.getVerticalLength() << ", Orientation: " << dir[secondL.getOrientation()] << std::endl;
    //std::cout << "Calculated Azimuth: " << azimuth << std::endl;
    //std::cout << "Calculated Distance (Full Horizontal) [In Meters]: " << distanceFullHorizontal << std::endl;
    //std::cout << "Calculated Distance (Vertical Average) [In Meters]: " << distanceVertical << std::endl;
    //std::cout << "Calculated Distance (Full Horizontal) [In Feet]: " << distanceFullHorizontal * 3.2808 << std::endl;
    //std::cout << "Calculated Distance (Vertical Average) [In Feet]: " << distanceVertical * 3.2808 << std::endl;
    std::cout << "TODO: add printing data\n";
}


