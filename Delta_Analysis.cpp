


void option :: greeks(
                        double S,
                        double K,
                        double r, 
                        double sigma,
                        double time,
                        double delta, 
                        double gamma, 
                        double theta,
                        double vega, 
                        double rho) 
                        
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
