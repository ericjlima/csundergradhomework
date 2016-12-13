  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex4.9.student.h
  // Header file with the class definition

// Namespace gets declared. Decleration of class student is contained here to access features within Student's scope.

  #ifndef EX4_9_STUDENT_H
  #define EX4_9_STUDENT_H
#include <string>
namespace e4_9 {
  class Student { 
  public:
    Student(const string& = "");    // needs a no-arg constructor 
    long getId() const;
    string getName() const;
    void setName(const string&);
  private:
    string name_;
    long id_;      
    static long idCounter_;
  };  
}
  #endif

