#opencvtest: opencvtest.cpp
#	g++ -o opencvtest opencvtest.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`
all: gradation edgetest

gradation: gradation.cpp
	g++ -o gradation gradation.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`

edgetest: edgetest.cpp
	g++ -o edgetest edgetest.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`