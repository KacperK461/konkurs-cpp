#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, p;
	int max = 0;
	int increase = 0;

	cin >> n >> m;
	int* buttons = new int[n]();

	while (m--)
	{
		cin >> p;

		if (p == n + 1)
		{
			increase = max;
			continue;
		}
			
		if (buttons[p - 1] < increase)
			buttons[p - 1] = increase + 1;
		else
			buttons[p - 1]++;

		if (p != n + 1 && buttons[p - 1] > max)
			max = buttons[p - 1];
	}

	for (int i = 0; i < n; i++)
		cout << std::max(buttons[i], increase) << " ";

	delete[] buttons;
	return 0;
}
