#include <iostream>
#include <cstdio>
#include <string>
int main() {

	char* c_str;
	std::string str;
	int a;

	//1자리 정수 입력받음
	scanf("%1d", &a);
	//문자열의 경우에도 가능 앞의 수만큼 끊어서 받음

	//한 줄 입력받는 법
	scanf("%[^/n]/n", str);
	//줄바꿈 문자를 제외한 한줄을 입력받음 
	//(빈 줄 입력받을수 없음)
	//시작과 끝에 공백또한 입력받을 수 없음
	fgets(c_str, 100, stdin);
	std::getline(std::cin, str);

	//파일의 끝까지 입력받는법
	while (scanf("%d", &a) != EOF);
	while (std::cin >> a);


	//c++ cin,cout 이 cstdio의 입출력버퍼와 동기화 하지 않음.
	// 동시에 사용 불가능
	std::ios_base::sync_with_stdio(false);

	//cin을 cout으로부터 untie합니다.
	//stream을 tie하면 다른 stream에서 입출력요청이 오기전에
	//stream을 flush시킵니다.
	std::cin.tie(NULL);

	//cout 의 endl의 경우 버퍼를 flush 시킵니다.
	//'\n'의 경우 버퍼를 flush 하지 않습니다.
	std::cout << '\n';
	return 0;
}