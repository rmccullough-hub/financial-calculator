
#include "equations.h"
#include <iostream>
#include <cmath>
#include <vector>

using namespace calc;

// Functions used for Calculations

//rounds number to two decimal places
double rnd(double num){

    std::string rounded_num = std::to_string(num);
    int count = 3;
    bool past_decimal= false;
    int ind = 0;

    for(int i = 0; i < rounded_num.length(); i++){

        if(past_decimal == true) count--;
        if(rounded_num[i] == '.') {
            past_decimal = true;
        }
        if(count == 0){
            ind = i;
            break;
        }

    }

    if(count == 0) rounded_num.erase(ind, std::string::npos);
    return std::stod(rounded_num);
}


double equations::simple_interest(double principal, double interest, double time ){

    float r = interest / 100.00;

    return rnd(principal * (1.0 + r * time));

}


double equations::compound_interest(double principal, double interest, double n, double time){

    float r = interest / 100.00;
    double base = 1 + r / n;
    int exponent = time * n;
    return rnd(principal * pow(base, exponent));

}


double equations::price_ratio(double pricePerShare, double valPerShare){

    return pricePerShare / valPerShare;
}


double equations::capm(int interest, float beta, int expected_return){
    float r = interest / 100.00;
    float ER = expected_return / 100.00 - r;
    return rnd((r + beta * ER) * 100);
}


double equations::cagr(double beginning, double fin, double time){

    return rnd((pow((fin/beginning), (1/time)) - 1) * 100);
}


double equations::amortization(double principal, float interest, int periods){
    float r = interest / 100.00;

    float exp = pow((1 + r), periods);

    float numerator = exp * r;

    float denominator = exp - 1;

    return rnd(principal * (numerator/denominator));
}


float equations::leverage_ratio(double total_debt, double total_assets){

    return rnd((total_debt / total_assets) * 100);
}


// arrays contain weight at index 0, and expected return at index 1
double equations::expected_return(int stock1[2], int stock2[2], int stock3[2], int stock4[2], int stock5[2]){

    return rnd(((stock1[0] / 100.00) * (stock1[1] / 100.00)) + ((stock2[0] / 100.00) * (stock2[1] / 100.00)) + ((stock3[0] / 100.00) * (stock3[1] / 100.00)) + ((stock4[0] / 100.00) * (stock4[1] / 100.00)) + ((stock5[0] / 100.00) * (stock5[1] / 100.00)) * 100);
}



double equations::dcf(std::vector<float> expected_cashflows, int interest){

    float answer = 0;
    float r = interest / 100.00;

    for (unsigned long long i = 0; i < expected_cashflows.size(); i++){

        float add = expected_cashflows.at(i) / pow((1 + r), (i + 1));
        answer = add + answer;
    }

    return rnd(answer);
}

double equations::future_value(double present_value, int interest, int periods){

    float r = interest / 100.00;
    return rnd(present_value * pow((1 + r), periods));

}
