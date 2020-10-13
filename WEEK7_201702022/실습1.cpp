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
/* (실습 1-1) 분석결과 : throw문이 없을 경우에는 메인에서 funcA()가 실행되면 id A를 가진 객체가 생성되었고 funcb 함수가 실행되서 다음 id B를 가진 객체가 실행
						 돼고 Executed in B라는 문자열이 출력 후 리턴되면서 파괴자가 실행되어 Destructor execution : B가 출력된다 그런 다음 다시 funcA로 돌아와
						 Executed in A를 출력하고 리턴되어서 또 다시 파괴자가 실행되어 Destructor execution : A가 출력된다.
						 */
						 /* (실습 1-2) 분석결과 : throw문이 있을 경우에 메인에서 funcA()가 실행되어 id A를 가진 객체가 생성되었고 funcb 함수가 실행되어 id B를 가진 객체를 생성하였으나
												  throw문이 리드되면서 런타임에러가 발생하여 e에 Exception from fuckB! 가 저장되고 리턴으로 돌아가는게 아닌 함수들이 그냥 종료되어서
												   문자열을 출력하지않고 파괴자만 실행되면서 Destructor execution : B,Destructor execution : A가 출력되고 catch문에서 예외처리를 받아서
												   어떤 예외처리가 발생했지는 문자열로 출력해준다..*/