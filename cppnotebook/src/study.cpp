#include <vector>
#include <algorithm>

#include "study.h"

using namespace std;

void test_2()
{
    // partial sort
    vector<int> vec{45, 23, 67, 6, 29, 44, 90, 3, 64, 18};
    auto middle = vec.begin() + 5;
    partial_sort(vec.begin(), middle, vec.end());

    cout << "smallest items" << endl;
    for_each(vec.begin(), middle, [](int i)
             { cout << i << " "; });
    cout << endl;

    cout << "biggest items" << endl;
    for_each(middle, vec.end(), [](int i){ cout << i << ' ';});
    cout << endl;
    
}

namespace STUDY
{
    void testAlg(void)
    {
        cout << "test algorithm" << endl;

        vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 7, 7, 8, 9};
        vector<int>::iterator it = vec.begin();

        do
        {
            it = adjacent_find(it, vec.end());
            if (it != vec.end())
            {
                cout << "duplicate: " << *it << endl;

                ++it;
            }
        } while (it != vec.end());

        test_2();
    }
}