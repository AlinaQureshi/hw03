/*******************************************************************************
Author :      Waqar Saleem
File   :      Truck.cpp
Date   :      4 Oct 2018

Implements Truck.h.
*******************************************************************************/
# include "Truck.h"

Truck::Truck(std::string driver, float fuel, float money,
	     float full_mileage, float empty_mileage) :
  m_driver(driver), m_fuel(fuel), m_money(money),
  m_full_mileage(full_mileage), m_empty_mileage(empty_mileage)
{}
//==============================================================================

Truck::Truck(const Truck& other) :
  m_driver(other.m_driver), m_fuel(other.m_fuel), m_money(other.m_money),
  m_full_mileage(other.m_full_mileage), m_empty_mileage(other.m_empty_mileage)
{}
//==============================================================================

Truck::~Truck()
{}
//==============================================================================

void Truck::load()
{
  // Assumes that delivery is possible.
  m_boxes.resize(12 + (rand()%9));
  m_money -= (FUEL_CAPACITY - m_fuel) * FUEL_PRICE;
  m_fuel = FUEL_CAPACITY;
}
//==============================================================================

void Truck::unload()
{
  m_fuel -= get_amount_of_required_fuel();
  m_boxes.clear();
}
//==============================================================================

bool Truck::is_loaded() const
{
  return not m_boxes.empty();
}
//==============================================================================

float Truck::get_amount_of_required_fuel() const
{
  float delivery_fuel = DELIVERY_DISTANCE / m_full_mileage;
  float return_fuel = DELIVERY_DISTANCE / m_empty_mileage;
  return delivery_fuel + return_fuel;
}
//==============================================================================

bool Truck::can_deliver() const
{
  float required_fuel = get_amount_of_required_fuel();
  if (required_fuel > FUEL_CAPACITY) {
    return false;
  }
  float fuel_cost = (FUEL_CAPACITY - m_fuel) * FUEL_PRICE;
  if (fuel_cost > m_money) {
    return false;
  }
  return true;
}
//==============================================================================

std::ostream& operator<<(std::ostream& out, const Truck& truck)
{
  out << "Driver: " << truck.m_driver << "\n"
      << "Fuel: " << truck.m_fuel << "\n"
      << "Money: " << truck.m_money << "\n"
      << "Full mileage: " << truck.m_full_mileage << "\n"
      << "Empty mileage: " << truck.m_empty_mileage;
  return out;
}
//==============================================================================

const std::vector<Box>& Truck::get_boxes() const
{
  return m_boxes;
}
//==============================================================================

const std::string& Truck::get_driver() const
{
  return m_driver;
}
//==============================================================================
