#include "Functions.h"
#include <iomanip>
#include <fstream>
#include <string>

int min_mark{5}, num_of_student{};
void DataEntry(student* (&d), int &n)
{
    cout << "������� ���������� ���������: ";
    cin >> n;
    d = new student[n];
	for (int i = 0; i < n; i++)
	{
		cout << "������� ������ �������� �" << i + 1;
        cout << "\n������� ��� ��������: ";
        cin >> d[i].name;
        system("cls");
        cout << "������� ������� ��������: ";
        cin>>d[i].surname;
        system("cls");
        cout << "������� ��� ����������� ��������: ";
        cin >> d[i].year;
        system("cls");
        while (d[i].year < 2000 || d[i].year > 2021)
        {
            system("cls");
            cout << "�� ����� �������� ������! ���������� ��� ���!" << endl;
            cout << "������� ��� ����������� ��������: ";
            cin >> d[i].year;
        }
        cout << "������� ���� ��������: ";
        cin >> d[i].course;
        system("cls");
        while (d[i].course < 1 || d[i].course > 6)
        {
            system("cls");
            cout << "�� ����� �������� ������! ���������� ��� ���!" << endl;
            cout << "������� ���� ��������: ";
            cin >> d[i].course;
        }
        cout << "������� ������ �������� �� ������� ��������: ";
        cin >> d[i].one_subject;
        system("cls");
        while (d[i].one_subject < 0 || d[i].one_subject > 5)
        {
            system("cls");
            cout << "�� ����� �������� ������! ���������� ��� ���!" << endl;
            cout << "������� ������ �������� �� ������� ��������: ";
            cin >> d[i].one_subject;
        }
        cout << "������� ������ �������� �� ������� ��������: ";
        cin >> d[i].two_subject;
        system("cls");
        while (d[i].two_subject < 0 || d[i].two_subject > 5)
        {
            system("cls");
            cout << "�� ����� �������� ������! ���������� ��� ���!" << endl;
            cout << "������� ������ �������� �� ������� ��������: ";
            cin >> d[i].two_subject;
        }
        cout << "������� ������ �������� �� �������� ��������: ";
        cin >> d[i].three_subject;
        system("cls");
        while (d[i].three_subject < 0 || d[i].three_subject > 5)
        {
            system("cls");
            cout << "�� ����� �������� ������! ���������� ��� ���!" << endl;
            cout << "������� ������ �������� �� �������� ��������: ";
            cin >> d[i].three_subject;
        }
	}
}
void Print(student* d, int n)
{
    cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "|" << left << setw(14) << "���" << "|" << left << setw(14) << "�������" << "|" << left << setw(20) << "��� �����������" << "|" << left << setw(8) << "����" << "|" << left << setw(30) << "������ �� ������� ��������" << "|" << left << setw(30) << "������ �� ������� ��������" << "|" << left << setw(31) << "������ �� �������� ��������" << "|" << endl;
    cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "|" << left << setw(14) << d[i].name << "|" << left << setw(14) << d[i].surname << "|" << left << setw(20) << d[i].year << "|" << left << setw(8) << d[i].course << "|" << left << setw(30) << d[i].one_subject << "|" << left << setw(30) << d[i].two_subject << "|" << left << setw(31) << d[i].three_subject << "|" << endl;
    }
    cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������" << endl;
}
void Search(student* d, int n)
{
    for (int i{}; i < n; i++)
    {
        if (((d[i].one_subject + d[i].two_subject + d[i].three_subject) / 3) < min_mark)
        {
            min_mark = (d[i].one_subject + d[i].two_subject + d[i].three_subject) / 3;
            num_of_student = i;
        }
    }
    cout << "������ �������� � ����������� ������� ������" << "\n";
    cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "|" << left << setw(14) << "���" << "|" << left << setw(14) << "�������" << "|" << left << setw(20) << "��� �����������" << "|" << left << setw(8) << "����" << "|" << left << setw(30) << "������ �� ������� ��������" << "|" << left << setw(30) << "������ �� ������� ��������" << "|" << left << setw(31) << "������ �� �������� ��������" << "|" << endl;
    cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "|" << left << setw(14) << d[num_of_student].name << "|" << left << setw(14) << d[num_of_student].surname << "|" << left << setw(20) << d[num_of_student].year << "|" << left << setw(8) << d[num_of_student].course << "|" << left << setw(30) << d[num_of_student].one_subject << "|" << left << setw(30) << d[num_of_student].two_subject << "|" << left << setw(31) << d[num_of_student].three_subject << "|" << endl;
    cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������" << endl;
}
void InputFromTxt(student* (&d), int& n, string fileName)
{
    ifstream reading(fileName);

    if (reading)
    {
        reading >> n;

        d = new student[n];

        for (int i = 0; i < n; i++)
        {
            reading >> d[i].name;
            reading >> d[i].surname;
            reading >> d[i].year;
            reading >> d[i].course;

            reading >> d[i].one_subject;
            reading >> d[i].two_subject;
            reading >> d[i].three_subject;
        }
        cout << "������ �������!" << endl;
    }
    else 
    {
        cout << "������ �������� �����!" << endl;
    }

    reading.close();   
}
void InputFromBin(student* (&d), int& n, string fileName)
{
    ifstream reading(fileName);

    if (reading)
    {
        reading >> n;

        d = new student[n];

        for (int i = 0; i < n; i++)
        {
            reading >> d[i].name;
            reading >> d[i].surname;
            reading >> d[i].year;
            reading >> d[i].course;

            reading >> d[i].one_subject;
            reading >> d[i].two_subject;
            reading >> d[i].three_subject;
        }
        cout << "������ �������!" << endl;
    }
    else
    {
        cout << "������ �������� �����!" << endl;
    }

    reading.close();
}
void TransDatabaseToTxt(student* (&d), int& n, string fileName)
{
    ofstream open(fileName);

    if (open)
    {
        open << n << endl;

        for (int i = 0; i < n; i++)
        {
            open << d[i].name << endl;
            open << d[i].surname << endl;
            open << d[i].year << endl;
            open << d[i].course << endl;
            open << d[i].one_subject << endl;
            open << d[i].two_subject << endl;
            open << d[i].three_subject << endl;
        }
        cout << "������ ��������!" << endl;
    }
    else
    {
        cout << "������ ������ � ����!" << endl;
    }
    open.close();
}
void TransTxtToBin(student* (&d), int& n)
{
    InputFromTxt(d, n, "Input.txt");
    TransDatabaseToTxt(d, n, "Output.bin");
    cout << "������� �����������!" << endl;
}
void Copy(student* (&d_n), student* (&d_o), int n)
{
    for (int i = 0; i < n; i++)
    {
        d_n[i] = d_o[i];
    }
}
void Copy(student& d_n, student& d_o)
{
    d_n.name = d_o.name;
    d_n.surname = d_o.surname;
    d_n.year = d_o.year;
    d_n.course = d_o.course;
    d_n.one_subject = d_o.one_subject;
    d_n.two_subject = d_o.two_subject;
    d_n.three_subject = d_o.three_subject;

}
void ChangeNote(student* (&d), int n)
{
    int _n;
    cout << "������� ����� �������� (�� 1 �� " << n << "): ";
    cin >> _n;
    _n--;
    system("cls");
    if (_n >= 0 && _n < n)
    {
        int b;
        cout << "[1] � �������� ���" << endl;
        cout << "[2] � �������� �������" << endl;
        cout << "[3] � �������� ��� �����������" << endl;
        cout << "[4] � �������� ����" << endl;
        cout << "[5] � �������� ������ �� ������� ��������" << endl;
        cout << "[6] � �������� ������ �� ������� ��������" << endl;
        cout << "[7] � �������� ������ �� �������� ��������" << endl;
        cout << "�������� ��� ��������: " << endl;
        cin >> b;
        switch (b)
        {
        case 1:
            cout << "\n������� ��� ��������: ";
            cin.ignore();
            cin >> d[_n].name;
            system("cls");
            break;
        case 2:
            cout << "������� ������� ��������: ";
            cin >> d[_n].surname;
            system("cls");
            break;
        case 3:
            cout << "������� ��� ����������� ��������: ";
            cin >> d[_n].year;
            system("cls");
            while (d[_n].year < 2000)
            {
                system("cls");
                cout << "�� ����� �������� ������! ���������� ��� ���!" << endl;
                cout << "������� ��� ����������� ��������: " << endl;
                cin >> d[_n].year;
            }
            break;
        case 4:
            cout << "������� ���� ��������: " << endl;
            cin >> d[_n].course;
            system("cls");
            while (d[_n].course < 1 || d[_n].course > 6)
            {
                system("cls");
                cout << "�� ����� �������� ������! ���������� ��� ���!" << endl;
                cout << "������� ���� ��������: " << endl;
                cin >> d[_n].course;
            }
            break;
        case 5:
            cout << "������� ������ �������� �� ������� ��������: " << endl;
            cin >> d[_n].one_subject;
            system("cls");
            while (d[_n].one_subject < 0 || d[_n].one_subject > 5)
            {
                system("cls");
                cout << "�� ����� �������� ������! ���������� ��� ���!" << endl;
                cout << "������� ������ �������� �� ������� ��������: " << endl;
                cin >> d[_n].one_subject;
            };
            break;
        case 6:
            cout << "������� ������ �������� �� ������� ��������: " << endl;
            cin >> d[_n].two_subject;
            system("cls");
            while (d[_n].two_subject < 0 || d[_n].two_subject > 5)
            {
                system("cls");
                cout << "�� ����� �������� ������! ���������� ��� ���!" << endl;
                cout << "������� ������ �������� �� ������� ��������: " << endl;
                cin >> d[_n].two_subject;
            }
            break;
        case 7:
            cout << "������� ������ �������� �� �������� ��������: " << endl;
            cin >> d[_n].three_subject;
            system("cls");
            while (d[_n].three_subject < 0 || d[_n].three_subject > 5)
            {
                system("cls");
                cout << "�� ����� �������� ������! ���������� ��� ���!" << endl;
                cout << "������� ������ �������� �� �������� ��������: " << endl;
                cin >> d[_n].three_subject;
            }
            break;
        default:
            system("cls");
            cout << "������� �������� �������. ���������� ��� ���.";
            break;
        }
        system("cls");
        cout << "������ ������� ��������!" << endl;
    }
    else
    {
        system("cls");
        cout << "����� �������� ������ �������!" << endl;
    }
}
void DeleteNote(student* (&d), int& n)
{
    int _n;
    cout << "������� ����� �������� (�� 1 �� " << n << "): ";
    cin >> _n;
    _n--;
    system("cls");
    if (_n >= 0 && _n < n)
    {
        student* temp = new student[n];

        Copy(temp, d, n);

        --n;
        d = new student[n];
        int q = 0;

        for (int i = 0; i <= n; i++)
        {
            if (i != _n)
            {
                d[q] = temp[i];
                ++q;
            }
        }
    }
}
void AddNote(student* (&d), int &n)
{
    student* temp;
    temp = new student[n];

    Copy(temp, d, n);

    n++;
    d = new student[n];
        
    Copy(d, temp, --n);

    cout << "������� ������ �������� �" << n + 1;
    cout << "\n������� ��� ��������: ";
    cin.ignore();
    cin>>d[n].name;
    system("cls");
    cout << "������� ������� ��������: ";
    cin>>d[n].surname;
    system("cls");
    cout << "������� ��� ����������� ��������: ";
    cin >> d[n].year;
    system("cls");
    while (d[n].year < 2000)
    {
        system("cls");
        cout << "�� ����� �������� ������! ���������� ��� ���!" << endl;
        cout << "������� ��� ����������� ��������: ";
        cin >> d[n].year;
    }
    cout << "������� ���� ��������: ";
    cin >> d[n].course;
    system("cls");
    while (d[n].course < 1 || d[n].course > 6)
    {
        system("cls");
        cout << "�� ����� �������� ������! ���������� ��� ���!" << endl;
        cout << "������� ���� ��������: ";
        cin >> d[n].course;
    }
    cout << "������� ������ �������� �� ������� ��������: ";
    cin >> d[n].one_subject;
    system("cls");
    while (d[n].one_subject < 0 || d[n].one_subject > 5)
    {
        system("cls");
        cout << "�� ����� �������� ������! ���������� ��� ���!" << endl;
        cout << "������� ������ �������� �� ������� ��������: ";
        cin >> d[n].one_subject;
    }
    cout << "������� ������ �������� �� ������� ��������: ";
    cin >> d[n].two_subject;
    system("cls");
    while (d[n].two_subject < 0 || d[n].two_subject > 5)
    {
        system("cls");
        cout << "�� ����� �������� ������! ���������� ��� ���!" << endl;
        cout << "������� ������ �������� �� ������� ��������: ";
        cin >> d[n].two_subject;
    }
    cout << "������� ������ �������� �� �������� ��������: ";
    cin >> d[n].three_subject;
    system("cls");
    while (d[n].three_subject < 0 || d[n].three_subject > 5)
    {
        system("cls");
        cout << "�� ����� �������� ������! ���������� ��� ���!" << endl;
        cout << "������� ������ �������� �� �������� ��������: ";
        cin >> d[n].three_subject;
    }
    system("cls");

    cout << "������ ������� ���������!" << endl;

    delete[]temp;

}
void SortNameAZ(student* d, int n)
{
    student temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (d[i].name > d[j].name)
            {
                Copy(temp, d[j]);
                Copy(d[j], d[i]);
                Copy(d[i], temp);
            }
        }
    }
    cout << "������ �������������!" << endl;
}
void SortNameZA(student* d, int n)
{
    student temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (d[i].name < d[j].name)
            {
                Copy(temp, d[j]);
                Copy(d[j], d[i]);
                Copy(d[i], temp);
            }
        }
    }
    cout << "������ �������������!" << endl;
}
void SortSurnameAZ(student* d, int n)
{
    student temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (d[i].surname > d[j].surname)
            {
                Copy(temp, d[j]);
                Copy(d[j], d[i]);
                Copy(d[i], temp);
            }
        }
    }
    cout << "������ �������������!" << endl;
}
void SortSurnameZA(student* d, int n)
{
    student temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (d[i].surname < d[j].surname)
            {
                Copy(temp, d[j]);
                Copy(d[j], d[i]);
                Copy(d[i], temp);
            }
        }
    }
    cout << "������ �������������!" << endl;
}
void SortYearAZ(student* d, int n)
{
    student temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (d[i].year > d[j].year)
            {
                Copy(temp, d[j]);
                Copy(d[j], d[i]);
                Copy(d[i], temp);
            }
        }
    }
    cout << "������ �������������!" << endl;
}
void SortYearZA(student* d, int n)
{
    student temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (d[i].year < d[j].year)
            {
                Copy(temp, d[j]);
                Copy(d[j], d[i]);
                Copy(d[i], temp);
            }
        }
    }
    cout << "������ �������������!" << endl;
}
void SortCourseAZ(student* d, int n)
{
    student temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (d[i].course > d[j].course)
            {
                Copy(temp, d[j]);
                Copy(d[j], d[i]);
                Copy(d[i], temp);
            }
        }
    }
    cout << "������ �������������!" << endl;
}
void SortCourseZA(student* d, int n)
{
    student temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (d[i].course < d[j].course)
            {
                Copy(temp, d[j]);
                Copy(d[j], d[i]);
                Copy(d[i], temp);
            }
        }
    }
    cout << "������ �������������!" << endl;
}
void SortAvgMarkAZ(student* d, int n)
{
    student temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((d[i].one_subject + d[i].two_subject + d[i].three_subject) > (d[j].one_subject + d[j].two_subject + d[j].three_subject))
            {
                Copy(temp, d[j]);
                Copy(d[j], d[i]);
                Copy(d[i], temp);
            }
        }
    }
    cout << "������ �������������!" << endl;
}
void SortAvgMarkZA(student* d, int n)
{
    student temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((d[i].one_subject + d[i].two_subject + d[i].three_subject) < (d[j].one_subject + d[j].two_subject + d[j].three_subject))
            {
                Copy(temp, d[j]);
                Copy(d[j], d[i]);
                Copy(d[i], temp);
            }
        }
    }
    cout << "������ �������������!" << endl;
}
