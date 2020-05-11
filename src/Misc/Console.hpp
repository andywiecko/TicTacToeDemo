#ifndef SRC_MISC_MISC_HPP
#define SRC_MISC_MISC_HPP

#include <string>
#include <iostream>

class Console
{
public:
    template <class T>
    static void ReadLine(std::string message, T &output)
    {
        std::cout << message;
        std::cin >> output;
        while (std::cin.fail())
        {
            Console::Log("Invalid Entry! Try again.\n");
            std::cout << message;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> output;
        }
    }

    template <class T>
    static void Log(T t)
    {
        std::cout << t;
    }

    static void Clear(size_t n = 100)
    {
        std::cout << std::string(n, '\n');
    }

    static void Line(size_t n = 20)
    {
        std::cout << std::string(n, '=') << std::endl;
    }
};

#endif