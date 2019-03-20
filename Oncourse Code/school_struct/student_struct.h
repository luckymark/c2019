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

struct studentStruct {
	char name[textLength];
	long long id;
	int age;
	double possession;
	klassStruct * klass;
};

struct klassStruct {
	int id;
	int grade;
	int studentN;
	studentStruct * student[maxStuPerKlass];
	collegeStruct * college;
};

struct collegeStruct { //??
	char name[textLength];
	int klassN[grade];
	klassStruct * klass[grade][maxKlassPerGrade];
};

struct schoolStruct {
	int collegeN;
	collegeStruct * college[maxCollege];
};

void test();