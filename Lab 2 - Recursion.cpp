// Lab 2 - Recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Paolo Barone
// CS 136 Data Structures

#include <iostream>
using namespace std;

void PrintMenu();
double RaiseBaseToPower(double base, int power);
long SumOfSquares1(long numberOfTerms);
long SumOfSquares2(long n, long numberOfTerms);
long factorial(long num);

int main()
{
    int choice = 0;
    double base = 0;
    int power = 0;
    double baseRaisedToAPower1 = 1;
    long n = 1, sumOfSquares1 = 0, sumOfSquares2 = 0, factorialOfN = 1, numberOfTerms = 0, count = 1, i = 0;

    do
    {
        PrintMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the base value to be raised to a power: ";
            cin >> base;
            cout << "Enter an integer exponent: ";
            cin >> power;
            baseRaisedToAPower1 = RaiseBaseToPower(base, power);
            cout << base << "^" << power << " = " << baseRaisedToAPower1;
            break;


        case 2:
            do
            {
                cout << "Enter the integer value of the number of terms, n, you want to calculate for (1^2) + (2^2) + (3^2) + ... + (n^2): ";
                cin >> numberOfTerms;

                if (numberOfTerms < 0)
                {
                    cout << "You can't enter a negative integer value for the number of terms.\n\n";
                }
            } while (numberOfTerms < 0);

            sumOfSquares1 = SumOfSquares1(numberOfTerms);

            for (int i = 1; i <= numberOfTerms; i++)
            {
                if (i < numberOfTerms)
                {
                    cout << i << "^2 + ";
                }
                else // i >= numberOfTerms
                {
                    cout << i << "^2";
                }

            }
            cout << " = " << sumOfSquares1;
            break;

        case 3:
            do
            {
                cout << "Enter the integer value of n, you want to calculate for (1^2) + (2^2) + (3^2) + ... + (n^2): ";
                cin >> n;

                if (n < 0)
                {
                    cout << "You can't enter a negative integer value for n.\n\n";
                }
            } while (n < 0);

            do
            {
                cout << "Enter an integer value of the number of terms you wish to compute: ";
                cin >> numberOfTerms;

                if (numberOfTerms < 0)
                {
                    cout << "You can't enter a negative integer value for the number of terms.\n\n";
                }
            } while (numberOfTerms < 0);

            while (numberOfTerms > n)
            {
                cout << "The number of terms, " << numberOfTerms << ", can't be an integer greater than n, " << n << ".\n\n";
                cout << "Enter an integer value of the number of terms you wish to compute: ";
                cin >> numberOfTerms;
                cout << endl;
            };

            sumOfSquares2 = SumOfSquares2(n, numberOfTerms);
            i = n;
            count = 1;
            cout << "i: " << i << "  n: " << n << endl;

            //for (int i = n; i >= (numberOfTerms); i--) // n=7, numberOfTerms=5;
            do
            {
                if (count < numberOfTerms)
                {
                    cout << i << "^2 + ";
                }
                else // count = numberOfTerms
                {
                    cout << i << "^2";
                }
                i--;
                count++;

            } while (count <= numberOfTerms);
            cout << " = " << sumOfSquares2;
            break;

        case 4:
            cout << "Enter an integer value of n for the factorial of n: ";
            cin >> n;
            factorialOfN = factorial(n);
            cout << n << "! = " << factorialOfN;
            break;

        case 5:
            break;

        default:
            cout << "***ERROR: You didn't enter an integer between 1 and 5\n\n";
            break;
        }
    } while (choice != 5);
}

void PrintMenu()
{
    cout << "\n\n                    Lab 2 - Recursion\n\n";
    cout << "1 - Raises  a  number to a power (whole number)\n";
    cout << "2 - Calculate the sum of squares (1^2) + (2^2) + (3^2) + ... + (n^2)\n";
    cout << "3 - Calculate the sum of squares (n^2) + ... + (3^2) + (2^2) + (1^2)\n";
    cout << "4 - Calculate a factorial n!\n";
    cout << "5 - QUIT PROGRAM\n\n";

}

double RaiseBaseToPower(double base, int exponent)
{

    /*
    int recursion1(int x, int n)
{
    // base condition
    if (n == 1)
        return x;
    else
        // recursion call with logic to get x^1 * x^2 * x^3 *... * x^n
        return x * recursion1(x, n - 1);
}
    */

    if (base == 0.0)
    {
        return 0.0;
    }
    else if (exponent == 0)
    {
        return 1.0;
    }
    else if (exponent == 1)
    {
        return base;
    }
    else if (exponent > 0)
    {
        return base * RaiseBaseToPower(base, exponent - 1);
    }
    else if (exponent < 0)
    {
        double tempAnswer = 0.0;

        tempAnswer = base * RaiseBaseToPower(base, abs(exponent) - 1);
        cout << "tempAnswer: " << tempAnswer << endl;
        return 1 / tempAnswer;
    }
}

long SumOfSquares1(long numberOfTerms) // starting with 1: (1^2) + (2^2) + (3^2) + ... + (n^2)
{

    long answer;

    if (numberOfTerms == 0) 
    {
        return 0;
    }
    else 
    s	{
        answer = pow(numberOfTerms, 2) + SumOfSquares1(numberOfTerms - 1);
        return answer;
    }
}


long SumOfSquares2(long n, long numberOfTerms) // starting with n^2: (n^2) + ... + (3^2) + + (2^2) + (1^2)
{
    /*

    */

    long answer = 0;

    //cout << "answer: " << answer << endl;
    if (numberOfTerms == 0)
    {
        return 0;
    }
    else
    {
        answer = pow(n, 2) + SumOfSquares2(n - 1, numberOfTerms - 1);
        //long n2 = pow(n, 2);
        //cout << "n2: " << n2 << endl;
        //cout << n << "^2 = " << pow(n, 2) << endl;
        //cout << "answer: " << answer << endl;
        return answer;
    }
}

long factorial(long num)
{
    if (num == 0 || num == 1)
    {
        return 1.0;
    }
    return num * factorial(num - 1);
}

/*
OUTPUT:



                    Lab 2 - Recursion

1 - Raises  a  number to a power (whole number)
2 - Calculate the sum of squares (1^2) + (2^2) + (3^2) + ... + (n^2)
3 - Calculate the sum of squares (n^2) + ... + (3^2) + (2^2) + (1^2)
4 - Calculate a factorial n!
5 - QUIT PROGRAM

Enter your choice: 1
Enter the base value to be raised to a power: 2
Enter an integer exponent: 4
2^4 = 16

                    Lab 2 - Recursion

1 - Raises  a  number to a power (whole number)
2 - Calculate the sum of squares (1^2) + (2^2) + (3^2) + ... + (n^2)
3 - Calculate the sum of squares (n^2) + ... + (3^2) + (2^2) + (1^2)
4 - Calculate a factorial n!
5 - QUIT PROGRAM

Enter your choice: 1
Enter the base value to be raised to a power: 2
Enter an integer exponent: -3
tempAnswer: 8
2^-3 = 0.125

                    Lab 2 - Recursion

1 - Raises  a  number to a power (whole number)
2 - Calculate the sum of squares (1^2) + (2^2) + (3^2) + ... + (n^2)
3 - Calculate the sum of squares (n^2) + ... + (3^2) + (2^2) + (1^2)
4 - Calculate a factorial n!
5 - QUIT PROGRAM

Enter your choice: 1
Enter the base value to be raised to a power: 3.14159
Enter an integer exponent: 3
3.14159^3 = 31.0062

                    Lab 2 - Recursion

1 - Raises  a  number to a power (whole number)
2 - Calculate the sum of squares (1^2) + (2^2) + (3^2) + ... + (n^2)
3 - Calculate the sum of squares (n^2) + ... + (3^2) + (2^2) + (1^2)
4 - Calculate a factorial n!
5 - QUIT PROGRAM

Enter your choice: 2
Enter the integer value of the number of terms, n, you want to calculate for (1^2) + (2^2) + (3^2) + ... + (n^2): 4
1^2 + 2^2 + 3^2 + 4^2 = 30

                    Lab 2 - Recursion

1 - Raises  a  number to a power (whole number)
2 - Calculate the sum of squares (1^2) + (2^2) + (3^2) + ... + (n^2)
3 - Calculate the sum of squares (n^2) + ... + (3^2) + (2^2) + (1^2)
4 - Calculate a factorial n!
5 - QUIT PROGRAM

Enter your choice: 2
Enter the integer value of the number of terms, n, you want to calculate for (1^2) + (2^2) + (3^2) + ... + (n^2): 5
1^2 + 2^2 + 3^2 + 4^2 + 5^2 = 55

                    Lab 2 - Recursion

1 - Raises  a  number to a power (whole number)
2 - Calculate the sum of squares (1^2) + (2^2) + (3^2) + ... + (n^2)
3 - Calculate the sum of squares (n^2) + ... + (3^2) + (2^2) + (1^2)
4 - Calculate a factorial n!
5 - QUIT PROGRAM

Enter your choice: 3
Enter the integer value of n, you want to calculate for (1^2) + (2^2) + (3^2) + ... + (n^2): 7
Enter an integer value of the number of terms you wish to compute: 3
i: 7  n: 7
7^2 + 6^2 + 5^2 = 110

                    Lab 2 - Recursion

1 - Raises  a  number to a power (whole number)
2 - Calculate the sum of squares (1^2) + (2^2) + (3^2) + ... + (n^2)
3 - Calculate the sum of squares (n^2) + ... + (3^2) + (2^2) + (1^2)
4 - Calculate a factorial n!
5 - QUIT PROGRAM

Enter your choice: 3
Enter the integer value of n, you want to calculate for (1^2) + (2^2) + (3^2) + ... + (n^2): 10
Enter an integer value of the number of terms you wish to compute: 4
i: 10  n: 10
10^2 + 9^2 + 8^2 + 7^2 = 294

                    Lab 2 - Recursion

1 - Raises  a  number to a power (whole number)
2 - Calculate the sum of squares (1^2) + (2^2) + (3^2) + ... + (n^2)
3 - Calculate the sum of squares (n^2) + ... + (3^2) + (2^2) + (1^2)
4 - Calculate a factorial n!
5 - QUIT PROGRAM

Enter your choice: 4
Enter an integer value of n for the factorial of n: 4
4! = 24

                    Lab 2 - Recursion

1 - Raises  a  number to a power (whole number)
2 - Calculate the sum of squares (1^2) + (2^2) + (3^2) + ... + (n^2)
3 - Calculate the sum of squares (n^2) + ... + (3^2) + (2^2) + (1^2)
4 - Calculate a factorial n!
5 - QUIT PROGRAM

Enter your choice: 4
Enter an integer value of n for the factorial of n: 10
10! = 3628800

                    Lab 2 - Recursion

1 - Raises  a  number to a power (whole number)
2 - Calculate the sum of squares (1^2) + (2^2) + (3^2) + ... + (n^2)
3 - Calculate the sum of squares (n^2) + ... + (3^2) + (2^2) + (1^2)
4 - Calculate a factorial n!
5 - QUIT PROGRAM

Enter your choice: 5

C:\Users\PBaro\source\repos\CS 136 Data Structures\Labs\Lab 2 - Recursion NEW 3\Lab 2 - Recursion NEW 3\Debug\Lab 2 - Recursion NEW 3.exe (process 18680) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/