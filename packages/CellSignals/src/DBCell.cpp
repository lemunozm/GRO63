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

/**********************************************************************/
/*                                                                    */
/*              CONTINOUS CELL CLASS IMPLEMENTATION                   */
/*                                                                    */
/**********************************************************************/

#include "DBCell.h"

/*********************** Getters and Setters **************************/

std::map<int,std::vector<unsigned int> > DBCell::getSignalsMap() {
  return this->local_signals;
}

/*********************** Auxiliary functions *************************/

bool DBCell::_existSignal(int id) {
  return (this->local_signals.find(id) != this->local_signals.end());
}

unsigned int DBCell::_getTimer(int signal_id) {
  if (_existSignal(signal_id)) {
    return this->local_signals[signal_id][1];
  }
}

void DBCell::_setTimer(int signal_id, unsigned int time) {
  if (_existSignal(signal_id)) {
    this->local_signals[signal_id][1] = time;
  }
}

/******************** Virtual member functions ***********************/

double DBCell::getValue(int signal_id) {
  if (_existSignal(signal_id)) {
    return this->local_signals[signal_id][0];
  }
}

void DBCell::setValue(int signal_id, double concentration) {
  if (_existSignal(signal_id)) {
    this->local_signals[signal_id][0] = ((unsigned int) concentration);
  } else {
    this->insertSignal(signal_id);
    this->local_signals[signal_id][0] = 0.0;
    this->local_signals[signal_id][0] = ((unsigned int) concentration);
  }
}

void DBCell::insertSignal(int signal_id) {
  std::vector<unsigned int> newS;
  newS.push_back(1);
  newS.push_back(0);
  this->local_signals.insert(std::pair<int,std::vector<unsigned int> >(signal_id, newS));
}

void DBCell::deleteSignal(int signal_id) {
  this->local_signals.erase(signal_id);
}

void DBCell::incSignal(int signal_id, double concentration) {
  if (_existSignal(signal_id)) {
    this->local_signals[signal_id][0] = 1;
  }
}

void DBCell::decSignal(int signal_id, double concentration) {
  if (_existSignal(signal_id)) {
    this->local_signals[signal_id][0] = 0;
  }
}
