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

#ifndef LDetector_hpp
#define LDetector_hpp

#include <iostream>
#include <opencv2/opencv.hpp>
#include "L.hpp"
#include "Ball.hpp"

class LDetector
{
    public:
        void process(cv::Mat foto);
        cv::Mat show();
        Ball* getBall();

    private:
        cv::Mat image;
        Ball* ball;
        // Holds the circle contours
        std::vector<cv::Vec3f> circles;

        // Thresholding
        cv::Mat threshed;
        std::vector<cv::Mat> channels;

        // Pipeline Methods
        void elSplit();
        void elThresh();
        void elFilter();
        void elContours();
};

#endif /* LDetector_hpp */
