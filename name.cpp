#include <iostream>
#include "name.hpp"

using namespace std;

Name::Name() : last(""), first("") { }

string Name::getLast() const {
  return last;
  }

string Name::getFirst() const {
  return first;
  }

string Name::toString() const {
  return first + " " + last;
  }

void Name::setLast(const string& l) {
  last = l;
  }

void Name::setFirst(const string& f) {
  first = f;
  }

bool Name::operator == (const Name& n) const {
  return  first == n.first and last == n.last;
  }

bool Name::operator != (const Name& n) const {
  return  first != n.first and last != n.last;
  }

bool Name::operator > (const Name& n) const {
  return  first > n.first and last > n.last;
  }

bool Name::operator >= (const Name& n) const {
  return  first >= n.first and last >= n.last;
  }

bool Name::operator < (const Name& n) const {
  return  first < n.first and last < n.last;
  }

bool Name::operator <= (const Name& n) const {
  return  first <= n.first and last <= n.last;
  }
