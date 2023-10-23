#include <iostream>
#include <string>

#include "teacher.h"

int Teacher::teachers = 0;

Teacher::Teacher()
    : Teacher("", "", 0)
{

}
Teacher::Teacher(const std::string &firstName, const std::string &lastName, int age)
    : m_firstName(firstName)
    , m_lastName(lastName)
    , m_age(age)
{
    teachers++;
}
Teacher::~Teacher() {
    teachers--;
}
    
void Teacher::setIdentity(const std::string &firstName, const std::string &lastName, int age)
{
    m_firstName = firstName;
    m_lastName = lastName;
    m_age = age;
}

int Teacher::getAge() const { return m_age; }

std::string Teacher::getFullName() const { return m_firstName + " " + m_lastName; }

int Teacher::getTeachersNumber() {
    return teachers;
}




