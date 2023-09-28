#include <iostream>
#include <cstring>
#include <cstdio>

#include "UI.h"
#include "GPA.h"
#include "GPAlist.h"


using namespace std;

namespace sdds
{
    void clearInputBuffer(void)
    {
        // Discard all remaining input from the standard input buffer:
        while (getchar() != '\n')
        {
            ;
        }
    }
    void displayCommand(struct GPA gpaStudent[])
    {
        double gpaNum = 0;
        char symbol = 0, exitCommand = 0;
        int i, flag = 1;

        cout << "Enter GPA query..." << endl;

        do
        {
            int count = 1;
            cout << "? ";
            cin >> symbol;
            //cout << symbol;
            //cin >> symbol;

            if (symbol == '!')
            {
                cout << "Exit the program? (Y)es/(N)o: ";
                cin >> exitCommand;
                if (exitCommand == 'y' || exitCommand == 'Y')
                {
                    flag = 0;
                }
                else if (exitCommand == 'n' || exitCommand == 'N')
                {
                    flag = 1;
                }
            }
            
            else
            {
                cin >> gpaNum;
            }
            

            if (symbol == '>')
            {
                for (i = 0; i < MAX_STUDENT; i++)
                {
                    if (gpaStudent[i].gpa > gpaNum)
                    {
                        printf("[%d] %d: %.1lf (%s)\n", count++, gpaStudent[i].stno, gpaStudent[i].gpa, gpaStudent[i].name);
                        flag = 1;
                    }
                }
            }
            else if (symbol == '<')
            {
                for (i = 0; i < MAX_STUDENT; i++)
                {
                    if (gpaStudent[i].gpa < gpaNum && gpaStudent[i].gpa != 0)
                    {
                        printf("[%d] %d: %.1lf (%s)\n", count++, gpaStudent[i].stno, gpaStudent[i].gpa, gpaStudent[i].name);
                        flag = 1;
                    }
                }
            }
            else if (symbol == '~')
            {
                //cout << "test" << gpaNum << "    " << gpaStudent[0].gpa << endl;
                for (i = 0; i < MAX_STUDENT; i++)
                {
                    if (gpaStudent[i].gpa <= (gpaNum + 0.05) && gpaStudent[i].gpa >= (gpaNum - 0.05))
                    {
                        printf("[%d] %d: %.1lf (%s)\n", count++, gpaStudent[i].stno, gpaStudent[i].gpa, gpaStudent[i].name);
                        flag = 1;
                    }
                }
            }
            else if (symbol != '~' && symbol != '<' && symbol != '>' && symbol != '!')
            {
                cout << "Syntax error: ? [Op][value]<ENTER>" << endl;
                cout << "Op: [>,<,~,!]" << endl;
                cout << "value: GPA value" << endl
                    << endl;
                flag = 1;
            }
        } while (flag);
    }
}