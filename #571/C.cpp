#include <bits/stdc++.h>

using namespace std;

int main(){
    string a, b;
    cin>>a;
    cin>>b;
    int ret=0;
    int cntb=0, cnta=0;
    for(int i=0; i<b.size(); i++){
        if(b[i]=='1'){
            cntb++;
        }
        if(a[i]=='1'){
            cnta++;
        }
    }
    int check = cntb%2;
    if(cnta%2==check)ret++;
    for(int i=b.size(); i<a.size(); i++){
        if(a[i-b.size()]=='1'){
            cnta--;
        }
        if(a[i]=='1'){
            cnta++;
        }
        if(cnta%2==check)ret++;
    }
    cout<<ret<<endl;
    return 0;
}