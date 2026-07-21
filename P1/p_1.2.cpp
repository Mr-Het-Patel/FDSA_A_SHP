#include <iostream>

using namespace std;

int main() 
{
    int size=7;
    int arr[100]={101, 102, 103, 101, 104, 102, 105};

    bool already_printed[100]={false};

    for(int i=0;i<size;i++) {
        int count=0;
        
        for(int j=0;j<size;j++) {
            if (arr[i]==arr[j]) {
                count++;
            }
        }

        if (count>1 && !already_printed[i]) {
            cout<<arr[i]<<" ";
            
            for(int k=i;k<size;k++) {
                if(arr[k]==arr[i]) {
                    already_printed[k]=true;
                }
            }
        }
    }
    cout<<endl;

    return 0;
}
