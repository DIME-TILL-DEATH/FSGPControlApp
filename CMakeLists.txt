cmake_minimum_required(VERSION  3.16)

project(FSGPControlApp VERSION 1.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(FSGPControlApp WIN32
    main.cpp
    gui/controlgui.cpp gui/controlgui.h
    gui/ethgui.cpp gui/ethgui.h
    eth/ethcore.h eth/ethcore.cpp
    eth/fsgp.h eth/fsgp.cpp
    eth/frame_defines.h
    eth/uppm_command_frame.h eth/uppm_fdk_frame.h eth/uppm_raw_comm_frame.h
    eth/fsgp_command_frame.h eth/fsgp_fdk_frame.h
    qml.qrc
)

find_package(Qt5 REQUIRED COMPONENTS Qml Quick Network)

target_link_libraries(FSGPControlApp PRIVATE
    Qt5::Core
    Qt5::Network
    Qt5::Quick
    Qt5::Qml
)

#if(CMAKE_BUILD_TYPE STREQUAL "Release")
#  set_property(TARGET main PROPERTY WIN32_EXECUTABLE true)
#endif()

target_include_directories(FSGPControlApp PRIVATE
    eth
    gui
)

target_compile_features(FSGPControlApp PRIVATE cxx_std_11)
