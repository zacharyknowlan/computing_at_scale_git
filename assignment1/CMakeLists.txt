cmake_minimum_required(VERSION 3.30)
project(assignment1 CXX)

set(TEST_MODE FALSE)

if (TEST_MODE)
    add_executable(main unit_tests.cpp)
    add_subdirectory(TestingLibrary)
    target_link_libraries(main PUBLIC TestingLibrary)
else()
    add_executable(main polynomial_integrate.cpp)
endif()

add_subdirectory(NumericalIntegrationLibrary)
target_link_libraries(main PUBLIC NumericalIntegrationLibrary)

add_subdirectory(FunctionLibrary)
target_link_libraries(main PUBLIC FunctionLibrary)