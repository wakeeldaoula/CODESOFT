#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
int main()
{
    cout<<"\t\t\t\t***NUMBER GUESSING GAME***\n";
    bool LoopControl=true;
    int number;
        srand(static_cast<unsigned int>(time(nullptr)));    
        while (LoopControl)
    {
        rand();
        cout << "Guess the number which is generated randomly:";
        cin >> number;
        if (number == rand())
        {
            cout << "OMG your guess is correct!!!!";
            LoopControl=false;
        }
        else
        {
            if (number > rand())
            {
                cout << "Too large\n";
            }
            else
            {
                cout << "Too Small\n";
            }
        }
    }

    return 0;
}