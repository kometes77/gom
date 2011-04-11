#ifndef __ROADVIEW__H__
#define __ROADVIEW__H__

namespace roadview {

	const int CUBE_L1_TILE_SIZE = 256;
	const int CUBE_L2_TILE_SIZE = 512;

	struct SliceInfo {
		char prefix[50];
		int faceSize;	
		int tileSize;
	};
		
};


#endif

