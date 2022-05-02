#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace alp
{
    //region --== Statements ==--

    //region Println
    template<typename T>
    [[maybe_unused]] void Println(T t)
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
    void Println(T t, Args... args)
    {
        std::cout << t;

        Println(args...);

        std::cout << '\n';
    }
    //endregion

    //region PrintASCII
    /// <summary>
    /// This method print's out the ascii values of the provided string.
    /// </summary>
    /// \tparam std::string
    [[maybe_unused]] void PrintASCII(std::string str)
    {
        try
        {
            std::vector<std::string> intStack { "" };

            for (int i { 0 }; i < str.length(); ++i)
            {
                std::cout << (int)str[i];
            }
        }
        catch (...)
        {
            throw std::runtime_error("Incorrect parameters for 'PrintASCII'");
        }

        std::cout << '\n';
    }

    [[maybe_unused]] bool StringIsDigit(std::string str)
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

    //endregion

    //region StringIsAlpha && StringIsDigit
    [[maybe_unused]] bool StringIsAlpha(std::string str)
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
    //endregion

    //region GetInput
    [[maybe_unused]] std::string GetInput()
    {
        std::string toReturn;
        std::getline(std::cin, toReturn); // Gets the user's input.

        return toReturn;
    }
    //endregion

    //region SpliceString
    /// <summary>
    /// This function returns a vector of strings that contain strings that you chose to splice between
    /// </summary>
    /// \param str
    /// \param find
    /// \return
    [[maybe_unused]] std::vector<std::string> SpliceString(const std::string& str, char find)
    {
        std::vector<std::string> output;
        std::string temp;

        for (char c: str)
        {
            if (c == find) {output.push_back(temp); temp.erase();}
            else {temp += c;}
        }

        return output;
    }
    //endregion
    //endregion

    //region --== Data Types ==--

    //region String
    /// <summary>
    /// The reason to create this data type is to add an automatic
    /// const to the variable (which holds the initial value), and add more modern functionality
    /// such as 'ToCharVector' instead of 'ToCharArray', to use endorse
    /// more modern C++ functionality.
    /// </summary>
    class [[maybe_unused]] String
    {
    public:
        std::string value;
        const std::string initialValue;

        [[maybe_unused]] const std::string *location { &value };

        [[maybe_unused]] explicit String(std::string initVal)
        {
            value = std::move(initVal);

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
        [[maybe_unused]] int FindIndexOf(char find)
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
        [[maybe_unused]] std::vector<char> ToCharVector()
        {
            std::vector<char> toReturn;

            for (char c : value)
            {
                toReturn.push_back(c);
            }

            return toReturn;
        }
    };
    //endregion

    //region Int
    class [[maybe_unused]] Int
    {
    public:
        int value { 0 };
        const int initialValue { 0 };

        [[maybe_unused]] const int *location { &value };

        [[maybe_unused]] explicit Int(int initVal)
        {
            value = initVal;

            int *ptr;
            ptr = (int*)(&initialValue);
            *ptr = value;
        }

        /// Returns a string value of the int.
        /// \return
        [[maybe_unused]] [[nodiscard]] std::string MakeString() const
        {
            std::string str { std::to_string(value) };
            return str;
        }
    };
    //endregion

    //region Pointer
    /// <summary>
    /// This class holds pointer data such as location, value, and even a vector, named 'pastLocations',
    /// which could potentially prevent memory leaks, since the past locations are stored automatically
    /// whenever the 'Locate' method is called.
    /// </summary>
    /// \tparam T
    template<class T>
    class Pointer
    {
    public:
        std::vector<T*> pastLocations {};

        T *location {nullptr};
        T value {};

        explicit Pointer(T *t)
        {
            location = t;
            value    = *location;
        }

        void Locate(T *t)
        {
            pastLocations.push_back(location);

            location = t;
            value    = *location;
        }

        void Log([[maybe_unused]] std::vector<T*> past)
        {
            std::cout << "(" << std::endl;

            for ([[maybe_unused]] auto a: past)
            {
                std::cout << " {" << a << "}" << std::endl;
            }

            std::cout << ")" << std::endl;
        }

        void Log()
        {
            std::cout << "{" << location << "} : '" << value << "'." << std::endl;
        }
    };
    //endregion
    //endregion
}