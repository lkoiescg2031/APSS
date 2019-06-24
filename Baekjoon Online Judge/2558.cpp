#include <iostream>
/*
1.std::ios::sync_with_stdio(false);
 ios::sync_with_stdio는 cpp의 iostream을 c의 stdio와 동기화시켜주는 역할을 합니다. 
 이는 iostream, stdio의 버퍼를 모두 사용하기 때문에 딜레이가 발생하게 됩니다. 
 ios::sync_with_stdio(false)는 이 동기화 부분을 끊는 함수입니다. 
 이를 사용하면 c++만의 독립적인 버퍼를 생성하게 되고 c의 버퍼들과는 병행하여 사용할 수 없게 됩니다.
 대신 사용하는 버퍼의 수가 줄어들었기 때문에 속도는 높아지게 됩니다.

2.std::cin.tie(NULL);
디폴트는 cout,cin이 tie되어 있습니다.
만약 cout << "hi"; cin >> name; 이 순서라면 디폴트의 경우 "hi"가 먼저 출력되고 name을 입력할 것입니다.
그러나 untie의 경우엔 cout으로부터 cin을 untie해주기 때문에 먼저 입력부터 하게 됩니다.
그러나 "hi"는 보이지 않는데, 
cout은 디폴트에서는 출력명령을 내리거나 버퍼가 가득찼을 경우에만 flushed되고 출력되기 때문입니다.
따라서 cin을 cout에서 untie하고 싶다면 cin으로 입력하기 전에 
cout으로 출력을 할 때마다 지속적으로 flush를 해줘야 합니다.
*/
int main() {
	std::ios_base::sync_with_stdio(false);
	int a, b;
	
	std::cin >> a >> b;
	std::cout << a + b;
	return 0;
}