#include <iostream>

using namespace std;
int main()
{
    float f { 100.0f };
    while ( f >= 0.01)
    {
        cout << f << endl;
        f = f / 10;
    }
}