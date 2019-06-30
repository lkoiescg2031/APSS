#include<iostream>
#include<sstream>
#include<string.h>
#define MAX_WORD_LEN 16
#define MAX_NUM_WORDS 1000
#define MAX_CRYPT 80

using namespace std;

static int num_of_dic;
char dic[MAX_NUM_WORDS][MAX_WORD_LEN + 1];
static char crypt[MAX_CRYPT + 1];

int recovery(stringstream &ss, char* encryption, char* decryption) {

	char encry['z' + 1], decry['z' + 1];
	char word[MAX_WORD_LEN + 1];
	int word_len,flag;
	
	if (!(ss >> word)) {
		for (int i = 0; i < strlen(crypt); i++)
			cout << ((crypt[i] == ' ') ? ' ' : decryption[crypt[i]]);
		cout << endl;
		return 1;
	}
	
	word_len = strlen(word);
	for (int i = 0; i < num_of_dic; i++) 
		if (strlen(dic[i]) == word_len) {

			flag = 1;
			for (int j = 'a'; j < 'z' + 1; j++) {
				encry[j] = encryption[j];
				decry[j] = decryption[j];
			}

			for (int j = 0; j < word_len; j++)
				if ((encry[dic[i][j]] != '\0' && encry[dic[i][j]] != word[j])
					|| (decry[word[j]] != '\0' && decry[word[j]] != dic[i][j])){
					flag = 0;
					break;
				}else {
					encry[dic[i][j]] = word[j];
					decry[word[j]] = dic[i][j];
				}

			if (flag)
				if(recovery(ss, encry, decry))
					return 1; 
		}
	

	return 0;
}

int main() {

	char encryption['z' + 1],decryption['z' + 1];
	stringstream sstream;

	cin >> num_of_dic;
	
	for (int i = 0; i < num_of_dic; i++)
		cin >> dic[i];

	cin.getline(crypt, MAX_CRYPT + 1);
	while (cin.getline(crypt, MAX_CRYPT + 1) && *crypt != '\0') {
		sstream.str(crypt);

		for (int i = 'a';i < 'z' + 1; i++) {
			encryption[i] = '\0';
			decryption[i] = '\0';
		}
		if (!recovery(sstream, encryption, decryption)) {
			for (int i = 0; i < strlen(crypt); i++)
				cout << ((crypt[i] == ' ') ? ' ' : '*');
			cout << endl;
		}
		sstream.clear();
	}

	return 0;
}
