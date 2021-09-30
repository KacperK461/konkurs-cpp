#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct Bacteria
{
	int iq;
	int weight;
};


void join (vector<vector<int>> colonies)
{
	int first, second;
	cin >> first >> second;
	first--;
	second--;

	colonies[first].push_back(second);
}



void bfs(int s, int n, vector<vector<int>> adj)
{
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
}



void iqMax(Bacteria* bacteries, vector<vector<int>> &colonies, int n)
{
	int s;
	cin >> s;
	s--;

	int max = -101;

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


		if (bacteries[s].iq > max)
			max = bacteries[s].iq;

		queue.pop_front();

		for (i = colonies[s].begin(); i != colonies[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}

	cout << max;
}

void iqMin(Bacteria* bacteries, vector<vector<int>> &colonies, int n)
{
	int s;
	cin >> s;
	s--;

	int min = 101;

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


		if (bacteries[s].iq < min)
			min = bacteries[s].iq;

		queue.pop_front();

		for (i = colonies[s].begin(); i != colonies[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}

	cout << min;
}

void showWeight(Bacteria* bacteries, vector<vector<int>> &colonies, int n)
{
	int s;
	cin >> s;
	s--;

	int weight = 0;

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

		weight += bacteries[s].weight;

		queue.pop_front();

		for (i = colonies[s].begin(); i != colonies[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}

	cout << weight;
}



void cos(vector<vector<int>> colonies, int n)
{
	int s = 1;

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


		cout << s;

		queue.pop_front();

		for (i = colonies[s].begin(); i != colonies[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
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

	Bacteria* bacteries = new Bacteria[n];

	for (int i = 0; i < n; i++)
	{
		cin >> weight >> iq;
		bacteries[i].iq = iq;
		bacteries[i].weight = weight;
	}

	vector<vector<int>> colonies(n);
	//cout << colonies.size();

	string command;
	while (cin >> command)
	{
		if (command == "JOIN")
			join(colonies);
		if (command == "IQ_MAX")
			iqMax(bacteries, colonies, n);
		if (command == "IQ_MIN")
			iqMin(bacteries, colonies, n);
		if (command == "MASA")
			showWeight(bacteries, colonies, n);
	}

	cout << endl << endl;
	for (auto vec : colonies)
	{
		for (auto i : vec)
			cout << i;
	}
	return 0;
}

//class Data
//{
//public:
//	int maxIq;
//	int minIq;
//	int sumWeight;
//
//	Data()
//	{
//		maxIq = -101;
//		minIq = 101;
//		sumWeight = 0;
//	}
//
//	void add(Bacteria& bac)
//	{
//		if (bac.iq > maxIq)
//			maxIq = bac.iq;
//		if (bac.iq < minIq)
//			minIq = bac.iq;
//		sumWeight += bac.weight;
//		bac.data = this;
//	}
//};


//void join(Bacteria* bacteries)
//{
//	int first, second;
//	cin >> first >> second;
//	first--;
//	second--;
//
//	if (bacteries[first].data == nullptr && bacteries[second].data == nullptr)
//	{
//		bacteries[first].data = new Data();
//		bacteries[first].data->add(bacteries[first]);
//		bacteries[first].data->add(bacteries[second]);
//	}
//	else if (bacteries[first].data != nullptr)
//		bacteries[first].data->add(bacteries[second]);
//	else if (bacteries[second].data != nullptr)
//		bacteries[second].data->add(bacteries[first]);
//}

//void iqMax(Bacteria* bacteries)
//{
//	int index;
//	cin >> index;
//	index--;
//
//	if (bacteries[index].data == nullptr)
//		cout << bacteries[index].iq << "\n";
//	else
//		cout << bacteries[index].data->maxIq;
//}
//
//void iqMin(Bacteria* bacteries)
//{
//	int index;
//	cin >> index;
//	index--;
//
//	if (bacteries[index].data == nullptr)
//		cout << bacteries[index].iq << "\n";
//	else
//		cout << bacteries[index].data->minIq;
//}
//
//void showWeight(Bacteria* bacteries)
//{
//	int index;
//	cin >> index;
//	index--;
//
//	if (bacteries[index].data == nullptr)
//		cout << bacteries[index].weight << "\n";
//	else
//		cout << bacteries[index].data->sumWeight;
//}


