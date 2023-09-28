#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#include "Numbers.h"

using namespace std;
namespace sdds 
{
    void Numbers::sort(double* nums, unsigned int size) 
    {
        unsigned int i, j;
        double temp;
        for (i = size - 1; size && i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (nums[j] > nums[j + 1]) {
                    temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
    }

    unsigned int Numbers::countLines(const char* filename) 
    { /**/
        unsigned int lines = 0u;
        ifstream nums(filename);
        while (nums) {
            lines += (nums.get() == '\n');
        }
        return lines;
    }

    void Numbers::setEmpty()
    {
        m_collection = nullptr;
        strcpy(m_fileName, "");
        m_collectionSize = 0;
        m_isOriginal = false;
        m_addFlag = false;
    }

    bool Numbers::load()
    {
        bool result = false;

        unsigned int noOfLines = countLines(m_fileName);
        unsigned int i{};
        double temp{};
        delete[] m_collection;
        m_collection = nullptr;
        if (noOfLines > 0) 
        {
            double temp{};
            m_collection = new double[noOfLines];
            ifstream istr(m_fileName);
            while (i < noOfLines && istr >> temp)
            {
                m_collection[i] = temp;
                i++;
            }
            result = true;

            if (noOfLines == i)
            {
                m_collectionSize = noOfLines;
                m_isOriginal = true;
            }
            else 
            {
                delete[] m_collection;
                setEmpty();
            }
        }

        return result;
    }

    void Numbers::save()
    {
        if (m_isOriginal && m_addFlag)
        {
            ofstream ostr(m_fileName);

            for (unsigned int i = 0; i < m_collectionSize; ++i)
            {
                ostr.precision(2);
                ostr << m_collection[i];

                if (i < m_collectionSize - 1) 
                {
                    ostr << endl;
                }
            }
        }
    }

    double Numbers::max() const
    {
        double max = m_collection[0];
        for (unsigned int i = 1; i < m_collectionSize; ++i)
        {
            if (max < m_collection[i])
            {
                max = m_collection[i];
            }
        }
        return max;
    }

    double Numbers::min() const
    {
        double min = m_collection[0];
        for (unsigned int i = 1; i < m_collectionSize; ++i)
        {
            if (min > m_collection[i]) 
            {
                min = m_collection[i];
            }
        }

        return min;
    }

    double Numbers::average() const
    {
        double sum = 0;
        for (unsigned int i = 0; i < m_collectionSize; ++i)
        {
            sum += m_collection[i];
        }
        return (sum / m_collectionSize);
    }

    Numbers::Numbers(const char* filename)
    {
        strcpy(m_fileName, filename);
        m_collection = nullptr;
        m_collectionSize = 0;
        m_isOriginal = true;
        m_addFlag = false;
        load();
    }

    Numbers::Numbers()
    {
        setEmpty();
    }

    Numbers::~Numbers()
    {
        save();
        delete[] m_collection;
        m_collection = nullptr;
    }
    Numbers::Numbers(const Numbers& I)
    {
        setEmpty();
        m_isOriginal = false;// 복사본이기 때문에 false.
        *this = I;
    }

    Numbers& Numbers::operator=(const Numbers& other)
    {
        if (this != &other)// 똑같은 애를 취급하지 않기 위해.
        {
            delete[] m_collection;
            setEmpty();
            m_isOriginal = false;
            m_collection = new double[m_collectionSize];

            for (unsigned int i = 0; i < m_collectionSize; i++)
            {
                m_collection[i] = other.m_collection[i];
            }

            m_collectionSize = other.m_collectionSize;
            strcpy(m_fileName, other.m_fileName);

        }
        return *this;
    }

    Numbers::operator bool() const
    {
       return (m_collection != nullptr);
    }

    void Numbers::sort()
    {
        sort(m_collection, m_collectionSize);
    }

    Numbers& Numbers::operator+=(double value)
    {
        if (*this) 
        {
            double* temp = new double[m_collectionSize + 1];
            for (unsigned int i = 0; i < m_collectionSize; ++i)
            {
                temp[i] = m_collection[i];
            }

            temp[m_collectionSize++] = value;
            delete[] m_collection;
            m_collection = temp;
            m_addFlag = true;
        }
        return *this;
    }

    std::ostream& Numbers::display(std::ostream& ostr) const
    {
        if (!m_collection)
        {
            ostr << "Empty list";
        }
        else
        {
            if (!m_isOriginal)
            {
                ostr << "Copy Of ";
            }
            ostr << m_fileName << endl;
            for (unsigned int i = 0; i < m_collectionSize; ++i)
            {
                ostr << m_collection[i];
                if (i < m_collectionSize - 1) 
                {
                    ostr << ", ";
                }
            }
            ostr << endl;
            for (int i = 0; i < 76; ++i)
            {
                ostr << "-";
            }
            ostr << endl;
            ostr << "Total of " << m_collectionSize << " number(s), ";
            ostr << "Largest: " << max() << ", ";
            ostr << "Smallest: " << min() << ", ";
            ostr << "Average: " << average() << endl;
            for (int i = 0; i < 76; ++i) {
                ostr << "=";
            }
        }
        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const Numbers& right)
    {
        return right.display(ostr);
    }

    std::istream& operator>>(std::istream& istr, Numbers& right)
    {
        double value;
        istr >> value;
        right += value;
        return istr;
    }

}