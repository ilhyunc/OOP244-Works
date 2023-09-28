#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "GPA.h"
#include "File.h"
#include "GPAlist.h"

using namespace std;

    FILE *fptr;

    namespace sdds
    {

        // opens the data file and returns true is successful
        bool openFile(const char students[])
        {  
           // cout << students <<endl;
           // cout << "in open\n";
            fptr = fopen(students, "r");
            //cout << fptr;
            return fptr != NULL;
        }

        void closeFile()
        {
            if (fptr)
            {
                fclose(fptr);
            }
        }

        bool read(char studentName[])
        {
            return fscanf(fptr, "%[^,],", studentName);
        }

        bool read(int* studentNumber)
        {
            return fscanf(fptr, "%d,", studentNumber);
        }

        bool read(double* gpa)
        {
            return fscanf(fptr, "%lf\n", gpa);

        }

    }
