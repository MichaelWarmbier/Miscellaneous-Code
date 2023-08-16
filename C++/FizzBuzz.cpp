/* An attempt to answer the question posed in Tom Scott's FizzBuzz video:
https://www.youtube.com/watch?v=QPZ0pIK_wsc&pp=ygUIRml6emJ1eno%3D */

#include <iostream>
using namespace std;

const string rules[][2] = {
  {"Fizz", "3"},
  {"Buzz", "5"}
};

const int rule_length = sizeof(rules)/sizeof(*rules);

int main() {
  
  for (int num = 1; num <= 100; num++) {

    string output = "";

    for (int i = 0; i < rule_length; i++) 
      if (num % stoi(rules[i][1]) == 0) output += rules[i][0];
    
    if (output == "") output += to_string(num);

    cout << output << endl;
  }

  return EXIT_SUCCESS;
}




