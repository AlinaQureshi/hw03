/*******************************************************************************
Author :      Waqar Saleem
Email  :      waqar.saleem@sse.habib.edu.pk
File   :      main.cpp
Date   :      4 Oct 2018

Simuatles a package delivery system as described in Assignment 2 of CS
 224 OOP, Fall 2018.

Uses the auto keyword which requires C++11.
*******************************************************************************/

//===== Headers. ===============================================================
// C headers come first in alphabetical order.
#include <cstdlib>
// C++ headers come next in alphabetical order.
#include <fstream>
#include <iostream>
#include <vector>
// Own headers come last.
#include "Truck.h"

//===== Typedefs. ==============================================================
typedef std::vector<Truck> Truck_Vector;

//===== Function Declrations. ==================================================
// Read trucks from filename into a structure and return the structure.
Truck_Vector read_trucks(const std::string& filename);
// Write trucks from structure to filename.
void write_trucks(const Truck_Vector& trucks, const std::string& filename);
// Load the trucks that can deliver.
void load_trucks(Truck_Vector& trucks);
// Unload the trucks that are delivering.
void unload_trucks(Truck_Vector& trucks);

//===== Main program. ==========================================================
int main()
{
  // Seed random number generator for various random number computations.
  srand(time(NULL));
  Truck_Vector trucks = read_trucks("../Drivers.txt");
  load_trucks(trucks);
  unload_trucks(trucks);
  write_trucks(trucks, "Trip.txt");
  
  return 0;
}

//===== Function Definitions. ==================================================

// Read trucks from file and return.
Truck_Vector read_trucks(const std::string& filename) {
  // Ensure that file is open.
  std::ifstream infile(filename);
  if (not infile) {
    std::cout << "Cannot open input file: " << filename << "\n";
    exit(0);
  }
  // Read truck info, create and save corresponding trucks.
  std::vector<Truck> trucks;
  std::string name;
  float fuel, money, full_mileage, empty_mileage;
  while (getline(infile, name)) {
    if (name.find('\r') != -1) {
      name = name.substr(0, name.size()-1);
    }
    infile >> fuel >> money >> full_mileage >> empty_mileage;
    trucks.push_back(Truck(name, fuel, money, full_mileage, empty_mileage));
    getline(infile, name);  // flush out the \n after the last read float value.
  }
  // Wrap up.
  infile.close();
  return trucks;
}
//==============================================================================

// Write trucks from structure to filename.
void write_trucks(const Truck_Vector& trucks, const std::string& filename) {
  // Ensure that file is open.
  std::ofstream outfile(filename);
  if (not outfile) {
    std::cout << "Cannot open output file: " << filename << "\n";
    exit(0);
  }
  // Write trucks to file and close file.
  std::copy(std::begin(trucks), std::end(trucks),
	    std::ostream_iterator<Truck>(outfile,"\n"));
  outfile.close();
}
//==============================================================================

// Load the trucks that can deliver.
void load_trucks(std::vector<Truck>& trucks)
{
  // Load boxes on capable trucks and print thier box information.
  for (auto & truck : trucks) {
    if (truck.can_deliver()) {
      std::cout << "Loading the truck of " << truck.get_driver() << ":\n";
      truck.load();
      std::copy(std::begin(truck.get_boxes()), std::end(truck.get_boxes()),
      		std::ostream_iterator<Box>(std::cout,"\n"));
    }
  }
}
//==============================================================================

// Unload the trucks that are delivering.
void unload_trucks(std::vector<Truck>& trucks) {
  // Print box infomation of loaded trucks and unload them.
  for (auto & truck : trucks) {
    if (truck.is_loaded()) {
      std::cout << "Unloading the truck of " << truck.get_driver() << ":\n";
      std::copy(std::begin(truck.get_boxes()), std::end(truck.get_boxes()),
		std::ostream_iterator<Box>(std::cout,"\n"));
      truck.unload();
    }
  }
}
//==============================================================================
