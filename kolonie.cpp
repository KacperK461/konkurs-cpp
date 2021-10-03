#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

int bfs(int n, int start, int** bacteries, vector<vector<int>> &adj, void (*func)(int&, int*))
{
	int output = start;
	int s;
	cin >> s;
	s--;

	bool* visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;

	deque<int> queue;


	visited[s] = true;
	queue.push_back(s);

	vector<int>::iterator i;

	while (!queue.empty())
	{
		s = queue.front();

		func(output, bacteries[s]);

		queue.pop_front();

		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}

	return output;
}

void iqMax(int &max, int* bacteria)
{
	if (bacteria[1] > max)
		max = bacteria[1];
}

void iqMin(int &min, int* bacteria)
{
	if (bacteria[1] < min)
		min = bacteria[1];
}

void calcWeight(int &weight, int* bacteria)
{
	weight += bacteria[0];
}

void join(vector<vector<int>> &colonies)
{
	int first, second;
	cin >> first >> second;
	first--;
	second--;

	colonies[first].push_back(second);
	colonies[second].push_back(first);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	int iq;
	int weight;
	cin >> n;

	int** bacteries = new int*[n];

	for (int i = 0; i < n; i++)
	{
		bacteries[i] = new int[2];
		cin >> weight >> iq;

	    bacteries[i][0] = weight;
		bacteries[i][1] = iq;
	}

	vector<vector<int>> colonies(n);

	string command;
	while (cin >> command)
	{
		if (command == "JOIN")
			join(colonies);
		if (command == "IQ_MAX")
			cout << bfs(n, -101, bacteries, colonies, iqMax) << endl;
		if (command == "IQ_MIN")
			cout << bfs(n, 101, bacteries, colonies, iqMin) << endl;
		if (command == "MASA")
			cout << bfs(n, 0, bacteries, colonies, calcWeight) << endl;
	}

	return 0;
}