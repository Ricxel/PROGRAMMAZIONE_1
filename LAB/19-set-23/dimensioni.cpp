using namespace std;
#include <iostream>

int main()
{
    enum e{
        shits,
        boobs,
        niga,
        ass,
        gnam,
        gron
    };
    cout << "Dimensioni fondamentali: " << endl << "----------------------" << endl
    << "int:\t" << sizeof(int) << endl
    << "short:\t" << sizeof(short) << endl
    << "long:\t" << sizeof(long) << endl
    << "bool:\t" << sizeof(bool) << endl
    << "enum:\t" << sizeof(e) << endl
    << "char:\t" << sizeof(char) << endl
    << "float:\t" << sizeof(float) << endl
    << "double:\t" << sizeof(double) << endl;
}