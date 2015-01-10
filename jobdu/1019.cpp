#include<stdio.h>
#include<stack>
#include<math.h>

using namespace std;

stack<double> numbers;
stack<char> ops;
char line[201];
char plussub[200];
double nums[200];

int main(){
  while(fgets(line, 201, stdin)){
    if((line[0] == '0')&&(line[1] == '\n' || line[1] == '\0')){
      break;
    }
    int i = 0, n, j, cur;
    double num1, num2;
    char mae;

    while(line[i] != '\n'){
      if(line[i] == ' '){
	cur = 0;
	for(j = i - 1; j >= 0 && line[j] != ' '; j--){
	  cur += pow(10, (i - j - 1)) * (line[j] - '0');
	}
	numbers.push((double)cur);
	i++;
	if(!ops.empty()){
	  mae = ops.top();
	  if(mae == '*' || mae == '/'){
	    num1 = numbers.top();
	    numbers.pop();
	    num2 = numbers.top();
	    numbers.pop();
	    if(mae == '*'){
	      numbers.push(num1 * num2);
	    }else{
	      numbers.push(num2 / num1);
	    }
	    ops.pop();	    
	  }
	}
      }
      else if(line[i] == '*' || line[i] == '/' || line[i] == '+' || line[i] == '-'){
	ops.push(line[i]);
	i += 2;
      }else{
	i++;
      }
    }
    //最后一个数字
    cur = 0;
    for(j = i - 1; j >= 0 && line[j] != ' '; j--){
      cur += pow(10, (i-j-1)) * (line[j] - '0');
    }
    numbers.push((double)cur);

    while(!ops.empty()){
      mae = ops.top();
      if(mae == '+' || mae == '-'){
	break;
      }
      num1 = numbers.top();
      numbers.pop();
      num2 = numbers.top();
      numbers.pop();
      if(mae == '/'){
	numbers.push(num2 / num1);
      }else{
	numbers.push(num1 * num2);
      }
      ops.pop();
    }

    for(n = 0; !numbers.empty(); n++){
      nums[n] = numbers.top();
      numbers.pop();
    }

    for(n = 0; !ops.empty(); n++){
      plussub[n] = ops.top();
      ops.pop();
    }

    if(n > 0){
      double alget = nums[n];
      for(i = n-1; i >= 0; i--){
        mae = plussub[i];
	num1 = nums[i];
        if(mae == '+'){
	  alget += num1;
        }else{
	  alget -= num1;
        }
      }
      printf("%.2f\n", alget);
    }else{
      printf("%.2f\n", nums[0]);
    }
  }
  return 0;
}
