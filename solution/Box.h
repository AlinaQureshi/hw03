/*******************************************************************************
Author :      Waqar Saleem
File   :      Box.h
Date   :      4 Oct 2018

Declares a Box type to model a box in the system.
*******************************************************************************/
#pragma once

#include <iostream>

class Box
{
private:
  int m_dimensions[3];

public:
  Box();
  Box(const Box&);
  ~Box();

  int get_volume() const;

  // Non-member function delcared friend to allow it access to class's
  // members. Overloads << operator to allow cout. See
  // https://www.learncpp.com/cpp-tutorial/93-overloading-the-io-operators/
  friend std::ostream& operator<<(std::ostream&, const Box&);
};

