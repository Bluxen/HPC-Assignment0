#include <iostream>

#include "fraction_toolbox.hpp"

void print_fraction(fraction frac)
{
    std::cout << frac.num << '/' << frac.denom << std::endl;
}

void print_fraction_array(fraction frac_array[], int n)
{
    std::cout << "[ " << frac_array[0].num << '/' << frac_array[0].denom << std::endl;
    for (int i = 1; i < n-1; i++)
    {
        std::cout << "  ";
        print_fraction(frac_array[i]);
    }
    std::cout << "  " << frac_array[n-1].num << '/' << frac_array[n-1].denom << " ]" << std::endl;
}

//DONE: implement function 2
fraction square_fraction(fraction frac)
{
    fraction sol;
    sol.num = frac.num * frac.num;
    sol.denom = frac.denom * frac.denom;
    return sol;
}

//DONE: implement function 3
void square_fraction_inplace(fraction & frac)
{
    frac.num = frac.num * frac.num;
    frac.denom = frac.denom * frac.denom;
}

//DONE: implement function 4
double fraction2double(fraction frac)
{
    double r;
    r = (double)frac.num / (double)frac.denom;
    return r;
}

//DONE: implement function 5
 int gcd(int a, int b)
 {
    if(b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a%b);
    }
 }

//DONE: implement function 6
int gcd(fraction frac)
{
    int a = frac.num;
    int b = frac.denom;
    int t;
    while(b != 0)
    {
        t = b;
        b = a%b;
        a = t;
    }
    return a;
}

//DONE: implement function 7
void reduce_fraction_inplace(fraction & frac)
{
    int d = gcd(frac);
    frac.num = frac.num / d;
    frac.denom = frac.denom / d;

    //DONE: add short comment to explain which of the gcd() functions your code is calling
    //the gcd function called is the iterative one at line 59:
    //by using a fraction as a parameter the compiler selects
    //the best matching function between the ones written
}

//DONE: implement function 8
 fraction add_fractions(fraction frac1, fraction frac2)
 {
    int a = frac1.num;
    int b = frac1.denom;
    int c = frac2.num;
    int d = frac2.denom;
    fraction frac3;
    int lcm = (b*d)/gcd(b,d);
    frac3.num = (a*lcm)/b + (c*lcm)/d;
    frac3.denom = lcm;
    reduce_fraction_inplace(frac3);
    return frac3;
 }

//DONE: implement function 9
 double sum_fraction_array_approx(fraction frac_array[], int n)
 {
    fraction frac_sum;
    frac_sum.num = 0;
    frac_sum.denom = 1;
    for(int i = 0; i < n; i++)
    {
        frac_sum = add_fractions(frac_sum, frac_array[i]);
    }
    return fraction2double(frac_sum);

     //DONE: add short comment to explain why this function is approximate
     //it's approximate because a double is 8 bytes,
     //meaning it can only show up to 15 digits after the decimal point
 }

//DONE: implement function 10
fraction sum_fraction_array(fraction frac_array[], int n)
{
    fraction frac_sum;
    frac_sum.num = 0;
    frac_sum.denom = 1;
    for(int i = 0; i < n; i++)
    {
        frac_sum = add_fractions(frac_sum, frac_array[i]);
    }
    return frac_sum;
}

void fill_fraction_array(fraction frac_array[], int n)
{
    fraction temp_frac;
    temp_frac.num = 1;
    for (int i = 1; i <= n; i++)
    {
        temp_frac.denom = i * (i+1);
        frac_array[i-1] = temp_frac;
    }
}

