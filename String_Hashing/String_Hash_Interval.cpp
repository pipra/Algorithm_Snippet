mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y) uniform_int_distribution<int>(x,y)(rng)
// must define int as long long
typedef uint64_t ull;
struct H {
    ull x; H(ull _x=0) : x(_x) {}
    H operator+(H o) { return x + o.x + (x + o.x < x); }
    H operator-(H o) { return *this + ~o.x; }
    H operator*(H o) { auto m = (__uint128_t)x * o.x;
        return H((ull)m) + (ull)(m >> 64); }
    ull get() const { return x + !~x; }
    bool operator==(H o) const { return get() == o.get(); }
    bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (int)rng(1e10,1e12); // (order ~ 3e9; random also ok)
 
struct HashInterval {
    vector<H> ha, pw;
    HashInterval(string& str) : ha(str.size()+1), pw(ha) {   // HashInterval H(s)
        pw[0] = 1;
        for (int i = 0; i < str.size(); i++)
            ha[i+1] = ha[i] * C + str[i],
            pw[i+1] = pw[i] * C;
    }
    H hashInterval(int a, int b) { // hash [a, b) // 0-index based
        return ha[b] - ha[a] * pw[b - a];
    }
    void insert(char a){
        ha.pb(ha.back()*C + a);
        pw.pb(pw.back()*C);
    }
};
// auto x = H.hashInterval(0, 5);  int y = x.get()
// it gives a big value that's not fit in ll
// TC = O(1)