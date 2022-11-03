#include <iostream>

#include "Solution.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

// int main(void){
//     cout << "Test begin -->" << endl;
    
//     return 0;
// }

TEST_CASE("Testing a fake test"){
    // cout << "Fake test begin" << endl;
    int len = 13;
    CHECK(len == 13);
}
TEST_CASE("Testing Stock prices"){
    Solution *solution =  new Solution();
    SUBCASE("One"){
        vector<int> arr = {7,1,5,3,6,4};
        CHECK(solution->maxProfit(arr) == 7);
    }
    SUBCASE("Two"){
        vector<int> arr = {1,2,3,4,5};
        CHECK(solution->maxProfit(arr) == 4);
    }
    SUBCASE("Three"){
        vector<int> arr = {7,6,4,3,1};
        CHECK(solution->maxProfit(arr) == 0);
    }
}