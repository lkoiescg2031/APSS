#include <iostream>
#include <queue>
using namespace std;

#define FOR(i,n) for(int (i) = 1 ;(i) <= (n);++(i))

int queue_size;
int Josephus;
queue<int> q;

int main() {

	ios_base::sync_with_stdio(false);

	cin >> queue_size >> Josephus;
	
	FOR(i, queue_size) q.push(i);

	cout << "<";
	while (q.size() != 1) {
		FOR(i, Josephus - 1) q.push(q.front()), q.pop();
		int output = q.front(); q.pop();
		cout << output << ", ";
	}
	
	cout << q.front() << ">" << endl;
	   	 
	return 0;
}