#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

struct Person
{
    char name[25];
    int exam_scores[3];
}A;

void main()
{
    setlocale(LC_ALL, "rus");
    const char* con = { "C:/Users/Admin/source/conv.txt" };
    ofstream f_REQ;
    ifstream f_ANS;
    ofstream kostil;
    fstream fC;
    long pred_size;
    int answer;

    fC.open(con);
    int temp;
    fC >> temp;
    fC.seekg(0, ios::beg);
    temp++;
    fC << temp << endl;;
    string str = to_string(temp);
    fC.close();
    string s2 = "C:/Users/Admin/source/" + str + ".txt";
    const char* client = { s2.c_str() };
    while (true)
    {
        kostil.open(client);
        f_ANS.open(client);
        f_ANS.seekg(0, ios::end);
        pred_size = f_ANS.tellg();
        cout << "Vvedite zapros: second name, exam scores" << endl;
        cin >> A.name;
        for (int i = 0; i < 3; i++)
            cin >> A.exam_scores[i];
        cout << A.name << endl;
        int sum = 0;
        for (int i = 0; i < 3; i++)
            sum += A.exam_scores[i];
        cout << sum;
        fC.open(con, ios::app | ios::in | ios::out);
        fC << A.name << endl;
        for (int i = 0; i < 3; i++)
            fC << A.exam_scores[i] << endl;
        fC.close();


        while (pred_size == f_ANS.tellg())
        {
            Sleep(100);
            f_ANS.seekg(0, ios::end);
        }
        f_ANS.seekg(pred_size, ios::beg);
        f_ANS >> answer;
        pred_size = f_ANS.tellg();
        f_ANS.close();


        switch (answer)
        {
        case 0: {cout << "Postupil \n"; break; }
        case 1: {cout << "Ne postupil\n"; break; }
        case 2: {cout << "Konkurs attestatov\n"; break; }
        }





    }
    std::cout << "Hello World!\n";
}

