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




// ��������� �������
void DataEntry(student* (&d), int &n); // ���� ������
void Print(student* d, int n); // ����� ������
void Search(student* d, int n); // ����� �� �������
void InputFromTxt(student* (&d), int& n, string fileName); // ���� ������ �� ���������� �����
void InputFromBin(student* (&d), int& n, string fileName); // ���� ������ �� ��������� �����
void TransDatabaseToTxt(student* (&d), int& n, string fileName); // ������� ���� ������ � ��������� ����
void TransTxtToBin(student* (&d), int& n); // ������� ���������� ����� � ��������
void Copy(student* (&d_n), student* (&d_o), int n); // ����������� ������
void Copy(student& d_n, student& d_o); // ����������� ������
void ChangeNote(student* (&d), int n); // ��������� ������
void DeleteNote(student* (&d), int& n); // �������� ������
void AddNote(student* (&d), int &n); // ���������� ������
void SortNameAZ(student* d, int); // ���������� ���� ������ �� ����� �-�
void SortNameZA(student* d, int); // ���������� ���� ������ �� ����� �-�
void SortSurnameAZ(student* d, int); // ���������� ���� ������ �� ������� (�� �����������)
void SortSurnameZA(student* d, int); // ���������� ���� ������ �� ������� (�� ��������)
void SortYearAZ(student* d, int); // ���������� ���� ������ �� ���� ����������� (�� �����������)
void SortYearZA(student* d, int); // ���������� ���� ������ �� ���� ����������� (�� ��������)
void SortCourseAZ(student* d, int); // ���������� ���� ������ �� ����� (�� �����������)
void SortCourseZA(student* d, int); // ���������� ���� ������ �� ����� (�� ��������)
void SortAvgMarkAZ(student* d, int); // ���������� ���� ������ ������� ������ (�� �����������)
void SortAvgMarkZA(student* d, int); // ���������� ���� ������ ������� ������ (�� ��������)