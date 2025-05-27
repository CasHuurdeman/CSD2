//
// Created by cashu on 21/05/2025.
//

#include <iostream>


int main() {

  std::cout << typeid(ceil(2.3f)).name() << std::endl;
}



/*
int main(){
  float x = 1.3f;
  for(int i = 0; i < 40; i++) {
    x = x+1;

    printf("%.14f\n", x);
  }
  return 0;
}
  //TODO - DIT IS ALLEEN VOOR +1 OF +1.0f, VOOR +1.01f IS DE FOUT GROOT
  //floating point error: als het getal heel hoog wordt,
  //dan gaan er sowieso vreemde dingen gebeuren
  //maar de error gebeurt meestal in een 'grotere' stap en dan gaat het voor
  //duizenden waarden goed, waarna er weer een stap komt
/*
  Hier ergens gaat het mis, voor de rest overal hetzelfde
  259001.29687500000000
  260001.29687500000000
  261001.29687500000000
  262001.29687500000000
  263001.31250000000000
  264001.31250000000000
  265001.31250000000000
  266001.31250000000000

  */