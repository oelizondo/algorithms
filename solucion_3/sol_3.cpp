// Oscar Elizondo
// 22.01.16
// Matrículas problema 1

#include <iostream>
#include <fstream>
#include <list>
#include <array>

using namespace std;

bool buscarMatricula(int iDato, array<list<int>, 1000> iMatriculas) {
  
  int iLlave = iDato % 1000;
  
  while(iDato != iMatriculas[iLlave].front()) {
    iMatriculas[iLlave].pop_front();
    if (iDato == iMatriculas[iLlave].front())
      return true;
  }
  return false;
}

void leerArchivo(array<list<int>, 1000> &iMatriculas) {
  
  int iDato;
  ifstream archEnt;
  
  archEnt.open("matriculas.txt");
  
  while(!archEnt.eof()) {
    archEnt >> iDato;
    int iLlave = iDato % 1000;
    iMatriculas[iLlave].push_back(iDato);
  }
  
  archEnt.close();
  
}

bool solucionTres() {
  int iDato;
  array<list<int>, 1000> iMatriculas;
  
  cout << "Dato a buscar" << endl;
  cin >> iDato;
  
  if (iDato % 1000 < 100) {
    cout << "No es una matricula valida" << endl;
  }
  else {
    leerArchivo(iMatriculas);
    return buscarMatricula(iDato, iMatriculas);
  }
  return false;
}


int main() {
  if (solucionUno()) {
    cout << "Encontrado" << endl;
  } else {
    cout << "No encontrado" << endl;
  }
  return 0;
}