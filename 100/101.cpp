#include <iostream>
#include <string>

using namespace std;

#define MAX 25

struct status {
	int pos;
	int height;
};

int stack[MAX][MAX];
status block[MAX];
int size[MAX];

int N;

void back(int from, int top)
{
	for (int i = size[from] - 1; i > top; i--) {
		int to = stack[from][i];    

		stack[to][size[to]] = to;
		block[to].pos = to;
		block[to].height = size[to];	 
		size[to]++;
		size[from]--;
	}
}

int put(int from, int top, int tostack)
{
	for (int i = top; i < size[from]; i++) {
		int to = stack[from][i];

		stack[tostack][size[tostack]] = to;
		block[to].pos = tostack;
		block[to].height = size[tostack];
		size[tostack]++;
	}

	size[from] = top;
}

void output(void)
{
	for (int i = 0; i < N; i++){
		cout << i << ":      ";
		for (int j = 0; j < size[i]; j++)
			cout << ' ' << stack[i][j];

		cout << endl;
	}
}

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		stack[i][0] = i;
		block[i].pos = i;
		block[i].height = 0;
		size[i] = 1;
	}

	while (true) {
		string verb, conj;

		cin >> verb;
		if (verb == "quit")
			break;

		int obj1, obj2;

		cin >> obj1 >> conj >> obj2;

		if (obj1 == obj2 || block[obj1].pos == block[obj2].pos)
			continue;

		if (verb == "move") 
			back(block[obj1].pos, block[obj1].height);
		if (conj == "onto")
			back(block[obj2].pos, block[obj2].height);
      
		put(block[obj1].pos, block[obj1].height, block[obj2].pos);
	}

	output();

	return 0;
}
