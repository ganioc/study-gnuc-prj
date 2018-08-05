#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    using namespace std;

    cout << "hi testfan.cc" << std::endl;
    vector<char> vec = {1, 2, 3, 4};
    int search_value = 45;

    vector<char>::const_iterator iter;
    iter = find(vec.begin(), vec.end(), search_value);

    cout << "The value " << search_value
         << ((iter == vec.end()) ? " is not present." : " is present.")
         << endl;

    for (int i : vec)
    {
        cout << i << ";" << endl;
    }

    enum class apple
    {
        green,
        red
    };
    cout << (apple::green == apple::red) << endl;

    return 1;
}