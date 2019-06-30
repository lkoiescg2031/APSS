#include <iostream>
#define REG_MAX 10
#define MEM_MAX 1000
#define ctoi(a) ((a)-48)

using namespace std;

int reg[REG_MAX],mem[MEM_MAX];

int main() {
	
	char cmd[100];
	int pc,flag,inst,d,n;
	int testcase=0;
	int inst_cnt;

	cin >> testcase;
	cin.getline(cmd, 5);
	cin.getline(cmd, 5);
	for (int t = 0;t < testcase;t++) {
		for (pc = 0;cin.getline(cmd, 5)&& *cmd!='\0';pc++) 
			mem[pc] = ctoi(cmd[0]) * 100 + ctoi(cmd[1]) * 10 + ctoi(cmd[2]);

		for (;pc < MEM_MAX;pc++) 
			mem[pc] = 0;
		for (int i = 0;i < REG_MAX;i++)
			reg[i] = 0;
		pc = 0;
		inst_cnt = 0;
		flag = 1;
		while (flag) {
			inst = mem[pc] / 100;
			d = (mem[pc] % 100) / 10;
			n = mem[pc] % 10;
			inst_cnt++;
			pc++;
			switch (inst) {
			case 1:
				flag = 0;
				break;
			case 2:
				reg[d] = n;
				break;
			case 3:
				reg[d] += n;
				reg[d] %= 1000;
				break;
			case 4:
				reg[d] *= n;
				reg[d] %= 1000;
				break;
			case 5:
				reg[d] = reg[n];
				break;
			case 6:
				reg[d] += reg[n];
				reg[d] %= 1000;
				break;
			case 7:
				reg[d] *= reg[n];
				reg[d] %= 1000;
				break;
			case 8:
				reg[d] = mem[reg[n]];
				break;
			case 9:
				mem[reg[n]] = reg[d];
				break;
			case 0:
				if (reg[n] != 0)
					pc = reg[d];
				break;
			}
		}
		if (t != 0)
			cout << endl;
		cout << inst_cnt<<endl;
	}
	return 0;
}