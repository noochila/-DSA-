#include "bits/stdc++.h"
#define rep(i, a, n) for (auto i = a; i <= (n); ++i)
#define revrep(i, a, n) for (auto i = n; i >= (a); --i)
#define all(a) a.begin(), a.end()
#define sz(a) (int)(a).size()
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
using namespace std;
 
template<class A, class B> string to_string(const pair<A, B> &p);
template<class A, class B, class C> string to_string(const tuple<A, B, C> &p);
template<class A, class B, class C, class D> string to_string(const tuple<A, B, C, D> &p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string) s); }
string to_string(char c) { return "'" + string(1, c) + "'"; }
string to_string(bool x) { return x ? "true" : "false"; }
template<size_t L> string to_string(const bitset<L> &x) { return x.to_string(); }
template<class A, class T = typename A::value_type> string to_string(const A &v) {
	bool first = 1;
	string res = "{";
	for (const auto &x: v) {
		if (!first) res += ", ";
		first = 0;
		res += to_string(x);
	}
	res += "}";
	return res;
}
template<class A, class B> string to_string(const pair<A, B> &p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template<class A, class B, class C> string to_string(const tuple<A, B, C> &p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
template<class A, class B, class C, class D> string to_string(const tuple<A, B, C, D> &p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }
template<class H, class... T> void debug_out(const H& h, const T&... t) {
	cerr << " " << to_string(h);
	debug_out(t...);
}
#ifndef ONLINE_JUDGE
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
	#define debug(...) if (0) puts("No effect.")
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

/**
 * Author: Yuhao Yao
 * Date: 23-05-11
 * Description: Modular integer with $mod \le 2^{31} - 1$. Note that there are several advantages to use this code:
   1. You do not need to keep writing $\%\, mod$;
   2. It is good to use this struct when doing Gaussian Elimination / Fast Walsh-Hadamard Transform;
   3. Sometimes the input number is greater than $mod$ and this code handles it.
  Do not write things like $mint\{1 / 3\}.pow(10)$ since $1 / 3$ simply equals $0$.
  Do not write things like $mint\{a * b\}$ where $a$ and $b$ are int since you might first have integer overflow.
 * Usage: Define the followings globally:
   const int mod = 998244353;
   using mint = MInt<mod>;
 * Status: tested on https://ac.nowcoder.com/acm/contest/33191/F.
 */
template<const unsigned &mod>
struct MInt {
	using Z = MInt;
	unsigned x; /// start-hash
	MInt(ll a = 0): x(a % mod + mod) { if (x >= mod) x -= mod; }
	explicit operator int() const { return x; }

	Z& operator +=(Z b) { x += b.x; if (x >= mod) x -= mod; return *this; }
	Z& operator -=(Z b) { x += mod - b.x; if (x >= mod) x -= mod; return *this; }
	Z& operator *=(Z b) { x = 1ll * x * b.x % mod; return *this; }
	friend Z operator +(Z a, Z b) { return a += b; }
	friend Z operator -(Z a, Z b) { return a -= b; }
	friend Z operator -(Z a) { return Z{} - a; }
	friend Z operator *(Z a, Z b) { return a *= b; }
	/// end-hash

	// the followings are for ntt and polynomials.
	Z pow(ll k) const { /// start-hash
		Z res = 1, a = *this;
		for (; k; k >>= 1, a = a * a) if (k & 1) res = res * a;
		return res;
	}
	Z& operator /=(Z b) {
		assert(b.x != 0);
		return *this *= b.pow(mod - 2);
	}
	friend Z operator /(Z a, Z b) { return a /= b; }
	friend bool operator ==(Z a, Z b) { return a.x == b.x; }
	friend bool operator !=(Z a, Z b) { return a.x != b.x; }
	friend bool operator <(Z a, Z b) { return a.x < b.x; }

	static unsigned get_mod() { return mod; } // ntt need this.
	/// end-hash

	friend istream& operator >>(istream &is, Z &a) {
		ll v; is >> v;
		a = v;
		return is;
	}
	friend string to_string(Z a) { return to_string(a.x); }
};

class Solution {
public:
	int countWinningSequences(string as) {
		static const unsigned mod = 1e9 + 7;
		using mint = MInt<mod>;

		static map<char, int> mp;
		mp['F'] = 0;
		mp['W'] = 1;
		mp['E'] = 2;

		int n = sz(as);
		static vector<vector<mint>> dp;
		dp.assign(n * 2 + 1, vector<mint>(3, 0));
		dp[n][0] = 1;
		rep(r, 0, n - 1) {
			int x = mp[as[r]];
			static vector<vector<mint>> ndp;
			ndp.assign(n * 2 + 1, vector<mint>(3, 0));
		
			rep(i, 0, n * 2) rep(last, 0, 2) if (dp[i][last] != 0) {
				rep(y, 0, 2) {
					if (r > 0 && y == last) {
						continue;
					}
					int ni = i;
					if (y == (x + 1) % 3) ni++;
					else if (y == (x + 2) % 3) ni--;
					ndp[ni][y] += dp[i][last];
				}
			}
			swap(dp, ndp);
		}
		mint ans = 0;
		rep(i, n + 1, n * 2) rep(last, 0, 2) ans += dp[i][last];
		return (int) ans;
	}
};