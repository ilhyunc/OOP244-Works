#ifndef SDDS_GPALIST_H 
#define SDDS_GPALIST_H 

#include "GPA.h"
#include "File.h"

namespace sdds 
{
    bool loadGpa(const char* filename);
    bool gpaQuery(const char* filename);
    void sortData(struct GPA studentNumber[]);
}
#endif