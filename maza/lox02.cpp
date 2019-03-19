#include <iostream>

using namespace std;

void Step(int x, int y, int num);
void Stop();

int num;

int m[5][5] = 
	{ 
		{0, 0, 0, 0, -2},
        {0, 0, 0, 0, 0},
        {0,-1,-1,-1,-1},
        {0, 0, 0,-1,-1},
        {0, 0, 0, 0, 0}	
	};

void Start(int xS, int yS) {
	m[xS][yS] = 1;
	Step(xS, yS, 1);
}


void Step(int x, int y, int num) {
	if (m[x][y] != -2)
	{
		m[x][y] = num;

		num += 1;

		if (x > 0 && x < 5 && y > 0 && y < 5)
		{
			if (m[x-1][y] == 0)
			{
				Step(x-1, y, num);
				Stop();
			}

			if (m[x+1][y] == 0)
			{
				Step(x+1, y, num);
				Stop();
			}
			
			if (m[x][y-1] == 0)
			{
				Step(x, y-1, num);
				Stop();
			}
			
			if (m[x][y+1] == 0)
			{
				Step(x, y+1, num);
				Stop();
			}
		}
	}
	else 
	{
		Stop();
	}
}

void Stop() {
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	
}

int main() {
	Start(1, 1);
	return 0;
}
