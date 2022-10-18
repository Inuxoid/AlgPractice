#include <iostream>

int main()
{
    try
    {
        int nMax;
        double absError;
        double x = 0.6;
        double formulaSum;
        double sum = 1;
        double nextTerm;
        double sign = 1;

        std::cin >> absError;
        std::cin >> nMax;
        std::cin >> x;

        nextTerm = -0.5 * x;

        if (x <= -1 || x >=1)
        {
            throw std::runtime_error("Error!");
        }

        formulaSum = 1 / (sqrtf(1 + x));

        for (size_t i = 2; i < nMax; i++)
        {
            sum += nextTerm;
            nextTerm = std::abs(nextTerm) * static_cast<double>(sign * (((1 + 2 * (i - 1)) * x)) / static_cast<double>((2 + 2 * (i - 1))));
            sign *= -1;
            if (std::abs(nextTerm) <= absError)
            {
                break;
            }
        }
        if (std::abs(nextTerm) > absError)
        {
            throw std::runtime_error("Error!");
        }

        std::cout << sum << "\n";
        std::cout << formulaSum << "\n";
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << e.what() << "\n";
    }
}   