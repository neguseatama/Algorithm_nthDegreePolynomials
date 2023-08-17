/*
 Algorithm : nth degree Polynomials in C++
 C++によるn次方程式の解の計算アルゴリズム
 https://github.com/neguseatama
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll n;
double start,error;
//項の数をnとして、
//初期値の入力をstartで受け取り、
//誤差限界の入力をerrorで受け取る。

vector<pair<ll,ll>> term;
//termに項の係数・指数のデータを追加する。

//微分を実行する関数
pair<ll,ll> differentiate(pair<ll,ll> p){
    return {p.first*p.second,p.second-1};
}

//ニュートン法の反復計算を実行する関数
double newton(void){
    double ans=start;
    double numerator=0.0,dinominater=0.0;
    for(ll i=0;i<n;i++){
        numerator+=term[i].first*pow(start,term[i].second);
        
        pair<ll,ll> p=differentiate(term[i]);
        dinominater+=p.first*pow(start,p.second);
    }
    
    double ans2=start-numerator/dinominater;
    
    while(abs(ans-ans2)>=error){
        ans=ans2;
        
        double nume=0.0,dino=0.0;
        for(ll i=0;i<n;i++){
            nume+=term[i].first*pow(ans,term[i].second);
            
            pair<ll,ll> p=differentiate(term[i]);
            dino+=p.first*pow(ans,p.second);
        }
        ans2=ans-nume/dino;
    }
    return ans2;
}

int main(void){
    cin>>start>>error;
    cin>>n;
    for(ll i=0;i<n;i++){
        ll x,d;
        cin>>x>>d;
        //termに入れるために係数x・指数dを入力として受け取る。
        term.push_back({x,d});
    }
    cout<<fixed<<setprecision(30)<<newton()<<endl;
    return 0;
}