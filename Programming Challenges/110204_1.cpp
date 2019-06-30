#include<cstdio>
#include<cstring>

#define MAX_DIC_SIZE 1000
#define MAX_LINE_LENGTH 80
#define MAX_WORD_LENGTH 16

static char dic[MAX_DIC_SIZE][MAX_WORD_LENGTH + 1];
static char line[MAX_LINE_LENGTH + 1];
static unsigned int dic_size;
static unsigned int line_len;

int search(unsigned int k, char* map, char* inv) {

	char word[MAX_WORD_LENGTH + 1];
	char map2['z' + 1], inv2['z' + 1];
	unsigned int i, j, t;
	char c;

	while (line[k] == ' ') k++;

	if (k >= line_len) {
		for (i = 0; i < line_len; i++)
			putchar(line[i] == ' ' ? ' ' : map[line[i]]);
		putchar('\n');
		return 1;
	}

	for (t = 0; line[k + t] >= 'a' && line[k + t] <= 'z'; t++)
		word[t] = line[k + t];
	word[t] = '\0';

	for (i = 0; i < dic_size; i++)
		if (strlen(dic[i]) == t) {
			for (c = 'a'; c <= 'z'; c++) {
				map2[c] = map[c];
				inv2[c] = inv[c];
			}
			for (j = 0; j < t; j++)
				if (map2[word[j]] && map2[word[j]] != dic[i][j]
					|| inv2[dic[i][j]] && inv2[dic[i][j]] != word[j])
					goto end_of_loop_i;
				else {
					map2[word[j]] = dic[i][j];
					inv2[dic[i][j]] = word[j];
				}
			if (search(k + t, map2, inv2))
				return 1;
		end_of_loop_i:;
		}

	return 0;
}

int main() {
	char map['z' + 1], inv['z' + 1];
	unsigned int i;

	scanf("%d", &dic_size);
	gets(line);
	for (i = 0; i < dic_size; i++)
		gets(dic[i]);
	while (gets(line) && *line != EOF) {
		line_len = strlen(line);
		for (i = 'a'; i <= 'z'; i++) {
			map[i] = '\0';
			inv[i] = '\0';
		}
		if (!search(0, map, inv)) {
			for (i = 0; i < line_len; i++)
				putchar(line[i] == ' ' ? ' ' : '*');
			putchar('\n');
		}
	}
}