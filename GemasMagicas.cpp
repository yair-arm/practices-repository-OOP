#include <iostream>
using namespace std;

class GemaMagica {
private:
  int FuerzaPrimaria;
  int FuerzaSecundaria;
public:
  GemaMagica(int p, int c) : FuerzaPrimaria(p), FuerzaSecundaria(c) {}

  GemaMagica operator+(const GemaMagica &c) const {
    int NuevaFP = FuerzaPrimaria + c.FuerzaPrimaria;
    int NuevaFS = FuerzaSecundaria + c.FuerzaSecundaria;

    return {NuevaFP, NuevaFS};
  }

  void mostrarFuerzas() const {
    cout << "Fuerza primaria de la nueva gema: " << FuerzaPrimaria << endl;
    cout << "Fuerza secundaria de la nueva gema: " << FuerzaSecundaria << endl;
  }
};

int main () {
  GemaMagica g1(9, 4), g2(8,5);
  GemaMagica g3 = g1 + g2;
  g3.mostrarFuerzas();
}