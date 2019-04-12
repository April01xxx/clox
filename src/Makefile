TARGET = clox
OBJS = chunk.o debug.o main.o memory.o value.o vm.o

CC = gcc
INCLUDE = -I. -I../include
LINK = -L.
FLAGS = -g -std=c99

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^ $(FLAGS) $(LINK)

$(OBJS): %.o : %.c
	$(CC) -c $< $(INCLUDE) $(FLAGS)

clean:
	@rm -f $(OBJS) $(TARGET)
