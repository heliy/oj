#include<iostream>

using namespace std;

int a[60];

int main(){
  int n, ni, ave, sum, need, c = 1;
  while(cin >> n && n != 0){
    sum = 0;
    for(ni = 0; ni < n; ni++){
      cin >> a[ni];
      sum += a[ni];
    }
    ave = sum/n;
    need = 0;
    for(ni = 0; ni < n; ni++){
      if(a[ni] > ave){
	need += (a[ni]- ave);
      }
    }

    cout << "Set #" << c << endl << "The minimum number of moves is " << need << "." << endl << endl;
    c++;
  }
}
