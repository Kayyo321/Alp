#include <vector>

#include "../Alp/Alp.h++"

using namespace alp;

/// <summary>
/// This example show-cases the String class in alp.
/// </summary>
void StringDemonstration()
{
    String string {"There"}; // initialValue.
    string.Assign("Hi");      // value.

    // Print's out 'Hi There' using the 'Println' method.
    Println(string.value, " ", string.intitialValue);

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