#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

namespace mp = boost::multiprecision; // Reduce the typing a bit later...
using namespace std;

mp::int128_t a(3);
mp::uint128_t b(4);

// mp::int512_t c(50), d;

int main(int nNumberofArgs, char *pszArgs[])
{
    uint64_t hi;
    uint64_t lo;

    cout << a << endl;
    cout << b << endl;

    // hi = a << 64;

    return 0;
}
