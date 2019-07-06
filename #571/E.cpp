#include <bits/stdc++.h>

using namespace std;

int getSum(int x, int y, vector<vector<int>>&mat, vector<vector<int>>&sumRec){
    cout<<"Finding for "<<x<<" "<<y<<endl;
    int ret=0;
    int rows = mat.size()-1, columns=mat[0].size()-1;
    int nearestX, nearestY;
    nearestX = (x-1)/columns*columns+1;
    nearestY = (y-1)/rows*rows+1;
    int countRow = (nearestX-1)/columns;
    int countCol = (nearestY-1)/rows;
    int blocks = countCol*countRow;
    cout<<"Closest x is "<<nearestX<<endl;
    cout<<"Closest y is "<<nearestY<<endl;
    cout<<"Row before it "<<countRow<<endl;
    cout<<"Columns before it "<<countCol<<endl;
    if(blocks%2==0){
        cout<<rows<<columns<<blocks<<((rows*columns)*blocks/2)<<endl;
        ret += (rows*columns)*(blocks/2);
    }else{
        cout<<rows<<columns<<blocks<<(rows*columns)*(blocks/2) +(sumRec[rows][columns])*(blocks-blocks/2*2)<<endl;
        ret += ((rows*columns)*(blocks/2) + (sumRec[rows][columns])*(blocks-blocks/2*2));
    }
    cout<<"After the complete boxes "<<ret<<endl;
    int xNorm = x - nearestX +1;
    int yNorm = y - nearestY +1;
    cout<<"Normalized "<<xNorm<<" "<<yNorm<<endl;
    if(countRow%2==0){
        ret += (sumRec[rows][yNorm]*(countRow/2));
    }else{
        if(countCol%2==0){
            ret += ((rows*yNorm)*(countRow/2) + sumRec[rows][yNorm]*(countRow-(countRow/2)*2));
        }else{
            ret += ((rows*yNorm)*(countRow/2) + (xNorm*columns - sumRec[rows][yNorm])*(countRow-(countRow/2)*2));
        }
    }
    cout<<"After the complete column "<<ret<<endl;
    if(countCol%2==0){
        ret += (sumRec[xNorm][columns]*countCol/2);
    }else{
        if(countRow%2==0){
            ret += ((xNorm*columns)*(countCol/2) + (sumRec[xNorm][columns])*(countCol-(countCol/2)*2));
        }else{
            ret += ((xNorm*columns)*(countCol/2) + (rows*yNorm - sumRec[xNorm][columns])*(countCol-(countCol/2)*2));
        }
    }
    cout<<"After the complete rows "<<ret<<endl;
    if((countRow%2==0&&countCol%2==0)||(countRow%2==1&&countCol%2==1)){
        ret += sumRec[xNorm][yNorm];
    }else{
        ret += xNorm*yNorm - sumRec[xNorm][yNorm];
    }
    
    return ret;
}

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> mat(n+1, vector<int>(m+1, 0));
    vector<vector<int>> sumRec(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++){
        string s;
        cin>>s;
        for(int j=1; j<=m; j++){
            mat[i][j]=(s[j-1]-'0');
            sumRec[i][j] = sumRec[i-1][j]+sumRec[i][j-1]-sumRec[i-1][j-1]+mat[i][j];
        }
    }
    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=m; j++){
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=m; j++){
    //         cout<<sumRec[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    while(q--){
        int x1, x2, y1, y2;
        cin>>x1>>y1>>x2>>y2;
        if(x1>x2){
            swap(x1, x2);
        }
        if(y1>y2){
            swap(y1, y2);
        }
        cout<<getSum(x1-1, y1-1, mat, sumRec)<<endl;
        cout<<getSum(x1-1, y2, mat, sumRec)<<endl;
        cout<<getSum(x2, y1-1, mat, sumRec)<<endl;
        cout<<getSum(x2, y2, mat, sumRec)<<endl;
        // cout<<getSum(x2, y2, mat, sumRec)-getSum(x1-1, y2, mat, sumRec)-getSum(x2, y1-1, mat, sumRec)+getSum(x1-1, y1-1, mat, sumRec)<<endl;
    }
    return 0;
}