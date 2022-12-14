cmake_minimum_required (VERSION 3.23)

if (POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW)
endif ()

set(PROJECTNAME recipes)
project(${PROJECTNAME})

set(CMAKE_CXX_STANDARD 20) # this does nothing for MSVC, use target_compile_options below
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_FLAGSD "${CMAKE_CXX_FLAGS} -O0 -Wall -g -ggdb -fno-rtti")

aux_source_directory(src DIR_MAIN_SRCS)
add_executable(${PROJECTNAME} ${DIR_MAIN_SRCS})

# include header path
target_include_directories(${PROJECTNAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/includes/>)
  
# Link libs
target_link_libraries(${PROJECTNAME} -lglfw)
target_link_libraries(${PROJECTNAME} -lpthread)
target_link_libraries(${PROJECTNAME} -ldl)
target_link_libraries(${PROJECTNAME} -lGL)
