#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, q;
    cin>>n>>m>>q;
    vector<vector<char>> mat;
    for(int i=0; i<n; i++){
        vector<char> temp;
        for(int j=0; j<m; j++){
            char rand;
            cin>>rand;
            temp.push_back(rand);
        }
        mat.push_back(temp);
    }
    return 0;
}