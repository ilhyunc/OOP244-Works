#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cstdio>

#include "GPAlist.h"
#include "File.h"
#include "GPA.h"
#include "UI.h"

#define MAX_STUDENT 86 

using namespace std;

namespace sdds
{
    GPA studentInfo[MAX_STUDENT];
    bool loadGpa(const char* filename)
    {
        //cout << filename <<endl;
        GPA studentGPA = { {0} };

        int readGPA = 0;
        bool success = false;
        
        if (openFile(filename))
        {
            //cout << "after openfile\n";
;            for (int i = 0; i < MAX_STUDENT; i++)
            {
                success = (read(studentGPA.name) && read(&studentGPA.stno) && read(&studentGPA.gpa));
                //cout << studentGPA.gpa << endl;
                if (success)
                {
                    studentInfo[readGPA++] = studentGPA;
                }
            }
            closeFile();
        }
        sortData(studentInfo);
        return success;
    }

    bool gpaQuery(const char* filename)
    {
        bool flag = false;
        //cout << filename <<endl;
        if (loadGpa(filename) == true)
        {
            //cout << "after loadgpa check\n";
            flag = true;
            displayCommand(studentInfo);
        }
        return flag;
    }

    void sortData(struct GPA studentNumber[])
    {
        GPA studentGPA;

        int i, j;

        for (i = 0; i < MAX_STUDENT - 1; i++)
        {
            for (j = 0; j < (MAX_STUDENT - 1 - i); j++)
            {
                if (studentNumber[j].stno > studentNumber[j + 1].stno)
                {
                    studentGPA = studentNumber[j];
                    studentNumber[j] = studentNumber[j + 1];
                    studentNumber[j + 1] = studentGPA;
                }
            }
        }
    }


}