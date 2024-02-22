project(
	CPlusBestC
	LANGUAGES CXX)
	
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_executable(main Gause.cpp)