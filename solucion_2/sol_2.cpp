//Oscar Elizondo
//22.01.16
//Matrículas problema 1

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool buscarMatricula(int iDato, vector<int>& iMatriculas) {

  for (int i = 0; i < iMatriculas.size(); i++)
    if(iDato == iMatriculas[i]) return true;

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
  cout << solucionDos() << endl;
  return 0;
}