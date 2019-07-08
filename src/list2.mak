list2: list2.o list2_sub01.o list2_sub02.o
	g++ -o list2 list2.o list2_sub01.o list2_sub02.o

list2.o: list2.cpp list2.h
	g++ -c -g  -O0 list2.cpp

list2_sub01.o: list2_sub01.cpp list2.h
	gcc -c -g  -O0 list2_sub01.cpp -lstdc++

list2_sub02.o: list2_sub02.cpp list2.h
	gcc -c -g  -O0 list2_sub02.cpp -lstdc++

clean:
	rm -f list2 list2.o list2_sub01.o list2_sub02.o

