/*
Задание 3. Валидация IP-адреса
Что нужно сделать
Проверьте, задаёт ли введённая пользователем строка корректный IP-адрес четвёртой версии (IPv4). IP-адрес должен представлять из себя четыре 
числа, разделённые точками без пробелов, причём каждое число должно быть в диапазоне от 0 до 255 включительно. 
Числа не должны содержать ведущих нулей. Других символов в строке, кроме вышеописанных, быть не должно.
Пользователь вводит строку, задающую IP-адрес через стандартный ввод. В результате программа должна вывести слово Valid, 
если адрес корректен, и слово Invalid, если это не так.

Примеры
Корректные:
127.0.0.1
255.255.255.255
1.2.3.4
55.77.213.101
Некорректные:
255.256.257.258 (есть числа больше 255)
0.55.33.22. (лишняя точка в конце)
10.00.000.0 (лишние нули)
23.055.255.033 (опять лишние нули)
65.123..9 (две точки подряд)
a.b.c.d (посторонние символы вместо чисел и точек)
*/

#include <iostream>
#include <string>

using namespace std;

string get_address_part(string ip_adress, int n){
    string answer = "";
    int counter_dot = -1;

    if (ip_adress.back() == '.'){
        return "";
    }

    for (size_t i=0; i<ip_adress.size(); ++i){
        if (ip_adress[i] == '.'){
            ++counter_dot;
            if (counter_dot == n){
                return answer;
            }
            else {
                answer = "";
            }
        }
        else {
            answer+=ip_adress[i];
        }
        if (i == ip_adress.size()-1 && n == 3){
            return answer;
        }
    }
    return "";
}

bool is_valid_ip(string ip_adress){
    for (int i=0; i<4; ++i){
        string oktet = get_address_part(ip_adress,i);

        if (oktet.size() < 1 || oktet.size() > 3){
            return false;
        }

        if (oktet[0] == '0' && oktet.size()>1){
            return false;
        }

        for (size_t j=0; j< oktet.size(); ++j){
            if (oktet[j] < '0' || oktet[j] > '9'){
                return false;
            }
        }
        int k = stoi(oktet);
            
        if (k > 255){
            return false;
        }
    }
    return true;
}

int main(){
    setlocale(LC_ALL, "Russian");
    string ip_adress;
    cout << "Введите IP-адрес: ";
    cin >> ip_adress;

    if (is_valid_ip(ip_adress)){
        cout << "Valid";
    }
    else {
        cout << "Invalid";
    }


}