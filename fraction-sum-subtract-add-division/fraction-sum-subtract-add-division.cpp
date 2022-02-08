// 1. Створіть структуру, що описує простий дріб. Реалізуйте арифметичні операції з дробами: суму, різницю, множення, ділення. 
//Врахувати можливість скорочення дробів і перетворення з неправильного дробу на простий.
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
struct Fraction// створюємо структуру, що описує простий дріб
{
    int a = 0;//чисельник
    int b = 0;//знаменник
    void inputPoint() {
        cout << "Enter numerator - a" << endl;
        cin >> a;
        cout << "Enter  denominator - b" << endl;
        cin >> b;
    }
    void madeFraction() {//функція для виведення дробу
        if (b == 0)cout << "Don't divide by zero" << endl;
        else {
            int fract = a % b;
            if (!fract) cout << a / b << endl;

            else cout << a << "/" << b << endl;
        }
    }
    void reduceFraction() {//функція для скорочення дробу
        while (a % 2 == 0 and b % 2 == 0)
        {
            a /= 2;
            b /= 2;
        }
        while (a % 3 == 0 and b % 3 == 0)
        {
            a /= 3;
            b /= 3;
        }
        while (a % 5 == 0 and b % 5 == 0)
        {
            a /= 5;
            b /= 5;
        }
        while (a % 7 == 0 and b % 7 == 0)
        {
            a /= 7;
            b /= 7;
        }
    }
};
int reduceNumer(int a, int b);//функція скорочення, яка повертає чисельник
int reduceDenom(int a, int b);//функція скорочення, яка повертає знаменник
void Sum(int a, int b, int a1, int b1);//функція для додавання двох дробів
void Subtraction(int a, int b, int a1, int b1);//функція для віднімання двох дробів
void Product(int a, int b, int a1, int b1);//функція для множення двох дробів
void Division(int a, int b, int a1, int b1);//функція для ділення двох дробів

int main()
{   Fraction A;//для першого дробу
    A.inputPoint();//вводимо чисельник та знаменник
    A.madeFraction();//виводимо дріб
    cout << "After fraction reduction" << endl;
    A.reduceFraction();//скорочуємо дріб
    A.madeFraction();//виводимо дріб
    Fraction B;// для другого дробу
    B.inputPoint();//вводимо чисельник та знаменник
    B.madeFraction();//виводимо дріб
    cout << "After fraction reduction" << endl;
    B.reduceFraction();//скорочуємо дріб
    B.madeFraction();//виводимо дріб
    Sum(A.a, A.b, B.a, B.b);//виводимо суму дробів
    Subtraction(A.a, A.b, B.a, B.b);//виводимо різницю дробів
    Product(A.a, A.b, B.a, B.b);//виводимо добуток дробів
    Division(A.a, A.b, B.a, B.b);//виводимо ділення дробів
}
// Не змогла підключити  void reduceFraction() до решти 4 функцій, тому написала дві нижче - перепробувала багато варіантів :(((
int reduceNumer(int a, int b) {//функція скорочення, яка повертає чисельник
    while (a % 2 == 0 and b % 2 == 0)
    {
        a /= 2;
        b /= 2;
    }
    while (a % 3 == 0 and b % 3 == 0)
    {
        a /= 3;
        b /= 3;
    }
    while (a % 5 == 0 and b % 5 == 0)
    {
        a /= 5;
        b /= 5;
    }
    while (a % 7 == 0 and b % 7 == 0)
    {
        a /= 7;
        b /= 7;
    }
    return a;
}
int reduceDenom(int a, int b) {//функція скорочення, яка повертає знаменник
    while (a % 2 == 0 and b % 2 == 0)
    {
        a /= 2;
        b /= 2;
    }
    while (a % 3 == 0 and b % 3 == 0)
    {
        a /= 3;
        b /= 3;
    }
    while (a % 5 == 0 and b % 5 == 0)
    {
        a /= 5;
        b /= 5;
    }
    while (a % 7 == 0 and b % 7 == 0)
    {
        a /= 7;
        b /= 7;
    }
    return b;
}
void Sum(int a, int b, int a1, int b1) {//функція для додавання двох дробів
    int sumNumer1 = 0;
    int denom1 = 1;
    if (b == b1) {
        sumNumer1 = a + a1;
        denom1 = b;
    }
    else if (b % b1 == 0) {
        sumNumer1 = a + a1 * (b / b1);
        denom1 = b;
    }

    else if (b1 % b == 0) {
        sumNumer1 = a * (b1 / b) + a1;
        denom1 = b1;
    }
    else {
        sumNumer1 = a * b1 + a1 * b;
        denom1 = b * b1;
    }
    int sumNumer = reduceNumer(sumNumer1, denom1);//скорочуємо дріб
    int  denom = reduceDenom(sumNumer1, denom1);//скорочуємо дріб
    if (sumNumer < denom) cout << "The sum is = " << sumNumer << "/" << denom << endl;
    else if (sumNumer > denom) {
        int Numb = sumNumer / denom;//шукаємо ціле число від дробу
        if (sumNumer / denom == 0) {
            cout << "The sum is = " << sumNumer / denom << endl;
        }
        int Numer = sumNumer % denom;//шукаємо залишок -чисельник  від неправильного дробу
        cout << "The sum is an improper fraction= " << sumNumer << "/" << denom;
        cout << "- correct is = " << Numb << " and " << Numer << "/" << denom << endl;//перетворюємо неправильний дріб в простий
    }
    else { cout << "The sum is = " << sumNumer / denom << endl; }
}
void Subtraction(int a, int b, int a1, int b1) {//функція для віднімання двох дробів
    int diffNumer1 = 0;
    int denom1 = 1;
    if (b == b1) {
        diffNumer1 = a - a1;
        denom1 = b;
    }
    else if (b % b1 == 0) {
        diffNumer1 = a - a1 * (b / b1);
        denom1 = b;
    }

    else if (b1 % b == 0) {
        diffNumer1 = a * (b1 / b) - a1;
        denom1 = b1;
    }
    else {
        diffNumer1 = a * b1 - a1 * b;
        denom1 = b * b1;
    }
    int diffNumer = reduceNumer(diffNumer1, denom1);//скорочуємо дріб
    int  denom = reduceDenom(diffNumer1, denom1);//скорочуємо дріб
    if (diffNumer < denom and diffNumer>0) cout << "The difference is = " << diffNumer << "/" << denom << endl;
    else if (diffNumer > denom or diffNumer < 0) {
        int Numb = diffNumer / denom;//шукаємо ціле число від дробу
        if (diffNumer / denom == 0) {
            cout << "The difference is = " << diffNumer / denom << endl;
        }
        int Numer = diffNumer % denom;//шукаємо залишок -чисельник  від неправильного дробу
        cout << "The difference is an improper fraction= " << diffNumer << "/" << denom;
        cout << "- correct is = " << Numb << "  and " << Numer << "/" << denom << endl;//перетворюємо неправильний дріб в простий
    }
    else { cout << "The difference is = " << diffNumer / denom << endl; }
}
void Product(int a, int b, int a1, int b1) {//функція для множення двох дробів
    int prodNumer1 = a * a1;
    int denom1 = b * b1;
    int prodNumer = reduceNumer(prodNumer1, denom1);//скорочуємо дріб
    int  denom = reduceDenom(prodNumer1, denom1);//скорочуємо дріб
    if (prodNumer < denom)
        cout << "The product is = " << prodNumer << "/" << denom << endl;
    else if (prodNumer > denom) {
        int Numb = prodNumer / denom;//шукаємо ціле число від дробу
        if (prodNumer / denom == 0) {
            cout << "The prod is = " << prodNumer / denom << endl;
        }
        int Numer = prodNumer % denom;//шукаємо залишок -чисельник  від неправильного дробу
        cout << "The product is an improper fraction= " << prodNumer << "/" << denom;
        cout << "- correct is = " << Numb << " and " << Numer << "/" << denom << endl;//перетворюємо неправильний дріб в простий

    }
}
void Division(int a, int b, int a1, int b1) {//функція для ділення двох дробів
    int divNumer1 = a * b1;
    int denom1 = b * a1;
    int divNumer = reduceNumer(divNumer1, denom1);//скорочуємо дріб
    int  denom = reduceDenom(divNumer1, denom1);//скорочуємо дріб
    if (divNumer < denom)
        cout << "The division is = " << divNumer << "/" << denom << endl;
    else if (divNumer > denom) {
        int Numb = divNumer / denom;//шукаємо ціле число від дробу
        if (divNumer / denom == 0) {
            cout << "The division is = " << divNumer / denom << endl;
        }
        int Numer = divNumer % denom;//шукаємо залишок -чисельник  від неправильного дробу
        cout << "The division is an improper fraction= " << divNumer << "/" << denom;
        cout << "- correct division is = " << Numb << " and " << Numer << "/" << denom << endl;//перетворюємо неправильний дріб в простий
    }
}