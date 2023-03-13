#include <iostream>

using namespace std;


class NUMS{
  int *p;
  int n;
  public:
  NUMS(int);
  NUMS(const NUMS &obj);
  ~NUMS();
  int getval(int i){
    return *p;
  }
};

NUMS::NUMS(int n){                //constuctor
  p = new int[n];
  for(int i =0; i < n; i++){
        p[i] = i;
      }
  cout << "Виділення пам'яті конструктором " << p << endl;
}

NUMS::NUMS(const NUMS &obj){      //copy constuctor
  p = new int[n];
  *p = *obj.p;
  cout << "Виділення пам'яті конструктором копії " << p << endl;
}

NUMS::~NUMS(){
  cout << "Звільнення пам'яті " << p << endl;
  delete p;
} 

int NUMS::getval(int i){
  return p[i];
}


int main(){
  if(true){
    NUMS a(10);
    NUMS b = a;
  for(int i=0; i<10; i++){
    cout << p[i] << " " << endl;
  }
  }
}
