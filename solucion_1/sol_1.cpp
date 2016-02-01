//Oscar Elizondo
//22.01.16
//Matrículas problema 1

#include <iostream>
#include <fstream>

using namespace std;

bool buscarMatricula(int iDato, int (&iMatriculas)[154733]) {

  for (int i = 0; i < 154733; i++)
    if(iDato == iMatriculas[i]) return true;

  return false;
}

void leerArchivo(int (&iMatriculas)[154733]) {
  
  int iDato;
  int iIndice = 0;
  ifstream archEnt;
  
  
  archEnt.open("matriculas.txt");
  
  while(!archEnt.eof()) {
    archEnt >> iDato;
    iMatriculas[iIndice] = iDato;
    iIndice++;
  }
  
  archEnt.close();

}

bool solucionUno() {
  int iDato;
  int iMatriculas[154733];
  
  
  cout << "Dato a buscar" << endl;
  cin >> iDato;
  
  leerArchivo(iMatriculas);
  return buscarMatricula(iDato, iMatriculas);
  
}


int main() {
  if (solucionUno()) {
    cout << "Encontrado" << endl;
  } else {
    cout << "No encontrado" << endl;
  }
  
  return 0;
}