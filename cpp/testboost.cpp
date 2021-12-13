#include <iostream>
#include <boost/lambda/lambda.hpp>
#include <iterator>
#include <algorithm>

int main()
{
    // using namespace boost::lambda;
    // typedef std::istream_iterator<int> in;

    // std::for_each(
    //     in(std::cin), in(), std::cout << (_1 * 3) << " ");

    std::cout << "\n";

    auto a = std::make_pair(1, "hi");
    std::cout << a.first << " " << a.second << std::endl;

    return 0;
}
