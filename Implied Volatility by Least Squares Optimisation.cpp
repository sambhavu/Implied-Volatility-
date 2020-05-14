//standard interface 
using IPricingFunction = std::functiom<double(double sig)>;

class ImpliedVolatilityEstimator
{
 private:
    double mp;                     //market price 
    IPricingFunction pricer        //call or put price
 public:
    ImpliedVolatilityEstimator(double marketprice,  const IPricingFunction& optionpricer)
             :mp(marketprice), pricer(optionpricer){}
    
    double operator()(double sig) const 
   { //compute residual
     double CalculatedValue = pricer(sig); 
     double d = -mp + CalculatedValue;
     return d*d; 
   } 

}; 


class Pricer{
  private:
    OptionData opt;
    
  public:
    Pricer(const OptionData& optionData):opt(optionData) {}
    
   double PutPrice(double sig) const
   {
       double temp = sig* std::sqrt(opt.T); 
      
       double d1 = (std::log(opt.S/opt.K) + (opt.b + (sig*sig)*.5)*opt.T)/temp;
      
       double d2 = d1 - temp;

       return opt.K*std::exp(-opt.r*opt.T)*N(-d2) - opt.S*std::exp((opt.b-opt.r)*opt.T)*N(-d1); 

   } 


   double CallPrice(double sig) const
  {
       double temp = sig*std::sqrt(opt.T); 

       double d1 = (std::log(opt.S/opt.K) + (opt.b + (sig*sig)*.5)*opt.T) / temp;
      
       double d2 = d1 - temp;

       return opt.S * std::exp((opt.b-opt.r)*opt.T)*N(d1)- opt.K*exp(-opt.r*opt.T)*N(d2); 

  }


  double Vega(double sig) const
  {
     double temp = sig* std::sqrt(opt.T); 

     double d1 = (std::log(opt.S/opt.K)+(opt.b+(sig*sig)*.5)*opt.T)/temp; 

     return opt.S* std::exp((opt.b-opt.r)*opt.T)*n(d1)*std::sqrt(opt.T); 

  } 


  double DVegaDVol(double sig) const
  {  //needed in Halleys and Schroeders Method 

     double temp = sig* std::sqrt(opt.T); 

     double d1 = (std::log(opt.S/opt.K)+(opt.b+(sig*sig)*.5)*opt.T)/temp;

     double d2 = d1 - temp;

     return (Vega(sig)*d1*d2)/sig;

  } 


};





