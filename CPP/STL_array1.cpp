#include <string>     //필요한 헤더파일 포함
#include <algorithm>
#include <sstream>
#include <iostream>

template <typename T>    //클래스 템플릿 작성후 주요 멤버 변수 선언
class dynamic_array 
{
	T* data;
	size_t n;

	public:
		dynamic_array(int n) {     //배열 크기를 인자로 하는 생성자와 복사 생성자 추가
			this->n = n;
			data = new T[n];
		}
		
		dynamic_array(const dynamic_array<T>& other) {
			n = other.n;
			data = new T[n];

			for(int i = 0; i < n; i++)
				data[i] = other[i];
		}

		T& operator[](int index) {    //[]연산자와 at()함수 작성
			return data[index];
		}

		const T& operator[](int index) const {
			return data[index];
		}

		T& at(int index) {
			if (index < n)
				return data[index];
			throw "Index Out Of Range";
		}

		size_t size() const {  //배열 크기 반환하는 size()멤버 함수와 소멸자 구현.
			return n;
		}

		~dynamic_array() {
			delete[] data;  //메모리 릭 방지
		}

		T* begin() { return data; }    //반복자 관련 함수 정의
		const T* begin() const { return data; }
		T* end() { return data + n; }
		const T* end() const { return data + n; }
		
//두 배열을 하나로 합치는 +연산자 함수 정의. 
			friend dynamic_array<T> operator+(const dynamic_array<T>& arr1,
dynamic_array<T>& arr2) {
			dynamic_array<T> result(arr1.size() + arr2.size());
			std::copy(arr1.begin() , arr1.end(), result.begin());
			std::copy(arr2.begin() , arr2.end(), result.begin() + arr1.size());

			return result;
		}

//모든 데이터를 문자열로 반환하는 to_string()멤버 함수 작성.
//데이터 구분을 위한 문자열 sep를 인자로 받으며 기본 값은 ", "쉼표로 지정한다.
		std::string to_string(const std::string& sep=", ") {
			if(n == 0) return "";
			
			std::ostringstream os;
			os << data[0];

			for(int i = 0; i < n; i++)
				os << sep << data[i];

			return os.str();
		}
};

struct student {
	std::string name;
	int standard;
};

std::ostream& operator<<(std::ostream& os, const student& s) {
	return (os << "[" << s.name << ", " << s.standard << "]");
}

int main() {
  int nStudents;
  std::cout << "1반 학생 수를 입력하세요: ";
  std::cin >> nStudents;

  dynamic_array<student> class1(nStudents); //템플렛 클래스 사용
  for (int i =0; i< nStudents; i++) {
    std::string name;
    int standard;
    std::cout << i + 1 << "번째 학생 이름과 나이를 입력하세요: ";
    std::cin >> name >> standard;
    class1[i] = student{name,standard};
  }

  //배열 크기보다 큰 인덱스의 학생에 접근
  try {
    //아래 주석 해제시 비정상 종료합니다.
    // class1[nStudents] = student {"John", 8}; //  예상할 수 없는 동작

    class1.at(nStudents) = student{"John", 8}; //예외 발생
  }
  catch(...){
    std::cout <<"예외 발생!" <<std::endl;
  }

  //깊은 복사
  auto class2 = class1;
  std::cout << "1반을 복사하여 2반을 생성: " << class2.to_string() << std::endl;
  
  //두반을 합쳐 큰 학급 생성
  auto class3 = class1 + class2;
  std::cout << "1반과 2반을 합쳐 3반 생성: " << class3.to_string() << std::endl;

  return 0;
}