#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int start=0;
    int end=9;
    int x;
    cin>>x;
    while(start<=end){
        int mid=(start +end)/2;
        if(arr[mid]==x){
            cout<<"element found at:"<<mid+1<<endl;
            break;
        }
        else if(arr[mid]>x){
            end=mid-1;
        }
        else if(arr[mid]<x){
            start=mid+1;
        }
    }
    return 0;
}
