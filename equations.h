#ifndef EQUATIONS_H
#define EQUATIONS_H

#include <vector>

// equations.h
namespace calc
{
    class equations
    {
    public:
        double simple_interest(double principal, double interest, double time);
        double compound_interest(double principal, double interest, double n, double time);
        double price_ratio(double pricePerShare, double valPerShare);
        double capm(int interest, float beta, int expected_return);
        double cagr(double beginning, double fin, double time);
        double amortization(double principal, float interest, int periods);
        float leverage_ratio(double total_debt, double total_assets);
        double expected_return(int stock1[2], int stock2[2], int stock3[2], int stock4[2], int stock5[2]);
        double dcf(std::vector<float> expected_cashflows, int interest);
        double future_value( double present_val, int interest, int periods);
    };

}
#endif // EQUATIONS_H
