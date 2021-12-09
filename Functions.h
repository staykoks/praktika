#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

struct student {
    string name{};
    string surname{};
    int year{};
    int course{};
    int one_subject{};
    int two_subject{};
    int three_subject{};
};




// Прототипы функций
void DataEntry(student* (&d), int &n); // Ввод данных
void Print(student* d, int n); // Вывод данных
void Search(student* d, int n); // Поиск по запросу
void InputFromTxt(student* (&d), int& n, string fileName); // Ввод данных из текстового файла
void InputFromBin(student* (&d), int& n, string fileName); // Ввод данных из бинарного файла
void TransDatabaseToTxt(student* (&d), int& n, string fileName); // Перевод базы данных в текстовый файл
void TransTxtToBin(student* (&d), int& n); // Перевод текстового файла в бинарный
void Copy(student* (&d_n), student* (&d_o), int n); // Копирование данных
void Copy(student& d_n, student& d_o); // Копирование данных
void ChangeNote(student* (&d), int n); // Изменение записи
void DeleteNote(student* (&d), int& n); // Удаление записи
void AddNote(student* (&d), int &n); // Добавление записи
void SortNameAZ(student* d, int); // Сортировка базы данных по имени А-Я
void SortNameZA(student* d, int); // Сортировка базы данных по имени Я-А
void SortSurnameAZ(student* d, int); // Сортировка базы данных по фамилии (по возрастанию)
void SortSurnameZA(student* d, int); // Сортировка базы данных по фамилии (по убыванию)
void SortYearAZ(student* d, int); // Сортировка базы данных по году поступления (по возрастанию)
void SortYearZA(student* d, int); // Сортировка базы данных по году поступления (по убыванию)
void SortCourseAZ(student* d, int); // Сортировка базы данных по курсу (по возрастанию)
void SortCourseZA(student* d, int); // Сортировка базы данных по курсу (по убыванию)
void SortAvgMarkAZ(student* d, int); // Сортировка базы данных средней оценки (по возрастанию)
void SortAvgMarkZA(student* d, int); // Сортировка базы данных средней оценки (по убыванию)