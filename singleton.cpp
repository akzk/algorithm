/*
    剑指offer 1, 单例模式
*/
#include <iostream>
#include <pthread.h>
using namespace std;

class Singleton
{
    public:
        int value;
        static Singleton& getInstance(int v)
        {
            static Singleton instance;
            instance.value = v;
            return instance;
        }
};

class Singleton2
{
    private:
        Singleton2(){}
        static Singleton2* p;
    public:
        static pthread_mutex_t mutex;
        static Singleton2* getInstance();
};
pthread_mutex_t Singleton2::mutex;
Singleton2* Singleton2::p = NULL;
Singleton2* Singleton2::getInstance()
{
    if (p != NULL) return p;
    pthread_mutex_lock(&mutex);
    if (p == NULL) p = new Singleton2();
    pthread_mutex_unlock(&mutex);
    return p;
}

int main()
{
    // Singleton a = Singleton::getInstance(1);
    // Singleton b = Singleton::getInstance(2);
    // cout << &a << a.value << endl;
    // cout << &b << b.value << endl;

    pthread_mutex_init(&Singleton2::mutex, NULL);

    Singleton2* a = Singleton2::getInstance();
    Singleton2* b = Singleton2::getInstance();
    cout << a << endl;
    cout << b << endl;
}
