#include <iostream>
using namespace std;

int main(){
    int T,s,t;
    cin >> T >> s >> t;
    if (s){
        if (T >= 35 && t >= 33){
            cout << "Bu Tie" << "\n" << T << endl;
        }else{
            cout <<"Bu Re" << "\n" << t << endl;
        }
    }else if ((T < 35 || t < 33) && s == 0) {
        cout << "Shu Shi" << "\n" << t << endl;
    }else{
        cout << "Shi Nei" << "\n" << T << endl;
    }
    return 0;
}