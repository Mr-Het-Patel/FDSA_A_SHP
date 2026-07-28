#include<iostream>
#include<string>
using namespace std;
int main(){
string arr[6]={"GJ-02-0090","GJ-02-0303","MH-04-9493","HR-09-2827","JK-27-3027","HR-09-2827"};
string target= "HR-09-2827";

for(int i=0;i<5;i++){
    if (arr[i]==target){
        cout<<" Found at position : "<<i+1<<endl;
        break;
    }
}
}
