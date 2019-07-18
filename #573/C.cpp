#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n, m, k;
    cin>>n>>m>>k;
    long long curr_start=1;
    long long curr_end=k;
    long long curr_count=0;
    long long ret=0;  
    long long i=0;
    long long temp;
    bool removed=false;
    cin>>temp;
    i++;
    while(i<=m){
        if(temp>curr_end){
            if(curr_count==0){
                if(removed){
                    ret++;
                    removed=false;
                }
                long long mul;
                if((temp-curr_end)%k==0){
                    mul = (temp-curr_end)/k-1;
                }else{
                    mul = (temp-curr_end)/k; 
                }           
                curr_start=curr_end+mul*k+1;
                curr_end=curr_end + mul*k + k;
            }else{
                if(removed){
                    ret++;
                    removed=false;
                }
                curr_end+=curr_count;
                curr_count=0;
            }
        }else{
            removed=true;
            curr_count++;
            i++;
            cin>>temp;
        }
        // cout<<temp<<" "<<curr_count<<" "<<curr_start<<" "<<curr_end<<" "<<ret<<endl;
    }
    if(removed){
        ret++;
    }
    cout<<ret<<endl;

    return 0;
}