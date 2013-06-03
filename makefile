CC = gcc
CFLAGS = -O3

TARGET = suniq
OBJS = suniq.o

default : all

all : $(TARGET)

suniq : $(OBJS)

clean :
	$(RM) $(TARGET) $(OBJS)
