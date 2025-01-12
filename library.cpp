#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>
#include <tuple>
#include <cmath>
#include <chrono>
#include <fstream>
// #define MOD (998244353l)
#define MOD (1000000007l)
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define PI (3.1415926535897932)
#define all(x) x.begin(), x.end()
#define Yes  cout << "Yes" << endl;  
#define No  cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl 
using namespace std;
const double pi = 3.141592653589793238;
const ll inf = 1073741823;
const ll infl = 1LL << 60;
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string abc = "abcdefghijklmnopqrstuvwxyz";
string inputfilename = "input.txt";
string outputfilename = "output.txt";
ifstream in(inputfilename);
ofstream out(outputfilename);



/*ランレングス圧縮
stringを引数にとりfirstに文字secondに数を入れたvector<pair<char,ll>>を返す
*/
vector<pair<char,ll>> RLE(string S){
    vector<pair<char,ll>> res;
    ll i;
    char c = S[0];
    ll cnt = 1;
    for(i = 1;i<S.size();i++){
        if(S[i] == c){
            cnt++;
        }
        else{
            res.push_back({c,cnt});
            c = S[i];
            cnt = 1;
        }
    }
    res.push_back({c,cnt});
    return res;
}

/*エラトステネスの篩
vector<bool>でN個の要素の配列を返す trueで素数
*/


vector<bool>  sieve(ll N) {
    vector<bool> isp(N+1, true);
    isp[0] = false;
    isp[1] = false;
    for (int i=2; pow(i,2)<=N; i++) {
        if (isp[i]) {
            for(int j=2; i*j<=N; j++) isp[i*j] = false;
        }
    }
    return isp;
}

void solve() {
    ll N,value;
    vector<ll> A(N);

    //ファイルから入力
    in >> N;
    while(in >> A[N]){
        N++;
    }
    //ファイルに出力
    out << N << endl;

    //逆順ソート
    sort(all(A));
    reverse(all(A));

    
    //vector<pair<ll.ll>を二個目の要素をもとにソート
    sort(all(A),[](pair<ll,ll> a,pair<ll,ll> b){
        return a.second < b.second;
    });

    //最初に出現するvalue以上の要素のindexを返す
    auto it = lower_bound(all(A),value);

    //最初に出現するvalueより大きい要素のindexを返す
    auto it = upper_bound(all(A),value);
}

int main(void){ 
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
    in.close();
    out.close();
}


