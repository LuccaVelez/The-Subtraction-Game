#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <ctime>
#include <chrono>

using namespace std;

int main()
{
    bool start = true;
    int total, maxx, n;
    bool maxError1 = true;
    bool game = true;

    while (game){
// ENTER A TOTAL
        while (start) {
            cout << "Enter a starting total: ";
            cin >> total;
            start = false;
            while (total <= 0) {
                cout << "Enter a positive value: ";
                cin >> total;
            }
        }
    // ENTER MAX SUBTRACTION ALLOWED
        cout << "total: " << total << endl;
        cout << "Enter the maximum amount allowed to be subtracted: ";
        cin >> maxx;
        while (maxError1) {
                if (maxx >= total) {
                    cout << "Enter a value that's smaller than the total: ";
                    cin >> maxx;
                } else if (maxx <= 0) {
                    cout << "Enter a positive value: ";
                    cin >> maxx;
                }
                else {
                    maxError1 = false;
                }

        }

        cout << "max: " << maxx << endl;
        cout << endl;
        int i = 1;
        bool main1 = true;
        while (main1) {
            while (total > 0) {

    // CPU SUBTRACTION

                if (((total - i) % (maxx + 1)) == 0 && i <= maxx) {
                    total -= i; //total = total - i;
                    cout << "I am subtracting " << i << endl;
                    cout << "new total is: " << total << endl;
                    cout << endl;
                } else {
                    i++;
                    if (i <= maxx){
                        continue;
                    } else {
               /*       i = 1;
                        total -= i; //total = total - i;
                        cout << "I am subtracting " << i << endl;
                        cout << "new total is: " << total << endl;
                        cout << endl;
                   */ }
                }
                if (total == 0) {
                    cout << "I reached: " << total << ". You lose!" << endl;
                    main1 = false;
                    //continue;
                    break;
                }

    // USER'S SUBTRACTION

                cout << "Enter number to subtract (1 to " << maxx << "): ";
                cin >> n;

                while ((n < 1 || n > maxx)) {
                    cout << "Number must be between 1 - " << maxx << "): ";
                    cin >> n;
                }
                cout << "You subtracted " << n << endl;

                total = total - n;

                cout << "New total is: " << total << endl;
                cout << endl;
                i = 1;
                if (total == 0) {
                    cout << "You win!" << endl;
                    main1 = false;
                    break;
                }
            }
        }

    // ASK TO PLAY AGAIN
    game = false;
        string YN;
        //if (total == 0) {
            cout << "Do you want to play again? type Y/N: ";
            cin >> YN;

            bool ask = true;
    //    bool restart = true;

            while (ask) {
                if (YN == "Y" || YN == "y") {
                    start = true;
                    maxError1 = true;
                    ask = false;
                    game = true;
                } else if (YN == "N" || YN == "n") {
                    start = true;
                    ask = false;
                } else {
                    cout << "Please select only Y or N: ";
                    cin >> YN;
                }
            }
        //}
    }

    system("PAUSE");
    return 0;
}
