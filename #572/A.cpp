#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin>>s;
    vector<pair<int, int>> storage(n, make_pair(0, 0));
    storage[n-1] = s[n-1]=='0'?make_pair(1, 0):make_pair(0, 1);
    for(int i=n-2; i>=0; i--){
        if(s[i]=='0'){
            storage[i].first = storage[i+1].first+1;
            storage[i].second = storage[i+1].second;
        }else{
            storage[i].first = storage[i+1].first;
            storage[i].second = storage[i+1].second+1;
        }
    }
    if(storage[0].first!=storage[0].second){
        cout<<1<<endl;
        cout<<s<<endl;
    }else{
        int current_0= s[0]=='0'?1:0;
        int current_1 = 1-current_0;
        int partition=-1;
        for(int i=1; i<n; i++){
            if(current_0!=current_1 && storage[i].first!=storage[i].second){
                partition= i;
                break;
            }else{
                current_0 += s[i]=='0'?1:0;
                current_1 += s[i]=='1'?1:0;
            }
        }
        cout<<2<<endl;
        for(int i=0; i<partition; i++){
            cout<<s[i];
        }
        cout<<" ";
        for(int i=partition; i<n; i++){
            cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}