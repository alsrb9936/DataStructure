#include <string>
#include <iostream>
#include <forward_list>

struct citizen
{
	std::string name;
	int age;
};

std::ostream &operator<<(std::ostream &os, const citizen &c)
{
	return (os << "[" << c.name << ", "<< c.age << "]");
}

int main()
{
	std::forward_list<citizen> citizens = {
		{"kim",22},{"Lee",25},{"Park",18},{"Jin",16}
	};
	
	auto citizens_copy = citizens;
	
	std::cout << "전체 시민들: ";
	for(const auto &c: citizens)
		std::cout << c << " ";
	std::cout << std::endl;
	
	citizens.remove_if([](const citizen &c) {return (c.age <19);} ); //remove_if() 는  bool 값을 반환하는 조건자 함수를 인자를 받는다 
	//이 함수는 람다로 조건자를 받는다 (나이 19이하 제거)
	
	std::cout <<"투표권이 있는 시민들: ";
	for(const auto &c:citizens)
		std::cout << c <<" ";
	std::cout << std::endl;
	
	citizens_copy.remove_if([](const citizen &c){return (c.age != 18);}); //18이외 제거
	
	std::cout << "내년에 투표권이 생기는 시민들: ";
	for(const auto &c:citizens_copy)
		std::cout << c << " ";
	std::cout << std::endl;
	
}