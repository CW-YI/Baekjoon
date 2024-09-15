#include <iostream>
#include <stack>
#pragma warning(disable:4996)
using namespace std;

int main(void) {
	stack<int> s;
	int N, index = 0, *ar, num = 1;
	string result = "";

	scanf("%d", &N);
	ar = (int*)malloc(sizeof(int) * N);
	
	for (int i = 0; i < N; i++) scanf("%d", &ar[i]);

	while (true) {
		if (num <= ar[index]) {
			s.push(num);
			num++;
			result += '+';
		}
		else if (num >= ar[index]) {
			//printf("-------num: %d, ar[index] : %d, s.top() : %d\n", num, ar[index], s.top());
			if (s.top() == ar[index]) {
				s.pop();
				index++;
				result += '-';
			}
			else break;
		}
		//printf("num : %d, index : %d, s.top() : %d-----------", num, index, s.top());

		if (num > N && s.empty()) break;
	}
	if (!s.empty()) printf("NO");
	else {
		for (int i = 0; i < result.length(); i++) printf("%c\n", result[i]);
	}

	free(ar);
	return 0;
}