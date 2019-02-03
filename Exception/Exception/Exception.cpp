#include <iostream>
#include <vector>

using namespace std;


// 服务器开发中通常使用的异常继承体系
class Exception
{
protected:
	string _errmsg;
	int _id;
	//list<StackInfo> _traceStack;
	// ...
};
class SqlException : public Exception
{};
class CacheException : public Exception
{};
class HttpServerException : public Exception
{};

/////////////////////////////////////////////////////////////////////////////////
double Div(int a, int b)
{
	if (b == 0)
		throw "Division by zero condition!";
	else
		return (double)a / (double)b;
}

double Fun()
{
	char* arr = new char(10);

	try
	{
		int a = 0;
		int b = 0;
		cin >> a >> b;
		cout << Div(a, b) << endl;
	}
	catch (...)
	{
		cout << "delete[] arr" << endl;
		delete[] arr;
		throw;	
	}

	cout << "delete[] arr" << endl;
	delete[] arr;
}

// 这里表示这个函数会抛出A/B/C/D中的某种类型的异常
//void fun() throw(A,B,C,D);
// 这里表示这个函数只会抛出bad_alloc的异常
void* operator new (std::size_t size) throw (std::bad_alloc);
// 这里表示这个函数不会抛出异常
void* operator new (std::size_t size, void* ptr) throw();

int main()
{
	try{
		// server.Start();
		// 抛出对象都是派生类对象
	}
	catch (const Exception& e) // 这里捕获父类对象就可以
	{
	}
	catch (...)
	{
		cout << "Unkown Exception" << endl;
	}
	/*try
	{
		cout << Fun() << endl;
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}

	catch (...)
	{
		cout << "do not know exception type" << endl;
	}*/


	try
	{
		vector<int> v(10, 5);
		v.reserve(1000000000);  //内存不够将会抛异常
		v.at(10) = 100;       //越界抛异常
	}

	catch (const exception& e)
	{
		cout << e.what() << endl;   //what是一个纯虚函数
	}
	catch (...)
	{
		cout << "unknow exception" << endl;
	}

	return 0;
}