// PIPRA ||  HABIB
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int        long long int
#define pb         push_back
#define all(x)     x.begin(),x.end()
#define allr(x)    x.rbegin(),x.rend()
#define ii         pair<int,int>
#define endl       "\n"

template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) {
    os << '{';
    for (const auto &x : v) os << " " << x;
        return os << '}';
}
using orderedTree = tree<int, null_type, less<int>, 
rb_tree_tag, tree_order_statistics_node_update>;

void pipra(){
    $1
}

int32_t main(){
    // HABIB
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int t;    cin>>t;
    while(t--) {
        pipra();
    }
    return 0 ;
}
