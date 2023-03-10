#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

class STUDENT{
  string name;
  int grade1;
  int grade2;
  int grade3;
public:
  void Set(string name, int grade1, int grade2, int grade3){
    this->name = name;
    this->grade1 = grade1;
    this->grade2 = grade2;
    this->grade3 = grade3;
  }
  string GetName(){
    return name;
  }
  int GetGradeA(){
    return grade1;
  }
  int GetGradeB(){
    return grade2;
  }
  int GetGradeC(){
    return grade3;
  }
};


int main(){
  ifstream file;
  string str;
  int lineCount = 0;
  
  file.open("group.txt");

  if(file){
    while(!file.eof()){
      getline(file, str, '\n');
      lineCount++;
    }
  lineCount--;

  STUDENT *group = new STUDENT[lineCount];
  file.clear();
  file.seekg(0);
  
  for (int i; i < lineCount; i++){
      string name;
      int grade1, grade2, grade3;
      file >> name;
      file >> grade1;
      file >> grade2;
      file >> grade3;
      group[i].Set(name, grade1,grade2,grade3);
    }
  for(int i = 0; i < lineCount; i++){
      cout << group[i].GetName() << " "<< group[i].GetGradeA() << " " << group[i].GetGradeB() << " " << group[i].GetGradeC() << endl;

    }

  }}
