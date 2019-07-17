#include <bits/stdc++.h>

using namespace std;

int getSol(string a, string b){
    // 0 no optioon
    // 1 is equal
    // 2 is continuous
    if(a[0]!=b[0]){
        return 0;
    }else{
        if(a[1]==b[1]){
            return 1;
        }else if(a[1]+1==b[1]){
            return 2;
        }else if(a[1]+2==b[1]){
            return 3;
        }
        return 0;
    }
}

int main(){
    vector<string> vec(3, "");
    cin>>vec[0]>>vec[1]>>vec[2];
    for(int i=0; i<3; i++){
        reverse(vec[i].begin(), vec[i].end());
    }
    sort(vec.begin(), vec.end());
    if(getSol(vec[0], vec[1])==1 && getSol(vec[1], vec[2])==1){
        cout<<0<<endl;
        return 0;
    }
    if(getSol(vec[0], vec[1])==2 && getSol(vec[1], vec[2])==2){
        cout<<0<<endl;
        return 0;
    }
    if(getSol(vec[0],vec[1])>0 || getSol(vec[1], vec[2])>0){
        cout<<1<<endl;
        return 0;
    }
    cout<<2<<endl;   
    return 0;
}