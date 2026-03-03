#include <iostream>

const int max_user = 30001;
int n,p,q,result;
bool isCalculated[max_user][max_user],isFriend[max_user][max_user];
int enemy_user[2][max_user];

int main() {
    std::cin >> n >> p >> q;
    result = n * (n - 1) / 2 - q;
    for (int u,v,i = 0;i < p;i++) {
        std::cin >> u >> v;
        isFriend[u][v] = isFriend[v][u] = true;
    }
    for (int u,v,i = 0;i < q;i++) {
        std::cin >> u >> v;
        isCalculated[u][v] = isCalculated[v][u] = true;
        enemy_user[0][i] = u;
        enemy_user[1][i] = v;
    }
    for (int u,v,i = 0;i < q;i++) {
        u = enemy_user[0][i];
        v = enemy_user[1][i];
        for (int w = 0;w < n;w++) {
            if (isFriend[u][w]) {
                if (!isFriend[v][w] && !isCalculated[v][w]) {
                    result--;
                    isCalculated[v][w] = isCalculated[w][v] = true;
                }
            }
        }
        for (int w = 0;w < n;w++) {
            if (isFriend[v][w]) {
                if (!isFriend[u][w] && !isCalculated[u][w]) {
                    result--;
                    isCalculated[w][u] = isCalculated[u][w] = true;
                }
            }
        }
    }
    std::cout << result;
    return 0;
}