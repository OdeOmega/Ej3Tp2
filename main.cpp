#include <iostream>
#include <vector>
#include <climits>
#include<list>
#include <algorithm>
using namespace std;

long minInf = LONG_MIN;

struct sextuple {
    float first;
    int second;
    int third;
    int fourth;
    int fifth;
    int sixth;

    bool operator<(const sextuple& other) const {
        if (first > other.first)
            return true;
        else if (first < other.first)
            return false;
        return second < other.second;
    }
};

pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) {
    int sum_first = a.first + b.first;
    int sum_second = a.second + b.second;
    return make_pair(sum_first, sum_second);
}


pair<int,int> maximizar(vector<sextuple> conexiones, vector<bool> usado){
    int R = 0;
    int D = 0;
    for(int i = 0; i < conexiones.size();i++){
        if(!usado[conexiones[i].third] || !usado[conexiones[i].fourth]){
            usado[conexiones[i].third] = true;
            usado[conexiones[i].fourth] = true;
            D = D+conexiones[i].fifth;
            R = R+conexiones[i].sixth;
        }
    }
    return {D,R};
}


int main() {
    int cantTest, cantEdificios, cantConexiones, ed1, ed2, d, r;
    cin >> cantTest;
    for (int i = 0; i < cantTest; i++) {
        cin >> cantEdificios >> cantConexiones;
        vector<sextuple> conexiones;
        for (int j = 0; j < cantConexiones; j++) {
            cin >> ed1 >> ed2 >> d >> r;
            float div = static_cast<float>(d) / static_cast<float>(r);
            div = div / static_cast<float>(d-r);
            conexiones.push_back({div,d-r,ed1-1,ed2-1,d,r});
        }
        sort(conexiones.begin(),conexiones.end());
        vector<bool> usado(cantEdificios,false);
        pair<int,int> ANS = maximizar(conexiones,usado);
        cout << ANS.first << " " << ANS.second << endl;
    }
}