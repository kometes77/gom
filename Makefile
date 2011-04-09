INC_PATH_OPENCV=/home/insight77/Project/OpenCV/include/opencv
LIB_PATH_OPENCV=/usr/local/lib

LIB_OPTION=-lopencv_core -lopencv_highgui

CC=g++

cubeSlicing:
	$(CC) -o cubeSlicing cubeSlicing.cpp -L$(LIB_PATH_OPENCV) -I$(INC_PATH_OPENCV) $(LIB_OPTION)

clean:
	rm cubeSlicing
