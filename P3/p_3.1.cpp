/*
A teacher has a stack of student answer sheets with marks written on them and needs to
arrange them in order before entering grades. She tries three different methods: in the first, she
repeatedly compares adjacent sheets and swaps them if they are out of order;

This file: Bubble sort implementation (p_3.1.cpp)
*/

#include <iostream>
#include <utility>
using namespace std;

int main(){
    int arr[] = {2,3,8,4,6,1,9,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << " " << arr[i];
    }
    cout << endl;
    return 0;
}
