struct str_hash {
	vector<int> h1,h2;
	static vector<int> b1,b2;
	constexpr static int B = 31, M1 = 1e9+7, M2 = 1e9+9;
	str_hash(const string& s) {
		h1.resize(s.size()+1,0);
		h2.resize(s.size()+1,0);
		b1.reserve(s.size()+1), b2.reserve(s.size()+1);
		while(b1.size() <= s.size()) {
			b1.push_back(1LL * b1.back() * B % M1);
			b2.push_back(1LL * b2.back() * B % M2);
		}
		for(int i = 0; i < s.size(); ++i) {
			h1[i+1] = (1LL * h1[i] * B + s[i]) % M1;
			h2[i+1] = (1LL * h2[i] * B + s[i]) % M2;
 		}
	}

	ll hash(int i, int j) const {
		ll a1 = (h1[j+1] - 1LL * h1[i] * b1[j-i+1]) % M1;
		ll a2 = (h2[j+1] - 1LL * h2[i] * b2[j-i+1]) % M2;
		if(a1 < 0) a1 += M1;
		if(a2 < 0) a2 += M2;
		return a1 ^ (a2<<32);
	}

	//for one time entire-string hashing
	static ll static_hash(const string& s) {
		ll a1=0,a2=0;
		for(char c : s) {
			a1 = (a1 * B + c) % M1;
			a2 = (a2 * B + c) % M2;
		}
		return a1 ^ (a2<<32);
	}
};
vector<int> str_hash::b1={1},str_hash::b2={1};