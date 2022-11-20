#include <thread>
#include <mutex>
#include <iostream>
using namespace std;

int value = 0;
std::mutex m;

void func_add(int id){
    m.lock();
    value++;
    std::cout << "Thread " << id << " esta alterando value." << std::endl;
    std::cout << value << "." << std::endl;
    m.unlock();
    if(value==1000) exit(0);
}

int main(){
    std::thread t1(func_add, 0);
    std::thread t2(func_add, 1);
    std::thread t3(func_add, 2);
    t1.join();
    t2.join();
    t3.join();
    std::cout << "Valor do value:" << value << "." << std::endl;
    return 0;
}


