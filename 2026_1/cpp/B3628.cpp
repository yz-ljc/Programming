#include <bits/stdc++.h>
using namespace std;

int main() {
    int num;
    cin >> num;
    int health = 1,current_health = 0,damage_sum = 0,damage = 0;
    for (int i = 0;i < num;i++) {
        cin >> damage;
        current_health += damage;
        damage_sum = min(damage_sum,current_health);
    }
    health = -damage_sum + 1;
    cout << health << endl;
    return 0;
}