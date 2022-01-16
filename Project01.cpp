#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    float floatNum = 10.0 / 3.0;    //single precision
    double doubleNum = 10.0 / 3.0;  //multiprecision
    const float million = 1000000;  //constant(常量)

    cout << "floatNum = " << floatNum << endl;
    cout << "100w * floatNum = " << million * floatNum << endl;
    cout << "1000w * floatNum = " << 10 * million * floatNum << endl;

    //Control the display precision of "cout"
    cout << fixed ;     // "fixed" can enforce the display as a decimal(小数)
    cout << setprecision(2);    // display two digits after the decimal point (include in iomanip)
    //cout << fixed << setprecision(2);

    cout << "doubleNum = " << doubleNum << endl;
    cout << "million * doubleNum = " << million * doubleNum << endl;

    cout << setw(8) << 3.14 << endl;    //before 3.14 insert 8 spaces
}