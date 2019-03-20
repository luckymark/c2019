#include <iostream>
#include<cstdlib>
#define strcpy strcpy_s

using namespace std;

const int textLength = 1000;
//const int idLength = 10;
const int maxStuPerKlass = 30;
const int maxKlassPerGrade = 12;
const int grade = 4;
const int maxCollege = 10;

struct studentStruct;
struct klassStruct;
struct collegeStruct;
struct schoolStruct;

struct studentStruct{
	char name[textLength];
	long long id;
	int age;
	double possession;
	klassStruct * klass;
};

struct klassStruct{
	int id;
	int grade;
	int studentN;
	studentStruct * student[maxStuPerKlass];
	collegeStruct * college;
};

struct collegeStruct{ //学院
	char name[textLength];
	int klassN[grade];
	klassStruct * klass[grade][maxKlassPerGrade];
};

struct schoolStruct{
	int collegeN;
	collegeStruct * college[maxCollege];
};

int main()
{
	studentStruct stu[100];
	for (int i = 0; i < 100; i++)
	{
		stu[i].name[0] = char((rand() % 26) + 65);
		stu[i].name[1] = char((rand() % 26) + 65);
		stu[i].name[2] = 0;
		stu[i].age = 18;
		stu[i].id = 2018081304001 + i;
		stu[i].possession = rand() % 1000 * 100;
	}

	klassStruct klass[10];
	for (int i = 0; i < 10; i++)
	{
		klass[i].grade = 1;
		klass[i].id = i + 1;
		klass[i].studentN = 0;
	}

	for (int i = 0; i < 100; i++)
	{
		int klassn = rand() % 10;
		klass[klassn].student[klass[klassn].studentN++] = &stu[i];
		stu[i].klass = &klass[klassn];
	}
	 
	collegeStruct college;
	strcpy(college.name, "SCSE");
	college.klassN[0] = 10;
	for (int i = 0; i < 10; i++)
	{
		college.klass[0][i] = &klass[i];
		klass[i].college = &college;
	}

	schoolStruct school;
	school.collegeN = 1;
	school.college[0] = &college;

	strcpy(stu[19].name,"NJJ");
	stu[19].possession = 10000000;

	for (int i = 0; i < 10; i++)
	{
		cout << "Class" << i << "（人数：" << klass[i].studentN << "）" << ":" << endl;
		for (int j = 0; j < klass[i].studentN; j++)
		{
			studentStruct * cur = klass[i].student[j];
			cout << "   姓名：" << cur->name << endl
				<< "      年龄:" << cur->age << endl
				<< "      学号：" << cur->id << endl
				<< "      财产：" << cur->possession << endl << endl;
		}
	}
}


