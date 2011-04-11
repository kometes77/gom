#ifndef __CUBESLICING__H__
#define __CUBESLICING__H__

#include<string>
using namespace std;

	namespace roadview {

	class CubeSlicing {
		public:
			void generateTiles(string strFilename, SliceInfo& sliceInfo);
	};

}//namespace

#endif 
