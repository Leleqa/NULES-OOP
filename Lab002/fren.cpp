#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

class HEXAGON {
  float a;

public:
    HEXAGON();
    HEXAGON(float);
    void sside(float);
    float gside();
    float area();
  friend HEXAGON frd(HEXAGON, HEXAGON);
};
HEXAGON::HEXAGON(){
    a=0;
    cout <<  "Конструктор викликаний для об'єкта " << this << endl;
}

HEXAGON::HEXAGON(float ASIDE){
    a = ASIDE;
    cout << "Конструтор з параметрами викликаний для об'єкта " << this << endl;
}

void HEXAGON::sside(float ASIDE){
    a = ASIDE;
    cout << "Сторону шайби перезадано для об'єкта " << this << endl;
}

float HEXAGON::gside(){
    return a;
}
float HEXAGON::area(){
    return ((3*sqrtf(3))/2)*pow(a,2);
    }

void print_sqr(HEXAGON &puck1, HEXAGON &puck2){
    cout << "Сторона шайби: " << puck1.gside() << endl;
    cout << "Площа шайби з заданими пaрaметрами = " << puck1.area() << endl;
    puck2.sside(4);
}

  HEXAGON frd(HEXAGON puck1, HEXAGON puck2){
  HEXAGON puck3;
  float area = ((3*sqrtf(3))/2)*pow(puck1.a,2) + ((3*sqrtf(3))/2)*pow(puck2.a,2); // sum of puck1.a and puck2.a
  puck3.a = sqrt((2*area)/(3*sqrtf(3)));                                          // calculate side a of puck3
  return puck3;

}

int main(){
  HEXAGON puck1(8);
  HEXAGON puck2;
  HEXAGON puck3;
  print_sqr(puck1, puck2);
  cout << puck2.area() << endl;
  puck3 = frd(puck1,puck2);
  cout << "Сторона нової шайби: " << puck3.gside() << endl;
  return 0;
}
