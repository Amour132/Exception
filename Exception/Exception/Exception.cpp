#include <iostream>
#include <vector>

using namespace std;


// ������������ͨ��ʹ�õ��쳣�̳���ϵ
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

// �����ʾ����������׳�A/B/C/D�е�ĳ�����͵��쳣
//void fun() throw(A,B,C,D);
// �����ʾ�������ֻ���׳�bad_alloc���쳣
void* operator new (std::size_t size) throw (std::bad_alloc);
// �����ʾ������������׳��쳣
void* operator new (std::size_t size, void* ptr) throw();

int main()
{
	try{
		// server.Start();
		// �׳����������������
	}
	catch (const Exception& e) // ���ﲶ�������Ϳ���
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
		v.reserve(1000000000);  //�ڴ治���������쳣
		v.at(10) = 100;       //Խ�����쳣
	}

	catch (const exception& e)
	{
		cout << e.what() << endl;   //what��һ�����麯��
	}
	catch (...)
	{
		cout << "unknow exception" << endl;
	}

	return 0;
}