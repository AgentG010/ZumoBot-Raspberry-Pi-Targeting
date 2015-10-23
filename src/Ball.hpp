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
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See thelibboost1.55-all-dev
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with FRC Team 3341 Targeting.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef BALL_h
#define BALL_h

#include <opencv2/opencv.hpp>

class Ball
{
    public:
        Ball();
        Ball(cv::Point center, double radius);
        void newBall(cv::Point center, double radius);
        void newBall();

        // Getters
        double getRadius();
        cv::Point getCenter();
        double getArea() const;
        bool getIsNull();

        // Operators
        bool operator < (const Ball& ball) const;
        bool operator > (const Ball& ball) const;

    private:
        double _radius;
        cv::Point _center;
        double _area;
};

#endif
