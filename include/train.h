// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  first = nullptr;
  last = nullptr;
  countOp = 0;

  dlina = 0;
  var_a = 0;
}

void Train::addCage(bool light) {
  if (!(first)) {
    Cage* NewCage = new Cage;
    NewCage->light = light;
   
    NewCage->next = NewCage->previous = nullptr;
    first = NewCage;
    last = first;
  } else {
    Cage* NewCage = new Cage;
    NewCage->light = light;

    NewCage->next = NewCage->previous = nullptr;
    last->next = NewCage;
    last->next->previous = last;
    last = last->next;
    if (!last->next) {
      last->next = first;
    } else {
      first->previous = last;
    }
  }
}
int Train::getLength() {
  int tempp;
  first->light = true;
  last = first;
  while (true) {

    countOp++;
    var_a++;
    last = last->next;
    if (last->light) {
      tempp = var_a;
      last->light = false;
      if ((last->previous) != nullptr) {
        while (last->light == false) {
          last = last->previous;

          var_a--;
          countOp++;
        }
      }
      if (!last->light) {

        dlina = tempp;
        break;
      }
    }
  }

  countOp += dlina;
  return dlina;
}


int Train::getOpCount() {
  return countOp;
}
