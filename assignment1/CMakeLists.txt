cmake_minimum_required(VERSION 3.30)
project(assignment1 CXX)

add_executable(main polynomial_integrate.cpp)

add_subdirectory(NumericalIntegrationLibrary)
target_link_libraries(main PUBLIC NumericalIntegrationLibrary)

add_subdirectory(FunctionLibrary)
target_link_libraries(main PUBLIC FunctionLibrary)