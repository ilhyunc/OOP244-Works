#ifndef SDDS_UI_H
#define SDDS_UI_H

#include "GPA.h"

#define MAX_STUDENT 86 

namespace sdds 
{
    void clearInputBuffer(void);

    void displayCommand(struct GPA search[]);
}
#endif