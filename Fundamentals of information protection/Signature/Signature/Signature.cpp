#include <iostream>
using namespace std;

int power(int a, int b, int n) { // a^b mod n
    int tmp = a;
    int sum = tmp;
    for (int i = 1; i < b; i++) {
        for (int j = 1; j < a; j++) {
            sum += tmp;
            if (sum >= n) {
                sum -= n;
            }
        }
        tmp = sum;
    }
    return tmp;
}

void var2()
{
    int p = 17, q = 5, eiler, e = 3, n, m1 = 10, m2, c, d, s;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    n = p * q;
    eiler = (p - 1) * (q - 1);
    cout << "Произведение:" << n << endl;
    cout << "Функция Эйлера: " << eiler << endl;
    cout << "Открытая экспонента: " << e << endl;
    /* d = power(e, -1, eiler); */ d = 43;
    cout << "Секретная экспонента: " << d << endl;
    cout << "Открытый ключ: {" << e << ", " << n << "}" << endl;
    cout << "Закрытый ключ: {" << d << ", " << n << "}" << endl << endl;
    cout << "Число для зашифровки: " << m1 << endl;
    c = power(m1, e, n);
    cout << "Шифротекст: " << c << endl;
    cout << "Расшифровка: " << power(c, d, n) << endl; // power c d n
    s = power(m1, d, n); // power m1 d n
    m2 = power(s, e, n); // power s e n
    if (m1 == m2)
    {
        cout << "Подпись правильная!" << endl;
    }
    else
    {
        cout << "Подпись некорректная :(" << endl;
    }
}

int main()
{
    int pulse;

    setlocale(LC_CTYPE, "Rus");

    do
    {
        cout << endl << "-------------------------------" << endl;
        cout << "Выберите, с чем будем работать:" << endl;
        cout << "1 - Работающий с подставлеными" << endl;
        cout << "2 - Выход" << endl;
        cin >> pulse;
        switch (pulse)
        {
        case 1: var2(); break;
        case 2: break;
        }


    } while (pulse != 2);
    system("pause");
}
