#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

int Comp(int a, int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

int Max(vector<vector<int>> Arr, vector<vector<int>> Soln) {
  int n = Arr.size();
  int Max = -101;
  for (int i = n-1; i >= 0; i--) {
    for (int j = n-1; j >= 0; j--) {
      Soln[i][j] = Arr[i][j] + Comp(Soln[i+1][j],Soln[i][j+1]);
      Max = Comp(Soln[i][j],Max);
    }
  }
  return Max;
}

int getRows(ifstream &inFile){
  string temp;
  getline(inFile,temp);
  return stoi(temp);
}

int main(){
  ifstream inFile("input.txt", ios::in);
  if(!inFile) {
    cout << "No Output file" << endl;
    return 0; 
  }
  int n = getRows(inFile);

  string temp;
  vector<vector<int>> array(n, vector<int>(n));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(j == n-1)
        getline(inFile,temp);
      else
        getline(inFile,temp,',');
      array[i][j] = stoi(temp);  
    }
  }

  vector<vector<int>> solution(n+1, vector<int>(n+1));
  for(int i= 0; i <= n; i++) {
    for(int j = 0; j <= n; j++) {
      solution[i][j] = 0;
    }
  }
  
  int max;
  max = Max(array, solution);
  cout << max << endl;
  inFile.close();
  return 0;
}
