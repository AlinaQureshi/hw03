/*******************************************************************************
Author :      Waqar Saleem
File   :      Box.cpp
Date   :      4 Oct 2018

Implements Box.h.
*******************************************************************************/
#include "Box.h"

Box::Box() {
  m_dimensions[0] = 5 + (rand() % 26);
  m_dimensions[1] = 5 + (rand() % 26);
  m_dimensions[2] = 5 + (rand() % 26);
}
//==============================================================================

Box::Box(const Box& other) {
  m_dimensions[0] = other.m_dimensions[0];
  m_dimensions[1] = other.m_dimensions[1];
  m_dimensions[2] = other.m_dimensions[2];
}
//==============================================================================

Box::~Box()
{}
//==============================================================================

int Box::get_volume() const
{
  return m_dimensions[0] * m_dimensions[1] * m_dimensions[2];
}
//==============================================================================

std::ostream& operator<<(std::ostream& out, const Box& box)
{
  out << "Dimensions: " << box.m_dimensions[0] << ", "
      << box.m_dimensions[1] << ", " << box.m_dimensions[2];
  return out;
}
//==============================================================================
