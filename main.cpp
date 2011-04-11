#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"roadviewSlice.h"
#include"CubeSlicing.h"

using namespace roadview;

int main(int argc, char** argv) {

	if(argc!=3) {
		printf("you should give 2 parameters\n");
		printf("roadviewSlicing level filename. ex> roadviewSlcing 0 left.jpg\n");
		return 0;
	}

	SliceInfo sliceInfo;
	char *inputFileName = argv[2];

	CubeSlicing cubeSlicing;
	switch(atoi(argv[1])) {
		case 0:
			strcpy(sliceInfo.prefix, "prefix");
			sliceInfo.faceSize = 1024;
			sliceInfo.tileSize = 256;
			printf("level 0 slicing started...");
			cubeSlicing.generateTiles(inputFileName, sliceInfo);
			break;
		case 1:
			strcpy(sliceInfo.prefix, "prefix_HD1");
			sliceInfo.faceSize = 2048;
			sliceInfo.tileSize = 512;
			printf("level 1 slicing started...");
			cubeSlicing.generateTiles(inputFileName, sliceInfo);	
			break;
	}	

	return 0;
}
