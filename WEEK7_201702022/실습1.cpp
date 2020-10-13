#include <iostream>
#include <stdexcept>
class Test {
public:
	Test(char id) : id_(id) {}
	~Test() {
		std::cout << "Destructor execution: "
			<< id_ << std::endl;
	}
private:
	char id_;
};
int funcB() {
	Test r('B');
	// throw std::runtime_error("Exception from funcB!\n");
	std::cout << "Executed in B" << std::endl;
	return 0;
}
int funcA() {
	Test r('A');
	funcB();
	std::cout << "Executed in A" << std::endl;
	return 0;
}
int main() {
	try {
		funcA();
	}
	catch (std::exception& e) {
		std::cout << "Exception : " << e.what();
	}
}
/* (�ǽ� 1-1) �м���� : throw���� ���� ��쿡�� ���ο��� funcA()�� ����Ǹ� id A�� ���� ��ü�� �����Ǿ��� funcb �Լ��� ����Ǽ� ���� id B�� ���� ��ü�� ����
						 �Ű� Executed in B��� ���ڿ��� ��� �� ���ϵǸ鼭 �ı��ڰ� ����Ǿ� Destructor execution : B�� ��µȴ� �׷� ���� �ٽ� funcA�� ���ƿ�
						 Executed in A�� ����ϰ� ���ϵǾ �� �ٽ� �ı��ڰ� ����Ǿ� Destructor execution : A�� ��µȴ�.
						 */
						 /* (�ǽ� 1-2) �м���� : throw���� ���� ��쿡 ���ο��� funcA()�� ����Ǿ� id A�� ���� ��ü�� �����Ǿ��� funcb �Լ��� ����Ǿ� id B�� ���� ��ü�� �����Ͽ�����
												  throw���� ����Ǹ鼭 ��Ÿ�ӿ����� �߻��Ͽ� e�� Exception from fuckB! �� ����ǰ� �������� ���ư��°� �ƴ� �Լ����� �׳� ����Ǿ
												   ���ڿ��� ��������ʰ� �ı��ڸ� ����Ǹ鼭 Destructor execution : B,Destructor execution : A�� ��µǰ� catch������ ����ó���� �޾Ƽ�
												   � ����ó���� �߻������� ���ڿ��� ������ش�..*/