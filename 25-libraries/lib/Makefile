CC=gcc
CCFLAGS=-c -Wall -O3 -fpic
LDFLAGS=-shared
SLIB=libdslib.a
DLIB=libdslib.so

# NOTES
# $< first dependent
# $@ target

all: $(SLIB) $(DLIB)

$(SLIB): *.o
	ar rcs $@ *.o

$(DLIB): *.o
	$(CC) $(LDFLAGS) -o $@ *.o

*.o: *.c
	@echo "compiling..."
	$(CC) $(CCFLAGS) *.c
	@echo "compiled!!"

clean:
	rm -rf *.o *.out *.a *.so