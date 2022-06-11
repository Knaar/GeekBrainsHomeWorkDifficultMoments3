#include <iostream>
#include <list>
#include <vector>
using namespace std;
/*1. Написать функцию, добавляющую в конец списка вещественных чисел элемент, значение которого равно среднему арифметическому всех его элементов.*/
void GetList(const list<double>& L) {
    for (auto const& i : L) {
        cout << i << " ";
    }
    cout << endl;
}
void FirstJob() {

    list<double> List{ 1.1,2.2,3.3,4.4,5.5 };
    GetList(List);
    double summ{ 0 };
    for (auto const& i : List) {
        summ += i;
    }

    List.push_back(summ / List.size());
    GetList(List);
}
/*2. Создать класс, представляющий матрицу. Реализовать в нем метод, вычисляющий определитель матрицы. Для реализации используйте контейнеры из STL.*/
class Matrix
{


public:
    vector<vector<int>>Vec
    { {9,2,3},
      {2,3,4},
      {8,6,9} };

    void Get() {
        for (int i = 0; i < Vec.size(); i++)
        {
            for (int j = 0; j < Vec[i].size(); j++) {
                cout << Vec[i][j] << " ";
            }
            cout << endl;
        }

    }
    void Determinant() {
        cout << "Determinant: " <<
            Vec[0][0] * Vec[1][1] * Vec[2][2] +
            Vec[0][1] * Vec[1][2] * Vec[2][0] +
            Vec[0][2] * Vec[1][0] * Vec[2][1] -
            Vec[2][0] * Vec[1][1] * Vec[0][2] -
            Vec[2][1] * Vec[1][2] * Vec[0][0] -
            Vec[2][2] * Vec[1][0] * Vec[0][1] <<
            endl;
    }
};
/*3. Реализовать собственный класс итератора, с помощью которого можно будет проитерироваться по диапазону целых чисел в цикле for-range-based.*/
template<typename T>
class MyArray
{
private:
    int size;
    T* arr;
public:
    MyArray(int _size) :size(_size) {
        arr = new T[_size];
    };
    T& operator[](const int& a) {
        return arr[a];
    }

    friend ostream& operator<<(ostream& os, const MyArray<T> n);
    class Iterator
    {
        T* curr;
    public:
        Iterator(T* first) :curr(first) {}
        T& operator+ (int n) { return *(curr + n); }
        T& operator- (int n) { return *(curr - n); }
        T& operator*() { return *curr; }
    };
    Iterator begin() { return arr; }
    Iterator end() { return arr + size; }
};


template<typename T>
ostream& operator<<(ostream& os, const MyArray<T> n) {
    os << MyArray.arr[n];
    return os;
}
int main()
{
    FirstJob();
    Matrix M;
    M.Get();
    M.Determinant();


    MyArray<int> arr(3);
    arr[0] = 44;
    arr[1] = 14;
    arr[2] = 40;

    auto it = MyArray<int>::Iterator(arr.begin());
    cout << it + 2;

}

