#include <cstdio>
#include <algorithm>
int dest, n, b, is_broken[10], ans;
int cnt_btn(int channel) {
	int ret = 0;
	if (channel == 0) return !is_broken[0];
	while (channel > 0) 
		if (is_broken[channel % 10]) return 0;
		else ret++, channel /= 10;
	return ret;
}
int main() {
	scanf("%d %d", &dest, &n);
	for (int i = 0; i < n; i++) scanf("%d", &b),is_broken[b] = true;
	ans = abs(dest - 100);
	for (int i = 0,sign = 1; i <= 500000; i++) 
		for (int j = 0; j < 2; j++, sign *= -1) {
			int channel = dest + sign * i;
			if (channel < 0) continue;
			int cnt = cnt_btn(channel);
			if (cnt > 0) ans = std::min(ans, cnt + i);
		}
	printf("%d", ans);
	return 0;
}