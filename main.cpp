#include "iostream"
using namespace std;

int BinToDec(bool bin[]);
bool* DecToBin(int dec);

int main(void) {
    system("clear");
    bool switch0_check[4] = {0};
    bool switch1_check[4] = {0};
    int i, sum, carry = 0;
    int switch_0, switch_1;
    int right_digit, left_digit;

    bool* right_D;
    bool* left_D;

    cout << "Enter the switch0: " << endl;
    for (i = 3; i >= 0; i--) 
        cin >> switch0_check[i];
    switch_0 = BinToDec(switch0_check);
    cout << '\t' << switch_0 << endl << endl;

    cout << "Enter the switch1: " << endl;
    for (i = 3; i >= 0; i--)
        cin >> switch1_check[i];
    switch_1 = BinToDec(switch1_check);
    cout << '\t' << switch_1 << endl << endl;


    sum = switch_0 + switch_1;
    cout << switch_0 << " + " << switch_1 << " = " << sum << endl << endl; 

    if (sum >= 100) {
        left_digit = 0;
        right_digit = 0;
    } else {
        left_digit = sum / 10;
        right_digit = sum % 10;
    }

    left_D = DecToBin(left_digit);
    right_D = DecToBin(right_digit);


    cout << "  " << left_digit << "    " << right_digit << endl;
    for (i = 3; i >= 0; i--)
        cout << left_D[i];

    cout << " ";
    for (i = 3; i >= 0; i--)
        cout << right_D[i];

}

int BinToDec(bool bin[]) {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        if (i == 0) {
            if (bin[i] == 1)
                sum += 1;
            else
                sum += 0;
        } else if (i == 1) {
            if (bin[i] == 1)
                sum += 2;
            else
                sum += 0;
        } else if (i == 2) {
            if (bin[i] == 1)
                sum += 4;
            else
                sum += 0;
        } else if (i == 3) {
            if (bin[i] == 1)
                sum += 8;
            else
                sum += 0;
        }
    }

    return sum;
}

bool* DecToBin(int dec) {
    bool*bin = (bool*) malloc(sizeof(bool) * 4);
    switch (dec) {
        case 9:
            bin[3] = 1;
            bin[2] = 0;
            bin[1] = 0;
            bin[0] = 1;
            break;
        case 8:
            bin[3] = 1;
            bin[2] = 0;
            bin[1] = 0;
            bin[0] = 0;
            break;
        case 7:
            bin[3] = 0;
            bin[2] = 1;
            bin[1] = 1;
            bin[0] = 1;
            break;
        case 6:
            bin[3] = 0;
            bin[2] = 1;
            bin[1] = 1;
            bin[0] = 0;
            break;
        case 5:
            bin[3] = 0;
            bin[2] = 1;
            bin[1] = 0;
            bin[0] = 1;
            break;
        case 4:
            bin[3] = 0;
            bin[2] = 1;
            bin[1] = 0;
            bin[0] = 0;
            break;
        case 3:
            bin[3] = 0;
            bin[2] = 0;
            bin[1] = 1;
            bin[0] = 1;
            break;
        case 2:
            bin[3] = 0;
            bin[2] = 0;
            bin[1] = 1;
            bin[0] = 0;
            break;
        case 1:
            bin[3] = 0;
            bin[2] = 0;
            bin[1] = 0;
            bin[0] = 1;
            break;
        default:
            bin[3] = 0;
            bin[2] = 0;
            bin[1] = 0;
            bin[0] = 0;
            break;
    }

    return bin;
}