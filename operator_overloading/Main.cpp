#include "Vector.h"
#include "Matrix.h"
#include "locale.h"


void Vector_test(const Vector& u, const Vector& v)
{
    std::cout << "Тестирование Vector:\n";
    std::cout << "Сложение векторов:\n" << u << "+" << v << "=" << u + v << std::endl;
    std::cout << "Вычитание векторов:\n" << u << "-" << v << "=" << u - v << std::endl;

    std::cout << "Скалярное произведение:\n" << u << "*" << v << "=" << u * v << std::endl;
    std::cout << "Умножение вектора на число:\n" << 2 << "*" << u << "*" << 3 << "=" << 2. * u * 3. << std::endl;

    std::cout << "Размер вектора: " << u << "=" << u.size() << std::endl;
    std::cout << "Длина вектора: " << u << "=" << u.length() << std::endl;
}

void CSLR_test(const CSLRMatrix& cslr, const Vector a, Vector b)
{
    std::cout << "\nТестирование CSLR:\n";
    std::cout << "CSLRMatrix:" << std::endl;
    std::cout << cslr;
    std::cout << "Умножение матрицы на число:\n" << 2. << "*" << "CSLRMatrix" << "*" << 2 << "=" << std::endl;
    std::cout << 2 * cslr * 2;
    std::cout << "Умножение вектора на матрицу:\n" << "CSLRMatrix" << "*" << a << "=";
    std::cout << cslr * a << std::endl;

    std::cout << "Размер CSLRMatrix" << "=" << cslr.size() << std::endl;
    std::cout << "Количество ненулевых элементов CSLRMatrix" << "=" << cslr.nzeros() << std::endl;

    std::cout << "Сложное выражение:" << std::endl;
    double comp = 2 * cslr * 2 * a * (a - b);
    std::cout << "2*CSLRMatrix*2*" << a << "*(" << a << "-" << b << ")=" << comp << std::endl;

    std::cout << "Сложное выражение:" << std::endl;
    Vector v = -2 * cslr * (a - 3. * b) + 4. * a;
    std::cout << "-2*CSLRMatrix*2*(" << a << "-3*" << b << ")+4*" << a << "=" << v << std::endl;
}

int main()
{
    setlocale(0, "russian"); 
    // { 1,-2,3,-1 }
    Vector u;
    std::cout << "Введите размер вектора и его координаты:" << std::endl;
    std::cin >> u;
    // { 1,1,1,0 }
    Vector v;
    std::cout << "Введите размер вектора и его координаты:" << std::endl;
    std::cin >> v;
    // { 1,2,0,3,1 }
    Vector a;
    std::cout << "Введите размер вектора и его координаты:" << std::endl;
    std::cin >> a;
    // { -1,2,3,5,-7 }
    Vector b;
    std::cout << "Введите размер вектора и его координаты:" << std::endl;
    std::cin >> b;

    Vector_test(u, v);

    // { 3,6,-4,2,9 }
    Vector v1(5);
    std::cout << "Введите координаты вектора размера 5:" << std::endl;
    std::cin >> v1;
    // { 7,-5,8,4,1 }
    Vector v2(5);
    std::cout << "Введите координаты вектора размера 5:" << std::endl;
    std::cin >> v2;
    Vector v3 = -2. * (-v1 + v2) + 6. * (a + b);

    std::cout << "Сложное выражение:" << std::endl;
    std::cout << "-2*(" << v1 << "+" << v2 << ")+6*(" << a << "+" << b << ")=" << v3 << std::endl;

    double adiag[] = { 1,3,1,2,3 };
    double altr[] = { 1,0.8,1,2 };
    double autr[] = { 1,0.8,1,2 };
    int jptr1[] = { 0,1,1,1 };
    int iptr1[] = { 0,0,0,2,3,4 };
    CSLRMatrix cslr = CSLRMatrix(adiag, altr, autr, jptr1, iptr1, 5, 13);

    CSLR_test(cslr, a, b);

    std::cout << "\nТестирование Exception:\n";
    try {
        std::cout << "Сложение векторов разных размеров:" << std::endl;
        std::cout << a << "+" << v << std::endl;
        Vector ex_1 = a + v;
    }
    catch (std::exception& ex) {
        std::cout << ex.what();
    }

    try {
        std::cout << "Умножение матрицы на вектор с несовпадающими размерами:" << std::endl;
        std::cout << "CSLRMatrix*" << v << std::endl;
        Vector ex_2 = cslr * v;
    }
    catch (std::exception& ex) {
        std::cout << ex.what();
    }

    try {
        std::cout << "Получение элемента вектора по отрицательному индексу:" << std::endl;
        std::cout << "v=" << v << ", v[-3]" << std::endl;
        double ex_3 = v[-3];
    }
    catch (std::exception& ex) {
        std::cout << ex.what();
    }

    return 0;
}
