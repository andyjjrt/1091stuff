#include <iostream>
#include <string>
using namespace std;

int main(){
    string text;
    cout << "馬德";
    int counter = 0;
    while(1){
        cin >> text;
        if(cin.eof()){
            break;
        }
        if(counter != 0){
            cout << "\n";
        }
        cout << text;
        counter++;
    }
    cout << "!!";
    
}