#ifndef BALL_h
#define BALL_h

#include <opencv2/opencv.hpp>

class Ball
{
    public:
        Ball();
        Ball(cv::Point center, double radius);

        // Getters
        double getRadius();
        cv::Point getCenter();
        double getArea() const;

        // Operators
        bool operator < (const Ball& ball) const;
        bool operator > (const Ball& ball) const;

    private:
        double _radius;
        cv::Point _center;
        double _area;
};

#endif
