/*
������� 3. ��������� IP-������
��� ����� �������
���������, ����� �� �������� ������������� ������ ���������� IP-����� �������� ������ (IPv4). IP-����� ������ ������������ �� ���� ������ 
�����, ���������� ������� ��� ��������, ������ ������ ����� ������ ���� � ��������� �� 0 �� 255 ������������. 
����� �� ������ ��������� ������� �����. ������ �������� � ������, ����� �������������, ���� �� ������.
������������ ������ ������, �������� IP-����� ����� ����������� ����. � ���������� ��������� ������ ������� ����� Valid, 
���� ����� ���������, � ����� Invalid, ���� ��� �� ���.

�������
����������:
127.0.0.1
255.255.255.255
1.2.3.4
55.77.213.101
������������:
255.256.257.258 (���� ����� ������ 255)
0.55.33.22. (������ ����� � �����)
10.00.000.0 (������ ����)
23.055.255.033 (����� ������ ����)
65.123..9 (��� ����� ������)
a.b.c.d (����������� ������� ������ ����� � �����)
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
    cout << "������� IP-�����: ";
    cin >> ip_adress;

    if (is_valid_ip(ip_adress)){
        cout << "Valid";
    }
    else {
        cout << "Invalid";
    }


}