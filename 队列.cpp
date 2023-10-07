#include <queue>
#include <string>
#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;

	queue <char> qe_gst;
	queue <int> qe_t;

	int A = 0, B = 0, C = 0;
	int A_ = 0, B_ = 0, C_ = 0;

	for (int i = 0; i < t; ++i) {
		char c;
		cin >> c;
		qe_gst.push(c);
	}

	for (int i = 0; i < t; ++i) {
		int data;
		cin >> data;
		qe_t.push(data);
	}

	for (int i = 0; i < t; ++i) {
		switch (qe_gst.front()) {
			case 'A': 
				A += qe_t.front();
				A_++;
				qe_t.pop();
				qe_gst.pop();
				break;
			case 'B':
				B += qe_t.front();
				B_++;
				qe_t.pop();
				qe_gst.pop();
				break;
			case 'C':
				C += qe_t.front();
				C_++;
				qe_t.pop();
				qe_gst.pop();
				break;
		}
	}
	cout << A/A_ << endl;
	cout << B/B_ << endl;
	cout << C/C_ << endl;
	return 0;
}
