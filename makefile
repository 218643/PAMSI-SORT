FLAGI=-g -pedantic -Wall -std=c++0x

program: src/tabdyn.cpp
	g++ ${FLAGI} -o program src/tabdyn.cpp
