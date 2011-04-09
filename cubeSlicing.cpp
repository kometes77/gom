#include<stdio.h>
#include<cv.h>
#include<cxcore.h>
#include<highgui.h>


int main(int argc, char** argv) {

	for(int i=0;i<argc;++i)
	{
		printf("[%d]:%s\n", i, argv[i]);
	}

	char *inputFileName = argv[1];

	IplImage *inputImage = 0;
	inputImage = cvLoadImage(inputFileName,CV_LOAD_IMAGE_UNCHANGED);

	IplImage *image1024 = cvCreateImage( cvSize(1024,1024), inputImage->depth, inputImage->nChannels );
	
	cvResize( (void*)inputImage, (void*)image1024, CV_INTER_CUBIC );

	cvSaveImage( "output.jpg", image1024 ); 

	cvReleaseImage( &inputImage );
	cvReleaseImage( &image1024 );



	return 0;
}
