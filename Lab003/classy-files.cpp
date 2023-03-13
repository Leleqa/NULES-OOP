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

int CountLine(ifstream &file){
int lineCount = 0;
string str;
    while(!file.eof()){
      getline(file, str, '\n');
      lineCount++;
    }
  lineCount--;
    return lineCount;
  }
    


void WriteObjects(STUDENT *group, ifstream &file, int lineCount){
  
  int grade1, grade2, grade3;
  string name;
 for (int i = 0; i < lineCount; i++){

     file >> name;
     file >> grade1;
     file >> grade2;
     file >> grade3;
     group[i].Set(name, grade1,grade2,grade3);
   }
}
void ReadAllObj(STUDENT *group, int lineCount){
 for(int i = 0; i < lineCount; i++){
      cout << group[i].GetName() << " "<< group[i].GetGradeA() << " " << group[i].GetGradeB() << " " << group[i].GetGradeC() << endl;

    }
}

void ReadSomeObj(STUDENT *group, int lineCount){
  for(int i = 0; i < lineCount; i++){
    if((group[i].GetGradeA() != 3) && (group[i].GetGradeB()  != 3) && (group[i].GetGradeC() != 3) && (group[i].GetGradeA() != 2) && (group[i].GetGradeB() != 2) && (group[i].GetGradeC() != 2)){
      cout << group[i].GetName() << " "<< group[i].GetGradeA() << " " << group[i].GetGradeB() << " " << group[i].GetGradeC() << endl;
    }
    }
  }




int main(){
  ifstream file;
  int lineCount;
  file.open("group.txt");

  if(file){

  lineCount = CountLine(file);
  
  STUDENT *group = new STUDENT[lineCount];
 file.clear();
 file.seekg(0);
  
  WriteObjects(group, file, lineCount);

  ReadAllObj(group, lineCount);
  cout << "\n" << endl;
  ReadSomeObj(group, lineCount);

  }
  else{
    cout << "Не вдалося відкрити файл" << endl;
  }
}
