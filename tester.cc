#include <iostream>
#include "list.h"
using namespace std;

int main() {
  List lista;
  cout << "Constructing lista" << endl;
  List listb;
  cout << "Constructing listb" << endl;
  lista.insertBefore(1);
  cout << "inserting 1 in lista" << endl;
  lista.insertBefore(2);
  cout << "inserting 2 in lista" << endl;
  lista.insertBefore(3);
  cout << "inserting 3 in lista" << endl;
  listb.insertAfter(1);
  cout << "inserting 1 in listb" << endl;
  listb.insertAfter(2);
  cout << "inserting 2 in listb" << endl;
  listb.insertAfter(3);
  cout << "inserting 3 in listb" << endl;
  lista.display(cout);
  cout << "displaying lista" << endl;
  listb.display(cout);
  cout << "displaying listb" << endl;
}