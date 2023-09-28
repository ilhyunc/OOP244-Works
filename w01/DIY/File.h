#ifndef SDDS_FILE_H
#define SDDS_FILE_H

namespace sdds
{
    bool openFile(const char students[]);
    void closeFile();
    bool read(char studentName[]);
    bool read(int* studentNumber);
    bool read(double* gpa);
}

#endif