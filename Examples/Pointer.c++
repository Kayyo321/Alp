#include "../Alp/Alp.h++"

int main()
{
    int integer  {10};
    int integer1 {20};
    int integer2 {30};

    // Using the constructor, you can create a pointer of any type,
    // and assign it to the address of any variable.
    alp::Pointer<int> pointer = alp::Pointer(&integer);

    // Using the UN-overloaded 'Log' method, we log the contents-
    // -of the current Pointers data.
    // (BASED ON MY SYSTEM)
    // (Will return: "{0x7f21fff82c} : '10'.")
    pointer.Log();

    // Using the 'Locate' method, we re-locate all the-
    // -pointers data to a new address.
    pointer.Locate(&integer1);

    // (BASED ON MY SYSTEM)
    // (Will return "{0x7f21fff828} : '20'.")
    pointer.Log();

    pointer.Log();

    // Using the 'Migrate' method, it does the same thing as-
    // -'Locate', it just sounds better in my opinion.
    // (BASED ON MY SYSTEM)
    // (Will return "{0x7f21fff824} : '30'.")
    pointer.Migrate(&integer2);

    // Using the overloaded 'Log' method, we print all the-
    // -pointers past locations. (Not including the current one.)
    pointer.Log(pointer.pastLocations);

    return 0;
}