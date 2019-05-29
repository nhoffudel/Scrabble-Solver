#include <iostream>
#include <queue>
#include <ctime>
#include "stdlib.h"
using namespace std;

int main() {
   srand(time(NULL));
   priority_queue<int> PQ;
   for (int i = 0; i < 10; i++){
       int t = rand() % 100;
       cout << "Inserting " << t << endl;
       PQ.push(t);
   }
   
   while(!PQ.empty()){
       cout << PQ.top() << " ";
       PQ.pop();
   }
   cout << endl;
} 