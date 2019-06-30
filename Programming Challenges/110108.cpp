#include<iostream>
#include<sstream>

#define CANDIDATE_MAX 20
#define NAME_MAX 80
#define VOTE_MAX 1000

using namespace std;

struct CANDIDATE {
	char name[NAME_MAX + 1];
	int vote;
	int survive;
};

int testcase;
int candidate_num,lose_candidate_num;
CANDIDATE candidate[CANDIDATE_MAX];
int vote_num, majority;
int vote[VOTE_MAX][CANDIDATE_MAX],vote_cnt[VOTE_MAX];

int main() {

	int result;
	int min,min_index;

	char line[NAME_MAX + 1];
	stringstream sstream;

	cin >> testcase;
	while (testcase-- > 0) {

		cin >> candidate_num;
		cin.getline(candidate[0].name,NAME_MAX+1);
		for (int i = 0;i < candidate_num;i++) {
			cin.getline(candidate[i].name,NAME_MAX+1);
			candidate[i].vote = 0;
			candidate[i].survive = 1;
		}

		vote_num = 0;
		while(cin.getline(line, 100) && *line != '\0') {
			sstream.clear();
			sstream.str(line);
			for (int i = 0;i < candidate_num;i++) {
				sstream >> vote[vote_num][i];
				vote[vote_num][i]--;
			}
			vote_cnt[vote_num] = 0;
			candidate[vote[vote_num][vote_cnt[vote_num]]].vote++;
			vote_num++;
		}

		majority = vote_num / 2;
		result = -1;
		lose_candidate_num = 0;
		
		while(1){

			min = VOTE_MAX+1;
			for (int j = 0;j < candidate_num;j++) {
				if (candidate[j].survive) {
					if (min > candidate[j].vote) {
						min = candidate[j].vote;
						min_index = j;
					}
					if (candidate[j].vote > majority) {
						result = j;
						break;
					}
				}
			}
			if (result != -1)
				break;

			for (int j = 0;j < candidate_num;j++) 
				if (candidate[j].survive && candidate[j].vote == min) {
					candidate[j].survive = 0;
					lose_candidate_num++;
				}
			if (lose_candidate_num == candidate_num)
				break;

			for (int j = 0;j < vote_num;j++) 
				if (!candidate[vote[j][vote_cnt[j]]].survive) {
					while (!candidate[vote[j][vote_cnt[j]]].survive) vote_cnt[j]++;
					candidate[vote[j][vote_cnt[j]]].vote++;
				}
		}
		if (result != -1)
			cout << candidate[result].name<<endl;
		else
			for (int i = 0;i < candidate_num;i++)
				if (candidate[i].vote == min)
					cout << candidate[i].name << endl;
		if (testcase > 0)
			cout << endl;
	}

	return 0;
}