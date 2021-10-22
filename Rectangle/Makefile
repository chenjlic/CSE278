Main:
	g++ -o run main.o Rectangle.o
main.o: main.cpp Rectangle.h
	g++ -c main.cpp
Shape.o: Shape.cpp
	g++ -c Rectangle.cpp
clean:
	rm -rf *.o run
