#include<bits/stdc++.h>
using namespace std;
float proterm(int i,float val,float x[]){
    float pro=1;
    for(int j=0;j<i;j++){
        pro *= (val - x[j]);
    }
    return pro;
}
void divideddiff(float x[],float y[][10],int n){
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            y[j][i] = (y[j][i-1] - y[j+1][i-1]) / (x[j] - x[j+i]);
        }
    }
}
float apply(float x[],float y[][10],int n,float val){
    float sum = y[0][0];
    for(int i=1;i<n;i++){
        sum+=proterm(i,val,x)*y[0][i];
    }
    return sum;
}
void print(float y[][10],int n){
    cout<<fixed<<setprecision(4);
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<setw(10)<<y[i][j];
        }
        cout<<"\n";
    }
}
int main(){
    int n; cin>>n;
    float val; cin>>val;
    float x[n],y[10][10];
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    for(int i=0;i<n;i++){
        cin>>y[i][0];
    }
    divideddiff(x,y,n);
    print(y,n);
    cout<<"Value at "<<val<<" is "<<apply(x,y,n,val)<<"\n";

}