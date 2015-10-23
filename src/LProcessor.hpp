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

#ifndef LProcessor_hpp
#define LProcessor_hpp

#include <opencv2/opencv.hpp>

#include "Ball.hpp"

class LProcessor {
    public:
        void determineL(Ball b);
        void determineDistance();
        void determineAzimuth();
        void outputData();
        double getAzimuth();
        double getDistance();
    private:
        double azimuth;
        double distance;
        // TODO: fix constants
        const double focalLength = 640;
        const double imgWidth = 640;
        const double imgHeight = 480;
        const double RADIUS = 0.1778;
        Ball ball;
};

#endif /* LProcessor_hpp */
