/*****************************************************************************
*
*  Author:           (Zachary Lewis)
*  Email:            (zalewis0317@my.msutexas.edu)
*  Label:            (06-P01)
*  Title:            (Fraction class)
*  Course:           (2243 OOP)
*  Semester:         (Fall 2024)
*
*  Description:
*        This program defines a `Fraction` class that models mathematical
*        fractions, allowing operations such as addition, subtraction,
*        multiplication, and division. It also provides a method to check
*        equality between fractions, simplifying them using the greatest
*        common divisor (GCD).
*
*  Usage:
*        Create instances of the `Fraction` class, perform arithmetic
*        operations, and output the results. The program demonstrates
*        basic usage through a simple main function.
*
*  Files:            (list of all source files used in this program)
*****************************************************************************/ 

#include <iostream>

using namespace std;

// Function to find the greatest common divisor
int FindGCD(int n1, int n2);

class Fraction {
    int num; // numerator
    int den; // denominator

    // private members can be added here

public:
    Fraction(); 
    Fraction(int, int);
    friend ostream& operator<<(ostream& os, const Fraction& rhs);
    Fraction operator*(const Fraction& rhs);
    Fraction operator/(const Fraction& rhs);
    Fraction operator+(const Fraction& rhs);
    Fraction operator-(const Fraction& rhs);
    bool operator==(const Fraction& rhs);
};


    // Default constructor initializing fraction to 1/1
    Fraction::Fraction() { num = den = 1; }
    
    // Parameterized constructor
    Fraction::Fraction(int n, int d) {
        if (d ==0){
            cout << "Invalid denominator\n";

        }
        else{
        den = d;
        num = n;
        }
       
    }

    // Overloaded stream insertion operator for output
     std:: ostream& operator<<(ostream& os, const Fraction& rhs) {
        return os << rhs.num << "/" << rhs.den; // Output format
    }

    // Overloaded multiplication operator
    Fraction Fraction:: operator*(const Fraction& rhs) {
        int num = this->num * rhs.num; // Multiply numerators
        int den = this->den * rhs.den;   // Multiply denominators
        return Fraction(num, den);
    }

    // Overloaded division operator
    Fraction Fraction::operator/(const Fraction& rhs) {
        int num = this->num * rhs.den; // Multiply numerator by denominator of rhs
        int den = this->den * rhs.num;  // Multiply denominator by numerator of rhs
        return Fraction(num, den);
    }

    // Overloaded addition operator
    Fraction Fraction::operator+(const Fraction& rhs) {
        int num = (this->num * rhs.den) + (rhs.num * this->den); // Calculating numerator
        int den = (this->den * rhs.den); // Calculating denominator

        // Simplify fraction if possible
        if (FindGCD(num, den) != 0) {
            int tempnum = num;
            tempnum /= FindGCD(num, den);
            den /= FindGCD(num, den);
            num = tempnum;
        }

        return Fraction(num, den);
    }

    // Overloaded subtraction operator
    Fraction Fraction::operator-(const Fraction& rhs) {
        int num = (this->num * rhs.den) - (rhs.num * this->den); // Calculate numerator
        int den = (this->den * rhs.den); // Calculate denominator
        
        // Simplify fraction if possible
        if (FindGCD(num, den) != 0) {
            int tempnum = num;
            tempnum /= FindGCD(num, den);
            den /= FindGCD(num, den);
            num = tempnum;
        }
        return Fraction(num, den);
    }

    // Overloaded equality operator
    bool Fraction::operator==(const Fraction& rhs) {
        // Simplifying both fractions for comparison
        int tempnum = this->num, tempden = this->den;
        tempnum /= FindGCD(this->num, this->den);
        tempden /= FindGCD(this->num, this->den);

        int tempnum2 = rhs.num, tempden2 = rhs.den;
        tempnum2 /= FindGCD(rhs.num, rhs.den);
        tempden2 /= FindGCD(rhs.num, rhs.den);

        // Check equality of simplified fractions
        bool equal = (Fraction(tempnum, tempden) == Fraction(tempnum2, tempden2));
        return equal;
    }

int main(int argc, char *argv[]) 
{
    int n, n2, d, d2;
    string ff1, ff2, op;

    // Read input in the format of two fractions and an operator
    while (cin >> ff1 >> op >> ff2)
    {
        // Extract the numerator and denominator from the string input
        n = ff1[0] - '0';   // First fraction numerator
        d = ff1[2] - '0';   // First fraction denominator
        n2 = ff2[0] - '0';  // Second fraction numerator
        d2 = ff2[2] - '0';  // Second fraction denominator

        // Create Fraction objects using parsed values
        Fraction b(n, d);
        Fraction b2(n2, d2);

        // Perform operations based on the specified operator
        if (op == "==")
        {
            bool equal;
            equal = b == b2;  // Check for equality
            cout << b << " ==" << b2 << " " << equal << endl;
        }
        else if (op == "-")
        {
            cout << b << " - " << b2 << " = " << (b - b2) << endl;  // Subtraction
        }
        else if (op == "+")
        {
            cout << b << " + " << b2 << " = " << (b + b2) << endl;  // Addition
        }
        else if (op == "*")
        {
            cout << b << " * " << b2 << " = " << (b * b2) << endl;  // Multiplication
        }
        else if (op == "/")
        {
            cout << b << " / " << b2 << " = " << (b / b2) << endl;  // Division
        }
        else
        {
            cout << "Invalid input." << endl;  // Handle invalid input
        }
    }
    
    return 0;
}

// Finds greatest common divisor
int FindGCD(int n1, int n2) {
    int GCD{};
    // Iterates through potential divisors to find GCD
    for (int i = 1; i <= n1 && i <= n2; i++) {
        if (n1 % i == 0 && n2 % i == 0)
            GCD = i; // Update GCD if a divisor is found
    }
    return GCD; // Return the GCD
}
