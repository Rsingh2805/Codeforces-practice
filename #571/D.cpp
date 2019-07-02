#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    vector<int> can(n, 0);
    long current = 0;
    for(int i=0; i<n; i++){
        float temp;
        cin>>temp;
        arr[i] = floor(temp);
        current+=arr[i];
        if(ceil(temp)==floor(temp)){
            can[i] = -1;
        }
    }
    int j=0;
    for(int i=0; i<n; i++){
        if(current==0){
            break;
        }else{
            if(can[i]==0){
                arr[i]++;
                current++;
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}