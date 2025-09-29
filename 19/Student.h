#ifndef try_class
#define try_class
#include <iostream>
#include <string>
class Student {
private:
  int _id;
  std::string _name;
  float _marks;

public:
  Student(int id, const std::string &name, float marks)
      : _id(id), _name(name), _marks(marks) {}
  Student() : _id(0), _name(""), _marks(0.0) {}
  Student(const Student &s) : _id(s._id), _name(s._name), _marks(s._marks) {}
  void changeName(const std::string &name) { _name = name; }
  void changeAge(int id) { _id = id; }
  void changeMarks(float marks) { _marks = marks; }
  std::string getName() const { return _name; }
  int getId() const { return _id; }
  float getMarks() const { return _marks; }
  void printInfo(const Student &s) const;
};

#endif // !try_class
