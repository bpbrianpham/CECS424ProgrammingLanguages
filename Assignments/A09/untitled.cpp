#include <iostream>
#include <iomanip>
#include <string>
#include <cfloat>
#include <fstream>
using namespace std;

string convertFloat(float);

int main(int argc, char* argv[]) {
	cout << "i. Floating point number converter.\n";
	float pi = 3.14159265358979;
	cout << pi << " -> " << convertFloat(pi) << endl;
}

string convertFloat(float number) {
	string floatVars;
	unsigned int number_i = (*(unsigned int*) &number);
	unsigned int sign = (number_i & 0x80000000) >> 31;
	unsigned int exp =  (number_i & 0x7f800000) >> 23;
	unsigned int mantissa = (number_i & 0x007fffff);

	floatVars ='(' + to_string(sign) + "," + to_string(exp)+ "," + to_string(mantissa)+')';
	return floatVars;

}
