CC= g++
CCFLAGS = -std=c++11
#LIBS = -lm -lx

Database.o: Database.cpp Database.h
	$(CC) $(CCFLAGS) Database.cpp -c

Driverbase.o: Driverbase.cpp
	$(CC) $(CCFLAGS) Driverbase.cpp -c

myprog: Database.o Driverbase.o
	$(CC) $(CCFLAGS) Database.o Driverbase.o -o myprog

run:
	./myprog
clean:
	rm -f *.o
