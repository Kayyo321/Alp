#pragma once

#include <iostream>

#include <vector>

#include <string>
#include <string_view>

#include <initializer_list>

namespace alp
{
    // --== Statements ==--
    // https://stackoverflow.com/questions/1657883/variable-number-of-arguments-in-c

    template<typename T>
    void Println(T t)
    {
        std::cout << t;
    }

    /// <summary>
    /// The purpose of having yet another printing
    /// statement is that this one automatically starts a new line,
    /// making the user type less, but this funcion uses '\n', instead of 'std::endl'
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