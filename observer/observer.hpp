#include<iostream>
#include<string>
#include<list>
using namespace std;

// 观察者模式

// 声明观察者接口
class Subject;

// 观察者类
class Observer
{
protected:
    // has a subject 而不是继承
    Subject* subject;
public:
    // // 可以在这里构造父类，也可以在具体类中直接赋值
    Observer(Subject* subject);
    virtual void update() = 0;
};

// 被观察的对象
class Subject
{
private:
    // 观察者列表
    list<Observer*> observers;
    // 当前状态(会被更新)
    string state;
public:
    // 注册观察者
    void attach(Observer* o)
    {
        observers.push_back(o);
    }
    // 删除观察者
    void detach(Observer* o)
    {
        observers.remove(o);
    }

    // 通知所有观察者
    void notify()
    {
        for(auto o : observers)
        {
            // 观察者都会调用update()
            o->update();
        }
    }

    // 设置状态之后立即通知观察者
    void setState(string state)
    {
        this->state = state;
        notify();
    }

    // 获取状态
    string getState()
    {
        return state;
    }
};