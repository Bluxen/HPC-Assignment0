#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "fraction_toolbox.hpp"

using namespace std;

fraction f;

// read command line arguments
static void readcmdline(fraction & frac, int argc, char* argv[])
{
    if (argc!=3)
    {
        printf("Usage: n d\n");
        printf("  n        numerator of fraction\n");
        printf("  d        denominator of fraction\n");
        exit(1);
    }

    // read n
    frac.num = atoi(argv[1]);

    // read d
    frac.denom = atoi(argv[2]);
}

static void test23467(int argc, char* argv[])
{
    //DONE: implement function
    cout << "\nTesting square_fraction: ";
    print_fraction(square_fraction(f));
    cout << "Testing square_fraction_inplace: ";
    square_fraction_inplace(f);
    print_fraction(f);
    cout << "Testing fraction2double: " << fraction2double(f) << "\n";
    cout << "Testing iterative gcd: " << gcd(f) << "\n";
    cout << "Testing reduce_fraction_inplace: ";
    reduce_fraction_inplace(f);
    print_fraction(f);
}

static void test5()
{
    //DONE: implement function
    int a,b;
    cout << "\nInsert two integers: ";
    cin >> a >> b;
    cout << "The GCD of " << a << " and " << b << " is: " << gcd(a,b) << "\n";
}

static void test_array_functions(int n)
{
    //DONE: implement function
    fraction* fracptr = (fraction*)malloc(n * sizeof(fraction));
    fill_fraction_array(fracptr, n);
    cout << "\nThe sum of the array is: ";
    print_fraction(sum_fraction_array(fracptr, n));
    cout << "The approximate sum of the array is: " << sum_fraction_array_approx(fracptr, n) << "\n";

    //TODO: find n for which sum function breaks. Explain what is happening.
    //with n = 1290 is when the sum goes from n/n+1 to something else,
    //and with n = 10000 the sum gives 0/1.
    //it has something to do with integer overflow, but that doesn't explain
    //why it would start giving problems from 1290 onward
}

static void test_toolbox(int argc, char* argv[])
{
    cout << "\n===============  test23467  =============== " << endl;
    test23467(argc, argv);

    cout << "\n=================  test5  ================= " << endl;
    test5();

    cout << "\n==========  test_array_functions  ========= " << endl;
    int n = 5;
    test_array_functions(n);
}

int main(int argc, char* argv[])
{
    readcmdline(f,argc, argv);
    cout << "\nThe fraction passed as an argument is: ";
    print_fraction(f);
    test_toolbox(argc, argv);
}