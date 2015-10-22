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
#include "L.hpp"

// Load image into LDetector
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
    cv::GaussianBlur(image, image, cv::Size(5, 5), 2, 2);
    cv::Mat hsv_temp;
    cv::cvtColor(image, hsv_temp, CV_BGR2HSV);
    cv::split(hsv_temp, channels); //Converted RGB to HSV, split into H S and V
}

// Perform the thresholding
void LDetector::elThresh()
{
    cv::Mat hueLower, hueUpper;

    cv::threshold(channels[0], hueLower, 100, 255, CV_THRESH_BINARY);
    cv::threshold(channels[0], hueUpper, 115, 255, CV_THRESH_BINARY_INV);
    threshed = hueLower & hueUpper;

    cv::imshow("threshed", threshed);
}

// Remove unnecessary circles
void LDetector::elFilter()
{
    // TODO: Change this
    //for (unsigned j = 0; j < all.size(); ++j)
    //{
    //    all.at(j).configureL();
    //    L L1 = all.at(j);
    //    unsigned i = j+1;
    //    while(i < all.size())
    //    {
    //        all.at(i).configureL();
    //        L L2 = all.at(i);

    //        if(L1.getTopPoint().x < L2.getTopPoint().x + 10 &&
    //                L1.getTopPoint().x > L2.getTopPoint().x - 10 &&
    //                L1.getTopPoint().y < L2.getTopPoint().x + 10 &&
    //                L1.getTopPoint().y > L2.getTopPoint().x - 10 &&
    //                L1.getOrientation() == L2.getOrientation())
    //        {
    //            all.erase(all.begin()+i);
    //            //CODE TO REMOVE L2
    //        }
    //        else
    //            i++;
    //    }
    //}
}

// Gets the Circle objects (Vec3f objects)
void LDetector::elContours()
{
    cv::Mat gray;

    cv::Canny(threshed, gray, 0, 50, 5);

    cv::imshow("Edges", gray);

    // dilate canny output to remove potential holes between edge segments
    dilate(gray, gray, cv::Mat());
    
    cv::HoughCircles(gray, circles, CV_HOUGH_GRADIENT, 2, gray.size().width/4);

    std::cout << "NumCircles: " << circles.size() << std::endl;
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

Ball* LDetector::getBall()
{
    return ball;
}
