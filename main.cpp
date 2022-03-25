#include <bits/stdc++.h>

using namespace std;
ifstream fin("lungimeminima.in");
ofstream fout("lungimeminima.out");
const int NLIM = 999;
int n, p, l;
vector<int> M[NLIM];
queue<int> coada;
int parcurs[NLIM];

void bfs() {
    int nod, vecin;
    while (!coada.empty()) {
        nod = coada.front();

        coada.pop();
        for (int i = 0; i < M[nod].size(); i++) {
            vecin = M[nod][i];
            if (!parcurs[vecin]) {
                coada.push(vecin);
                parcurs[vecin] = parcurs[nod] + 1;
            }
        }
    }
}

void citire() {
    fin >> n >> p >> l;
    int i, j;
    while (fin >> i >> j) {
        M[i].push_back(j);
        M[j].push_back(i);
    }
    coada.push(p);
    bfs();
    int cnt = 0;
    vector<int>value;
    for (int i = 1; i <= n; i++)
        if (parcurs[i] >= l && i != p)
            value.push_back(i);
   fout<<value.size()<<endl;
    sort(value.begin(),value.end());
    for(int i=0;i<value.size();i++)
    {
       fout<<value[i]<<" ";
    }
}

int main() {
    citire();
    return 0;
}
