#include "../Alp/Alp.h++"

using namespace alp;

/// <summary>
/// This example show-case's all of the statement methods in alp.
/// </summary>
void StatementDemonstration()
{
    // Using the 'Println' method to print to the screen.
    // This method automatically adds a new line once all parameter's have been printed.
    // (Will not flush the buffer!)
    Println("This is one parameter", "And this is another!", 123);

    String str { String("") };

    // Using the 'GetInput' method to get input from the user to put text into the 'str' variable.
    // (Will return a string. Does not cut off the string if a space is in the input.)

    str.value = GetInput();

    int boolean { 0 };

    // Using the 'Check' method to check if two parameters are equal.
    // 0: false. 1: true.
    boolean = Check("foo", "bar");

    if (boolean == 1)
    {
        Println("True! (", boolean, ")");
    }
    else if (boolean == 0)
    {
        Println("False! (", boolean, ")");
    }

    // Print's out '72101108108111328711111410810033' using the 'PrintASCII'
    // method, because that is the ASCII value of 'Hello World!'.
    PrintASCII("Hello World!");

    // Print's out 'Hello World!' using the 'PrintASCII' method, because that is
    // the string conversion of the ASCII value : '72101108108111328711111410810033'.
    PrintASCII("72101108108111328711111410810033");

    // Using the 'StringIsDigit' method, we check if a string is of numeric value.
    // (Will return false);
    Println(StringIsDigit("Hi"));

    // Using the 'StringIsAlpha' method, we check if a string is of alphabetical value.
    // (Will return true);
    Println(StringIsAlpha("Hi"));
}
