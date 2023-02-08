CC = g++
CFLAGS = -I include -std=c++11 main.cpp -std=c++11 -Wall -lGL -lGLU -lglut -lGLEW -lglfw -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor

runwen:
	$(CC) $(CFLAGS)  -o "runwen"

clean:
	rm -rf runwen
