//Oscar Elizondo
//22.01.16
//Matrículas problema 1

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T, class t>
bool busqueda_binaria(T first, T last, t iDato)
{
    first = std::lower_bound(first, last, iDato);
    return (!(first == last) && !(iDato < *first));
}

bool buscarMatricula(int iDato, vector<int>& iMatriculas) {

  sort(iMatriculas.begin(), iMatriculas.end());
  if (busqueda_binaria(iMatriculas.begin(), iMatriculas.end(), iDato)) return true;

  return false;
}

void leerArchivo(vector<int>& iMatriculas) {
  
  int iDato;
  ifstream archEnt;
  
  
  archEnt.open("matriculas.txt");
  
  while(!archEnt.eof()) {
    archEnt >> iDato;
    iMatriculas.push_back(iDato);
  }
  
  archEnt.close();
  
}

bool solucionDos() {
  int iDato;
  vector<int> iMatriculas;
  
  
  cout << "Dato a buscar" << endl;
  cin >> iDato;
  
  leerArchivo(iMatriculas);
  return buscarMatricula(iDato, iMatriculas);
  
}


int main() {
  if (solucionDos()) {
    cout << "Encontrado" << endl;
  } else {
    cout << "No encontrado" << endl;
  }
  return 0;
}