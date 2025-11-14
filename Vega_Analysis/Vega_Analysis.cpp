#include<iostream> 
#include<cmath> 
#include<vector> 
using namespace std; 



#ifndef Pi 
#define Pi 3.141592653589793238462643 
#endif 

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

     double U = 100;
     double iv_s = .1;  
     double t=.5; 
     double r=.03; 
     double srike = 100;
     double iv=.25; 
     double iv_end= .5; 
     double iv_step=.02;   //vol step

     
     void Vega_Analysis(); 

}; 


void option::Vega_Analysis()
{
   
   double impliedvol = iv_s; 


   while(impliedvol<=iv_end) 
   { 
         greeks(U, strike, r, iv, t); 
         //cout<<strike<<", ";
         cout<<vega<<"\n"; 
         
         impliedvol=impliedvol+k_step; 

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




int main() 
{

   option call;
   call.Vega_Analysis();



return 0; 
}
