/*
 * Copyright (C) Sandra Sáez Raspeño - All Rights Reserved
 *
 * This file is part of Cellsignals.
 *
 * All information contained in this package is, and remains the property of
 * Sandra Sáez Raspeño. Copy and distribution of CellSignals or any result
 * generated by it is strictly forbidden unless prior written permission is
 * obtained from Sandra Sáez Raspeño.
 */

#include <vector>

class GReaction {
 public:
  float rate;
  std::vector<int> reactants;
  std::vector<int> products;

 GReaction(float rate): rate(rate) {}

 void add_reactant(int react) {
   this->reactants.push_back(react);
 }
 
 void add_product(int prod) {
   this->products.push_back(prod);
 }
};
