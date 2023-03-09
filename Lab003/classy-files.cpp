#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

class STUDENT{
  string name;
  int grade;
public:
  void Set(string name, int grade){
    this->name = name;
    this->grade = grade;
  }
  string GetName(){
    return name;
  }
  int GetGrade(){
    return grade;
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
      int grade;
      file >> name;
      file >> grade;
      group[i].Set(name, grade);
    }
  for(int i = 0; i < lineCount; i++){
      cout << group[i].GetName() << " "<< group[i].GetGrade() << endl;

    }

  }}
