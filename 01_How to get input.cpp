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
	while (scanf("%d", &a) != EOF);
	while (std::cin >> a);


	//c++ cin,cout �� cstdio�� ����¹��ۿ� ����ȭ ���� ����.
	// ���ÿ� ��� �Ұ���
	std::ios_base::sync_with_stdio(false);

	//cin�� cout���κ��� untie�մϴ�.
	//stream�� tie�ϸ� �ٸ� stream���� ����¿�û�� ��������
	//stream�� flush��ŵ�ϴ�.
	std::cin.tie(NULL);

	//cout �� endl�� ��� ���۸� flush ��ŵ�ϴ�.
	//'\n'�� ��� ���۸� flush ���� �ʽ��ϴ�.
	std::cout << '\n';
	return 0;
}