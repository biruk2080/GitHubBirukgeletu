#include "skipList.h"
#include <iostream>
#include <random>
#include <climits>
#include <stdio.h>
using namespace std;
void test1()
{
    SkipList sl(3);

    sl.Add(20);
    sl.Add(9);
    sl.Add(99);
    sl.Add(3);
    sl.Add(45);
    sl.Add(8);
    sl.Add(56);
    sl.Add(77);
    sl.Add(44);

    std::cout << "After Additions:\n";
    std::cout << sl << std::endl;

    int data[]  = {45, 20, 77, 1, 0};
    for (int elt : data) {
        std::cout << "contains " << elt << ": " << sl.Contains(elt) << std::endl;
    }

    int delData[]  = {45, 77, 1};
    for (int elt : delData) {
        std::cout << "delete " << elt << ": " << sl.Remove(elt) << std::endl;
    }
    std::cout << "After Removes:\n";
    std::cout << sl << std::endl;
}

void test2()
{
    SkipList sl(5);

    sl.Add(20);
    sl.Add(500);
    sl.Add(88);
    sl.Add(-3);
    sl.Add(-8);
    sl.Add(100);
    sl.Add(200);
    sl.Add(150);
    sl.Add(-40);
    sl.Add(200);
    sl.Add(400);
    sl.Add(-8);
    sl.Add(100);
    sl.Add(200);
    sl.Add(150);
    sl.Add(-40);
    sl.Add(200);
    sl.Add(400);
    sl.Remove(200);
    sl.Add(300);
    sl.Add(250);
    sl.Add(350);


    std::cout << "After Additions:\n";
    std::cout << sl << std::endl;

    int data[]  = {45, 200, 7, 100};
    for (int elt : data) {
        std::cout << "contains " << elt << ": " << sl.Contains(elt) << std::endl;
    }

    int delData[]  = {200, -40, 300};
    for (int elt : delData) {
        std::cout << "delete " << elt << ": " << sl.Remove(elt) << std::endl;
    }
    std::cout << "After Removes:\n";
    std::cout << sl << std::endl;
}

void test4() {
    SkipList s(5);
    for (int i = 0; i < 20; ++i) {
        int number = rand() % 100;
        s.Add(number);
        cout << "After adding " << number << endl;
        cout << s << endl;
    }
}

int main() {
    srand(1);
    std::cout << "Test1 ================"<<std::endl;
    test1();
    std::cout << "Test2 ================"<<std::endl;
    test2();
    std::cout << "Test4 ================"<<std::endl;
    test4();
    return 0;
}

