#ifndef _STUDENT_H
#define _STUDENT_H
 
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
 
class Student {
 public:
  Student();
  Student(int, const char*, int);
  void set(int id_, const char* name_, int age_);
  void print();
 
 private:
  int id;
  char name[50];
  int age;
};
 
Student::Student() {
    id = 0;
    snprintf(name, sizeof("No Name"), "No Name");
    age = 0;
}
 
Student::Student(int id_, const char* name_ = "No Name", int age_ = 0) {
    id = id_;
    snprintf(name, sizeof(name), name_);
    age = age_;
}
 
void Student::set(int id_, const char* name_, int age_) {
    id = id_;
    snprintf(name, sizeof(name), name_);
    age = age_;
}
void Student::print() {
    printf("%s (%d) is %d years old.\n", name, id, age);
}
#endif
