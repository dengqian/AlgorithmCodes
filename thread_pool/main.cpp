#include <iostream>  
#include "thread_pool.h"  
  
  
using namespace std;  
  
  
void Test(int i)  
{  
    printf("I love you %d time\n",i);  
}  
  
int main()  
{  
    ThreadPool threadPool;  
    threadPool.setMaxQueueSize(10);  
    threadPool.start(2);  
  
    for(int i = 0;i < 10;++i)  
    {  
        auto task = bind(Test,i);  
        threadPool.run(task);  
    }  
  
    getchar();  
    return 0;  
}  