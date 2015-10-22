#include <iostream>

#include <boost/lexical_cast.hpp>
#include "CmdLineInterface.hpp"
#include "AppConfig.hpp"
#include "GUIManager.hpp"
#include "VideoDevice.hpp"
#include "LDetector.hpp"
#include "LProcessor.hpp"


int main(int argc, char* argv[])
{
    // get command line interface config options
    CmdLineInterface interface(argc, argv);
    AppConfig config = interface.getConfig();

    GUIManager gui;
    VideoDevice camera;
    LProcessor processor;

    // Init camera
    if(config.getIsDevice())
    {
        camera.startCapture(config.getDeviceID());
        if(config.getIsDebug())
            std::cout << "Camera ready!\n";
    }

    // Init GUI if not headless
    if(!config.getIsHeadless())
        gui.init();

    // Continuous server loop
    do
    {
        LDetector detector;

        cv::Mat image;
        if(config.getIsFile())
            image = cv::imread(config.getFileName());
        else
            image = camera.getImage(config.getIsDebug());

        std::cout << "Loaded image\n";

        detector.process(image);

        bool foundL = detector.getBall() != NULL;

        if (foundL)
        {
            processor.determineL(detector.getBall());
            processor.determineAzimuth();
            processor.determineDistance();
            //double azimuth = processor.getAzimuth();
            double distance = processor.getDistance();

            if(config.getIsDebug())
            {
                processor.outputData();
                std::cout << "Final distance (m): " << processor.getDistance() << std::endl;
            }

            if(!config.getIsHeadless())
            {
                int i_dist = (int) (distance * 1000.0);
                int dist_left = i_dist / 1000;
                int dist_right = i_dist % 1000;
                std::string dist_str = boost::lexical_cast<std::string>(dist_left) + "." + boost::lexical_cast<std::string>(dist_right);
                
                gui.setImage(detector.show());
                gui.setImageText("Distance: " + dist_str + " m");
                gui.show(config.getIsFile());
            }
        }
        else
        {
            if(!config.getIsHeadless())
            {
                gui.setImage(detector.show());
                gui.setImageText("Ball not found");                
                gui.show(config.getIsFile());
            }
        }
    }
    // Run only once if reading from a file
    while(config.getIsDevice());

    return 0;
}

