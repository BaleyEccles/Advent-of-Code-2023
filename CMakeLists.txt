cmake_minimum_required(VERSION 3.15)

project(AOC2023)

set(SOURCES src/main.cpp
	    src/days/Day1.cpp
	    src/days/Day2.cpp
	    src/days/Day3.cpp
	    src/days/Day4.cpp
	    src/days/Day5.cpp
	    src/days/Day6.cpp
	    src/days/Day7.cpp
	    src/days/Day8.cpp
	    src/days/Day9.cpp
	    src/days/Day10.cpp
	    src/days/Day12.cpp	
	    )
	    
add_executable(main ${SOURCES})

#target_compile_options(main PRIVATE
#			    -O3
#			    -march=native	    
#			    -flto
#			    -funroll-loops
#			    -ftree-vectorize	    
#)

