#include "../Alp/Alp.h++"

using namespace alp;

/// <summary>
/// This example show-case's the Int class in alp.
/// </summary>
void IntegerDemonstration()
{
    Int integer { Int(20) }; // InitialValue. <const>
    integer.value = 100;     // Value.

    // Printing out the current value of 'integer', and the initialized one.
    Println("the 'integer' variables current value is       : ", integer.value);
    Println("The initial value of the 'integer' variable is : ", integer.initialValue);

    // Printing out the location of the variable 'integer'.
    Println("The location of the 'integer' variable is      : ", integer.location);

    // Making the 'integer' variable a string using the MakeString method attached to it.
    String newStr { String(integer.MakeString()) };

    // Printing out the string counter-part to the 'integer' variable.
    Println(newStr.value);
}