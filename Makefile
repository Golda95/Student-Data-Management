project: main.o mainfuncs.o 
	cc main.o mainfuncs.o -o project
main.o: main.c main.h
	cc -c main.c 
mainfuncs.o: mainfuncs.c main.h
	cc -c mainfuncs.c 
clean:
	rm *.o project
