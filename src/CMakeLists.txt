# Find Libraries
find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS system thread)

# magica
add_executable(magica magica.cpp LDetector.cpp LProcessor.cpp VideoDevice.cpp CmdLineInterface.cpp AppConfig.cpp Ball.cpp GUIManager.cpp libs/libarduino.o libs/libfirmataplus.o)
target_link_libraries(magica ${OpenCV_LIBS} ${Boost_LIBRARIES})

add_executable(circles circles.cpp)
target_link_libraries(circles ${OpenCV_LIBS})
