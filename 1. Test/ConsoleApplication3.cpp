


#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <iostream>


using namespace std;


class TEST
{
	int m_iID = 4;
	int m_iAge = 12;
	float m_fAver = 0.0f;
public:
	TEST() {}
	TEST(int i, int a, float f) : m_iID(i), m_iAge(a), m_fAver(f) {}
};

std::map<int, TEST> mapTEST;
std::vector<TEST> vecTEST;
std::list<TEST> listTEST;

int main()
{
	std::string str = "    asdfasdf   ";

	trim_left(str);

	cout << str << endl;



	//auto a = 3;
	//auto* p = &a;
	//auto& b = p;
	//auto& c = a;

	//cout << *b << endl;
	//cout << c << endl;

	//cout << sizeof(a) << endl;
	//cout << sizeof(c) << endl;

	auto iter1 = mapTEST.begin();

	auto& iter2 = mapTEST.begin();

	auto iter3 = vecTEST.begin();

	vecTEST.push_back( TEST() );
	vecTEST.push_back( TEST(3, 5, 0.4f) );

	auto& iter4 = vecTEST.begin();
	++iter4;

	auto iter5 = listTEST.begin();

	cout << sizeof(iter1) << endl;
	cout << sizeof(iter2) << endl;

	cout << sizeof(iter3) << endl;
	cout << sizeof(iter4) << endl;

	cout << sizeof(iter5) << endl;

	std::map<int,TEST>::iterator itr1;
	std::vector<TEST>::iterator itr2;
	std::list<TEST>::iterator itr3;

	return 0;
}


//#include <cstdio>
//#include <thread>
//
//using namespace std;
//
//class Counter
//{
//private:
//	int m_iID;
//	int m_iLength;
//
//public:
//	Counter(const int iID, const int iLength)
//	{
//		m_iID = iID;
//		m_iLength = iLength;
//	}
//
//	void operator()() const
//	{
//		for(int i = 1; i<= m_iLength; ++i )
//			printf("counter[%d] : %d\n", m_iID, i);
//	}
//
//	void loop() const
//	{
//		for (int i = 1; i <= m_iLength; ++i)
//			printf("counter[%d] : %d\n", m_iID, i);
//	}
//};
//
////void counter(int id, int length) 
////{
////	for (int i = 1; i <= length; i++) 
////	{
////		printf("counter[%d] : %d\n", id, i);
////	}
////}
//
//int main() 
//{
//	thread t1{ Counter(1,5) };
//
//	Counter c2(2, 7);
//	thread t2(c2);
//
//	thread t3(Counter(3, 8));
//
//
//	thread t4([](int iID, int iLength) {
//		for (int i = 1; i <= iLength; ++i)
//			printf("counter[%d] : %d\n", iID, i);
//	}, 4,7  );
//
//
//	Counter c5(5, 4);
//
//	thread t5{ &Counter::loop, &c5 };
//
//	t1.join();
//	t2.join();
//	t3.join();
//	t4.join();
//	t5.join();
//
//
//
//
//
//	//thread t1(counter, 1, 5);
//	//thread t2(counter, 2, 7);
//
//	//t1.join();
//	//t2.join();
//
//
//	return 0;
//}


//
//#include <iostream>
//#include <thread>
//#include <mutex>
////using namespace std;
//
//
//std::mutex m;
//void thread_function(int tid)
//{
//
//
//	m.lock();
//
//	std::cout << "abcdefghijklmnopqrstuvwxyz" << std::endl;
//
//	m.unlock();
//}
//
//int main()
//{
//	const int iThreadCount = 10000;
//
//	std::thread t[iThreadCount];
//
//
//	for (int i = 0; i < iThreadCount; ++i)
//	{
//		t[i] = std::thread(thread_function, i);
//	}
//
//
//	for (int i = 0; i < iThreadCount; ++i)
//	{
//		t[i].join();
//	}
//
//
//	return 0;
//}


//#include "stdafx.h"
//#include <memory>
//#include <iostream>
//
//using namespace std;
//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	shared_ptr<int> sp1(new int(10));
//	weak_ptr<int> wp1 = sp1;
//
//	cout << sp1.use_count() << endl;
//	cout << wp1.use_count() << endl;
//
//	{
//		shared_ptr<int> sp2 = wp1.lock();
//
//		cout << sp1.use_count() << endl;
//		cout << wp1.use_count() << endl;
//	}
//
//	cout << sp1.use_count() << endl;
//	cout << wp1.use_count() << endl;
//
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//class Parent
//{
//private:
//	int num1, num2;
//
//public:
//	Parent(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)
//	{ }
//
//	void ShowData() { cout << num1 << ", " << num2 << endl; }
//
//	Parent& operator=(const Parent& ref)
//	{
//		cout << "Parent& operator=()" << endl;
//		num1 = ref.num1;
//		num2 = ref.num2;
//
//		return *this;
//	}
//};
//
//class Child : public Parent
//{
//private:
//	int num3, num4;
//
//public:
//	Child(int n1, int n2, int n3, int n4)
//		: Parent(n1, n2), num3(n3), num4(n4)
//	{ }
//
//	void ShowData()
//	{
//		Parent::ShowData();
//		cout << num3 << ", " << num4 << endl;
//	}
//
//	// 유도 클래스의 대입 연산자 정의에서 기초 클래스의 대입 연산자를 호출하지 않으면
//	// 기촐 클래스의 대입 연산자는 호출되지 않는다.
//	Child& operator=(const Child& ref)
//	{
//		cout << "Second& operator=()" << endl;
//
//		// 호출해서 멤버대 멤버 복사를 하기 위함
//		//Parent::operator=(ref);
//		num3 = ref.num3;
//		num4 = ref.num4;
//
//		return *this;
//	}
//};
//
//// 테스트
//void main()
//{
//	Child ssrc(11, 22, 33, 44);
//	Child scpy(0, 0, 0, 0);
//
//	scpy = ssrc;
//	scpy.ShowData();
//}



//
//#include <iostream>
//
//using namespace std;
//
//
//class Base
//{
//public:
//	Base() { cout << "Base::Base()" << endl; }
//	~Base() { cout << "Base::~Base()" << endl; }
//
//	Base(const Base& rhs) { cout << "Base::Base(const Base&)" << endl; }
//	Base& operator=(const Base& rhs) { cout << "Base::operator=(const Base&)" << endl; return *this;  }
//
//	Base(Base&& rhs) { cout << "Base::Base(const Base&&)" << endl; };
//	Base& operator=(const Base&& rhs) { cout << "Base::operator=(const Base&&)" << endl; return *this; }
//
//
//	int i = 0;
//};
//
//class Derived : public Base
//{
//public:
//	Derived() { cout << "Derived::Derived()" << endl; }
//	~Derived() { cout << "Derived::~Derived()" << endl; }
//};
//
//
//int main()
//{
//	Base base1;
//	Base base2 = base1;
//
//	base1 = base2;
//
//	base1 = std::move(base2);
//	Base base3 = std::move(base1);
//
//
//	getchar();
//
//	return 0;
//}





//#include <iostream>
//#include <algorithm>
//#include <array>
//
//using namespace std;
//
//
//
//
//void main()
//{
//	std::array<int, 5> myArray = { 1,2,3,4,5 };
//
//	int iSum = 0;
//
//
//	for_each(myArray.begin(), myArray.end(), [&iSum](int x) -> void {
//		iSum += x;
//	});
//
//
//	cout << iSum << endl;
//}






//#include <iostream>
//#include <functional>
//using namespace std;
//
//
//void main()
//{
//	std::function<int(int) > factorial = [&factorial](int x) -> int {
//		return x <= 1 ? 1 : x * factorial(x - 1);
//	};
//
//	cout << factorial(4) << endl;
//}


//#include <iostream>
//#include <functional>
//
//using namespace std;
//
//int ADD(int a, int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	std::function <int(void)> f;
//	std::function <int(int, int)> g;
//
//	int z;
//	cin >> z;
//	if (z % 2)
//	{
//		f = bind(ADD, 1, 2);
//		g = bind(ADD, placeholders::_1, placeholders::_2);
//	}
//	else
//	{
//		f = bind(ADD, 3, 4);
//		g = bind(ADD, placeholders::_1, placeholders::_2);
//	}
//
//	cout << f() << "\n";
//	cout << g(1, 2) << "\n";
//
//
//	return 0;
//}



//#include <iostream>
//#include <functional>
//
//void ADD(int a, int b)
//{
//	std::cout << a + b << std::endl;
//}
//
//
//int main()
//{
//	int x = 3;
//	int y = 4;
//
//
//	//std::function<void (int, int)> addxy = std::bind(&ADD, std::placeholders::_1, std::placeholders::_2);
//	//auto addxy = std::bind(&ADD, std::cref(x), std::cref(y));
//
//
//
//	//auto addxy = std::bind(&ADD, x, y);
//	//std::_Binder<std::_Unforced, void(*)(int a, int b), int&, int&> addxy = std::bind(&ADD, x, y);
//
//	//std::function< void (int&, int&) > addxy = std::bind(&ADD, x, y);
//	//addxy();
//
//	//y = 7;
//	//addxy();
//
//	//std::_Binder<std::_Unforced, void(&)(int a, int b), int&, int&>
//	auto f = std::bind(ADD, x, y);
//	f();
//
//	//std::_Binder<std::_Unforced, void(*)(int a, int b), int&, int&>
//	auto f2 = std::bind(&ADD, x, y);
//	f2();
//
//	//y = 7;
//
//	//f();
//	//f2();
//
//
////	std::_Bind_helper<int(&)(int, int), int, int>::type
//
//
//}




//#include <iostream>
//#include <functional>
//using namespace std;
//
//void foo() { cout << "foo" << endl; }
//void goo(int a) { cout << "goo" << a << endl; }
//void hoo(int a, int b) { cout << "hoo" << a << b << endl; }
//
//class Dialog
//{
//public:
//	void Close() { cout << "Dialog Close" << endl; }
//};
//
//int main()
//{
//	function<void()> f = &foo;
//	f();
//
//	f = bind(&goo, 5);
//	f();
//
//	f = bind(&hoo, 1, 2);
//	f();
//
//
//	Dialog dlg;
//	f = bind(&Dialog::Close, &dlg);
//	f();
//}


//#include <iostream>
//using namespace std;
//
//
//void foo()
//{
//	cout << "ButtonHandler (foo)" << endl;
//}
//
//
//class Button
//{
//public:
//	void SetHandler(void (Button::*f)()) { handler = f; }
//	void SetHandler2(void (*f)()) { handler2 = f;  }
//
//	void Click() { (this->*handler)(); }
//	void Click2() { (*handler2)();  }
//
//	void goo()	{ 	cout << "ButtonHandler (goo)" << endl; 	}
//
//private:
//	void (Button::*handler)();
//	void (*handler2)();
//};
//
//
//int main(int argc, char* argv[])
//{
//	Button btn;
//
//	btn.SetHandler(&Button::goo);
//	btn.SetHandler2( &foo );
//
//	btn.Click();
//	btn.Click2();
//
//	return 0;
//}









//#include <iostream>
//#include <functional>
//
//using namespace std;
//
//
//void koo(int a, int b, int c, int d)
//{
//	printf("%d, %d, %d, %d\n", a, b, c, d);
//}
//
//int main(int argc, char* argv[])
//{
//	function<void(int, int)> f;
//	// 문제: 8, 3, 5, 1을 출력되게 하려면 어떻게 해야할까?
//
//	f = bind(koo, 8, placeholders::_2, placeholders::_1, 1 );
//
//	f(5, 3);
//
//
//
//	return 0;
//}





















//#include <iostream>
//#include <vector>
//#include <iterator>
//
//template<typename T, T... args>
//struct EnumIter : public std::iterator<std::input_iterator_tag, T, ptrdiff_t, const T*, const T&>
//{
//	static constexpr T              values[] = { args... };
//	static constexpr std::size_t    size = sizeof...(args);
//
//	int     pos;
//	EnumIter()   // No value is end
//		: pos(size)
//	{}
//	EnumIter(T val)
//		: pos(std::distance(&values[0], std::find(&values[0], &values[size], val)))
//	{}
//
//	const T&    operator*()                 const { return values[pos]; }
//	EnumIter&   operator++() { ++pos; return *this; }
//	EnumIter    operator++(int) { EnumIter r(*this); this->operator++(); return r; }
//	bool        operator==(EnumIter const& rhs) { return pos == rhs.pos; }
//	bool        operator!=(EnumIter const& rhs) { return pos != rhs.pos; }
//};
//template<typename T, T... args>
//constexpr T EnumIter<T, args...>::values[];
//
//
//
//enum Ace { One = 101, Two = 233, Three = 455 };
//typedef struct EnumIter<Ace, One, Two, Three>  AceIter;
//
//int main()
//{
//	for (AceIter loop(One); loop != AceIter(); ++loop)
//	{
//		std::cout << static_cast<int>(*loop) << "\n";
//	}
//}
