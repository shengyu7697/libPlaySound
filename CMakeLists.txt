project(libPlaySound)
cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(MSVC)
else()
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -std=c++11")
    set(CMAKE_CXX_FLAGS_RELEASE "-W -Wall -O3 -std=c++11")
endif()

file(GLOB SRCS ./*.h ./*.cpp)
add_executable(playsound ${SRCS})
if(WIN32)
target_link_libraries(playsound Winmm)
else()
#target_link_libraries(playsound pthread)
endif()

add_custom_command(TARGET playsound POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_CURRENT_SOURCE_DIR}/shutter.wav"
    $<TARGET_FILE_DIR:playsound>)
