#include <stdio.h> 


char stocks[0][4]; 

stocks[0][0] ="AAPL";
stocks[0][1] = "GOOG";
stocks[0][2] = "CLDR";
stocks[0][3] = "AMZN";


struct underlying{

	char[4] ticker; 

	double price;
	double strike; 
	double t; 
	double r; 
	double iv; 

	double delta;
	double gamma; 
	double theta; 
	double vega; 
	double rho;

	int type; 


};

int main()
{
	char[4] asset; 
	underlying option; 

	for( int i = 0; i<4; i++)
	{
		double pricestep = 1;
		double timestep = -5; 
		double ivstep = .07;

		asset = stocks[0][i];
		option.ticker = asset; 
		for(int j = 0; j<3; j++)
		{
			option.ticker = asset;
			option.price = 100.12235+ (pricestep*j);
			option.strike = 100; 
			option.t = 30 + (timestep*j); 
			option.iv = .25 + (ivstep*j); 

			printf("Underlying.......... %c", option.ticker,"\n");
			printf("Underlying Price.... %f", option.price, "\n");
			printf("Option Strike....... %f", option.strike, "\n");
			printf("Option Time to exp.. %f", option.t, "\n");
			printf("Option Implied Vol.. %f", option.iv, "\n\n");
		}

	

	}

	return 0;
}
