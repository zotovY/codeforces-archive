// https://codeforces.com/problemset/problem/1618/C

#define _USE_MATH_DEFINES
#include <time.h>

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:16777216")
#define pb push_back
#define en '\n'
#define forn(i, n) for (int i = 0; i < n; i++)
#define for0(i, n) for (int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vec vector
#define veci vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define szof(x) int(x.size())
#define sqr(x) ((x) * (x))
#define debug(x) cerr << #x << " = " << x << '\n'

using namespace std;

const int INF = 1000000000 + 1e8;
const ll LINF = 2000000000000000000;

template <typename T>
void print(vector<T>& a) {
    for (int i = 0; i < a.size(); i++) cout << a[i] << ' ';
}

template <typename T>
void input(vector<T>& a) {
    for (int i = 0; i < a.size(); i++) cin >> a[i];
}

void solve() {
    int n;
    cin >> n;
    vec<ull> a(n);
    input(a);

    ull gcd = a[0];
    for (int i = 0; i < n; i += 2) gcd = __gcd(gcd, a[i]);

    if (gcd != 1) {
        bool u = false;
        for (int i = 1; i < n && !u; i += 2) {
            if (a[i] % gcd == 0) u = true; 
        }
        if (!u) {
            cout << gcd << en;
            return;
        }
    }

    gcd = a[1];
    for (int i = 1; i < n; i += 2) gcd = __gcd(gcd, a[i]);
    if (gcd != 1) {
        bool u = false;
        for (int i = 0; i < n && !u; i += 2) {
            if (a[i] % gcd == 0) u = true; 
        }
        if (!u) {
            cout << gcd << en;
            return;
        }
    }

    cout << 0 << en;

}

int main() {
    srand(time(0));
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    int tst = 1;
    cin >> tst;

    while (tst--) solve();
}