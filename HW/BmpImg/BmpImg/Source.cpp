#include <iostream>
#include "BmpStructures.h"
#include "ImgFunctions.h"
#include <algorithm>

void testBmpIo()
{
	printImgInfo("masterpiece.bmp");
	RgbImg img = readRgbImg("masterpiece.bmp");
	for (size_t row=0; row < 50;++row)
		for (size_t col = 0; col < 50; ++col)
		{
			img.pixels[row][col].Blue = 255;
			img.pixels[row][col].Green = 128;
			img.pixels[row][col].Red = 0;
			//img.pixels[row][col] = {255, 255, 255}; //same as above
		}
	writeRgbImg("out\\ugly_copy.bmp", img);
	deleteRgbImg(img);
}

//Generate dummy image example
void genImgWithSquare()
{
	RGB background = { 255, 128, 0 };
	RgbImg img = createRgbImg(600, 600, background);
	for (size_t row = 50; row < 200; ++row)
		for (size_t col = 100; col < 400; ++col)
			img.pixels[row][col] = { 128, 255, 0 };

	writeRgbImg("out\\ai_masterpiece.bmp", img);
	deleteRgbImg(img);
}

//Autobalancing example
void testAutolevels()
{
	RgbImg img = readRgbImg("data\\Lenna.bmp");
	RgbImg balanced = autolevels(img);
	writeRgbImg("out\\Lenna_avtolevels.bmp", img);
	deleteRgbImg(img);
}

//Another autobalancing example
void testGrayworld()
{
	RgbImg img = readRgbImg("data\\sinichka.bmp");
	RgbImg balanced = grayworld(img);
	writeRgbImg("out\\grayworld.bmp", balanced);
	deleteRgbImg(img);
}

//Box filter example
void testBoxFilter()
{
	RgbImg img = readRgbImg("data\\kidsnoise.bmp");
	RgbImg filtered = convolution(img, 5);
	writeRgbImg("out\\kids_filtered.bmp", img);
	deleteRgbImg(img);
	deleteRgbImg(filtered);
}

void testKernelFilter()
{
	size_t const kern_sz = 3;
	double** kernel = new double* [kern_sz];
	for (size_t row = 0; row < kern_sz; ++row)
	{
		kernel[row] = new double[kern_sz];
		for (size_t col = 0; col < kern_sz; ++col)
			kernel[row][col] = 1. / 9;
	}
	RgbImg img = readRgbImg("data\\kidsnoise.bmp");
	RgbImg filtered = convolution(img, 5, kernel);
	writeRgbImg("out\\kids_filtered_kernel.bmp", img);
	deleteRgbImg(img);
	deleteRgbImg(filtered);
}

void testContours()
{
	RgbImg img = readRgbImg("data\\sinichka.bmp");
	RgbImg contour_img = contours(img);
	writeRgbImg("out\\contours.bmp", contour_img);
	deleteRgbImg(img);
	deleteRgbImg(contour_img);
}

void generate_rainbow(char* out_file=(char *)"out\\ai_masterpiece.bmp") {
	RgbImg img = createRgbImg(100, 700, {0, 0, 0});
	RGB colors[7] = { {0, 0, 255}, {0, 165, 255}, {0, 255, 255}, {0, 255, 0}, {255, 255, 0}, {255, 0, 0}, {128, 0, 128} };
	for (size_t c = 0; c < 7; c++)
	{
		for (size_t i = c * 100; i < (c + 1) * 100; i++)
		{
			for (size_t j = 0; j < 100; j++)
			{
				img.pixels[j][i] = colors[c];
			}
		}
	}

	writeRgbImg(out_file, img);
	deleteRgbImg(img);
}

void rotate_img(char* source=(char*)"data\\sinichka.bmp", char* destination=(char*)"data\\sinichka_rotated.bmp", int rotate=90) {
	rotate %= 360;
	if (rotate % 90 != 0)
		return;

	RgbImg src_img = readRgbImg(source);
	int h = src_img.height, w = src_img.width;

	if (rotate == 0) {
		writeRgbImg(destination, src_img);
		deleteRgbImg(src_img);
		return;
	}
	else if (rotate == 90) {
		RgbImg des_img = createRgbImg(w, h, { 0, 0, 0 });
		for (size_t x = 0; x < w; x++)
		{
			for (size_t y = 0; y < h; y++)
			{
				des_img.pixels[w - 1 - x][y] = src_img.pixels[y][x];
			}
		}
		writeRgbImg(destination, des_img);
		deleteRgbImg(src_img);
		deleteRgbImg(des_img);
	}
	else if (rotate == 180) {
		RgbImg des_img = createRgbImg(h, w, { 0, 0, 0 });
		for (size_t x = 0; x < w; x++)
		{
			for (size_t y = 0; y < h; y++)
			{
				des_img.pixels[y][x] = src_img.pixels[h - y - 1][w - x - 1];
			}
		}
		writeRgbImg(destination, des_img);
		deleteRgbImg(src_img);
		deleteRgbImg(des_img);
	}
	else if (rotate == 270) {
		RgbImg des_img = createRgbImg(w, h, { 0, 0, 0 });
		for (size_t x = 0; x < w; x++)
		{
			for (size_t y = 0; y < h; y++)
			{
				des_img.pixels[x][h - 1 - y] = src_img.pixels[y][x];
			}
		}
		writeRgbImg(destination, des_img);
		deleteRgbImg(src_img);
		deleteRgbImg(des_img);
	}
}


void to_grayscale(char* source = (char*)"data\\sinichka.bmp", char* destination = (char*)"data\\sinichka_grayscale.bmp") {
	RgbImg src_img = readRgbImg(source);
	int h = src_img.height, w = src_img.width;

	RgbImg des_img = createRgbImg(h, w, { 0, 0, 0 });
	for (size_t x = 0; x < w; x++)
	{
		for (size_t y = 0; y < h; y++)
		{
			unsigned char avg = (src_img.pixels[y][x].Red + src_img.pixels[y][x].Green + src_img.pixels[y][x].Blue) / 3;
			des_img.pixels[y][x].Red = avg;
			des_img.pixels[y][x].Green = avg;
			des_img.pixels[y][x].Blue = avg;

		}
	}
	writeRgbImg(destination, des_img);
	deleteRgbImg(src_img);
	deleteRgbImg(des_img);
}

void sharpen_img(char* source = (char*)"data\\kidsnoise.bmp", char* destination = (char*)"data\\kidsnoise_sharpened.bmp") {
	RgbImg src_img = readRgbImg(source);

	double** kernel_blur = new double* [5];
	for (size_t row = 0; row < 5; ++row)
	{
		kernel_blur[row] = new double[5];
		for (size_t col = 0; col < 5; ++col)
			kernel_blur[row][col] = 1.;
	}
	RgbImg des_img = convolution(src_img, 5, kernel_blur);
	double** kernel_sharpen = new double*[3];
	kernel_sharpen[0] = new double[3]{ 0, -1., 0 };
	kernel_sharpen[1] = new double[3]{ -1. , 5, -1. };
	kernel_sharpen[2] = new double[3]{ 0, -1, 0 };


	des_img = convolution(des_img, 3, (double**)kernel_sharpen);

	for (size_t i = 0; i < 3; i++)
		delete [] kernel_sharpen[i];
	delete [] kernel_sharpen;

	for (size_t i = 0; i < 5; i++)
		delete [] kernel_blur[i];
	delete [] kernel_blur;

	writeRgbImg(destination, des_img);
	deleteRgbImg(src_img);
	deleteRgbImg(des_img);
}


int max(int a, int b) {
	return (a >= b) ? a : b;
}

int min(int a, int b) {
	return (a >= b) ? b : a;
}


unsigned char get_median(unsigned char arr[], int n) {
	std::sort(arr, arr + n);

	if (n % 2 != 0)
		return arr[n / 2];

	return (arr[(n - 1) / 2] + arr[n / 2]) / 2;
}

void median_filtering(char* source = (char*)"data\\kidsnoise.bmp", char* destination = (char*)"data\\kidsnoise_median.bmp", int n = 3) {
	if (n == 0) {
		RgbImg src_img = readRgbImg(source);
		writeRgbImg(destination, src_img);
		deleteRgbImg(src_img);
		return;
	}
	else if (n <= 0)
		return;

	RgbImg src_img = readRgbImg(source);
	int h = src_img.height, w = src_img.width;
	RgbImg dest_img = createRgbImg(h, w, { 0, 0, 0 });


	for (size_t x = 0; x < w; x++)
	{
		for (size_t y = 0; y < h; y++)
		{
			int s = (min(w - 1, x + n / 2) - max(0, x - n / 2) + 1) * (min(h - 1, y + n / 2) - max(0, y - n / 2) + 1);
			unsigned char* window_r = new unsigned char[s];
			unsigned char* window_g = new unsigned char[s];
			unsigned char* window_b = new unsigned char[s];

			int counter = 0;
			for (size_t x_ = max(0, x - n / 2); x_ <= min(w - 1, x + n / 2); x_++)
			{
				for (size_t y_ = max(0, y - n / 2); y_ <= min(h - 1, y + n / 2); y_++, counter++)
				{
					window_r[counter] = src_img.pixels[y_][x_].Red;
					window_g[counter] = src_img.pixels[y_][x_].Green;
					window_b[counter] = src_img.pixels[y_][x_].Blue;
				}
			}
			dest_img.pixels[y][x].Red = get_median(window_r, s);
			dest_img.pixels[y][x].Green = get_median(window_g, s);
			dest_img.pixels[y][x].Blue = get_median(window_b, s);
			delete [] window_r;
			delete [] window_g;
			delete [] window_b;
		}
	}
	writeRgbImg(destination, dest_img);
	deleteRgbImg(src_img);
	deleteRgbImg(dest_img);
}

int main()
{
	try
	{
		median_filtering();
	}
	catch (std::exception const& e)
	{
		std::cout << "Error: " << e.what() << "\n";
		return -1;
	}
	return 0;
}
