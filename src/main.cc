#include <iostream>
#include <string>
#include <memory>

#include <opencv2/core/core.hpp>
#include <opencv2/core/ocl.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <tesseract/baseapi.h>
//#include <leptonica/allheaders.h>

int main(int argc, char** argv)
{
	cv::ocl::setUseOpenCL(true);

	std::string image_filename = argv[1];

	std::unique_ptr<tesseract::TessBaseAPI> tesseract_api
		= std::make_unique<tesseract::TessBaseAPI>();

	if (tesseract_api->Init(nullptr, "eng")) {
		std::cerr << "Could not initialize tesseract." << std::endl;
		return 1;
	}
	
	cv::Mat image = cv::imread(image_filename);
	//Pix* image = pixRead(image_filename.c_str());
	
	tesseract_api->SetImage((uchar*)image.data, image.size().width,
		image.size().height, image.channels(), image.step1());

	std::string outText = tesseract_api->GetUTF8Text();

	return 0;
}