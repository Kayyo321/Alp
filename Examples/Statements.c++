#include "../Alp.h++"

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
    boolean = Check(0, 1);

    if (boolean == 1)
    {
        Println("True! (", boolean, ")");
    }
    else if (boolean == 0)
    {
        Println("False! (", boolean, ")");
    }
}