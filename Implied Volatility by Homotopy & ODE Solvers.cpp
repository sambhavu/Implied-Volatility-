const double S = 60; 
const double K = 65;
const double r = 0.08;
const double b = r;
const double T = .25;
const double sig = .3;

value_type marketValue = 2.1333;

value_type Function(state_type x)
{
   
    value_type tmp = x[0] * std::sqrt(T); 

    value_type d1 = (std::(log(S/K)+(b+x[0]*x[0]*.5)*T) /temp;

    value_type d2 = d1-temp;

    return (S*exp((b-r)*T)*N(d1)-K*exp(-r*T)*N(d2))-marketValue;

} 


value_type FunctionDeriv(state_type x)
{
     value_type tmp = x[0] * std::sqrt(T); 

     value_type d1 = (std::(log(S/K)+(b+x[0]*x[0]*.5)*T) /temp;
     
     return S* std::exp((b-r)*T)*n(d1)*std::sqrt(T);

} 



class Davidenko{
private:
    state_type x0; 

public:
    Davidenko(state_type guess): x0(guess) {}

    void operator() (const state_type &x, state_type& dxdt, 
                     const value_type t)
    {
        dxdt[0] = -Function(x0)/FunctionDeriv(x);

    }

}; 


//test program below: 

typedef double value_type;
typedef std::vector<value_type> state_type;

int main() 
{


   namespace Bode = boost::numeric::odeint; 
   
   //initial condition

   state_type x(1.0,0.0);
   x[0]=.113;

   Davidenko ode(x); 

   value_type L = 0;
   value_type U = 1.0;
   value_type dt= 1.0e-9;

   std::size_t steps = Bode::integrate(ode, x,L,U,dt); 
   std::cout<<"Value from 101 Integrator: " 
            <<std::setprecision(8) << x[0] <<std::endl; 
   Bode::runge_kutta_dopri5<state_type, value_type> MyStepper;

   x[0] = .113;
   dt = 1.0e-1;
   int n= static_cast<int> ((U-L)/dt);

   steps = Bode::integrate_n_steps(MyStepper, ode, x, L, dt, n);
   std::cout<<"Value from n steps: "<< x[0] << std::endl;

return 0;

}


