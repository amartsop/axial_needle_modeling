cmake_minimum_required( VERSION 3.10 )

project( identification_cpp )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# #Optimization parameters
# set(CMAKE_BUILD_TYPE Release)
# set(CMAKE_CXX_FLAGS "-march=native -O2")

# Python linking
find_package(PythonLibs 2.7)

# Armadillo linking
find_package(Armadillo REQUIRED)

# Include directories
include_directories(
    ./include  
)

set(ALL_LIBS
  ${PYTHON_LIBRARIES}
  ${ARMADILLO_LIBRARIES})

set(SOURCES
  ./src/tcaf.cpp 
  ./src/identification.cpp
    )

  
# target
add_executable(main main.cpp ${SOURCES})


target_include_directories(main PRIVATE ${PYTHON_INCLUDE_DIRS} ${ARMADILLO_INCLUDE_DIRS})
target_link_libraries(main ${ALL_LIBS})
