#include <iostream>

using namespace std;


class NUMS{
  int *p;                         //pointer
  int numOfElements;
  public:
  NUMS(int);
  ~NUMS();
  int getval(int i){
    return p[i];
  }
  int getplace(){
    return numOfElements;
  }
};

NUMS::NUMS(int n){                //constuctor
  p = new int[n];
  numOfElements = n;
  for(int i =1; i < n; i++){
        p[i] = i;
      }
  cout << "Виділення пам'яті конструктором " << p << endl;
}


NUMS::~NUMS(){
  cout << "Звільнення пам'яті " << p << endl;
  //delete p;
} 

void ReadObject(NUMS &obj){
  int n = obj.getplace();
  for(int i=0; i<n; i++){
  cout << "reading from function " << obj.getval(i) << endl;
  }
}

void CountEven(NUMS &obj){
  int evenCount = 0;
  for(int i=0; i<obj.getplace(); i++){
    if((obj.getval(i) % 2) == 0){
      evenCount++;
    }
  }
  evenCount--;
  cout << "У цьому масиві " << evenCount << " парних чисел" << endl;
}



int main(){
  NUMS vals1(12);
  ReadObject(vals1);
  CountEven(vals1);
}
