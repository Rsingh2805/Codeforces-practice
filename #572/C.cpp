#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> prefixArray(n+1, 0);
    prefixArray[0] = 0;
    prefixArray[1]=arr[0];
    for(int i=2; i<=n; i++){
        prefixArray[i] = prefixArray[i-1]+arr[i-1];
    }

    int q;
    cin>>q;
    while(q--){
        int r, l;
        cin >> l >> r;
        cout<< (prefixArray[r]-prefixArray[l-1])/10<<endl;        
    }

}