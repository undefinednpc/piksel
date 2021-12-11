CC = cc
CFLAGS = -pedantic -Wall -Werror -Wextra -lSDL2

TARGET = piksel

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	$(RM) $(TARGET)
