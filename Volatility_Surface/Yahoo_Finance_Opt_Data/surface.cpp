#include<iostream> 
#include<cmath> 
#include<vector> 
#include<cstdlib> 
#include<conio.h> 

using namespace std; 


#ifndef Pi 
#define Pi 3.141592653589793238462643 
#endif 

const double s1[]=
{
	125.00,
150.00,
155.00,
160.00,
165.00,
170.00,
190.00,
195.00,
200.00,
205.00,
210.00,
220.00,
225.00,
227.50,
230.00,
232.50,
235.00,
237.50,
240.00,
242.50,
245.00,
247.50,
250.00,
252.50,
255.00,
257.50,
260.00,
262.50,
265.00,
267.50,
270.00,
272.50,
275.00,
277.50,
280.00,
282.50,
285.00,
287.50,
290.00,
292.50,
295.00,
297.50,
300.00,
302.50,
305.00,
307.50,
310.00,
312.50,
315.00,
317.50,
320.00,
322.50,
325.00,
330.00,
335.00,
340.00,
345.00,
350.00,
355.00,
360.00,
365.00,
370.00,
375.00,
380.00
	
	
};


const double s2[]=
{
	140.00,
160.00,
165.00,
175.00,
185.00,
190.00,
195.00,
200.00,
205.00,
210.00,
215.00,
220.00,
225.00,
230.00,
235.00,
240.00,
242.50,
245.00,
247.50,
250.00,
252.50,
255.00,
257.50,
260.00,
262.50,
265.00,
267.50,
270.00,
272.50,
275.00,
277.50,
280.00,
282.50,
285.00,
287.50,
290.00,
292.50,
295.00,
297.50,
300.00,
302.50,
305.00,
307.50,
310.00,
312.50,
315.00,
317.50,
320.00,
322.50,
325.00,
330.00,
335.00,
340.00,
345.00,
350.00,
355.00,
360.00,
365.00,
370.00,
375.00,
380.00,
385.00,
390.00	
	
};


const double s3[]=
{
	145.00,
160.00,
190.00,
195.00,
200.00,
205.00,
210.00,
220.00,
225.00,
230.00,
235.00,
240.00,
245.00,
250.00,
252.50,
255.00,
257.50,
260.00,
262.50,
265.00,
267.50,
270.00,
272.50,
275.00,
277.50,
280.00,
282.50,
285.00,
287.50,
290.00,
292.50,
295.00,
297.50,
300.00,
302.50,
305.00,
307.50,
310.00,
312.50,
315.00,
317.50,
320.00,
322.50,
325.00,
330.00,
335.00,
340.00,
345.00,
350.00,
355.00,
360.00,
365.00,
370.00,
375.00,
380.00,
385.00
	
}; 

const double s4[]= 
{
	180.00,
185.00,
200.00,
240.00,
245.00,
250.00,
260.00,
262.50,
265.00,
267.50,
270.00,
272.50,
275.00,
277.50,
280.00,
282.50,
285.00,
287.50,
290.00,
292.50,
295.00,
297.50,
300.00,
302.50,
305.00,
307.50,
310.00,
312.50,
315.00,
317.50,
320.00,
322.50,
325.00,
330.00,
335.00,
340.00,
345.00,
350.00,
355.00,
360.00,
365.00,
370.00,
375.00,
380.00,
385.00,
390.00
	
};

const double s5[]=
{
	75.00,
80.00,
85.00,
90.00,
95.00,
100.00,
105.00,
110.00,
115.00,
120.00,
125.00,
130.00,
135.00,
140.00,
145.00,
150.00,
155.00,
160.00,
165.00,
170.00,
175.00,
180.00,
185.00,
190.00,
195.00,
200.00,
205.00,
210.00,
215.00,
220.00,
225.00,
230.00,
235.00,
240.00,
245.00,
250.00,
255.00,
260.00,
265.00,
270.00,
275.00,
280.00,
285.00,
290.00,
295.00,
300.00,
305.00,
310.00,
315.00,
320.00,
325.00,
330.00,
335.00,
340.00,
345.00,
350.00,
355.00,
360.00,
365.00,
370.00,
375.00,
380.00,
385.00,
390.00,
395.00,
400.00,
405.00,
410.00,
420.00,
430.00,
440.00,
450.00,
460.00,
470.00,
480.00,
490.00,
500.00,
	
};


const double s6[]=
{
	200.00,
230.00,
235.00,
240.00,
250.00,
255.00,
260.00,
265.00,
270.00,
275.00,
277.50,
280.00,
282.50,
285.00,
287.50,
290.00,
292.50,
295.00,
297.50,
300.00,
302.50,
305.00,
307.50,
310.00,
312.50,
315.00,
317.50,
320.00,
322.50,
325.00,
330.00,
335.00,
340.00,
345.00,
350.00,
355.00,
360.00,
365.00,
370.00,
375.00,
380.00,
385.00
	
};

const double p1[]=
{
	183.05,
153.03,
150.90,
118.07,
138.05,
95.65,
84.64,
119.65,
107.25,
113.05,
108.59,
83.36,
78.12,
75.72,
76.70,
71.01,
68.54,
65.71,
78.50,
67.70,
74.60,
55.77,
62.00,
50.78,
49.80,
52.08,
43.82,
45.00,
42.11,
35.60,
37.40,
40.70,
36.75,
34.80,
31.70,
29.66,
26.45,
20.99,
22.00,
20.45,
17.93,
15.62,
13.50,
11.25,
9.40,
7.43,
5.67,
4.18,
3.06,
2.11,
1.36,
0.89,
0.58,
0.25,
0.12,
0.07,
0.05,
0.03,
0.03,
0.03,
0.02,
0.02,
0.01,
0.01,
	
};

const double p2[]=
{
	160.79,
113.01,
108.46,
106.01,
118.35,
117.80,
108.28,
107.00,
98.11,
79.60,
75.48,
82.99,
78.19,
76.13,
68.14,
63.00,
53.45,
58.24,
42.88,
56.38,
50.81,
50.85,
46.16,
46.00,
53.80,
42.15,
44.15,
42.80,
40.27,
36.90,
30.40,
33.24,
30.01,
28.25,
25.19,
23.34,
19.90,
18.40,
16.05,
14.00,
12.85,
11.10,
9.40,
7.13,
6.00,
4.85,
3.75,
2.77,
1.98,
1.41,
0.69,
0.31,
0.19,
0.12,
0.08,
0.06,
0.07,
0.07,
0.05,
0.05,
0.07,
0.03,
0.05,
	
};

const double p3[]=

{
	152.40,
141.75,
113.01,
94.63,
102.99,
102.35,
101.41,
85.46,
84.71,
82.92,
72.17,
71.05,
63.33,
55.82,
42.00,
58.83,
50.90,
46.00,
55.63,
42.16,
38.63,
36.84,
36.09,
31.50,
30.42,
29.69,
32.42,
29.50,
21.43,
24.41,
22.00,
20.00,
18.15,
15.63,
14.60,
12.82,
11.02,
9.34,
7.78,
6.55,
5.30,
4.30,
3.08,
2.54,
1.45,
0.75,
0.44,
0.28,
0.18,
0.14,
0.15,
0.13,
0.10,
0.10,
0.06,
0.09
	
}; 

const double p4[] =

{
	
	123.29,
117.60,
103.13,
67.42,
71.30,
67.80,
49.81,
52.55,
42.66,
47.20,
44.86,
44.25,
33.55,
41.86,
29.80,
30.00,
25.75,
23.87,
25.58,
19.70,
21.70,
19.14,
17.24,
15.75,
14.20,
12.50,
10.90,
9.45,
7.82,
6.90,
5.57,
4.57,
3.50,
2.39,
1.48,
0.87,
0.53,
0.37,
0.27,
0.20,
0.19,
0.11,
0.14,
0.15,
0.13,
0.12
	
};

const double p5[]=
{
	228.67,
223.29,
218.65,
214.80,
208.70,
213.00,
198.30,
193.67,
188.30,
188.48,
178.35,
175.00,
168.75,
169.94,
160.50,
153.50,
150.10,
151.50,
143.38,
134.50,
138.00,
132.00,
131.22,
126.56,
121.20,
103.37,
101.86,
97.30,
88.76,
83.14,
76.93,
82.85,
69.55,
64.54,
66.15,
59.15,
53.50,
54.00,
48.50,
43.35,
40.62,
34.25,
30.85,
26.85,
22.70,
19.10,
15.40,
12.32,
9.45,
6.95,
4.85,
3.25,
2.07,
1.31,
0.84,
0.55,
0.34,
0.25,
0.24,
0.17,
0.18,
0.09,
0.11,
0.06,
0.07,
0.08,
0.09,
0.04,
0.04,
0.03,
0.01,
0.03,
0.03,
0.03,
0.01,
0.08,
0.01,
	
};

const double p6[]=
{
	103.60,
84.65,
74.17,
64.32,
59.00,
62.41,
48.95,
49.11,
46.50,
36.61,
34.15,
37.15,
34.48,
28.60,
25.74,
28.72,
26.00,
24.50,
17.49,
21.00,
19.48,
17.74,
15.55,
14.30,
13.00,
11.50,
10.05,
8.75,
7.70,
6.60,
4.80,
3.30,
2.23,
1.42,
0.99,
0.64,
0.46,
0.30,
0.26,
0.20,
0.15,
0.13
	
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
     double vanna;
     double volga; 

     const double U    = 307.7;

     double K_s  =  75.00;    //start strike
     double t_s  = .008;     //start time
 
     const double r=.03; 
     double iv;             //forecast variable
 
     double num_weeks = 6;
     double K_end    =    500; 
     double t_step	 =    .02;
     double t_end    =    num_weeks*t_step;
     double K_step   =    2.5 ;   //strike step

     int it; 
 
     void Volatility_Surface(); 
 
     vector<vector<double>> model; 
 
     double call_search(double CP, double S, double K, double r, double time); 
 
    int find_n(double K); 
    int count=0; 
     

}; 


void option::Volatility_Surface()
{
   
   double strike=K_s; 
   double t=t_s;
   double call_val; 
   double strike_test; 
   
   int i; 

   vector<double> values; 
   
   double dir, change; 

   while(t<=t_end)
   {
   	   strike=K_s;
   	   
   	   values.clear(); 
   	   i=0;
   	   
   	   while(strike<=K_end)
   	   {
   	   
   	   	 if(count==0)
   	   	 {
   	   	 	 i=find_n(strike); 
   	   	 	 if(i != 1000) 
   	   	 	 {
   	   	 	 	call_val=p1[i]; 
   	   	 	 	iv=call_search(call_val, U, strike, r, t); 

   	   	        values.push_back(iv); 
   	   	 	 	cout<<"here\n";
   	   	 	 }
   	   	 	 
   	   	 	 else{
   	   	 	 	values.push_back(0); 
   	   	 	 	cout<<"here3\n";
   	   	 	 	
   	   	 	 	
   	   	 	 } 
   	   	 	 
   	   	 }
   	   	 
   	   	 else if(count==1)
   	   	 {
   	   	 	 i=find_n(strike); 
   	   	 	 if(i != 1000) 
   	   	 	 {
   	   	 	 	call_val=p2[i]; 
   	   	 	 	iv=call_search(call_val, U, strike, r, t); 

   	   	        values.push_back(iv); 
   	   	        cout<<"here2\n";
   	   	 	 	
   	   	 	 }
   	   	 	 
   	   	 	 else{
   	   	 	 	values.push_back(0); 
   	   	 	 	
   	   	 	 	
   	   	 	 } 
   	   	 } 
   	   	 
   	   	 else if(count==2)
   	   	 {
   	   	 	
   	   	 	 i=find_n(strike); 
   	   	 	 if(i != 1000) 
   	   	 	 {
   	   	 	 	call_val=p3[i]; 
   	   	 	 	iv=call_search(call_val, U, strike, r, t); 

   	   	        values.push_back(iv); 
   	   	 	 	
   	   	 	 }
   	   	 	 
   	   	 	 else{
   	   	 	 	values.push_back(0); 
   	   	 	 	
   	   	 	 	
   	   	 	 } 
   	   	 	
   	   	 }
   	   	 
   	   	 else if(count==3)
   	   	 {
   	   	 	 i=find_n(strike); 
   	   	 	 if(i != 1000) 
   	   	 	 {
   	   	 	 	call_val=p4[i]; 
   	   	 	 	iv=call_search(call_val, U, strike, r, t); 

   	   	        values.push_back(iv); 
   	   	 	 	
   	   	 	 }
   	   	 	 
   	   	 	 else{
   	   	 	 	values.push_back(0); 
   	   	 	 	
   	   	 	 	
   	   	 	 } 
   	   	 }
   	   	 
   	   	 else if(count==4)
   	   	 {
   	   	 	 i=find_n(strike); 
   	   	 	 if(i != 1000) 
   	   	 	 {
   	   	 	 	call_val=p5[i]; 
   	   	 	 	iv=call_search(call_val, U, strike, r, t); 

   	   	        values.push_back(iv); 
   	   	 	 	
   	   	 	 }
   	   	 	 
   	   	 	 else{
   	   	 	 	
   	   	 	 	values.push_back(0); 
   	   	 	 	
   	   	 	 	
   	   	 	 } 
   	   	 }
   	   	 
   	   	 else if(count==5)
   	   	 {
   	   	 	 i=find_n(strike); 
   	   	 	 if(i != 1000) 
   	   	 	 {
   	   	 	 	call_val=p6[i]; 
   	   	 	 	iv=call_search(call_val, U, strike, r, t); 

   	   	        values.push_back(iv); 
   	   	 	 	
   	   	 	 }
   	   	 	 
   	   	 	 else{
   	   	 	 	values.push_back(0); 
   	   	 	 	
   	   	 	 	
   	   	 	 } 
   	   	 	 
   	   	 	 
   	   	 }
   	   	  
   	   	 
   	   	 
   	   	 
   	   	 
   	   	 strike=strike+K_step; 
   	   	 
   	   	 
   	    	 
   	   	 
   	  } 
   	  cout<<"found one \n"; 
   	   	 
   	  model.push_back(values); 
   	  t=t+t_step; 
   	  count++;
   	  
   	  
   	 
   	   
   } 
   
  
   
   
   clrscr();
   
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


int option::find_n(double K)
{
	vector<double> strikes; 
	strikes.clear(); 
	
	if(count==0)
	{
		for(int i=0; i<64; i++)
		{
			strikes.push_back(s1[i]);
		}
		
	} 
	
	else if(count==1)
	{
		for(int i=0; i<63; i++)
		{
			strikes.push_back(s2[i]); 
		}
	}
	else if(count==2)
	{
		for(int i=0; i<56; i++)
		{
			strikes.push_back(s3[i]); 
		}
	}
	else if(count==3)
	{
		for(int i=0; i<46; i++) 
		{
			strikes.push_back(s4[i]); 
		}
	}
	else if(count==4)
	{
		for(int i=0; i<77; i++)
		{
			strikes.push_back(s5[i]); 
		}
	}
	else if(count==5)
	{
		for(int i=0; i<42; i++)
		{
			strikes.push_back(s6[i]);
		}
	} 
	
	int size;
	size=strikes.size(); 
	
	for(int i=0; i<size; i++)
	{
		if(K==strikes[i])
		{
			return i; 
		}
	}
	
	
	return 1000;
	
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
        vanna=S*time_sqrt*normdist(d1)*(1-d1);
        volga=time_sqrt*normdist(d1)*(d1*d2/sigma); 
        
        
    }


    
double option::call_search(double CP, double S, double K, double r, double time)
{
	
	double und= S;
	double strike=K;
	double rf=r;
	
    double sig_est =.04; 
    
    double t=time;
    
    double price=0; 
    double ERROR =.05; 
    
     cout<<"sig\n";

    
    while(price<CP-ERROR || price>CP+ERROR)
    {

       price=call_price(und,strike,rf,sig_est,t); 

      if(price<CP) 
      {
         sig_est+=.0002; 
      } 

      else{
         sig_est-=.0002; 
      } 
      
      if(sig_est<0)
      {
      	sig_est=0;
      	break;
      } 

       it++; 
       //cout<<sig_est<<"\n"; 

    }
    
   
    return sig_est; 


}


int main() 
{

   option call;
   call.Volatility_Surface();



return 0; 
}
