#include "Functions.h"
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int command{};

void Menu()
{
    cout << "Выберите действие: \n";
    cout << "[1]  — Ввести данные группы студентов\n";
    cout << "[2]  — Распечатать данные группы студентов\n";
    cout << "[3]  — Вывести анкетные данные студента, имеющего минимальный средний балл\n";
    cout << "[4]  — Ввести данные из уже созданного текстового файла\n";
    cout << "[5]  — Ввести данные из уже созданного бинарного файла\n";
    cout << "[6]  — Перевести базу данных в текстовый файл\n";
    cout << "[7]  — Перевести содержимое текстового файла в бинарный файл\n";
    cout << "[8]  — Изменить запись\n";
    cout << "[9]  — Удалить запись\n";
    cout << "[10] — Добавить запись\n";
    cout << "[11] — Сортировка\n";
    cout << "[0]  — Выход из меню\n";
    cin >> command;
}

int main()
{
    system("chcp 1251 >> null");
    
    Menu();

    int amountData = 0;
    string fileName;


    student* d = new student[amountData];


    while (command != 0)
    {
        switch (command)
        {
        case 1:
            system("cls");
            DataEntry(d, amountData);
            system("cls");
            Menu();
            break;
        case 2:
            system("cls");
            if (amountData != 0)
            {
                Print(d, amountData);
            }
            else
            {
                cout << "Данные пусты!"<<endl;
            }
            system("pause");
            system("cls");
            Menu();
            break;
        case 3:
            system("cls");
            if (amountData != 0)
            {
                Search(d, amountData);
            }
            else
            {
                cout << "Данные пусты!" << endl;
            }
            system("pause");
            system("cls");
            Menu();
            break;
        case 4:
            system("cls");
            InputFromTxt(d, amountData, "Input.txt");
            system("pause");
            system("cls");
            Menu();
            break;
        case 5:
            system("cls");
            InputFromBin(d, amountData, "Input.bin");
            system("pause");
            system("cls");
            Menu();
            break;
        case 6:
            system("cls");
            TransDatabaseToTxt(d, amountData, "Output.txt");
            system("pause");
            system("cls");
            Menu();
            break;
        case 7:
            system("cls");
            TransTxtToBin(d, amountData);
            system("pause");
            system("cls");
            Menu();
            break;
        case 8:
            system("cls");
            if (amountData != 0)
            {
                ChangeNote(d, amountData);
            }
            else
            {
                cout << "Данные пусты!" << endl;
            }
            system("pause");
            system("cls");
            Menu();
            break;
        case 9:
            system("cls");
            if (amountData != 0)
            {
                DeleteNote(d, amountData);
            }
            else
            {
                cout << "Данные пусты!" << endl;
            }
            system("pause");
            system("cls");
            Menu();
            break;
        case 10:
            system("cls");
            if (amountData != 0)
            {
                AddNote(d, amountData);
                amountData++;
            }
            else
            {
                cout << "Данные пусты!" << endl;
            }
            system("pause");
            system("cls");
            Menu();
            break;
        case 11:
            system("cls");
            if (amountData != 0)
            {
                int a;
                cout << "[1]  — Сортировка по имени (А-Я)" << endl;
                cout << "[2]  — Сортировка по имени (Я-А)" << endl;
                cout << "[3]  — Сортировка по фамилии (А-Я)" << endl;
                cout << "[4]  — Сортировка по фамилии (Я-А)" << endl;
                cout << "[5]  — Сортировка по году поступления (по возрастанию)" << endl;
                cout << "[6]  — Сортировка по году поступления (по убыванию)" << endl;
                cout << "[7]  — Сортировка по курсу (по возрастанию)" << endl;
                cout << "[8]  — Сортировка по курсу (по убыванию)" << endl;
                cout << "[9]  — Сортировка по среднему баллу (по возрастанию)" << endl;
                cout << "[10] — Сортировка по среднему баллу (по убыванию)" << endl;
                cout << "Выберите тип сортировки: " << endl;
                cin >> a;
                    switch (a)
                    {
                    case 1:
                        system("cls");
                        SortNameAZ(d, amountData);
                        break;
                    case 2:
                        system("cls");
                        SortNameZA(d, amountData);
                        break;
                    case 3:
                        system("cls");
                        SortSurnameAZ(d, amountData);
                        break;
                    case 4:
                        system("cls");
                        SortSurnameZA(d, amountData);
                        break;
                    case 5:
                        system("cls");
                        SortYearAZ(d, amountData);
                        break;
                    case 6:
                        system("cls");
                        SortYearZA(d, amountData);
                        break;
                    case 7:
                        system("cls");
                        SortCourseAZ(d, amountData);
                        break;
                    case 8:
                        system("cls");
                        SortCourseZA(d, amountData);
                        break;
                    case 9:
                        system("cls");
                        SortAvgMarkAZ(d, amountData);
                        break;
                    case 10:
                        system("cls");
                        SortAvgMarkZA(d, amountData);
                        break;
                    default:
                        system("cls");
                        cout << "Выбрана неверная команда. Попробуйте ещё раз.";
                        break;
                    }
            }
            else
            {
                cout << "Данные пусты!" << endl;
            }
            system("pause");
            system("cls");
            Menu();
            break;
        default:
            system("cls");
            cout << "Выбрана неверная команда. Попробуйте ещё раз.";
        }
    }
}