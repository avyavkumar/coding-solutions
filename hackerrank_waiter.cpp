#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

// finding the next prime number after a prime number

bool IsPrime(long long int number)
{
    if (number == 2 || number == 3)
        return true;
    if (number % 2 == 0 || number % 3 == 0)
        return false;
    int divisor = 6;
    while (divisor * divisor - 2 * divisor + 1 <= number)
    {
        if (number % (divisor - 1) == 0)
            return false;
        if (number % (divisor + 1) == 0)
            return false;
        divisor += 6;
    }
    return true;
}

long long int NextPrime(long long int a)
{
    while (!IsPrime(++a)) {}
    return a;
}

int main()
{
    stack <long long int> plates_all;
    stack <long long int> plates_prime;
    stack <long long int> plates_comp;

    int number, primes;
    cin>>number>>primes;
    for (int i = 0; i < number; i++)
    {
        int plate;
        cin>>plate;
        plates_all.push(plate);
    }

    long long int current_prime = 2;
    for (int i = 0; i < primes; i++)
    {
        if (plates_all.size() == 0)
            break;
        while( plates_all.size() > 0)
        {
            long long int current = plates_all.top();
            plates_all.pop();
            if (current%current_prime == 0)
                plates_prime.push(current);
            else
                plates_comp.push(current);
        }
        while(plates_prime.size() > 0)
        {
            std::cout << plates_prime.top() << std::endl;
            plates_prime.pop();
        }
        plates_all = plates_comp;
        while(!plates_comp.empty())
            plates_comp.pop();
        current_prime = NextPrime(current_prime);
    }

    while(plates_all.size() > 0)
    {
        std::cout << plates_all.top() << std::endl;
        plates_all.pop();
    }
}
