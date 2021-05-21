cmake_minimum_required(VERSION 3.15)
project(disservice)

# set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

################### Added by me #########################
find_package(Boost 1.76.0)

set(Boost_USE_STATIC_LIBS        ON) # only find static libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
#find_package(Boost 1.76.0 COMPONENTS asio date_time filesystem system ...)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    #add_executable(disservice main.cpp)
    add_executable(disservice main.cpp connection.cpp connection.hpp connection_manager.cpp connection_manager.hpp server.hpp mime_types.cpp mime_types.hpp reply.cpp reply.hpp request.hpp request_handler.cpp request_handler.hpp request_parser.cpp request_parser.hpp server.cpp header.hpp)
    target_link_libraries(disservice ${Boost_LIBRARIES})
    target_link_libraries( ${PROJECT_NAME} -lws2_32 -lwsock32 )
endif()

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -lws2_32 -lwsock32")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

if(MINGW)
    target_link_libraries(disservice ws2_32)
endif()
##########################################################
# add_executable(disservice main.cpp connection.cpp connection.hpp connection_manager.cpp connection_manager.hpp server.hpp mime_types.cpp mime_types.hpp reply.cpp reply.hpp request.hpp request_handler.cpp request_handler.hpp request_parser.cpp request_parser.hpp server.cpp header.hpp)