#include <iostream>
#include <cstdio>
#include <string>
int main() {

	char* c_str;
	std::string str;
	int a;

	//1�ڸ� ���� �Է¹���
	scanf("%1d", &a);
	//���ڿ��� ��쿡�� ���� ���� ����ŭ ��� ����

	//�� �� �Է¹޴� ��
	scanf("%[^/n]/n", str);
	//�ٹٲ� ���ڸ� ������ ������ �Է¹��� 
	//(�� �� �Է¹����� ����)
	//���۰� ���� ������� �Է¹��� �� ����
	fgets(c_str, 100, stdin);
	std::getline(std::cin, str);

	//������ ������ �Է¹޴¹�
	while (scanf("%d", &a));
	while (std::cin >> a);


	//c++ cin,cout �� cstdio�� ����¹��ۿ� ����ȭ ���� ����.
	// ���ÿ� ��� �Ұ���
	std::ios_base::sync_with_stdio(false);

	return 0;
}