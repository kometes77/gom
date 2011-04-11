#include<stdio.h>
#include<cv.h>
#include<cxcore.h>
#include<highgui.h>

#include "roadviewSlice.h"
#include "CubeSlicing.h"

namespace roadview {

	void CubeSlicing::generateTiles(string strFilename, SliceInfo& sliceInfo) {
		IplImage *inputImage = 0;
		inputImage = cvLoadImage(strFilename.c_str(),CV_LOAD_IMAGE_UNCHANGED);

		IplImage *image1024 = cvCreateImage( cvSize(sliceInfo.faceSize,sliceInfo.faceSize), inputImage->depth, inputImage->nChannels );
		
		cvResize( (void*)inputImage, (void*)image1024, CV_INTER_CUBIC );

		char outputFilename[100];	
		int x,y;
		for(y=0;y<4;++y) {
			for(x=0;x<4;++x) {
				cvSetImageROI( image1024,cvRect(x*CUBE_L1_TILE_SIZE,y*CUBE_L1_TILE_SIZE,CUBE_L1_TILE_SIZE,CUBE_L1_TILE_SIZE) );
				sprintf(outputFilename,"%s_%d_%d.jpg",sliceInfo.prefix,y,x);
				cvSaveImage(outputFilename, image1024 ); 
			}
		}
		
		cvResetImageROI( image1024 );
		cvReleaseImage( &inputImage );
		cvReleaseImage( &image1024 );
	}  		

}//namespace			
	                	
				
