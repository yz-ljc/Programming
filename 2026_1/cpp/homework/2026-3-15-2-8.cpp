#include <iostream>
#include <iomanip>
using namespace std;
double get_volume(double r, double h);

int main() {
	double r,h;
	cin >> r >> h;
	double result = get_volume(r ,h);
	cout << "Volume: " << setw(10) << result << endl;
	return 0;
}

double get_volume(double r, double h) {
	const double pi = 3.14;
	const double v = pi * r * r * h;
	return v;
}
