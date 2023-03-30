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

int mul(int a, int b, int n) { // a*b mod n
    int sum = 0;

    for (int i = 0; i < b; i++) {
        sum += a;

        if (sum >= n) {
            sum -= n;
        }
    }

    return sum;
}

void diffie()
{
    int p, g, n, d, a = 6, b = 15, s;
    cout << "Введите простое число p: ";
    cin >> p;
    cout << "Введите простое число g меньше p " << p << "): ";
    cin >> g;
    cout << "Секретный ключ Алисы: " << a << endl;
    cout << "Секретный ключ Боба: " << b << endl;
    cout << "Открытый ключ Алисы: " << power(g, a, p) << endl;
    cout << "Открытый ключ Боба: " << power(g, b, p) << endl;
    cout << "Общий секретный ключ (по Алисе): " << power(power(g, b, p), a, p) << endl;
    cout << "Общий секретный ключ (по Бобу): " << power(power(g, a, p), b, p) << endl;
}

void rsa()
{
    int p, q, eiler, e = 3, n, m, c;
    double d;
    cout << "Введите p (простое число): ";
    cin >> p;
    cout << "Введите q (простое число): ";
    cin >> q;
    n = p * q;
    eiler = (p - 1) * (q - 1);
    cout << "Произведение: " << n << endl;
    cout << "Функция Эйлера: " << eiler << endl;
    cout << "Открытая экспонента: " << e << endl;
    d = power(e, -1, eiler);
    cout << "Секретная экспонента: " << d << endl;
    cout << "Открытый ключ: {" << e << ", " << n << "}" << endl;
    cout << "Закрытый ключ: {" << d << ", " << n << "}" << endl << endl;
    cout << "Введите число для зашифровки: ";
    cin >> m;
    c = power(m, e, n);
    cout << "Шифротекст: " << c << endl << endl;
    cout << "Расшифровка: " << power(c, d, n);
}

void elgamal()
{
    int M, M1, p, g, x, y, k, a, b;
    cout << "Введите сообщение для шифрования: ";
    cin >> M;
    cout << "Введите простое число p: ";
    cin >> p;
    cout << "Введите случайный примитивный элемент g: ";
    cin >> g;
    cout << "Введите случайное целое число х (1 < x < " << p - 1 << "): ";
    cin >> x;
    y = power(g, x, p);
    cout << "Открытый ключ: тройка (" << p << ", " << g << ", " << y << ")" << endl;
    cout << "Закрытый ключ: " << x << endl;
    cout << "Введите сессионный ключ (1 < k < " << p - 1 << "): ";
    cin >> k;
    a = power(g, k, p);
    b = mul(power(y, k, p), M, p);
    cout << "Шифротекст: пара (" << a << ", " << b << ")" << endl << endl;
    M1 = mul(b, power(a, p - 1 - x, p), p);
    cout << "Расшифровка: " << M1;
}


int main()
{
    int pulse;
    setlocale(LC_CTYPE, "Rus");
    do
    {
        cout << endl << "-------------------------------" << endl;
        cout << "Выберите алгоритм шифрования:" << endl;
        cout << "1 - Диффи-Хеллман" << endl;
        cout << "2 - RSA" << endl;
        cout << "3 - Эль-Гамаль" << endl;
        cout << "4 - Выход" << endl;
        cin >> pulse;
        switch (pulse)
        {
        case 1: diffie(); break;
        case 2: rsa(); break;
        case 3: elgamal();  break;
        case 4: break;
        }
    } while (pulse != 4);
}

