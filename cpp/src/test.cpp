#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "Test " << endl;
    float v[] = {1.0, 22, 5.1, 14, 100, 20, 27, 9};

    const int n = 8;

    cout << "vector size: " << n << endl;
    for( size_t i=0; i< n; i++){
        cout << i << " " << v[i] << endl;
    }

    for(int gap =n/2; gap > 0; gap/=2){
        for(int i=gap; i<n; i++){
            for(int j=i-gap; 0<=j; j-=gap){
                if(v[j+gap] < v[j]){
                    float temp = v[j];
                    v[j] = v[j+gap];
                    v[j+gap] = temp;
                }
            }
        }
    }


    cout << "after sorting" << endl;

    for( size_t i=0; i< n; i++){
        cout << i << " " << v[i] << endl;
    }
    return 0;
}