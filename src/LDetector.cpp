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

#include <math.h>
#include <iostream>
#include <opencv2/opencv.hpp>

#include "LDetector.hpp"

// Load image into LDetector and do the image processing
void LDetector::process(cv::Mat foto)
{
    image = foto;
    elSplit();
    elThresh();
    elContours();
    elFilter();
}

// Split image into individual H, S, and V channels
void LDetector::elSplit()
{
    // Smooth the image a bit
    cv::GaussianBlur(image, image, cv::Size(3, 3), 1, 1);

    // Separate the HSV channels
    cv::Mat hsv_temp;
    cv::cvtColor(image, hsv_temp, CV_BGR2HSV);
    cv::split(hsv_temp, hsv_channels);
}

// Perform the thresholding
void LDetector::elThresh()
{
    cv::Mat hueLower, hueUpper;
    cv::Mat satLower, satUpper;

    cv::threshold(hsv_channels[0], hueLower, 100, 255, CV_THRESH_BINARY);
    cv::threshold(hsv_channels[0], hueUpper, 115, 255, CV_THRESH_BINARY_INV);
    cv::Mat hueThresh = hueLower & hueUpper;
    cv::imshow("hueThreshed", hueThresh);

    // prev values: 60, 140
    cv::threshold(hsv_channels[1], satLower, 30, 255, CV_THRESH_BINARY);
    cv::threshold(hsv_channels[1], satUpper, 100, 255, CV_THRESH_BINARY_INV);
    cv::Mat satThresh = satLower & satUpper;
    cv::imshow("saturation", satThresh);

    threshed = hueThresh & satThresh;
}

// Remove unnecessary circles
void LDetector::elFilter()
{
    for (unsigned int j = 0; j < circles.size(); ++j)
    {
        Ball b(cv::Point(circles.at(j)[0], circles.at(j)[1]), circles.at(j)[2]);
        unsigned i = j+1;
        while(i < circles.size())
        {
            // TODO: tweak area values if necessary
            if( (b.getRadius() > 50 || b.getRadius() < 40))
            {
                std::cout << "Erased a circle with radius of " << b.getRadius() << std::endl;
                circles.erase(circles.begin() + i);
            }
            else
            {
                std::cout << "Kept circle with radius of " << b.getRadius() << std::endl;
                i++;
            }
        }
    }
    if(circles.size() != 0)
        ball.newBall(cv::Point(circles.at(0)[0], circles.at(0)[1]), circles.at(0)[2]);
    else
        ball.newBall(); // Create a null ball
}

// Gets the Circle objects (Vec3f objects)
void LDetector::elContours()
{
    cv::Mat gray;// = threshed.clone();

    cv::Canny(threshed, gray, 0, 50, 5);

    // dilate canny output to remove potential holes between edge segments
    dilate(gray, gray, cv::Mat());
    erode(gray, gray, cv::Mat());

    cv::imshow("Edges", gray);
    
    cv::HoughCircles(gray, circles, CV_HOUGH_GRADIENT, 2, gray.size().width/4, 100, 100, 40, 150);
}

// Return a Mat with all the contours printed on the original image
cv::Mat LDetector::show()
{
    // Don't modify the actual image
    cv::Mat toRet = image.clone();

    for (unsigned int i = 0; i < circles.size(); i++)
    {
        // Extract the circle data
        cv::Point center(circles.at(i)[0], circles.at(i)[1]);
        double radius = circles.at(i)[2];

        // Draw the circle on the image itself
        cv::circle(toRet, center, radius, cv::Scalar(255, 0, 0), 3, 8, 0);
    }

    return toRet;
}

Ball LDetector::getBall()
{
    return ball;
}
