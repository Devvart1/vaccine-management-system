#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <iomanip>
#include <time.h>
#define num_of_xx 200
using namespace std;
int password();
void menu();
void show();
class xx
{
    int age;
    int temperature;
    int blood_pressure;
    char gender;
    string name;
    string aadhar;
    string profession;
    string state;
    string mobile_number;
    int cnt;

public:

    void search_data();
    void add_new();
    void show_all();
    void setdata();
    void view_vaccine();
    void showdata();
    void search_by_aadhar();
    void search_by_age();
    void search_by_profession();
    void search_by_gender();
    void search_by_state();
    void show_list();
};
void show()
{
    cout << setw(10) << setiosflags(ios::left) << "Name ";
    cout << setw(20) << "Aadhar No.";
    cout << setw(10) << "Age";
    cout << setw(18) << "Profession";
    cout << setw(8) << "B.P.";
    cout << setw(15) << "Temperature";
    cout << setw(7) << "gender";
    cout << setw(15) << "Mobile No.";
    cout << "State" << endl;
}
void xx ::view_vaccine()
{
    ifstream ind;
    int i = 0;
    ind.open("vaccinetrial.txt");
    ind.seekg(0, ios::beg);
    while (ind.read((char *)this, sizeof(xx)))
    {
        i++;
    }
    ind.close();
    int ch;
    int s = num_of_xx - i;
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
         << endl;

    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t    VACCINE STATISTICS";
    cout << "\n\t\t\t*****************************************\n\n";
    cout << "\t\t 1. Add more        \t\t\t2.View available \n\t\t\t\t\t 3. Back" << endl;
    cout << "\n\n\t\t\tSelect a option: ";
    cin >> ch;
    int f_var = 0;
    fstream file("count.txt");
    file >> f_var;
    switch (ch)
    {
    case 1:
        int m;
        cout << "\t Enter number of vaccines you want to add " << endl;
        cin >> m;
        f_var = f_var + m;
        file.seekg(0);
        file << f_var;
        cout << "\t\t Now total number of vaccines are : " << f_var + s;
        break;
    case 2:
        cout << "\n\nAvailable number of vaccines are " << s + f_var;
        break;
    case 3:
        system("cls");
        menu();
    default:
        system("cls");
        cout << "\nEnter valid option " << endl;
        menu();
    }
    file.close();
    getch();
}
void xx::show_all()
{
    int count = 0;

    ifstream in("vaccinetrial.txt");

    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
         << endl;

    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t              ALL ENTRIES ";
    cout << "\n\t\t\t*****************************************\n\n";
    show();
    while (in.read((char *)this, sizeof(xx)))
    {
        ++count;

        show_list();
        getch();
    }

    cout << "\n\n\n\t\t\t\tTotal Number of People who were Vaccinated: " << count;
    cout << " \n\n\n\n\t\t\t\tRecord Successfully Read" << endl;
    getch();
    in.close();
}

void xx::show_list()
{
    cout << "\n";
    cout << setw(10) << setiosflags(ios::left) << name;
    cout << setw(20) << aadhar;
    cout << setw(10) << age;
    cout << setw(18) << profession;
    cout << setw(8) << blood_pressure;
    cout << setw(15) << temperature;
    cout << setw(7) << gender;
    cout << setw(15) << mobile_number;
    cout << state << endl;
}
void xx::search_data()
{
    xx item;
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
         << endl;

    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t         SEARCHING STATISTICS";
    cout << "\n\t\t\t*****************************************\n\n";
    cout << "From which option you want to perform searching " << endl;
    cout << "\n\t\t 1. By aadhar \t\t\t 2. By Age " << endl;
    cout << "\n\t\t 3. By profession \t\t 4. By gender " << endl;
    cout << "\n\t\t 5. By Home State" << endl;
    cout << "\n\n\t\tEnter your choice : ";
    int ch;
    cin >> ch;
    switch (ch)
    {
    case 1:
        system("cls");
        search_by_aadhar();
        getch();
        break;
    case 2:
        system("cls");
        search_by_age();
        getch();
        break;
    case 3:
        system("cls");
        search_by_profession();
        getch();
        break;
    case 4:
        system("cls");
        search_by_gender();
        getch();
        break;
    case 5:
        system("cls");
        search_by_state();
        getch();

        break;
    default:
        system("cls");
        cout << "ENTER VALID OPTION" << endl;
        menu();
    }
}
void xx::search_by_state()
{
    ifstream in("vaccinetrial.txt");
    int flag = 0, p = 0;
    string st;
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
         << endl;

    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t              STATE SEARCHING ";
    cout << "\n\t\t\t*****************************************\n\n";
    cout << "Enter state of any vaccinated person:" << endl;
    fflush(stdin);
    getline(cin, st);
    show();
    in.read((char *)this, sizeof(xx));
    while (!in.eof())
    {

        if (st.compare(state) == 0)
        {
            show_list();
            p++;
            flag = 1;
            break;
        }
        in.read((char *)this, sizeof(xx));
    }
    if (flag == 0)
    {
        cout << "\n\n\n\t\t\tState not found ! " << endl;
    }
    cout << "\n\n\n\n\t\tNO of people vaccinated in this state: " << p;

    in.close();
}
void xx::search_by_aadhar()
{
    ifstream in("vaccinetrial.txt");
    int flag = 0;
    string adh_num;
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
         << endl;

    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t              ADHAR SEARCHING ";
    cout << "\n\t\t\t*****************************************\n\n";
    cout << "Enter your Aadhar number " << endl;
    fflush(stdin);
    getline(cin, adh_num);
    show();
    in.read((char *)this, sizeof(xx));
    while (!in.eof())
    {
        if (adh_num.compare(aadhar) == 0)
        {
            show_list();

            flag = 1;
            break;
        }
        in.read((char *)this, sizeof(xx));
    }
    if (flag == 0)
    {
        cout << "\n\n\n\t\t\tAadhar number not found " << endl;
    }

    in.close();
}
void xx::search_by_age()
{
    ifstream in("vaccinetrial.txt");
    int flag = 0;
    int a, p = 0;
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
         << endl;

    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t AGE SEARCHING ";
    cout << "\n\t\t\t*****************************************\n\n";
    cout << "enter Age by which you want to search " << endl;
    cin >> a;
    show();
    in.read((char *)this, sizeof(xx));
    while (!in.eof())
    {
        if (a == age)
        {
            show_list();
            flag = 1;
            p++;
        }
        in.read((char *)this, sizeof(xx));
    }
    if (flag == 0)
    {
        cout << "\n\n\n\t\t\tAge you entered is not found" << endl;
    }
    cout << "\n\n\n\n\t\t\tNO of people vaccinated  by this age: " << p;
    in.close();
}
void xx::search_by_profession()
{
    ifstream in("vaccinetrial.txt");
    int flag = 0;
    int p = 0;
    string prof;
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
         << endl;

    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t PROFESSION SEARCHING ";
    cout << "\n\t\t\t*****************************************\n\n";
    cout << "enter Profession by which you want to search " << endl;
    fflush(stdin);
    getline(cin, prof);
    show();
    in.read((char *)this, sizeof(xx));
    while (!in.eof())
    {
        if (prof.compare(profession) == 0)
        {
            show_list();
            flag = 1;
            p++;
        }
        in.read((char *)this, sizeof(xx));
    }
    if (flag == 0)
    {
        cout << "\n\n\n\t\t\tThe profession you have Enter does not exist" << endl;
    }
    cout << "\n\n\n\t\tNO of people vaccinated by this profession:" << p << endl;
    in.close();
}
void xx::search_by_gender()
{
    ifstream in("vaccinetrial.txt");
    int flag = 0;
    char g;
    int p = 0;
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
         << endl;

    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t GENDER SEARCHING ";
    cout << "\n\t\t\t*****************************************\n\n";
    cout << "Enter gender by which you want to search " << endl;
    cin >> g;
    show();
    in.read((char *)this, sizeof(xx));
    while (!in.eof())
    {
        if (toupper(g) == toupper(gender))
        {
            show_list();
            flag = 1;
            p++;
        }
        in.read((char *)this, sizeof(xx));
    }
    if (flag == 0)
    {
        cout << "\n\n\t\t\tThe gender you entered does not exist " << endl;
    }
    cout << "\n\n\n NO. of people vaccinated by this gender: " << p << endl;
    in.close();
}
void xx::setdata()
{
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
         << endl;

    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t             ENTRY DATA ";
    cout << "\n\t\t\t*****************************************\n\n";
    fflush(stdin);
    cout << "\n\t\t Enter your name :-  ";
    getline(cin, name);
    cout << "\n\t\t Enter your aadhar :-  ";
    getline(cin, aadhar);
    cout << "\n\t\t Enter your gender (M|F) :-  ";
    cin >> gender;
    cout << "\n\t\t Enter your age:- ";
    cin >> age;
    fflush(stdin);
    cout << "\n\t\t Enter your profession :-  ";
    getline(cin, profession);
    cout << "\n\t\t Enter your B.P. :-  ";
    cin >> blood_pressure;
    cout << "\n\t\t Enter your Body temperature:-  ";
    cin >> temperature;
    fflush(stdin);
    cout << "\n\t\t Enter your Home state :-  ";
    getline(cin, state);
    cout << "\n\t\t Enter your Mobile number :- ";
    getline(cin, mobile_number);
}
void xx::showdata()
{
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
         << endl;

    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t DETAILS  ";
    cout << "\n\t\t\t*****************************************\n\n";
    cout << "\t\t Name is: " << name << endl;
    cout << "\t\t Aadhar number is: " << aadhar << endl;
    cout << "\t\t Your age is " << age << endl;
    cout << "\t\t Profession is : " << profession << endl;
    cout << "\t\t Gender is : " << gender << endl;
    cout << "\t\t Blood pressure is :" << blood_pressure << endl;
    cout << "\t\t Body temperature is : " << temperature << endl;
    cout << "\t\t state is " << state << endl;
    cout << "\t\t Mobile number is: " << mobile_number << endl;
}
void xx::add_new()
{
    fstream outin;
    outin.open("vaccinetrial.txt", ios::app | ios::in);
    setdata();
    outin.write((char *)this, sizeof(xx));
    cout << "YOUR DATA HAS BEEN SUCCESSFULLY INSERTED " << endl;
    getch();
    outin.close();
}

void menu()
{
    system("cls");
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
         << endl;

    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t\tMENU";
    cout << "\n\t\t\t*****************************************\n";
    cout << "\n\t\t1: Add NEW Record\t\t\t 2: View VACCINE DATA" << endl;
    cout << "\n\t\t3: search   \t\t\t\t 4: Show all data" << endl;
    cout << "\n\t\t\t\t\t5: exit  " << endl;
}
int main()
{

    cout << "\n\n\n\n\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
    cout << "\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t@@|                                    WELCOME TO                                         |@@\n";
    cout << "\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t@@|                     \xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3                      |@@\n";
    cout << "\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t@@|                                       -Brought To You by DEVVART     2k20/IT/41       |@@\n";
    cout << "\t\t\t\t@@|                                                      and DHARAMVEER  2k20/It/42       |@@\n";
    cout << "\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
    cout << "\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";

    cout << "\t\n\n\t\t\t\t\t CONTINUE[Press any key]  " << endl;
    getch();

    xx obj;
    int k = 3;
    int num_vac;
B:
    system("cls");
    cout << "\n\n\t\t\t\t*********************************************";
    cout << "\n\t\t\t\t\tEnter User name and Password\n";
    cout << "\t\t\t\t*********************************************\n";
    while (k >= 1)
    {
        int c = password();
        if (c == 1)
        {
            cout << "\n\t\t******LOG IN SUCCESSFUL*******";
            Sleep(2000);
            break;
        }
        else
            cout << "\n\n\t\t Wrong Password Or User Name \n\n\t\t You Can try Only " << k - 1 << " times more";
        k--;
        if (k < 1)
        {
            for (int i = 59; i >= 0; i--)
            {
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\t\t\t\t\tYOU ARE BLOCKED FOR 1 MINUTE!!";
                cout << "\n\n\n\n\n\n\t\t\t\t\tTRY AFTER " << i << " SECONDS.....";
                Sleep(1000);
            }
            k = 3;
            goto B;
        }
    }
    int ch;
    do
    {
        cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
             << endl;
    A:

     label:
        menu();

        cout << "\n\t\n\tChoose according to your need : ";

            cin >> ch;

        xx v1;
        switch (ch)
        {
        case 1:
            system("cls");
            obj.add_new();
            break;
        case 2:
            system("cls");
            obj.view_vaccine();
            break;
        case 3:
            system("cls");
            obj.search_data();
            break;
        case 4:
            system("cls");
            obj.show_all();
            break;
        case 5:
            system("cls");
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tTHANK YOU!!";
            //cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t*Avoid Hand shakes* ";

            cout << "\n\n\t\t\t\t\t  *****HAVE A NICE DAY*****";
            Sleep(3000);
            exit(0);

        default:
            system("cls");
            cout << "\n\n\n\n\n\t\t\t\t\t\tSorry Choice Unavailable !"<< endl;
            cout << "\n\n\t\t\t\t\t\t!!!! RETURNING TO HOME PAGE !!!!";
            Sleep(3000);
            goto A;

            exit(0);
        }
    } while (ch != 0);

    return 0;
}
int password()
{
    char cname[30], pass[20];
    int ch, i = 0, cap = 0, capt = 0;
    cout << "\n\n\n\n\n\t\t\t\t\tUSER NAME:  ";
    fflush(stdin);
    gets(cname);
    cout << "\n\t\t\t\t\tPASSWORD:    ";
    while ((ch = getch()) != 13)
    {
        cout << "*";
        pass[i] = ch;
        i++;
    }
    pass[i] = '\0';
    srand(time(0));
    cap = rand();
    cout << "\n\t\t\t\t\t CAPTURE:->  " << cap << endl;
    cout << " Please enter the valid capture :-   ";
    cin >> capt;
    if ((strcmp(cname, "devvart") == 0) && (strcmp(pass, "dharamveer") == 0) && cap == capt)
        return 1;
    else
        return 0;
}
