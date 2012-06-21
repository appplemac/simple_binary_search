#include <iostream>
#include <vector>
using namespace std;

// Pre: (0 <= left) and (right < v.size()) and (v is sorted in an ascending order)
// Post: returns a number i, left<=i<=right and v[i]==x.
//		 If there is no element x in v[], returns -1.
int position(double x, const vector<double>& v, int left, int right) {
    if (left > right) return -1;
    int pos = (left + right)/2; // the middle of v[left,right]
    if (x < v[pos]) return position(x, v, left, pos - 1);
    if (x > v[pos]) return position(x, v, pos + 1, right);
    return pos;
}

int main() {
	int size;
	cin >> size;
	vector<double> v(size);
	for (int i = 0; i < size; ++i) {
		cin >> v[i];
	}
	double x;
	cin >> x;
	int left, right;
	cin >> left >> right;
	cout << position(x, v, left, right);
}