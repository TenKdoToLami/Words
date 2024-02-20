#include <iostream>
#include <string>
#include <vector>
#include <set>

std::set <unsigned int> FibonacciSet;

void Fibonacci()
{
    unsigned int first = 1;
    unsigned int second = 2;
    unsigned int Sum = 2;

    while (first <= second)
    {
        FibonacciSet.insert(Sum);
        Sum = first + second;
        first = second;
        second = Sum;
    }

}



class WordBank
{
public:
    std::vector <std::string> words; // Vector to store the list of words.


    void ReadSTDIn(unsigned int SizeOfWordsToRead)
    {
        std::string word;
        while (std::cin >> word)
            if (word.length() == SizeOfWordsToRead)
                words.push_back(word);
    }

    void PrintWords()
    {
        for (const auto &word : words)
        {
            unsigned int Number = ConvertToInteger(word);
           if ( IsPrime(Number))
                std::cout << word << " " << Number << std::endl;
        }

    }


    unsigned int ConvertToInteger(const std::string & str)
    {
        return (str[0] << 24) + (str[1] << 16) + (str[2] << 8) + str[3];
    }

    bool IsPrime(unsigned int number)
    {
        for (unsigned int i = 2; i * i <= number; ++i)
            if (number % i == 0)
                return false;

        return true;
    }

    bool IsDividedByFibonacci(unsigned int number)
    {
        for (unsigned int i : FibonacciSet)
            if (number % i != 0)
                return true;
        return false;
    }

};




int main()
{
    WordBank wordBank;
    Fibonacci();
    wordBank.ReadSTDIn(4);
    wordBank.PrintWords();

    return EXIT_SUCCESS;
}