#include <iostream>
#include <cstring>
using namespace std;
class PermanentWorker
{
private:
	char name[100];
	int salary;
public:
	PermanentWorker(const char* name, int money)
		:salary(money)
	{
		strcpy(this->name, name);
	}
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		cout << "name : " << name << endl;
		cout << "salary : " << salary << endl;
	}
	
};
class EmployeeHandler
{
private:
	PermanentWorker *empList [50];
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{ } // emplist는 0으로 자동 초기화 되는 듯 하다. empnum은 수동으로 0으로 초기화 해 줬다.
	void AddEmployee(PermanentWorker* emp)
	{
		empList[empNum++] = emp;
	}
	//모든 직원의 이번달 급여 내역 출력
	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();
	}
	//이번달 급여의 총액 출력
	void ShowTotalSalary() const
	{
		int sum = 0;
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();
		cout << "salary sum: " << sum << endl;
	}
	//
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};