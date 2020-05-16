#include <iostream>
#include <algorithm> 
#include <cmath> 
using namespace std; 

#ifndef Pi 
#define Pi 3.141592653589793238462643 
#endif 


class option{
public:
     
     double und, strike, rf, sig_guess, t, CP; //CP call price  
     int type; //0 for call, 1 for put 
     double sig; 
     int it=0; //iterations 
     
     option(); 

     double call_price(double S, double K, double r, double sigma, double time);
     double put_price(double S, double K, double r, double sigma, double time); 
     double cnd(double x);

     void search(); 
     double call_search(); 
     double put_search(); 

     void display_parameters(); 
     void display_results(); 

}; 

option::option()
{
     CP = 2.282;
     und=50;
     strike=52;
     rf=.03;
     sig_guess=.01;
     t=.5;

     type=0; 
}

double option::call_search()
{
    double sig_est = sig_guess; 
    double price; 
    double ERROR =.0001; 
    
    
    do{ 

       price=call_price(und,strike,rf,sig_est,t); 

      if(price<CP-ERROR) 
      {
         sig_est+=ERROR; 
      } 

      else{
         sig_est-=ERROR; 
      } 

       it++; 

    }while(price<CP-ERROR || price>CP+ERROR); 

    return sig_est; 


}



double option::put_search()
{
    double sig_est = sig_guess; 
    double price; 
    double ERROR =.00001; 
    
    do{ 

       price=put_price(und,strike,rf,sig_est,t); 

      if(price<CP-ERROR) 
      {
         sig_est+=ERROR; 
      } 

      else{
         sig_est-=ERROR; 
      } 

       it++; 

    }while(price<CP-ERROR || price>CP+ERROR);

    return sig_est; 


}



void option:: search()
{

   if(type==0)
   {
     cout<<"\nSearching......      ";
     sig=call_search(); 
     cout<<"Found\n"; 
     
   } 
   else{
   	 cout<<"\nSearching......      ";
     sig=put_search(); 
     cout<<"Found\n"; 
     
   } 
}

void option:: display_parameters()
{
  if(type == 0) 
   {
     cout<<"Call\n"; 
   } 
   else { 
     cout<<"Put\n"; 
    } 

    cout<<"\nUnderlying Price    -> "<<und;
    cout<<"\nStike Price         -> "<<strike;
    cout<<"\nTime to Exp         -> "<<t<<" years";
    cout<<"\nRisk free rate      -> "<<rf*100<<"%";
    cout<<"\n";
    cout<<"\nGuess Volatility    -> "<<sig_guess*100<<"%"; 


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

void option::display_results() 
{ 
	cout<<"\nImplied Vol Est:    -> "<<sig*100<<"%"; 
	
	cout<<"\nIterations taken    -> "<<it<<" iterations"; 
	
} 


int main()

{

option iv_finder;

iv_finder.display_parameters();
iv_finder.search(); 
iv_finder.display_results(); 
	
cout<<"\n\nend";

return 0; 


}
