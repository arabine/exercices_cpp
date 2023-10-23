#pragma once

class Teacher
{
public:
    Teacher();
    Teacher(const std::string &firstName, const std::string &lastName, int age);
    ~Teacher();
        
    void setIdentity(const std::string &firstName, const std::string &lastName, int age);
    
    int getAge() const;
    
    std::string getFullName() const;
    
    static int getTeachersNumber();
    
private:
    std::string m_firstName;
    std::string m_lastName;
    int m_age;
    static int teachers;
};


