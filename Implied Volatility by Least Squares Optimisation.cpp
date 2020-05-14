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

int main()
{

   OptionData opt;

   opt.K = 65.0;
   opt.T = .25;
   opt.r = .08;
   opt.b = opt.r;
   opt.sig = .3;
   opt.S = 60.0;

   value_type putMarketPrice = 5.8462;
   value_type callMarketPrice = 2.1333;

   auto pricer1 = std::bind(&Pricer::PutPrice, option, std::placerholders::_1);
   ImpliedVolatilityEstimator ivp1(putMarketPrice, pricer1); 

   auto pricer2 = [&option](value_type sig) {return option.CallPrice(sig); }; 
   ImpliedVolatilityEstimator ivp2(callMarketPrice, pricer2); 


   //bounds for Implied Vol 

   value_type sigL = .0023;
   value_type sigH = .9;
   value_type fL = 0.0;
   value_type fH = 0.0;

   TerminatorI<value_type> stopping(1.0e-12);
   ReportingDefault<value_type> report;
   MISDefault<int> mis;
   
  ThreePointIntervalSolver<value_type> solver1(ivp1, sigL, sigH); 
  GoldenSectionIntervalSolver<value_type> solver2(ivp2, sigL, sigH); 
  BrentIntervalSolver<value_type> solver3(ivp2, sigL, sigH); 

  Mediator<value_type> med1(ivp1, sigL, sigH, stopping, solver1, mis, repot); 
  med1.run();

  Mediator<value_type> med2(ivp2, sigL, sigH, stopping, solver2, mis, report); 
  med2.run(); 

  Mediator<value_type> med3(ivp2, sigL, sigH, stopping, solver3, mis, report); 
  med3.run(); 

}


  












