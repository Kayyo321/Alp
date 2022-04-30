#include "../Alp/Alp.h++"

using namespace alp;

/// <summary>
/// This example show-case's all of the statement methods in alp.
/// </summary>
void StatementDemonstration()
{
    //region Println
    // Using the 'Println' method to print to the screen.
    // This method automatically adds a new line once all parameter's have been printed.
    // (Will not flush the buffer!)
    Println("This is one parameter", "And this is another!", 123);
    //endregion

    //region GetInput
    String str { String("") };

    // Using the 'GetInput' method to get input from the user to put text into the 'str' variable.
    // (Will return a string. Does not cut off the string if a space is in the input.)
    str.value = GetInput();
    //endregion

    //region Check
    int boolean { 0 };

    // Using the 'Check' method to check if two parameters are equal.
    boolean = Check("foo", "bar");

    if (boolean == 1)
    {
        Println("True! (", boolean, ")");
    }
    else if (boolean == 0)
    {
        Println("False! (", boolean, ")");
    }
    //endregion

    //region PrintASCII
    // Print's out '72101108108111328711111410810033' using the 'PrintASCII'
    // method, because that is the ASCII value of 'Hello World!'.
    PrintASCII("Hello World!");
    //endregion

    //region StringIsDigit && StringIsAlpha
    // Using the 'StringIsDigit' method, we check if a string is of numeric value.
    // (Will return false);
    Println(StringIsDigit("Hi"));

    // Using the 'StringIsAlpha' method, we check if a string is of alphabetical value.
    // (Will return true);
    Println(StringIsAlpha("Hi"));
    //endregion

    //region SpliceString
    std::string unSpliced {"Hello World!"};
    std::vector<std::string> spliced {};

    // Using the 'SpliceString' method, we return a vector of strings, with each
    // element being a string cut around the given character.
    // (Will return 'Hello', and 'World!'.)
    spliced = alp::SpliceString(unSpliced, ' ');

    for (std::string s: spliced)
    {
        alp::Println(s);
    }
    //endregion
}
