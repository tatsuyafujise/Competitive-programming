#include <bits/stdc++.h>
using namespace std;
void init(int n); 
vector<int>par;//n の親
int root(int x);//x の根
bool same(int x,int y);//x とy が同じ集合に属しているか
void unite(int x,int y);//x とy の属する集合を併合
int main() {
    int n,q;
    cin>>n>>q;
    init(n);
    while(q>0){
        int p,a,b;
        cin>>p>>a>>b;
        if(p==0){
            unite(a,b);
        }
        else{
            if(same(a,b)){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
       q--; 
    }
    return 0;
}
void init(int n){
    par.resize(n);
    for(int i=0;i<n;i++)
    par[i]=i;
}
int root(int x){
    if(par[x]==x){
        return x;
    }
    else{
        return par[x]=root(par[x]);//経路圧縮
    }
}
bool same(int x,int y){
    return root(x)==root(y);
}
void unite(int x,int y){
    x=root(x);y=root(y);
    if(x==y)return;
    par[x]=y;
}
