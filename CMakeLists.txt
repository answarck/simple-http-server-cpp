cmake_minimum_required(VERSION 3.22)
project(http-server)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")

add_executable(
	http-server
	src/main.cpp
	src/http/server.cpp
	src/http/client.cpp
	)

target_include_directories(http-server PRIVATE ${PROJECT_SOURCE_DIR}/include)

