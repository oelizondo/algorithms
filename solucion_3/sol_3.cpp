//Oscar Elizondo
//22.01.16
//Matrículas problema 1

#include <iostream>
#include <fstream>
#include <list>
#include <array>

using namespace std;

int formarLlave(int iDato) {
  return iDato % 1000;
}

bool buscarMatricula(int iDato, array<list<int>, 1000>& iMatriculas) {

  int iLlave = formarLlave(iDato);

  for (int i = 0; i < iMatriculas.size(); i++)
    if(iDato == iMatriculas[iLlave].front()) return true;

  return false;
}

void leerArchivo(array<list<int>, 1000>& iMatriculas) {
  
  int iDato;
  ifstream archEnt;
  
  
  archEnt.open("matriculas_ejemplo.txt");
  
  while(!archEnt.eof()) {
    archEnt >> iDato;
    int iLlave = formarLlave(iDato);
    iMatriculas[iLlave].push_back(iDato);
  }
  
  archEnt.close();

}

bool solucionTres() {
  int iDato;
  array<list<int>, 1000> iMatriculas;

  cout << "Dato a buscar" << endl;
  cin >> iDato;
  
  leerArchivo(iMatriculas);
  return buscarMatricula(iDato, iMatriculas);
}


int main() {
  cout << solucionTres() << endl;
  return 0;
}