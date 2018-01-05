"""
    singleton，单例模式，懒汉式
    剑指offer 2
    通用解法（不依赖语言特性）：创建前加锁，加锁前后都检查
"""

import threading
lock = threading.Lock()

class Singleton:
    """
        __new__为静态构造函数，但不同于C#的静态构造函数
        只会执行一次，Python中该类的__new__可多次执行，
        为应对多线程情况，需要进行加锁前后两次判断
    """

    def __new__(cls):
        if not hasattr(cls, 'instance'):
            try:
                lock.acquire()
                if not hasattr(cls, 'instance'):
                    cls.instance = super(Singleton, cls).__new__(cls)
            finally:
                lock.release()

        return cls.instance

if __name__ == "__main__":
    a = Singleton()
    b = Singleton()

    print(id(a), id(b), a == b)

