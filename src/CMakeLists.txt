# Find Libraries
find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS system thread)

# magica
add_executable(magica magica.cpp LDetector.cpp LProcessor.cpp L.cpp NetworkController.cpp VideoDevice.cpp CmdLineInterface.cpp AppConfig.cpp Ball.cpp GUIManager.cpp libarduino.so libfirmataplus.so)
target_link_libraries(magica ${OpenCV_LIBS} ${Boost_LIBRARIES})
