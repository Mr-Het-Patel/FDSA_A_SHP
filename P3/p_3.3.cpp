/*
A teacher has a stack of student answer sheets with marks written on them and needs to
arrange them in order before entering grades. In the second method,
she finds the lowest-marked sheet each time and places it at the front.

This file: Selection sort implementation (p_3.3.cpp)
*/

#include <iostream>
#include <utility>
using namespace std;

int main(){
    int arr[] = {2,6,3,8,1,0,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i < n-1; i++){
        int min_idx = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        if(min_idx != i) swap(arr[min_idx], arr[i]);
    }

    for(int i = 0; i < n; i++){
        cout << " " << arr[i];
    }
    cout << endl;
    return 0;
}
