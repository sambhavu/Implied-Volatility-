
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
