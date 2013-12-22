#include "convolution.h"
#include "iostream"
#include <math.h>

void Convolution::convolution()
{
	ifstream file("kernel.txt");
	int j, n, o, p, q, i = 0;
	float k;
	while(file >> k)
	{
		kernel[i] = k;
		i++;
	}
	int kCenter = k_dim/2;

	for(i = 0; i < dim; i++)          
	{
    		for(j = 0; j < dim; j++)         
    		{                    
        		for(n = 0; n < k_dim; n++)
            		{
                		o = k_dim - 1 - n; 

                		p = i + (n - kCenter);
                		q = j + (n - kCenter);

                		if( p >= 0 && p < dim && q >= 0 && q < dim )
                		{	
					pixels[i*dim + j] += pixels[p*dim + q] * kernel[o*k_dim + o];
				}
      			}
        	}
    	}
}


void Convolution::calculateConvolution(char * inputFile, char * outputFile)
{
        readImage(inputFile, outputFile);

        convolution();

        writeImage();
}
