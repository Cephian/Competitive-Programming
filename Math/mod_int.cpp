template <int mod>
struct mod_int {
	int x;
	inline mod_int() {}
	inline mod_int(int a) {
		if(a < 0) a = -a;
		if(a > mod) x = a % mod;
		else x = a;
	}
	inline mod_int(long long a) {
		if(a < 0) a = -a;
		if(a > mod) x = a % mod;
		else x = a;
	}
	inline mod_int& operator=(int a) {
		if(a < 0) a = -a;
		if(a > mod) x = a % mod;
		else x = a;
		return *this;
	}

	inline mod_int& operator=(long long a) {
		if(a < 0) a = -a;
		if(a > mod) x = a % mod;
		else x = a;
		return *this;
	}

	inline mod_int operator-(const mod_int& e) const {
		return mod_int(x - e.x);
	}

	inline mod_int& operator+=(const mod_int& e) {
		x += e.x;
		if(x >= mod)
			x -= mod;
		return *this;
	}

	inline mod_int operator+(const mod_int& e) {
		const int val = x + e.x;
		if(val >= mod) return mod_int(val-mod);
		return mod_int(val);
	}

	inline mod_int operator*(const mod_int& e) {
		return mod_int(x * (long long)e.x);
	}

	inline mod_int operator*(const int a) {
		return *this * mod_int(a);
	}
};

template <int mod>
inline mod_int<mod> operator*(int a, mod_int<mod> m) {
	return m * a;
}

template <int mod>
istream& operator>>(istream& i, mod_int<mod>& m) {
	return i >> m.x;
}

template <int mod>
ostream& operator<<(ostream& o, const mod_int<mod>& m) {
	return o << m.x;
}

typedef mod_int<MOD> mint;
///////////////////////////////////////////

