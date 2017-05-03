#opencvtest: opencvtest.cpp
#	g++ -o opencvtest opencvtest.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`
all: gradation edgetest hexagon

gradation: gradation.cpp
	g++ -o gradation gradation.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`

edgetest: edgetest.cpp
	g++ -o edgetest edgetest.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`

hexagon: hexagon.cpp
	g++ -o hexagon hexagon.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`

#h5group: h5group.cpp
#	h5c++ -o h5group h5group.cpp