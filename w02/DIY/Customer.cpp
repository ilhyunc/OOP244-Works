#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include "Customer.h"
#include "Tools.h"

#include <cstring>

namespace sdds {

    // complete

    void read(char* str, int len) {  // Fully provided
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        cin.getline(str, len);
    }


    // complete

    void EmptyRecord(Customers& cus) {
       
        cus = { 0 };
    }

    void EmptyRecord(CustomersRecord& cusRecord) {
        
        cusRecord = { 0 };
    }

    bool read(Customers& c_rec) {

        int noEmpty = false;

        cout << " Enter User name: ";
        read(c_rec.user_name, 20);
        if (strcmp(c_rec.user_name, "") != 0)
        {
            cout << " Enter likes_count: ";
            cin >> (c_rec.likes_count);
            cout << " Enter retweets_count: ";
            cin >> (c_rec.retweets_count);
            cout << " Enter replies_count: ";
            cin >> (c_rec.replies_count);
            cout << " Enter share videos (y/n): ";
            cin >> (c_rec.share_videos);
            noEmpty = true;
        }
        else
        {
            noEmpty = false;
        }

        return noEmpty;
    }

    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec) {

        Customers* temp = new Customers[t_rec.noOfRecords + 1];
        if (temp == nullptr)
        {
            cout << "Error" << endl;
        }

        for (int i = 0; i < t_rec.noOfRecords; i++)
        {
            temp[i] = t_rec.ptr_rec[i];
        }

        temp[t_rec.noOfRecords] = c_rec;

        delete[] t_rec.ptr_rec;
        t_rec.ptr_rec = nullptr; //de-allocate 
        t_rec.ptr_rec = temp;
        t_rec.noOfRecords++;
    }

    void display(const Customers& c_rec) {
        
        cout << c_rec.user_name << ", "
            << c_rec.likes_count << ", "
            << c_rec.retweets_count << ", "
            << c_rec.replies_count << ", "
            << c_rec.share_videos << endl << endl;
    }

    void display(const CustomersRecord& t_rec) {

        for (int i = 0; i < t_rec.noOfRecords; i++) // print off the records as it is stored. 
        {
            cout << i + 1 << ". ";
            display(t_rec.ptr_rec[i]);

        }
    }
}

