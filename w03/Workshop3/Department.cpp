#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Department.h"

using namespace std;

namespace sdds {


    //fully provided for students to display details of a project
    void display(const Project& project) {
        cout << "Project " << project.m_topic
            << " will cost a total of " << project.m_cost << " C$." << endl;
    }

    //fully provided for students to display details of a department
    void display(const Department& department) {
        Project* temp = department.fetchProjects();
        int projects = department.fetchNumProjects();
        cout << "Department " << department.fetchName() << " details:" << endl;
        cout << "Budget: " << department.fetchBudget()
            << " and the number of projects in progress is: " << projects << endl;
        cout << "Below are the details of the projects we are currently working on: " << endl;
        for (int i = 0; i < projects; i++) {
            display(temp[i]);
        }
    }

    Department::Department(){
        m_name = nullptr;
        project = nullptr;
        m_numOfProject = 0;
        m_budget = 15345.99;
    }

    void Department::updateName(const char* newname) {

        if (newname != nullptr){
           
            if (m_name != nullptr){

                delete[] m_name;
            }

            m_name = new char[strlen(newname) + 1];
            strcpy(m_name, newname);
        }
    }

    void Department::updateBudget(double change) {

        m_budget += change;
    }

    bool Department::addProject(Project& newproject) {

        bool result = false;
        if (totalexpenses() + newproject.m_cost <= m_budget)
        {
            Project* temp = new Project[m_numOfProject + 1];
            for (int i = 0; i < m_numOfProject; i++)
            {
                temp[i] = project[i];
            }
            temp[m_numOfProject] = newproject;
            delete[] project;
            project = nullptr;
            project = temp;
            m_numOfProject++;
            result = true;
        }
        return result;
    }

    void Department::createDepartment(const char* newname, Project& newproject, double change) {

        updateName(newname);
        addProject(newproject);
        updateBudget(change);
    }

    Project* Department::fetchProjects() const {

        return project;
    }

    int Department::fetchNumProjects() const {

        return m_numOfProject;
    }

    double Department::fetchBudget() const {

        return m_budget;
    }

    char* Department::fetchName() const {

        return m_name;
    }
    
    double Department::totalexpenses() {

        double total = 0.0;

        for (int i = 0; i < m_numOfProject; i++)
        {
            total += project[i].m_cost;
        }
        return total;
    }

    double Department::remainingBudget() {

        return m_budget - totalexpenses();
    }

    void Department::clearDepartment() {

        delete[] m_name;
        m_name = nullptr;
        delete[] project;
        project = nullptr;
        m_numOfProject = 0;
        m_budget = 15345.99;
    }

}

