#include <iostream>
#include <vector>
#include<list>
using namespace std;


int main() {
    int cantTest, edificios, cantConexiones,conex,ed1,ed2,d,r;
    cin >> cantTest;
    for(int i = 0; i<cantTest;i++){
        cin >> edificios >> cantConexiones;
        vector<list<vector<int>>> conexiones(edificios+1);
        for(int j = 0; j<cantConexiones;j++){
            cin >> ed1 >> ed2 >> d >> r;
            conexiones[ed1].push_back({ed2,d,r});
            conexiones[ed2].push_back({ed1,d,r});
        }
        int b = 0;
    }
    int a = 0;

}
