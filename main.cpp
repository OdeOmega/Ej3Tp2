#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct triple {
    long long first;
    long long second;
    long long third;
};

struct quintuple {
    int first;
    int second;
    int third;
    int fourth;
    int fifth;

    bool operator<(const quintuple& other) const {
        if (first > other.first)
            return true;
        else if (first < other.first)
            return false;
        return second > other.second;
    }

};

struct DSU {
    vector<int> padre;
    vector<int> tam;

    DSU(int n){
        padre = vector<int>(n);
        tam = vector<int>(n,0);
        for(int i = 0; i<n;i++){
            padre[i] = i;
        }
    }
    int find(int v){
        if (padre[v] != v){
            padre[v] = find(padre[v]);
        }
        return padre[v];
    }

    void unite (int a, int b){
        a = find(a);
        b = find(b);
        if(tam[a] < tam[b]){
            swap(a,b);
        }
        padre[b] = a;
        tam[a] = tam[a]+1;
    }

};


triple kruskal(vector<quintuple> conexiones){
    long long C = 0;
    long long D = 0;
    long long R = 0;
    sort(conexiones.begin(),conexiones.end());
    DSU DSU(conexiones.size());

    int aristas = 0;

    for(int i = 0; i<conexiones.size(); i++){
        if(DSU.find(conexiones[i].second) != DSU.find(conexiones[i].third)){
            DSU.unite(conexiones[i].second,conexiones[i].third);
            C = C + conexiones[i].first;
            D = D + conexiones[i].fourth;
            R = R + conexiones[i].fifth;
            aristas++;
        }
    }
    return {C,D,R};

}

int main() {
    int cantTest, cantEdificios, cantConexiones, ed1, ed2, d, r;
    cin >> cantTest;
    for (int i = 0; i < cantTest; i++) {
        cin >> cantEdificios >> cantConexiones;
        vector<quintuple> conexiones;
        for (int j = 0; j < cantConexiones; j++) {
            cin >> ed1 >> ed2 >> d >> r;
            conexiones.push_back({d,ed1-1,ed2-1,d,r});
        }
        triple ANS = kruskal(conexiones);
        int A = 0;
        int B = ANS.first;
        while(A != B){
            int mitad = (A+B)/2;
            for(int p = 0; p<conexiones.size(); p++){
                conexiones[p].first = conexiones[p].fourth - mitad*conexiones[p].fifth;
            }
            ANS = kruskal(conexiones);
            if(ANS.first >= 0){
                A = mitad+1;
            }
            else{
                B = mitad;
            }
        }

        cout << ANS.second << " " << ANS.third << endl;
    }
}