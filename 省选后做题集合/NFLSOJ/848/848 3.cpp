#include <bits/stdc++.h>
#define rep(i, f, t) for (int i(f); i <= t; ++i)
#define re(i, t) for (int i(1); i <= t; ++i)
#define per(i, t, f) for (int i(t); i >= f; --i)
#define pe(i, t) for (int i(t); i >= 1; --i)
#define nx(i, u) for (int i(head[u]); i; i = e[i].nxt)
typedef long long ll;
typedef long double ld;
typedef __int128 i128;
// #define int long long
using namespace std;
typedef pair<int, int> pii;
#define pb push_back
#define fi first
#define se second
#define ix(l, r) ((l + r) | (l != r))
#define mp(i, j) (make_pair(i, j))
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

struct IO {
#define MAXSIZE 1 << 21
#define isdigit(x) (x >= '0' && x <= '9')
#define isspace(x) (x == ' ' || x == '\n' || x == '\r' || x == '\t')
    char ibuf[MAXSIZE], obuf[MAXSIZE], *s1, *s2, *s3, endl, blank;
    int round[10] = { 0, 0, 0, 0, 0, 1, 1, 1, 1 }, sta[65], precisions;
    bool fail;
    FILE *in_stream, *out_stream;
    IO(FILE *_stream = stdin, FILE *__stream = stdout) { reset(_stream, __stream); }
#if DEBUG
#else
    ~IO() { close(); }
#endif
    inline void reset(FILE *_stream = stdin, FILE *__stream = stdout, bool reset = true) {
        s1 = s3 = ibuf, s2 = obuf, in_stream = _stream, out_stream = __stream, fail = false;
        if (reset) {
            endl = '\n';
            blank = ' ';
            precisions = 6;
        }
    }
    inline void flush_in() { s3 = (s1 = ibuf) + fread(ibuf, 1, MAXSIZE, in_stream); }
    inline void flush_out() { fwrite(obuf, 1, s2 - obuf, out_stream), s2 = obuf; }
    inline void flush_out_with_stream() {
        flush_out();
        fflush(out_stream);
    }
    inline char get() {
#if DEBUG
        return getchar();
#endif
        return s1 == s3 && (flush_in(), fail = s1 == s3) ? 0 : *s1++;
    }
    inline void put(char ch) {
#if DEBUG
        putchar(ch);
#else
        s2 - obuf == MAXSIZE ? flush_out(), 0 : 0, *s2++ = ch;
#endif
    }
    template <class T>
    inline void read(T &x) {
        bool sign = false;
        char c = get();
        x = 0;
        while (!isdigit(c) && c) {
            sign = c == '-';
            c = get();
        }
        while (isdigit(c)) {
            x = (x << 1) + (x << 3) + (c ^ '0');
            c = get();
        }
        sign ? x = ~x + 1 : 0;
    }
    inline void read(double &x) {
        bool sign = false;
        char c = get();
        x = 0;
        while (!isdigit(c) && c) {
            sign = c == '-';
            c = get();
        }
        while (isdigit(c)) {
            x = x * 10 + (c ^ '0');
            c = get();
        }
        if (c == '.') {
            c = get();
            double tmp = 1;
            while (isdigit(c)) {
                tmp /= 10, x += tmp * (c ^ '0');
                c = get();
            }
        }
        sign ? x = -x : 0;
    }
    inline void read(long double &x) {
        bool sign = false;
        register char c = get();
        x = 0;
        while (!isdigit(c) && c) {
            sign = c == '-';
            c = get();
        }
        while (isdigit(c)) {
            x = x * 10 + (c ^ '0');
            c = get();
        }
        if (c == '.') {
            c = get();
            register long double tmp = 1;
            while (isdigit(c)) {
                tmp /= 10, x += tmp * (c ^ '0');
                c = get();
            }
        }
        sign ? x = -x : 0;
    }
    inline void read(char *s) {
        char c = get();
        while (isspace(c)) c = get();
        while (!isspace(c) && c) {
            *s++ = c;
            c = get();
        }
        *s = '\0';
    }
    inline void read(char &c) {
        do
            c = get();
        while (isspace(c));
    }
    template <class T, class... Args>
    inline void read(T &x, Args &... args) {
        read(x), read(args...);
    }
    template <class T>
    inline void write(T x) {
        int top = 0;
        if (x < 0) {
            put('-');
            sta[top++] = ~(x % 10) + 1, x /= 10;
            x = ~x + 1;
        } else
            sta[top++] = x % 10, x /= 10;
        while (x) sta[top++] = x % 10, x /= 10;
        while (top) put(sta[--top] ^ '0');
    }
    inline void write(double y) {
        int top = 0;
        if (y < 0) {
            put('-');
            y = -y;
        }
        int x = y;
        y -= x;
        write(x);
        if (y) {
            do
                sta[top++] = y * 10, y = y * 10 - sta[top - 1];
            while (top < precisions - 1);
            sta[top++] = y * 10 + round[(int)((y * 10 - ((int)(y * 10))) * 10)];
        }
        put('.');
        for (int i(0); i < top; ++i) put(sta[i] ^ '0');
        for (int i(top); i < precisions; ++i) put('0');
    }
    inline void write(long double y) {
        register int top = 0;
        if (y < 0) {
            put('-');
            y = -y;
        }
        int x = y;
        y -= x;
        write(x);
        if (y) {
            do
                sta[top++] = y * 10, y = y * 10 - sta[top - 1];
            while (top < precisions - 1);
            sta[top++] = y * 10 + round[(int)((y * 10 - ((int)(y * 10))) * 10)];
        }
        put('.');
        for (register int i(0); i < top; ++i) put(sta[i] ^ '0');
        for (register int i(top); i < precisions; ++i) put('0');
    }
    inline void write(const char ch) { put(ch); }
    inline void write(char *s) {
        while (*s != '\0') put(*s++);
    }
    inline void write(const char *s) {
        while (*s != '\0') put(*s++);
    }
    inline void write(const std::string str) { write(str.c_str()); }
    inline IO &precision(const int x) {
        precisions = x;
        return *this;
    }
    template <class T, class... Args>
    inline void write(T x, Args... args) {
        write(x), blank ? put(blank), 0 : 0, write(args...);
    }
    template <class... Args>
    inline void writeln(Args... args) {
        write(args...), endl ? put(endl), 0 : 0;
    }
    template <class T>
    inline IO &operator>>(T &x) {
        read(x);
        return *this;
    }
    inline IO &operator>>(IO &x) { return *this; }
    template <class T>
    inline IO &operator<<(const T x) {
        write(x);
        return *this;
    }
    inline IO &operator<<(IO &x) { return *this; }
    inline operator bool() { return !fail; }
    template <class T>
    inline operator T() {
        T x;
        read(x);
        return x;
    }
    inline void open(FILE *_stream = stdin, FILE *__stream = stdout) {
        close(), reset(_stream, __stream, false);
    }
    inline void close() {
        flush_out_with_stream();
        fclose(in_stream), fclose(out_stream);
    }
#define read(x) io >> x
#define out(x) io << x
} io;

#define N6 1000005

int n , m , u[N6] , v[N6] , w[N6] , cnt , mod = 998244353;
ll a[205][205];
int valans , sum;

int qpow(int a , int b){
    ll res = 1;
    while(b){
        if(b & 1){
            res = 1ll * res * a % mod;
        }
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return res;
}

int inv(int a){
    return qpow(a , mod - 2);
}

int det () {
    ll res = 1;
    rep(i, 2, n) {
        rep(j, i + 1, n) {
            while(a[j][i]) {
                int d = a[i][i] / a[j][i];
                rep(k, i, n) a[i][k] = (a[i][k] - 1ll * d * a[j][k] % mod + mod) % mod; 
                swap(a[i], a[j]);
                res *= -1;
            }
        }
    }
    rep(i, 2, n) res = 1ll * res * a[i][i] % mod;
    res = (res + mod) % mod;
    return res;
}

// #define LOCAL

signed main() {
#ifdef LOCAL
    freopen("genshin.in", "r", stdin);
    freopen("genshin.out", "w", stdout);
#endif
   // int tt = read<int>(_);
    // init();
        io >> n >> m;
    rep(i ,1 , m){
        io >> u[i] >> v[i] >> w[i];
        a[u[i]][u[i]] ++ , a[v[i]][v[i]] ++;
        a[u[i]][v[i]] -- , a[v[i]][u[i]] --;
    }
    sum = det();
    rep(bit , 0 , 29){
        rep(i ,1 , n){
            rep(j ,1 , n){
                a[i][j] = 0;
            }
        }
        rep(i ,1 , m){
            if((w[i] >> bit) & 1){
                a[u[i]][u[i]] ++ , a[v[i]][v[i]] ++;
                a[u[i]][v[i]] -- , a[v[i]][u[i]] --;
            }
        }
        // rep(i ,1 , n){
        //     rep(j ,1 , n){
        //         a[i][j] = (a[i][j] + mod) % mod;
        //     }
        // }
        valans = (valans + 1ll * det() * (1ll << bit) % mod) % mod;
    }
    io << 1ll * valans * inv(sum) % mod;
    end:
    {}
    return 0;
}
