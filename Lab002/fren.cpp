#include <iostream>
#include <cmath>

using namespace std;

class triangle{
    float Aside, Bside, Cside;

    public:
    triangle();
    triangle(float, float, float);
    void sside(float, float, float);
    void gside();
    float area();
};
triangle::triangle(){
    Aside=Bside=Cside=0;
    cout <<  "Конструктор викликаний для об'єкта " << this << endl;
}
triangle::triangle(float ASIDE, float BSIDE, float CSIDE){
    Aside = ASIDE;
    Bside = BSIDE;
    Cside = CSIDE;
    cout << "Конструктор з параметрами викликаний для об'єкта " << this << endl;
}
void triangle::sside(float ASIDE, float BSIDE, float CSIDE){
    Aside = ASIDE;
    Bside = BSIDE;
    Cside = CSIDE;
    cout << "Сторони трикутника перезадано для об'єкта " << this << endl;
}
void triangle::gside(){
    cout << "Сторона A: " << Aside << " Сторона B: " << Bside << " Сторона C: " << Cside << " " << this << endl;
}
float triangle::area(){
    return sqrtf((Aside+Bside+Cside)*(Bside+Cside-Aside)*(Aside+Cside-Bside)*(Aside+Bside-Cside))/4; 
    }

void print_sqr(triangle &trianp, triangle &trian){
    trianp.gside();
    cout << "Площа трикутника з заданими пaрaметрами = " << trianp.area() << endl;
    trian.sside(4, 5, 6);
}

int main(){
    triangle triplet;
    triangle tripletp(10,7,5);
    print_sqr(tripletp, triplet);
    triplet.gside();

    return 0;
}