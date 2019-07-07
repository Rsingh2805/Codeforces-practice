#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> vec(n+1, 0);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        vec[a]++;
        vec[b]++;
    }
    for(int i=1; i<=n; i++){
        if(vec[i]==2){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}