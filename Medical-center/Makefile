CC = gcc
CFLAGS = -Iinclude -Wall
OBJ = src/main.o src/patient.o src/io.o src/auth.o

all: patient_system

patient_system: $(OBJ)
	$(CC) -o patient_system $(OBJ) $(LDFLAGS)

src/main.o: src/main.c include/patient.h include/io.h include/auth.h
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/patient.o: src/patient.c include/patient.h
	$(CC) $(CFLAGS) -c src/patient.c -o src/patient.o

src/io.o: src/io.c include/io.h include/patient.h
	$(CC) $(CFLAGS) -c src/io.c -o src/io.o

src/auth.o: src/auth.c include/auth.h include/patient.h
	$(CC) $(CFLAGS) -c src/auth.c -o src/auth.o

clean:
	rm -f src/*.o patient_system
