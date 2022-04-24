#include <iostream>
#include <vector>

#include "../Alp.h++"

using namespace alp;

/// <summary>
/// This example show-cases the String class in alp.
/// </summary>
void StringDemonstration()
{
    String string { String("There") }; // initialValue. <const>
    string.value = "Hi";               // value.

    // Print's out 'Hi There' using the 'Println' method.
    Println(string.value, " ", string.initialValue);

    // Print's out the location of the 'string' variable.
    Println("The location of the 'string' variable is : ", string.location);

    // Returns a vector of characters based on the 'string' variable's value.
    std::vector<char> charVector { string.ToCharVector() };

    for (char c : charVector)
    {
        Println(c);
    }

    string.value = "What's the index?";

    // Will find the index of the letter 'i' in the 'string' variable.
    int index { string.FindIndexOf('i') };

    Println(string.value);
    Println("The index of 'i' is : ", index);
}