CC = gcc
CFLAGS = -O3 -g -Wall

TARGET = suniq
TESTS = test_hash test_counter
OBJS = suniq.o hash.o counter.o

default : all

test : $(TESTS)

test_counter :

test_hash : hash.o test_hash.o

all : $(TARGET)

suniq : $(OBJS)

clean :
	$(RM) $(TARGET) $(TESTS) $(OBJS)
