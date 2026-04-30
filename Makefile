CC = g++
CFLAGS = -Wall -std=c++17
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
TARGET = gra
SRC = main.cpp food.cpp snake.cpp gui.cpp gameconfig.cpp

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) $(LIBS)

clean:
	rm -f $(TARGET)