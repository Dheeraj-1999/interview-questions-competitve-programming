#include<bits/stdc++.h>
using namespace std;

// void urlify(char* input, int tLen) {
//     // char* output = new char[input.length()];
//     vector<char> output; 
//     for(int i=0; i<tLen; i++) {
//         if(input[i] == ' ') {
//             output.push_back('%');
//             output.push_back('2');
//             output.push_back('0');
//         } else {
//             output.push_back(input[i]);
//         }
//         // cout << output[i] << " " ;
//     }
//     cout << output.size() <<endl;
//     for (int i=0; i<output.size(); i++)
//         cout << endl << output[i];
// }


void replaceThestring(char* input, int trueLength) {
    // Forward pass
    int spCount = 0;
    int index;
    for(int i=0; i<trueLength; i++) {
        if(input[i] == " ")
            spCount += 1;
    }
    // backward pass
    index = trueLength + spCount*2;
    for(int i=trueLength-1; i>=0; i--) {
        if(input[i] == " ") {
            input[index-1] = '%';
            input[index-2] = '2';
            input[index-3] = '0';
            index -= 3;
        } else {
            input[index-1] = input[i];
            index--;
        }
    }
}

int main() {
    int trueLength;
    cin >> trueLength;
    char* input = new char[trueLength];
    cin >> input;
    // cout << input.size();
    // urlify(input, trueLength);
    replaceThestring(input, trueLength);
}