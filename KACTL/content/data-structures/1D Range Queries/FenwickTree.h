/**
 * Author: tdipto008
 * Date: 2026-09-02
 * Source: cp-algorithms/kactal
 * Time: Both operations are $O(\log N)$.
 * Status: cses problem verdict AC
 */
#pragma once

template<class T> struct FenwickTree {
	vector<T> s;
	FenwickTree(int n) : s(n) {}

	void update(int pos, T dif) {
		for (; pos < (int)s.size(); pos |= pos + 1) s[pos] += dif;
	}

	T query(int pos) { // sum [0, pos)
		T res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
};
