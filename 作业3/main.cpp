#include <iostream>
#include <time.h>
#include <stdio.h>
#include <ctime>

using namespace std;
 
int main()
  {
    int i;
  
    for(i=0; i<= 10000; i *= 10)
      {
        testprogram(i);
      }
  
  return 0;
  }
  
void testprogram()
  {
     clock_t start, end;
     double total;

     start = clock();
 
     cout << "程序启动，start = " << start ;

     cout << "开始循环，start = " << start ;

     end = clock();
     
     cout << "循环结束，end = " << end ;

     total = (double)(end - start) / CLOCKS_PER_SEC ;
 
     cout << "CPU 占用的总时间：" << total  ;
 
     cout << "程序退出..." << endl ;

     return(0);
  }
