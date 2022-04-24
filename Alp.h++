#pragma once

#include <iostream>
#include <vector>

#include <string>

#include <initializer_list>

// Function to print the character sequence
// for the given ASCII sentence
// (https://www.geeksforgeeks.org/convert-the-ascii-value-sentence-to-its-equivalent-string/)
void ASCIIToSentence(std::string str)
{
    int len = str.length();
    int num = 0;

    for (int i = 0; i < len; i++)
    {
        // Append the current digit
        num = num * 10 + (str[i] - '0');

        // If num is within the required range
        if (num >= 32 && num <= 122)
        {
            // Convert num to char
            char ch = (char)num;
            std::cout << ch;

            // Reset num to 0
            num = 0;
        }
    }
}

namespace alp
{
    // --== Statements ==--
    // https://stackoverflow.com/questions/1657883/variable-number-of-arguments-in-c

    template<typename T>
    void Println(T t)
    {
        std::cout << t;

        std::cout << '\n';
    }

    /// <summary>
    /// The purpose of having yet another printing
    /// statement is that this one automatically starts a new line,
    /// making the user type less, but this method uses '\n', instead of 'std::endl'
    /// meaning that this will not flush the output buffer everytime it is called.
    /// </summary>
    /// \tparam T
    /// \tparam Args
    /// \param t
    /// \param args
    template<typename T, typename... Args>
    void Println(T t, Args... args) // Recursive variadic function.
    {
        std::cout << t;

        Println(args...);

        std::cout << '\n';
    }

    bool StringIsAlpha(std::string str)
    {
        bool isAlpha { true };

        for (int i { 0 }; i < str.length(); ++i)
        {
            if (!std::isalpha(str[i]) && str[i] != ' ')
            {
                if (isAlpha) { isAlpha = false; }
            }
        }

        return isAlpha;
    }

    bool StringIsDigit(std::string str)
    {
        bool isDigit { true };

        for (int i { 0 }; i < str.length(); ++i)
        {
            if (!std::isdigit(str[i]) && str[i] != ' ')
            {
                if (isDigit) { isDigit = false; }
            }
        }

        return isDigit;
    }

    /// <summary>
    /// This method print's out the ascii values of the provided string.
    /// </summary>
    /// \tparam std::string
    void PrintASCII(std::string str)
    {
        try
        {
            if (!StringIsDigit(str))
            {
                for (char c : str)
                {
                    std::cout << (int)c;
                }
            }
            else
            {
                ASCIIToSentence(str);
            }
        }
        catch (std::exception e)
        {
            std::string throwErr { "Incorrect parameters for 'PrintASCII'. Make sure the data type is alphabetical." };
            throw std::runtime_error(throwErr);
        }

        std::cout << '\n';
    }

    std::string GetInput()
    {
        std::string toReturn { "" };
        std::getline(std::cin, toReturn); // Gets the user's input.

        return toReturn;
    }

    /// <summary>
    /// Returns a boolean stating weather the first and the
    /// second parameter are equal.
    /// </summary>
    bool Check(auto x, auto y)
    {
        bool boolean;

        try
        {
            if (x == y) { boolean = true; }
            else { boolean = false; }
        }
        catch (const bool e)
        {
            std::cerr << "Error checking '" << x << "', and '" << y << "'. Error exited with the message '" << e << "'." << std::endl;
        }

        return boolean;
    }

    // --== Data Types ==--

    /// <summary>
    /// The reason to create this data type is to add an automatic
    /// const to the variable (which holds the initial value), and add more modern functionality
    /// such as 'ToCharVector' instead of 'ToCharArray', to use endorse
    /// more modern C++ functionality.
    /// </summary>
    class String
    {
    public:
        std::string value { "" };
        const std::string initialValue { "" };

        const std::string *location { &value };

        String(std::string initVal)
        {
            value = initVal;

            std::string *ptr;
            ptr = (std::string*)(&initialValue);
            *ptr = value;
        }

        /// <summary>
        /// Returns the starting index of the character
        /// given in the second parameter.
        /// </summary>
        /// \param str
        /// \param find
        /// \return
        int FindIndexOf(char find)
        {
            int index { 0 };

            for (int i { 0 }; i < value.length(); ++i)
            {
                if (value[i] == find)
                {
                    index = i;
                }
            }

            return index;
        }

        /// <summary>
        /// Returns a vector of characters from a given alp::String.
        /// </summary>
        /// \param str
        /// \return
        std::vector<char> ToCharVector()
        {
            std::vector<char> toReturn;

            for (char c : value)
            {
                toReturn.push_back(c);
            }

            return toReturn;
        }
    };

    class Int
    {
    public:
        int value { 0 };
        int initialValue { 0 };

        const int *location { &value };

        Int(int initVal)
        {
            value = initVal;

            int *ptr;
            ptr = (int*)(&initialValue);
            *ptr = value;
        }

        /// Returns a string value of the int.
        /// \return
        std::string MakeString()
        {
            std::string str { std::to_string(value) };
            return str;
        }
    };
}