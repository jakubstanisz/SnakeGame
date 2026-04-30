CC = g++
CFLAGS = -Wall -std=c++17
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
TARGET = gra
SRC = src/*.cpp
# -Iinclude means that if compiler meets "#include" it will come to folder include and search for it
$(TARGET): $(SRC)
	$(CC) $(SRC) -Iinclude -o $(TARGET) $(CFLAGS) $(LIBS)

clean:
	rm -f $(TARGET)