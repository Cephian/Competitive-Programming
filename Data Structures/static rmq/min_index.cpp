// O(n log n) space, O(1) index query R(min)Q
// returns the INDEX of the min element
struct rmq_ind {
	vector<vector<int> > t;
	int *A;
	rmq_ind(){}
	rmq_ind(int* a, int n):t(32-__builtin_clz(n),vector<int>(n)) {
		A = a;
		for(int i = 0; i < n; ++i)
			t[0][i] = i;
		for(int k = 1, p = 1; k < (int)t.size(); ++k, p<<=1)
			for(int i = 0; i < n; ++i)
				t[k][i] = (i+p<n && a[t[k-1][i+p]] < a[t[k-1][i]])?t[k-1][i+p]:t[k-1][i];
	}
	//inclusive min query
	inline int query(int l, int r) const {
		int p = 31-__builtin_clz(r-l+1), i = t[p][l], j = t[p][r+1-(1<<p)];
		return (A[i]<A[j])?i:j;
	}
};
