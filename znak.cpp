#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b;
	cin >> a >> b;

	char operatorChar = '0';
	int result;
	int addition = a + b;
	int subtraction = a - b;
	int multiplication = a * b;

	if (addition > multiplication&& addition > subtraction)
	{
		operatorChar = '+';
		result = addition;
	}

	if (multiplication > addition&& multiplication > subtraction)
	{
		operatorChar = '*';
		result = multiplication;
	}

	if (subtraction > addition&& subtraction > multiplication)
	{
		operatorChar = '-';
		result = subtraction;
	}
		
	if (operatorChar == '0')
		cout << "NIE";
	else
	{
		string aLook = a < 0 ? "(" + to_string(a) + ")" : to_string(a);
		string bLook = b < 0 ? "(" + to_string(b) + ")" : to_string(b);
		string resultLook = result < 0 ? "(" + to_string(result) + ")" : to_string(result);

		cout << aLook << operatorChar << bLook << "=" << resultLook;
	}

	return 0;
}