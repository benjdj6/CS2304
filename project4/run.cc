#include "convolution.cc"
#include <cstdlib>
#include <stdio.h>

int main(int argc, char** argv) 
{

	char in[] = "1.bmp";
	char out[] = "1_out.bmp";
	Convolution newConv;
	newConv.calculateConvolution(in, out);

	char in2[] = "2.bmp";
	char out2[] = "2_out.bmp";
	Convolution newConv2;
	newConv2.calculateConvolution(in2, out2);

	char in4[] = "lena512.bmp";
	char out4[] = "lena512_out.bmp";
	Convolution newConv4;
	newConv4.calculateConvolution(in4, out4);

	return 0;
}
