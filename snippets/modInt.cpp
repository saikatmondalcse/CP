using uint = unsigned int;
using ull = unsigned long long;
const uint MOD = 998244353;

template<uint mod=MOD> struct mint { // 1000000007  1000000009 998244353
    uint val;
 
    mint() : val(0) {}
    mint(ll _x) {
        _x %= mod;
        if (_x < 0) _x += mod;
        val = _x;
    }
    mint& operator += (const mint &a) {
        val += a.val;
        if (val >= mod) val -= mod;
        return *this;
    }
    mint& operator -= (const mint &a) {
        val += mod - a.val;
        if (val >= mod) val -= mod;
        return *this;
    }
    mint& operator *= (const mint &a) {
        val = (ull)val * a.val % mod;
        return *this;
    }
    mint pow(ll pw) const {
        mint res = 1;
        mint cur = *this;
        while(pw) {
            if (pw & 1) res *= cur;
            cur *= cur;
            pw >>= 1;
        }
        return res;
    }
    mint inv() const {
        assert(val != 0);
        uint t = val;
        uint res = 1;
        while(t != 1) {
            uint z = mod / t;
            res = (ull)res * (mod - z) % mod;
            t = mod - t * z;
        }
        return res;
    }
    mint& operator /= (const mint &a) {
        return *this *= a.inv();
    }
    mint operator + (const mint &a) const {
        return mint(*this) += a;
    }
    mint operator - (const mint &a) const {
        return mint(*this) -= a;
    }
    mint operator * (const mint &a) const {
        return mint(*this) *= a;
    }
    mint operator / (const mint &a) const {
        return mint(*this) /= a;
    }
    bool operator == (const mint &a) const {
        return val == a.val;
    }
    bool operator != (const mint &a) const {
        return val != a.val;
    }
    bool operator < (const mint &a) const {
        return val < a.val;
    }
    friend constexpr std::istream &operator>>(std::istream &is, mint &a) {
        ll v;
        is >> v;
        a = mint(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const mint &a) {
        return os << a.val;
    }
};
using Mint=mint<>;
