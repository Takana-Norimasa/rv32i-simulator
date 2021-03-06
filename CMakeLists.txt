cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0 -pg")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -s -DNDEBUG -march=native")

project(
	riscv-sim
	VERSION 0.0.1
	DESCRIPTION "RISC-V simulator"
	LANGUAGES CXX
)

add_subdirectory(src)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} libs)


# tests
if(NOT without-test)
	enable_testing()
	add_subdirectory(test)
	add_custom_target(unit
		./test/unittest
	)
	add_custom_target(run
		./riscv-sim
	)
endif()
