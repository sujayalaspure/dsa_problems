#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

int main() {
  fork();
  fork();
  printf("Hi");

  return 0;
}