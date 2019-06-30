#include <iostream>
#include <sstream>
#include <stdlib.h>
#define LINE 100
#define MAXTEAM 100
#define MAXPROBLEM 9
#define INCORRECT_TIME 0
#define RESULT 1
#define RESULT_TIME 2

using namespace std;

struct Team {
	int number;
	int Num_solvedProblem;
	int timeScore;
};

Team team[MAXTEAM];
int problem[MAXTEAM + 1][MAXPROBLEM + 1][3];

void reset() {
	for (int i = 1; i <= MAXTEAM; i++) {
		for (int j = 1; j <= MAXPROBLEM; j++) {
			problem[i][j][INCORRECT_TIME] = 0;
			problem[i][j][RESULT] = 0;
		}
		team[i].Num_solvedProblem = 0;
		team[i].timeScore = 0;
		team[i].number = 0;
	}
}
int compare(const void *x, const void *y) {
	Team *item1 = (Team*)y;
	Team *item2 = (Team*)x;

	if (item1->Num_solvedProblem != item2->Num_solvedProblem)
		return item1->Num_solvedProblem - item2->Num_solvedProblem;
	return item1->timeScore - item2->timeScore;
}

int main() {

	int i, j, t;
	int teamNum, PNum, time;
	char result;
	int testcase;
	char line[LINE];
	stringstream ss(line);

	cin >> testcase;

	cin.ignore();//clear buffer
	cin.getline(line, LINE);//read empty line
	
	for (t = 0, reset(); t < testcase; t++, reset()) {
		//input
		while (cin.getline(line, LINE) && *line) {
			ss.clear();
			ss.str(line);
			ss >> teamNum >> PNum >> time >> result;
			if (result == 'I' && problem[teamNum][PNum][RESULT] == 0)
				problem[teamNum][PNum][INCORRECT_TIME]++;
			else if (result == 'C'&& problem[teamNum][PNum][RESULT] == 0) {
				problem[teamNum][PNum][RESULT] = 1;
				problem[teamNum][PNum][RESULT_TIME] = time;
			}
		}
		//counting
		for (i = 1; i <= MAXTEAM; i++) {
			for (j = 1; j <= MAXPROBLEM; j++){
				if (problem[i][j][RESULT]) {
					team[i].Num_solvedProblem++;
					team[i].timeScore = team[i].timeScore + (problem[i][j][INCORRECT_TIME] * 20) + problem[i][j][RESULT_TIME];
					team[i].number = i;
				}
			}
		}
		//sorting
		std::qsort(team,MAXTEAM, sizeof(Team), compare);
		//print
		if (t > 0)
			cout << endl;
		for (i = 0; i < MAXTEAM && team[i].number != 0; i++) {
			cout << team[i].number << " " << team[i].Num_solvedProblem << " " << team[i].timeScore << endl;
		}
	}

	return 0;
}