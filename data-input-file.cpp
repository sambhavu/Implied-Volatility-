#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<time.h>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

std::ifstream infile;

std::ofstream outfile;
std::ofstream writepnl;

std::ofstream writegbp;
std::ofstream writeaud;
std::ofstream writejpy;
std::ofstream writechf;
std::ofstream writenzd;
std::ofstream writecad;
std::ofstream writeeur;

std::ofstream writegbptrade;
std::ofstream writeaudtrade;
std::ofstream writejpytrade;
std::ofstream writechftrade;
std::ofstream writenzdtrade;
std::ofstream writecadtrade;
std::ofstream writeeurtrade;

double _B_A_C_E_ = 5;          /// V E R Y  H I G H  V O L U M E  T R A D I N G

bool winning = false, losing =false;
bool *win = &winning;
bool *lose = &losing;
double degree;
double *w_count = &degree;
double factor =1 ;
double *f = &factor;
double position = 0;
double p1, p2, pc;
double balance = 0;
double change;
double *AUM = &balance;
double *pnl = &change;
string instrument;
bool trading = true;
int vol_int = 750;

//GREAT BRITAIN POUND VARIABLES
std::vector<double> gbpusd;
std::vector<string> gbpusd_t;
double GBPPIP = .1/1000;
double gbpf = 1;
double *gbpfactor = &gbpf;
double gbp_pnl=0;
double *pound_pnl  = &gbp_pnl;
double gbp_test=0;
double *gbptest = &gbp_test;
int gbptime = 5;
int *gbpusdt = &gbptime;
std::string gbpsecond;
double gbpprofit_;
double *gbpprofit = &gbpprofit_;


//AUSTRALIAN DOLLAR VARIABLES
std::vector<double> audusd;
std::vector<string> audusd_t;

double AUDPIP = .1/1000;
double audf = 1.0;
double *audfactor = &audf;
double aud_pnl = 0;
double *aussie_pnl = &aud_pnl;
double aud_test = 0;
double *audtest = &aud_test;
int audtime = 5;
int *audusdt = &audtime;
std::string audsecond;
double audprofit_;
double *audprofit = &audprofit_;


//JAPANESE YEN VARIABLES
std::vector<double> usdjpy;
std::vector<string> usdjpy_t;

double JPYPIP = .09181/1000;
double jpyf = 1.0;
double *jpyfactor = &jpyf;
double jpy_pnl = 0;
double *yen_pnl = &jpy_pnl;
double jpy_test = 0;
double *jpytest = &jpy_test;
int jpytime = 5;
int *usdjpyt = &jpytime;
std::string jpysecond;
double jpyprofit_;
double *jpyprofit = &jpyprofit_;

//SWISS FRANC VARIABLES
std::vector<double> usdchf;
std::vector<string> usdchf_t;

double CHFPIP = .10405/1000;
double chff = 1.0;
double *chffactor = &chff;
double chf_pnl = 0;
double *swiss_pnl = &chf_pnl;
double chf_test = 0;
double *chftest = &chf_test;
int chftime = 5;
int *usdchft = &chftime;
std::string chfsecond;
double chfprofit_;
double *chfprofit = &chfprofit_;

//NEW ZEALAND DOLLAR VARIABLES
std::vector<double> nzdusd;
std::vector<string> nzdusd_t;

double NZDPIP = .1/1000;
double nzdf = 1.0;
double *nzdfactor = &nzdf;
double nzd_pnl = 0;
double *nzdollar_pnl = &nzd_pnl;
double nzd_test = 0;
double *nzdtest = &nzd_test;
int nzdtime = 5;
int *nzdusdt = &nzdtime;
std::string nzdsecond;
double nzdprofit_;
double *nzdprofit = &nzdprofit_;

//CANADIAN DOLLAR VARIABLES
std::vector<double> usdcad;
std::vector<string> usdcad_t;

double CADPIP = .07409/1000;
double cadf = 1.0;
double *cadfactor = &cadf;
double cad_pnl = 0;
double *caddollar_pnl = &cad_pnl;
double cad_test = 0;
double *cadtest = &cad_test;
int cadtime = 5;
int *usdcadt = &cadtime;
std::string cadsecond;
double cadprofit_;
double *cadprofit = &cadprofit_;

//EURO VARIABLES
std::vector<double> eurusd;
std::vector<string> eurusd_t;

double EURPIP = .1/1000;
double eurf = 1.0;
double *eurfactor = &eurf;
double eur_pnl = 0;
double *euro_pnl = &eur_pnl;
double eur_test = 0;
double *eurtest = &eur_test;
int eurtime = 5;
int *eurusdt = &eurtime;
std::string eursecond;
double eurprofit_;
double *eurprofit = &eurprofit_;



void getdata()
{
    infile.open("/users/satish/Desktop/gbpusd2019.txt", std::ifstream::binary);
    double data = 0;
    string temp, temp1, final;
    while(!infile.eof()) {
        infile >> data;
        gbpusd.push_back(data);
    }
    infile.close();

    infile.open("/users/satish/Desktop/gbpusd2019times.txt", std::ifstream::binary);
    while(!infile.eof()){

        infile >> skipws >> temp >> temp1;
        final = temp + " " + temp1;
        gbpusd_t.push_back(final);
    }
    infile.close();

    infile.open("/users/satish/Desktop/audusd2019.txt", std::ifstream::binary);
    while(!infile.eof())
    {
        infile>>data;
        audusd.push_back(data);
    }
    infile.close();

    infile.open("/users/satish/Desktop/audusd2019times.txt");
    while(!infile.eof())
    {
        infile >> skipws >> temp >> temp1;
        final = temp + " " + temp1;
        audusd_t.push_back(final);

    }
    infile.close();

    infile.open("/users/satish/Desktop/usdjpy2019.txt");
    while(!infile.eof())
    {
        infile>>data;
        usdjpy.push_back(data);
    }
    infile.close();

    infile.open("/users/satish/Desktop/usdjpy2019times.txt");
    while(!infile.eof())
    {
        infile>>skipws >> temp >> temp1;
        final = temp + " " + temp1;
        usdjpy_t.push_back(final);
    }
    infile.close();

    infile.open("/users/satish/Desktop/usdchf2019.txt");
    while(!infile.eof())
    {
        infile>>data;
        usdchf.push_back(data);
    }
    infile.close();

    infile.open("/users/satish/Desktop/usdchf2019times.txt");
    while(!infile.eof())
    {
        infile>>skipws >> temp >>temp1;
        final = temp + " " + temp1;
        usdchf_t.push_back(final);
    }
    infile.close();

    infile.open("/users/satish/Desktop/nzdusd2019.txt");
    while(!infile.eof())
    {
        infile >> data;
        nzdusd.push_back(data);
    }
    infile.close();

    infile.open("/users/satish/Desktop/nzdusd2019times.txt");
    while(!infile.eof())
    {
        infile>>skipws>>temp>>temp1;
        final = temp + " " + temp1;
        nzdusd_t.push_back(final);
    }
    infile.close();

    infile.open("/users/satish/Desktop/usdcad2019.txt");
    while(!infile.eof())
    {
        infile>>data;
        usdcad.push_back(data);
    }
    infile.close();

    infile.open("/users/satish/Desktop/usdcad2019times.txt");
    while(!infile.eof())
    {
        infile>>skipws>>temp>>temp1;
        final = temp + " " + temp1;
        usdcad_t.push_back(final);
    }
    infile.close();

    infile.open("/users/satish/Desktop/eurusd2019.txt");
    while(!infile.eof())
    {
        infile>>data;
        eurusd.push_back(data);
    }
    infile.close();

    infile.open("/users/satish/Desktop/eurusd2019times.txt");
    while(!infile.eof())
    {
        infile>>skipws>>temp>>temp1;
        final = temp + " " + temp1;
        eurusd_t.push_back(final);
    }
    infile.close();

    outfile.open("/users/satish/Desktop/trades.txt");
    writepnl.open("/users/satish/Desktop/pnl.txt");
    writegbp.open("/users/satish/Desktop/gbpusdpnl.txt");
    writeaud.open("/users/satish/Desktop/audusdpnl.txt");
    writejpy.open("/users/satish/Desktop/usdjpypnl.txt");
    writechf.open("/users/satish/Desktop/usdchfpnl.txt");
    writenzd.open("/users/satish/Desktop/nzdusdpnl.txt");
    writecad.open("/users/satish/Desktop/usdcadpnl.txt");
    writeeur.open("/users/satish/Desktop/eurusdpnl.txt");

    writegbptrade.open("/users/satish/Desktop/gbptrades.txt");
    writeaudtrade.open("/users/satish/Desktop/audtrades.txt");
    writejpytrade.open("/users/satish/Desktop/jpytrades.txt");
    writechftrade.open("/users/satish/Desktop/chftrades.txt");
    writenzdtrade.open("/users/satish/Desktop/nzdtrades.txt");
    writecadtrade.open("/users/satish/Desktop/cadtrades.txt");
    writeeurtrade.open("/users/satish/Desktop/eurtrades.txt");

}

void writethis(string timestamp, string *ins, double exitprice, double enterprice, double *v, double profit, double *bal) {
    outfile << setprecision(5);
    outfile << std::fixed;
    outfile << timestamp << "  " << *ins << "  UNITS  " << setw(10) << setprecision(0)<< *v << setprecision(5)<<  "\tENTERPRICE  " << setw(10) << enterprice
            << "  EXITPRICE  " << setw(10) << exitprice << "\tPERCENTCHANGE(%)  " << setw(10)
            << 100 * (profit / (*bal - profit)) << "\tPROFIT(USD)  " << setw(10) << profit << "  BALANCE(USD)  "
            << setw(10) << *bal << std::endl;
    writepnl << balance << endl;

    if (*ins == "GBP/USD") {
        writegbp << *pound_pnl << endl;

        writegbptrade << setprecision(5);
        writegbptrade << std::fixed;
        writegbptrade << timestamp << "  " << *ins << "  UNITS  " << setw(10) << setprecision(0)<< *v << setprecision(5)<< "\tENTERPRICE  " << setw(10)
                      << enterprice << "  EXITPRICE  " << setw(10) << exitprice << "\tPERCENTCHANGE(%)  " << setw(10)
                      << 100 * (profit / (*bal - profit)) << "\tPROFIT(USD)  " << setw(10) << profit
                      << "  BALANCE(USD)  " << setw(10) << *bal << std::endl;
    } else if (*ins == "AUD/USD") {
        writeaud << *aussie_pnl << endl;

        writeaudtrade << setprecision(5);
        writeaudtrade << std::fixed;
        writeaudtrade << timestamp << "  " << *ins << "  UNITS  " << setw(10) << setprecision(0)<< *v << setprecision(5) << "\tENTERPRICE  " << setw(10)
                      << enterprice << "  EXITPRICE  " << setw(10) << exitprice << "\tPERCENTCHANGE(%)  " << setw(10)
                      << 100 * (profit / (*bal - profit)) << "\tPROFIT(USD)  " << setw(10) << profit
                      << "  BALANCE(USD)  " << setw(10) << *bal << std::endl;
    } else if (*ins == "USD/JPY") {
        writejpy << *yen_pnl << endl;

        writejpytrade << setprecision(5);
        writejpytrade << std::fixed;
        writejpytrade << timestamp << "  " << *ins << "  UNITS  " << setw(10) << setprecision(0)<< *v << setprecision(5) << "\tENTERPRICE  " << setw(10)
                      << enterprice << "  EXITPRICE  " << setw(10) << exitprice << "\tPERCENTCHANGE(%)  " << setw(10)
                      << 100 * (profit / (*bal - profit)) << "\tPROFIT(USD)  " << setw(10) << profit
                      << "  BALANCE(USD)  " << setw(10) << *bal << std::endl;
    } else if (*ins == "USD/CHF") {
        writechf << *swiss_pnl << endl;

        writechftrade << setprecision(5);
        writechftrade << std::fixed;
        writechftrade << timestamp << "  " << *ins << "  UNITS  " << setw(10) << setprecision(0)<< *v << setprecision(5) << "\tENTERPRICE  " << setw(10)
                      << enterprice << "  EXITPRICE  " << setw(10) << exitprice << "\tPERCENTCHANGE(%)  " << setw(10)
                      << 100 * (profit / (*bal - profit)) << "\tPROFIT(USD)  " << setw(10) << profit
                      << "  BALANCE(USD)  " << setw(10) << *bal << std::endl;
    } else if (*ins == "NZD/USD") {
        writenzd << *nzdollar_pnl << endl;

        writenzdtrade << setprecision(5);
        writenzdtrade << std::fixed;
        writenzdtrade << timestamp << "  " << *ins << "  UNITS  " << setw(10) << setprecision(0)<< *v << setprecision(5) << "\tENTERPRICE  " << setw(10)
                      << enterprice << "  EXITPRICE  " << setw(10) << exitprice << "\tPERCENTCHANGE(%)  " << setw(10)
                      << 100 * (profit / (*bal - profit)) << "\tPROFIT(USD)  " << setw(10) << profit
                      << "  BALANCE(USD)  " << setw(10) << *bal << std::endl;


    } else if (*ins == "USD/CAD") {
        writecad << *caddollar_pnl << endl;

        writecadtrade << setprecision(5);
        writecadtrade << std::fixed;
        writecadtrade << timestamp << "  " << *ins << "  UNITS  " << setw(10) << setprecision(0)<< *v << setprecision(5) << "\tENTERPRICE  " << setw(10)
                      << enterprice << "  EXITPRICE  " << setw(10) << exitprice << "\tPERCENTCHANGE(%)  " << setw(10)
                      << 100 * (profit / (*bal - profit)) << "\tPROFIT(USD)  " << setw(10) << profit
                      << "  BALANCE(USD)  " << setw(10) << *bal << std::endl;
    }


    else if(*ins == "EUR/USD") {
        writeeur << *euro_pnl << endl;

        writeeurtrade << setprecision(5);
        writeeurtrade << std::fixed;
        writeeurtrade << timestamp << "  " << *ins << "  UNITS  " << setw(10) << setprecision(0)<< *v << setprecision(5) << "\tENTERPRICE  " << setw(10)
                      << enterprice << "  EXITPRICE  " << setw(10) << exitprice << "\tPERCENTCHANGE(%)  " << setw(10)
                      << 100 * (profit / (*bal - profit)) << "\tPROFIT(USD)  " << setw(10) << profit
                      << "  BALANCE(USD)  " << setw(10) << *bal << std::endl;

    }
