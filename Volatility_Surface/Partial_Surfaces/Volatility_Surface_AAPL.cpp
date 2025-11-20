#include<iostream> 
#include<cmath> 
#include<vector> 
using namespace std; 


#ifndef Pi 
#define Pi 3.141592653589793238462643 
#endif 

const double p1[17]=
{
	28.08,
	25.68,
	23.43,
	21.18,
	18.68,
	16.48,
	14.35,
	12.33,
	10.43,
	8.58,
	6.8,
	5.35,
	4.00,
	2.89,
	2.01,
	1.35,
	.88
	
};

const double p2[17]=
{
	29.05,
	26.78,
	24.35,
	22.38,
	20.05,
	17.95,
	15.88,
	14.03,
	12.15,
	10.43,
	8.78,
	7.25,
	5.98,
	4.73,
	3.68,
	2.8,
	2.09
};

const double p3[17]=
{
	30.00,
	27.8,
	25.65,
	23.38,
	21.38,
	19.45,
	17.45,
	15.83,
	14.18,
	12.4,
	10.63,
	9.13,
	7.78,
	6.58,
	5.38,
	4.43,
	3.5
	
};

const double p4[17]=
{
	30.85,
	28.95,
	26.9,
	24.88,
	22.83,
	20.68,
	18.93,
	17.2,
	15.4,
	13.78,
	12.25,
	10.7,
	9.4,
	8.1,
	7.00,
	5.88,
	4.93
	
};

const double p5[17]=
{
	32.05,
	29.88,
	27.85,
	25.91,
	24.03,
	23.00,
	20.18,
	18.34,
	16.8,
	15.8,
	13.55,
	12.17,
	10.65,
	9.37,
	8.13,
	6.99,
	6.03
	
};

const double p6[17]
{
	33.13,
	31.00,
	28.95,
	27.08,
	25.23,
	23.15,
	21.33,
	19.78,
	18.13,
	16.5,
	14.78,
	13.45,
	11.9,
	10.65,
	9.38,
	8.2,
	7.15
	
};


class option{

public:
     double call_price(double S, double K, 
                           double r, double sigma, double time); 
     double put_price(double S, double K,
                            double r, double sigma, double time); 

     double cnd(double x); 
     double normdist(double x); 
     void greeks(double S, double K, double r, double sigma, double time); 
 
     double delta;
     double gamma;
     double theta; 
     double vega; 
     double rho; 

     double U    = 307.7;

     double K_s  =  280;    //start strike
     double t_s  = .008;     //start time
 
     double r=.08; 
     double iv;             //forecast variable
 
     double K_end    =    320; 
     double t_end    =    .108;
     double t_step	 =    .02;
     double K_step   =    2.5  ;   //strike step

     int it; 
 
     void Volatility_Surface(); 
 
     vector<vector<double>> model; 
 
     double call_search(double CP, double S, double K, double r, double time); 


}; 


void option::Volatility_Surface()
{
   
   double strike=K_s; 
   double t=t_s;
   double call_val; 
   
   int count=0; 
   int i; 

   vector<double> values; 

   while(t<=t_end)
   {
   	   strike=K_s;
   	   
   	   values.clear(); 
   	   i=0;
   	   
   	   while(strike<=K_end)
   	   {
   	   
   	   	 if(count==0)
   	   	 {
   	   	 	 call_val=p1[i]; 
   	   	 	 //cout<<"here\n";
   	   	 }
   	   	 
   	   	 else if(count==1)
   	   	 {
   	   	 	call_val=p2[i]; 
   	   	 	
   	   	 } 
   	   	 
   	   	 else if(count==2)
   	   	 {
   	   	 	call_val=p3[i];
   	   	 	
   	   	 }
   	   	 
   	   	 else if(count==3)
   	   	 {
   	   	 	call_val=p4[i]; 
   	   	 }
   	   	 
   	   	 else if(count==4)
   	   	 {
   	   	 	call_val=p5[i];
   	   	 }
   	   	 
   	   	 else if(count==5)
   	   	 {
   	   	 	call_val=p6[i]; 
   	   	 }
   	   	  
   	   	 i++; 
   	   	 
   	   	 
   	   	 iv=call_search(call_val, U, strike, r, t); 

   	   	 values.push_back(iv); 
   	   	 
   	   	 strike=strike+K_step; 
   	  } 
   	  // cout<<"found one \n"; 
   	   	 
   	  model.push_back(values); 
   	  t=t+t_step; 
   	  count++;
   	  
   	   
   } 
   
  
   
   
   
   //Print Model 
   
   vector<double> thi;
   int size, size2; 
   thi=model[0]; 
   size=thi.size(); 
   size2=model.size();
   
   for(int a=size2-1; a>=0; a--) 
   {
   
         for(int i=0; i<size; i++)
   	     { 
   	     	  thi.clear(); 
              thi=model[a]; 
              cout<<thi[i]<<", ";
              
         } 
         
         cout<<"\n";
   	       
   } 

}



double option :: call_price(
                            double S,
                            double K,
                            double r,
                            double sigma,
                            double time)
{
        
        double time_sqrt = sqrt(time);
        
        
       /* double d1 = (log(S/K)+r*time)/(sigma*time_sqrt)+.5*sigma*time_sqrt; */
        
        double d1 = (log(S/K) + (r+sigma*sigma*.5)*time)/(sigma*time_sqrt);
       
       
       
        double d2 = d1-(sigma*time_sqrt);
        
        double price = S*cnd(d1)-K*exp(-r*time)*cnd(d2);
        
        return price; 
}
 


double option :: put_price(
                            double S,
                            double K,
                            double r,
                            double sigma,
                            double time)
{
        
        double time_sqrt = sqrt(time);
        
        
       /* double d1 = (log(S/K)+r*time)/(sigma*time_sqrt)+.5*sigma*time_sqrt; */
        
        double d1 = (log(S/K) + (r+sigma*sigma*.5)*time)/(sigma*time_sqrt);
       
        double d2 = d1-(sigma*time_sqrt);
        
        double price = -S*cnd(-d1)+K*exp(-r*time)*cnd(-d2);
        
        return price; 
    }
    

    
double option:: cnd(double x)
{
  double L, K, w ;
  /* constants */
  double const a1 = 0.31938153, a2 = -0.356563782, a3 = 1.781477937;
  double const a4 = -1.821255978, a5 = 1.330274429;

  L = fabs(x);
  K = 1.0 / (1.0 + 0.2316419 * L);
  w = 1.0 - 1.0 / sqrt(2 * Pi) * exp(-L *L / 2) * (a1 * K + a2 * K *K + a3 * pow(K,3) + a4 * pow(K,4) + a5 * pow(K,5));

  if (x < 0 ){
    w= 1.0 - w;
  }
  return w;
}


double option:: normdist(double x)
{
    double num = 0;
    double w1 = 0;
    double w2 = 0;
    
    w1 = (1/sqrt(2*Pi));
    w2 = exp(-.5*x*x);
    
    num = w1*w2; 
    
    return num;
}





void option :: greeks(
                        double S,
                        double K,
                        double r, 
                        double sigma,
                        double time
                                      ) 
                        
    {
        double time_sqrt = sqrt(time);
        double d1 = ((log(S/K)+r*time)/(sigma*time_sqrt)) + 0.5*sigma*time_sqrt;
        double d2 = d1-(sigma*time_sqrt);
        delta = cnd(d1);
        gamma = normdist(d1)/(S*sigma*time_sqrt);
        theta =- (S*sigma*normdist(d1))/(2*time_sqrt) - r*K*exp(-r*time)*cnd(d2);
        vega = S*time_sqrt*normdist(d1);
        rho = K*time*exp(-r*time)*cnd(d2);
        
    }


    
double option::call_search(double CP, double S, double K, double r, double time)
{
	
	double und= S;
	double strike=K;
	double rf=r;
	
    double sig_est =.04; 
    
    double t=time;
    
    double price; 
    double ERROR =.01; 
    
    
    do{ 

       price=call_price(und,strike,rf,sig_est,t); 

      if(price<CP-ERROR) 
      {
         sig_est+=.00001; 
      } 

      else{
         sig_est-=.00001; 
      } 

       it++; 

    }while(price<CP-ERROR || price>CP+ERROR); 

    return sig_est; 


}


int main() 
{

   option call;
   call.Volatility_Surface();



return 0; 
}
