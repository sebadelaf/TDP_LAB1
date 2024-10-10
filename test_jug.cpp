#include "Jug.h"

int main() {
  Jug j(1000,1000);
  State *solution = j.solve();
  if (solution != nullptr) {
    solution->print();
  } else {
    cout << "No se encontró solución." << endl;
  }
  return 0;
}
