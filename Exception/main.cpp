#include <exception>
#include <iostream>
#include <string>

using namespace std;


class Fraction
{
private:
    int numerator, denominator;

public:
    Fraction(int n, int d)
    {
        numerator = n;
        if(d == 0)
            throw std::runtime_error("denominator must be not equal 0\n");
    }
};

int main()
{
    std::cout<< "Please enter numerator and denominator\n";
    int n,d;
    std::cin>>n >> d;
    try
    {
        Fraction f(n,d);
    }
    catch(const std::exception& e)
    { 
        std::cerr << e.what() << '\n';
    }
    
    
    return 0;
}