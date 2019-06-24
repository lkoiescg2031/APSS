#include <iostream>

int N, L;
int ans;
int map[200][100];

int main() {

	std::cin >> N >> L;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			std::cin >> map[i][j];
			map[j + N][i] = map[i][j];
		}

	for (int i = 0; i < 2 * N; i++) {
		int j = 1, cnt = 1;
		for (j = 1; j < N; j++) {
			if (map[i][j] == map[i][j - 1])cnt++;
			else if (map[i][j - 1] + 1 == map[i][j] && cnt >= L) cnt = 1;
			else if (map[i][j - 1] == map[i][j] + 1 && cnt >= 0) cnt = 1 - L;
			else break;
		}
		ans += (j == N && cnt >= 0);
	}

	std::cout << ans;

	return 0;
}