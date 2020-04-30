#include <bits/stdc++.h>

using namespace std;

int main() {
    string input = "";
    string output = "";
    int t;
    cin >> t;
    int num = 0;
    int num_old = 0;
    int openparan = 0;

    for (int k = 0; k < t; k++) {
        openparan = 0;
        output = "";
        cin >> input;
        for (int i = 0; i < input.length(); ++i) {
            num = input[i] - '0';
            if (i == 0)
            {

                output += string(num, '(');
                output += input[i];
                num_old= num;
                openparan += num;
            }
            else {
                if (num == num_old) {
                    output += input[i];
                    num_old = num;
                }
                else if (num > num_old) {
                    //output += string(num_old, ')');
                    output += string(num - num_old, '(');
                    output += input[i];
                    openparan += (num - num_old);
                    num_old = num;

                }
                else if (num < num_old) {
                    output += string(num_old - num, ')');
                    output += input[i];
                    openparan -= (num_old - num);
                    num_old = num;

                }
            }

        }
        output += string(openparan, ')');
        cout << "Case #" << k+1 << ": " <<  output << endl;
    }
    return 0;
}
