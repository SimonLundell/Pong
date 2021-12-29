cmake_minimum_required(VERSION 3.10.2) # cmake --version

project(pong)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/plugins DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_compile_options(-g -Wall)

file(GLOB sourcefiles ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_executable(pong ${sourcefiles})
add_library(ponginterface SHARED ${sourcefiles}) # Will create a libponginterface.so

target_include_directories(ponginterface
  PUBLIC
  $<INSTALL_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  ${CMAKE_CURRENT_BINARY_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# tell the compiler where our files are.
# You don't need to do this if you have these files in
# your path
# include_directories(libraries/include)
# target_link_directories(pong PRIVATE libraries/lib)
# arget_link_directories(pong PRIVATE libraries/bin)

# tell the compiler that we want to link and use the SDL2
# library.
target_link_libraries(pong PUBLIC SDL2 SDL2_ttf)

target_link_libraries(pong PUBLIC dl)

if(WIN32)
  target_link_libraries(pong PUBLIC Kernel32)
ENDIF()
