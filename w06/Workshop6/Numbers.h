#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
    class Numbers 
    {
        double* m_collection;
        char m_fileName[255];
        unsigned int m_collectionSize{};
        bool m_isOriginal{};
        bool m_addFlag{};
        
        void sort(double* collectionPtr, unsigned int size);

        unsigned int countLines(const char* filename);
        void setEmpty();
        bool load();
        void save();
        double max() const;
        double min() const;
        double average() const;

    public:
        // constructors
        Numbers();
        Numbers(const char* filename);
        // destructor
        ~Numbers();
        // copy constructor
        Numbers(const Numbers& I);// 만들어지면서 복사완료.
        // assignment operator
        Numbers& operator=(const Numbers& other);// 만들고 난후 복사 따로 시행.

        // type cast operator
        operator bool() const;

        void sort();
        Numbers& operator+=(double value);
        std::ostream& display(std::ostream& ostr = std::cout) const;
    };

    std::ostream& operator<<(std::ostream& ostr, const Numbers& right);
    std::istream& operator>>(std::istream& istr, Numbers& right);
}
#endif // !SDDS_NUMBERS_H_


