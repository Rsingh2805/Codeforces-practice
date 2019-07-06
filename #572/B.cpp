#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int first = INT_MIN, second=INT_MIN, third=INT_MIN;
    vector<int> A(n, 0);
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    sort(A.begin(), A.end());
    if(A[n-1]>=A[n-2]+A[n-3]){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        int i;
        for(i=n-1; i>=0; i-=2){
            cout<<A[i]<<" ";
        }
        if(i==-2){
            i=1;
        }else{
            i=0;
        }
        for(; i<n; i+=2){
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}