#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int numberOfChildren;
	int sightRange;
	int lifeguardX;
	int lifeguardY;

	cin >> numberOfChildren
		>> sightRange
		>> lifeguardX
		>> lifeguardY;

	int childX;
	int childY;
	int unsafeChildren = 0;

	while (numberOfChildren--)
	{
		cin >> childX >> childY;
		if (sqrt(pow(lifeguardX - childX, 2) + pow(lifeguardY - childY, 2)) > sightRange)
			unsafeChildren++;	
	}

	cout << unsafeChildren;

	return 0;
}