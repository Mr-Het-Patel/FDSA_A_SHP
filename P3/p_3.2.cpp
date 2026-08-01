/*
A teacher has a stack of student answer sheets with marks written on them and needs to
arrange them in order before entering grades. In the third method, she picks
each sheet one by one and inserts it into its correct position among the already-arranged
sheets.

This file: Insertion sort implementation (p_3.2.cpp)
*/

#include <iostream>
using namespace std;

int main(){
    int arr[] = {2,6,3,8,7,4,5,1,0,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }

    for(int i = 0; i < n; i++){
        cout << " " << arr[i];
    }
    cout << endl;
    return 0;
}
