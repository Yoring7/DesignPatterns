/*
 * @Author: Yoring
 * @Date: 2022-05-22 12:13:34
 * @LastEditors: louyuqian louyuqian@hopechart.com
 * @LastEditTime: 2022-05-22 13:47:51
 * @FilePath: \factory\observer\observer.cc
 * @Description: 
 * 
 * Copyright (c) 2022 by louyuqian louyuqian@hopechart.com, All Rights Reserved. 
 */
#include "observer.hpp"
using namespace std;

// 观察者抽象类构造函数
Observer::Observer(Subject* subject)
{
    this->subject = subject;
    // 注册观察者
    subject->attach(this);
}

class ConcreteObserverA : public Observer
{
public:
    // 具体观察者被创建的时候就会被注册到subject的观测者列表中
    ConcreteObserverA(Subject* subject):Observer(subject)
    {
        // 在这里可以做一些初始化的工作
    }
    // {
    //     this->subject = subject;
    //     subject->attach(this);
    // }
    void update() override
    {
        cout << "ConcreteObserverA::update()" << endl;
    }
};

class ConcreteObserverB : public Observer
{
public:
    ConcreteObserverB(Subject* subject):Observer(subject)
    {
        // 在这里可以做一些初始化的工作
    }
    void update() override
    {
        cout << "ConcreteObserverB::update()" << endl;
    }
};

class ConcreteSubject : public Subject
{
public:
    ConcreteSubject()
    {
    }
};

int main()
{
    /**
     * 观察者模式简单说就是：
     * 1. 首先创建被观察的对象；
     * 2. 创建观察者，并且注册到被观察者的观察者列表中；所以观察者需要包含被观察者
     * 3. 被观察者发生变化，会自动通知观察者（某些方法中可以调用观察者的更新方法）；所以被观察者需要包含观察者
     */
    Subject* subject = new ConcreteSubject();

    // 问：为什么不用抽象类来接具体观察者？
    // 答：当然可以，这样才是统一接口。
    Observer* oa = new ConcreteObserverA(subject);
    Observer* ob = new ConcreteObserverB(subject);
    subject->setState("state1");
    subject->setState("state2");
    return 0;
}