
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
using namespace std;

struct Person
{
    char name[25];
    int exam_scores[3];
}B;

int answer;
long poz_pred;

int main()
{
    int test = 1;
    ifstream fR;
    ofstream fA;
    fstream fC;
    setlocale(LC_ALL, "rus");
    const char* nameR = { "C:/Users/Admin/source/REQUEST.txt" };
    const char* nameA = { "C:/Users/Admin/source/ANSWER.txt" };
    const char* con = { "C:/Users/Admin/source/conv.txt" };



    cout << "Server is working" << endl;
    fC.open(con, ios::in | ios::out);
    int t1 = 0;

    fC << 0 << endl;
    fC.close();

    while (true)
    {
        fC.open(con);
        fC.seekg(0, ios::end);
        poz_pred = fC.tellg();
        while (poz_pred == fC.tellg())
        {
            Sleep(100);
            fC.seekg(0, ios::end);
        }
        fC.seekg(0, ios::beg);
        int temp;
        fC >> temp;

        fC << temp << endl;
        string str = to_string(temp);
        string s2 = "C:/Users/Admin/source/" + str + ".txt";
        const char* client = { s2.c_str() };

        fA.open(client, ios::app);

        fC.seekg(poz_pred, ios::beg);
        fC >> B.name >> B.exam_scores[0] >> B.exam_scores[1] >> B.exam_scores[2];
        poz_pred = fC.tellg();

        int sum = 0;
        double average = 0;
            for (int i = 0; i < 3; i++)
                sum += B.exam_scores[i];
        average = sum / 3;
        if (average >= 75)
            answer = 0;
        else if (average < 70)
            answer = 1;
        else answer = 2;

        fC.seekg(0, ios::beg);

        fC.close();

        fA << answer;
        fA << endl;
        fA.close();
    }
}
