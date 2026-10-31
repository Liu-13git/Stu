#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    string id;
    int* scores;    
    int numScores;
public:
    Student(string n, string i, int cnt, int scoreArr[])
    {
        name = n;
        id = i;
        numScores = cnt;
        scores = new int[numScores]; 
        for(int j = 0; j < numScores; j++)
        {
            scores[j] = scoreArr[j];
        }
        cout << "【调用构造函数】" << endl;
    }

    Student(const Student& other)
    {
        name = other.name;
        id = other.id;
        numScores = other.numScores;
        scores = new int[numScores]; 
        for(int j = 0; j < numScores; j++)
        {
            scores[j] = other.scores[j];
        }
        cout << "【调用深拷贝构造函数】" << endl;
    }

    ~Student()
    {
        delete[] scores;
        cout << "【调用析构函数，释放成绩内存】" << endl;
    }

    void print() const
    {
        cout << name << " " << id << " ";
        for(int j = 0; j < numScores; j++)
        {
            cout << scores[j] << " ";
        }
        cout << endl;
    }

    void setScore(int index, int value)
    {
        if(index >= 0 && index < numScores)
        {
            scores[index] = value;
        }
    }
};

int main()
{
    int scoreArray[] = {85, 90, 78};
    Student stu1("张三", "2025001", 3, scoreArray);
    cout << "stu1：";
    stu1.print();

    Student stu2 = stu1;
    cout << "stu2：";
    stu2.print();

    stu1.setScore(0, 60);
    cout << "\n修改 stu1 第一门成绩为 60 后：" << endl;
    cout << "stu1：";
    stu1.print();
    cout << "stu2：";
    stu2.print();

    return 0;
}