#include <iostream>
/*
1.std::ios::sync_with_stdio(false);
 ios::sync_with_stdio�� cpp�� iostream�� c�� stdio�� ����ȭ�����ִ� ������ �մϴ�. 
 �̴� iostream, stdio�� ���۸� ��� ����ϱ� ������ �����̰� �߻��ϰ� �˴ϴ�. 
 ios::sync_with_stdio(false)�� �� ����ȭ �κ��� ���� �Լ��Դϴ�. 
 �̸� ����ϸ� c++���� �������� ���۸� �����ϰ� �ǰ� c�� ���۵���� �����Ͽ� ����� �� ���� �˴ϴ�.
 ��� ����ϴ� ������ ���� �پ����� ������ �ӵ��� �������� �˴ϴ�.

2.std::cin.tie(NULL);
����Ʈ�� cout,cin�� tie�Ǿ� �ֽ��ϴ�.
���� cout << "hi"; cin >> name; �� ������� ����Ʈ�� ��� "hi"�� ���� ��µǰ� name�� �Է��� ���Դϴ�.
�׷��� untie�� ��쿣 cout���κ��� cin�� untie���ֱ� ������ ���� �Էº��� �ϰ� �˴ϴ�.
�׷��� "hi"�� ������ �ʴµ�, 
cout�� ����Ʈ������ ��¸���� �����ų� ���۰� ����á�� ��쿡�� flushed�ǰ� ��µǱ� �����Դϴ�.
���� cin�� cout���� untie�ϰ� �ʹٸ� cin���� �Է��ϱ� ���� 
cout���� ����� �� ������ ���������� flush�� ����� �մϴ�.
*/
int main() {
	std::ios_base::sync_with_stdio(false);
	int a, b;
	
	std::cin >> a >> b;
	std::cout << a + b;
	return 0;
}