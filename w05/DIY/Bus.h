#ifndef SDDS_BUS_H
#define SDDS_BUS_H
#include <iostream>

using namespace std;
 namespace sdds
 {
     const double ticketPrice = 125.34;

     class Bus 
     {
         int m_seats;
         int m_passengers;
         void drawBus(int seats, int noOfPassengers, ostream& ostr) const;

     public:
         // constructor
         Bus(int seats = 20, int passengers = 0);
         ~Bus();

         // Read function
         istream& read(istream& istr = cin);

         // Display function
         ostream& display(ostream& ostr) const;

         // operators
         operator bool() const;
         operator int() const;
         operator double() const;

         // unary operators
         bool operator--();
         bool operator++();
         bool operator--(int);
         bool operator++(int);

         // binary operators
         Bus& operator=(int passengers);
         Bus& operator+=(int passengers);
         Bus& operator+=(Bus& right);
         bool operator==(const Bus& b) const;

    };

     int operator+(int left, const Bus& right);
     istream& operator>>(istream& is, Bus& B);
     ostream& operator<<(ostream& os, const Bus& B);
}
#endif 