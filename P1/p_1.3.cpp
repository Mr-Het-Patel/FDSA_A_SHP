#include <iostream>
#include <string>

using namespace std;

int main() {
    string text="The library issues incredible books to students every morning";
    
    string l_word="";
    string c_word="";
    
    for (int i=0;i<=text.length();i++){
        if (i<text.length()&&text[i]!=' ') {
            c_word=c_word+text[i];
        } 
        else {
            if (c_word.length()>l_word.length()) {
                l_word=c_word;
            }
            c_word="";
        }
    }
    
    cout<<"Word: "<<l_word<<endl;
    cout<<"Letters: "<<l_word.length()<<endl;
    
    return 0;
}
