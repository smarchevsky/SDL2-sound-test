cmake_minimum_required(VERSION 3.13)

project(SDL2_Sound LANGUAGES CXX)

find_package(SDL2 REQUIRED)

find_library(SDL_MIXER_LIBRARY
  NAMES SDL2_mixer
  HINTS
    ENV SDLMIXERDIR
    ENV SDLDIR
  PATH_SUFFIXES lib
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${GLM_INCLUDE_DIRS})

add_executable(SDL2_Sound main.cpp KeyMapper.cpp)
target_link_libraries(SDL2_Sound ${SDL2_LIBRARIES})

target_link_libraries(SDL2_Sound ${SDL_MIXER_LIBRARY})


#install libsdl2-dev libsdl2-mixer-dev libglm-dev

