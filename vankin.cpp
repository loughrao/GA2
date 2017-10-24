#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

int getRows(ifstream &inFile){
  string temp;
  getline(inFile,temp);
  return stoi(temp);
}

void out(int input){
  ofstream outFile("output.txt", ios::out);
  outFile << input;
  if(!outFile)
    cout << "There was an error writing to the output file!!!" << endl;
  outFile.close();
}

int main(){
  ifstream inFile("input.txt", ios::in);
  if(!inFile)
    return 0;

  int n = getRows(inFile);

  string temp;
  vector<vector<int>> array(n, vector<int>(n));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(j == n-1)
        getline(inFile,temp);
      else
        getline(inFile,temp,',');
      cout << "["<<i<<"]["<<j<<"]: " << temp << endl;
      array[i][j] = stoi(temp);
      
    }
  }

  cout << "vector pos 1,1: " << array[1][1] << endl;
  
  out(14);

  inFile.close();
  return 0;
}
