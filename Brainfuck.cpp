#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string input;
    vector<int> tape(1, 0);
    int ptr = 0;

    cout << "Enter your Brainfuck code: ";
    getline(cin, input);

    for (int i = 0; i < input.length(); i++)
    {
        switch (input[i])
        {
        case '>':
            ptr++;
            if (ptr == tape.size())
                tape.push_back(0);
            break;
        case '<':
            ptr--;
            break;
        case '+':
            tape[ptr]++;
            break;
        case '-':
            tape[ptr]--;
            break;
        case '.':
            cout << (char)tape[ptr];
            break;
        case ',':
            cin >> tape[ptr];
            break;
        case '[':
            if (tape[ptr] == 0)
            {
                int brac = 1;
                while (brac != 0)
                {
                    i++;
                    if (input[i] == '[')
                        brac++;
                    if (input[i] == ']')
                        brac--;
                }
            }
            break;
        case ']':
            if (tape[ptr] != 0)
            {
                int brac = 1;
                while (brac != 0)
                {
                    i--;
                    if (input[i] == '[')
                        brac--;
                    if (input[i] == ']')
                        brac++;
                }
            }
            break;
            
        default: break;
        }
    }
    cout << endl;
    return 0;
}