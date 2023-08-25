
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi; vector<int> C; // C[i] = # of first i elements going left
    Node(const vector<int>& A, int lo, int hi) : lo(lo), hi(hi), C(1, 0) {
        if(lo + 1 == hi) return;
        int mid = (lo + hi) / 2;
        vector<int> L, R;
        for(int a: A) {
            C.push_back(C.back());
            if(a < mid) L.push_back(a), C.back()++;
            else R.push_back(a);
        }
        l = new Node(L, lo, mid), r = new Node(R, mid, hi);
    }
    // k'th (0-indexed) element in the sorted range [L, R)
    int quantile(int k, int L, int R) {
        if(lo + 1 == hi) return lo;
        int c = C[R] - C[L];
        if(k < c) return l->quantile(k, C[L], C[R]);
        return r->quantile(k - c, L - C[L], R - C[R]);
    }
    // number of elements in range [0, R) equal to x
    int rank(int x, int R) {
        if(lo + 1 == hi) return R;
        if(x < l->hi) return l->rank(x, C[R]);
        return r->rank(x, R - C[R]);
    }
    // number of elements x in range [L, R) st. a <= x < b
    int rectangle(int a, int b, int L, int R) {
        if(a <= lo && hi <= b) return R - L;
        if(a >= hi || b <= lo) return 0;
        return l->rectangle(a, b, C[L], C[R]) +
            r->rectangle(a, b, L - C[L], R - C[R]);
    }
    ~Node(){
        delete l;
        delete r;
    }
};


    // auto [lo, hi] = minmax_element(all(v));
    // Node tr(v, *lo, (*hi)+1);


