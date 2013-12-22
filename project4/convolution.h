#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>


using namespace std;

class Convolution {
 public:
 
	Convolution()
	{
		k_dim = 3;
		
		image_size=0;
	};
	~Convolution(){};
	
	void calculateConvolution(char * inputFile, char * outputFile);

	
private:
	void convolution();

	//structure defines bitmap header
	struct BITMAPFILEHEADER{
	   unsigned short type;//type of file (bit map)
	   unsigned long size;//size of file
	   unsigned short reserved1;//
	   unsigned short reserved2;//
	   unsigned long offsetbits;//off set bits
	};

	struct BITMAPINFOHEADER{
	   unsigned long size;//bitmap size
	   unsigned long width;//width of bitmap
	   unsigned long height;//hight of bitmap
	   unsigned short planes;
	   unsigned short bitcount;
	   unsigned long compression;// compression ratio (zero for no compression)
	   unsigned long sizeimage;//size of image
	   long xpelspermeter;
	   long ypelspermeter;
	   unsigned long colorsused;
	   unsigned long colorsimportant;
	};

	struct SINGLE_PIXEL{
	   unsigned char pixel;
	};

	long int image_size; //number of pixels to read

	BITMAPFILEHEADER source_head;//to store file header
	BITMAPINFOHEADER source_info;//to store bitmap info header

	FILE *fp;//file pointer for source file
	FILE *Dfp;//file pointer for destination file
	
	char *Input_FILE_NAME ;
	char *Output_FILE_NAME ;

	int k_dim ; //kernel matrix dimention -  - for a 3X3 kernel k_dim will be 3
	int dim ; //image dimention - for a 512X512 image dim will be 512

	//kernel matrix
	float kernel[3 * 3] ; 
	//image data matrix
	char pixels[3000*3000 *sizeof(struct SINGLE_PIXEL)]; 
	
	
void readImage(char * inputFile, char * outputFile)
	{
		if(!(fp=fopen(inputFile,"rb")))//open in binary read mode
		{
			printf("\ncan not open file");//prind and exit if file open error
			exit(-1);
		}
		//read the headers to source file
		fread(&source_head,sizeof(struct BITMAPFILEHEADER),1,fp);
		fread(&source_info,sizeof(struct BITMAPINFOHEADER),1,fp);

		Dfp=fopen(outputFile,"wb");//open in binary write mode

		//write the headers to destination file
		fwrite(&source_head,sizeof(struct BITMAPFILEHEADER),1,Dfp);
		fwrite(&source_info,sizeof(struct BITMAPINFOHEADER),1,Dfp);

		//calculate the number of pix to read
		//read picture dimention from file info in file header
		dim = (int) source_head.reserved2;
		image_size = dim * dim;

		fread(&pixels, image_size*sizeof(struct SINGLE_PIXEL),1,fp);
	};
	

void writeImage()
	{
		fwrite(&pixels,(image_size+968)*sizeof(struct SINGLE_PIXEL),1,Dfp);	
		fclose(fp);
		fclose(Dfp);
	};

};


