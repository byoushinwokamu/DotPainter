project(DotClock)
cmake_minimum_required(VERSION 3.22)

add_executable(
	main
	main.c
	src/conio.c
)
target_include_directories(
	main
	PUBLIC inc
)
