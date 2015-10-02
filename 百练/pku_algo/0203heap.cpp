#include<cstdio>
#include<iostream>
#include<vector>
#define N 100001

using namespace std;

int heap[N];
int size;

void swap(int n, int m){
  int s = heap[n];
  heap[n] = heap[m];
  heap[m] = s;
}

void show(){
  int i;
  cout << size << ": ";
  for(i = 1; i < size; i++){
    cout << heap[i] << " ";
  }
  cout << endl;
}

int min(int a, int b, int c){
  int m = a;
  if(b <= size && heap[m] > heap[b]){
    m = b;
  }
  if(c <= size && heap[m] > heap[c]){
    m = c;
  }
  return m;
}

void up(int n){
  if(n == 1){
    return;
  }
  int parent = n/2;
  if(heap[n] < heap[parent]){
    swap(n, parent);
  }
  up(parent);
}

void down(int n){
  if(n*2 > size){
    return;
  }
  int left = n*2;
  int right = n*2+1;
  int m = min(n, left, right);
  // cout << "min: " << m << endl;
  if(m == n){
    return;
  }else{
    swap(n, m);
    down(m);
  }
}

int main(){
  int t, ti, n, i, type, m;
  cin >> t;
  for(ti = 0; ti < t; ti++){
    size = 1;
    cin >> n;
    for(i = 0; i < n; i++){
      scanf("%d", &type);
      if(type == 1){
	scanf("%d", heap+size);
	up(size++);
      }else{
	printf("%d\n", heap[1]);
	heap[1] = heap[--size];
	down(1);
      }
      // show();
    }
  }
}
