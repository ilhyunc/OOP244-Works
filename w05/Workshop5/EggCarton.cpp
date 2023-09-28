#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "EggCarton.h"

using namespace std;

namespace sdds
{
    EggCarton::EggCarton(int size, int noOfEggs, bool jumboSize)
    {
        if (size % 6 != 0 || size < 6 || size > 36 || noOfEggs < 0 || noOfEggs > size)
        {
            setBroken();
        }
        else
        {
            m_size = size;
            m_noOfEggs = noOfEggs;
            m_isJumbo = jumboSize;
        }
    }

    void EggCarton::setBroken()
    {
        m_size = -1;
        m_noOfEggs = -1;
        m_isJumbo = false;
    }

    ostream& EggCarton::displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr) const
    {
        int cartonWidth = size == 6 ? 3 : 6;

        for (int i = 0; i < size; i++)
        {
            ostr << ((i % cartonWidth) ? '|' : '[') << ((i < noOfEggs) ? (jumbo ? 'O' : 'o') : ' ');
            ((i + 1) % cartonWidth == 0) && ostr << ']' << endl;
        }

        return ostr;
    }

    ostream& EggCarton::display(ostream& ostr) const
    {
        if (operator bool())  //If the carton is not broken
        {
            displayCarton(m_size, m_noOfEggs, m_isJumbo, ostr);
        }
        else //If the carton is broken
        {
            ostr << "Broken Egg Carton!" << endl;
        }

        return ostr;
    }

    istream& EggCarton::read(istream& istr)
    {
        m_isJumbo = false;
        char jumbo;
        int size;
        int noOfEggs;

        //Reads a character from istr
        istr >> jumbo;

        if (jumbo == 'j')
        {
            m_isJumbo = true;
        }

        //Ignores the next character
        istr.ignore();

        //Reads an integer into the size of the carton
        istr >> size;

        //Ignores the next character
        istr.ignore();

        //Reads another integer into the number of eggs
        istr >> noOfEggs;

        //Validate the attributes
        if (size % 6 == 0 && size >= 6 && size <= 36 && noOfEggs >= 0 && noOfEggs <= size)
        {
            m_size = size;
            m_noOfEggs = noOfEggs;
        }
        else
        {
            //Set the carton to broken
            setBroken();
        }

        return istr;
    }


    EggCarton::operator bool() const
    {
        return m_size > 0;
    }

    EggCarton::operator int() const
    {
        int value;

        if (operator bool()) //If the carton is not broken
        {
            value = m_noOfEggs;
        }
        else //If the carton is broken
        {
            value = -1;
        }

        return value;
    }

    EggCarton::operator double() const//---------------------------------------------------------------------------------------
    {
        double value = 0.0;
        int weight = m_isJumbo ? JumboEggWieght : RegularEggWieght;

        if (operator bool())  //If the carton is not broken
        {
            value = m_noOfEggs * weight * 0.001;
        }
        else //If the carton is broken
        {
            value = -1.0;
        }

        return value;
    }

    EggCarton& EggCarton::operator--()
    {
        if (operator bool() && m_noOfEggs > 0)
        {
            m_noOfEggs--;
        }

        return *this;
    }

    EggCarton& EggCarton::operator++()
    {
        if (operator bool())
        {
            m_noOfEggs++;
            if (m_noOfEggs > m_size)
            {
                setBroken();
            }
        }
        return *this;
    }

    EggCarton EggCarton::operator--(int)
    {
        EggCarton copy(*this);
        --(*this);
        return copy;
    }

    EggCarton EggCarton::operator++(int)
    {
        EggCarton copy(*this);
        ++(*this);
        return copy;
    }

    EggCarton& EggCarton::operator=(int value)
    {
        if (operator bool())
        {
            m_noOfEggs = value;
            if (m_noOfEggs > m_size)
            {
                setBroken();
            }
        }
        return *this;
    }

    EggCarton& EggCarton::operator+=(int value)
    {
        if (operator bool())
        {
            m_noOfEggs += value;
            if (m_noOfEggs > m_size)
            {
                setBroken();
            }
        }
        return *this;
    }

    EggCarton& EggCarton::operator+=(EggCarton& right)//----------------------
    {
        if (operator bool())
        {
            m_noOfEggs += right.m_noOfEggs;
            if (m_noOfEggs > m_size)
            {
                right.m_noOfEggs -= m_size - m_noOfEggs;
                m_noOfEggs = m_size;
            }
            else
            {
                right.m_noOfEggs = 0;
            }


        }
        return *this;
    }

    bool EggCarton::operator==(const EggCarton& right) const
    {
        if (operator bool() && right.operator bool())
        {
            double diff = (operator double() - right.operator double());
            return diff >= -0.001 && diff <= 0.001;
        }
        else
        {
            return false;
        }
    }

    int operator+(int left, const EggCarton& right)
    {
        int value = left;

        if (bool(right))
        {
            value = left + int(right);
        }
        return value;
    }

    ostream& operator<<(ostream& ostr, const EggCarton& right)
    {
        right.display(ostr);
        return ostr;
    }

    istream& operator>>(istream& istr, EggCarton& right)
    {
        right.read(istr);
        return istr;
    }

}