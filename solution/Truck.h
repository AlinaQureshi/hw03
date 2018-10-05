/*******************************************************************************
Author :      Waqar Saleem
File   :      Truck.h
Date   :      4 Oct 2018

Declares a Truck type to model a delivery truck in the system.
*******************************************************************************/
#pragma once

#include <string>
#include <vector>

#include "Box.h"

const float DELIVERY_DISTANCE = 60;
const float FUEL_PRICE = 2.73;
const float FUEL_CAPACITY = 50;

class Truck
{
private:
  std::string m_driver;
  float m_fuel;
  float m_money;
  float m_full_mileage;
  float m_empty_mileage;
  std::vector<Box> m_boxes;

public:
  Truck(std::string, float, float, float, float);
  Truck(const Truck&);
  ~Truck();
  
  void load();
  void unload();

  bool is_loaded() const;
  float get_amount_of_required_fuel() const;
  bool can_deliver() const;
  
  const std::string& get_driver() const;
  const std::vector<Box>& get_boxes() const;

  // Non-member function delcared friend to allow it access to class's
  // members. Overloads << operator to allow cout. See
  // https://www.learncpp.com/cpp-tutorial/93-overloading-the-io-operators/
  friend std::ostream& operator<<(std::ostream&, const Truck&);
};
