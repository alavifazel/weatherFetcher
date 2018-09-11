cmake_minimum_required(VERSION 3.0)

project (weatherFetcher)

file(GLOB_RECURSE weatherFetcher_SOURCES "src/*.cpp")
file(GLOB_RECURSE weatherFetcher_HEADERS "src/*.h")

set (CMAKE_CXX_STANDARD 17)

set (weatherFetcher_INCLUDE_DIRS "")
foreach (_headerFile ${weatherFetcher_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND weatherFetcher_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES weatherFetcher_INCLUDE_DIRS)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.66 REQUIRED COMPONENTS system) 
find_package (Threads)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    add_executable (weatherFetcher ${weatherFetcher_SOURCES})
    target_link_libraries(weatherFetcher ${Boost_LIBRARIES})
    target_link_libraries (weatherFetcher ${CMAKE_THREAD_LIBS_INIT})
  endif()
