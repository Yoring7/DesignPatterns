#include<iostream>
#include<string>
using namespace std;

// 桥接模式
// 将抽象部分与实现部分分离，使它们都可以独立的变化
// 实现部分可以是一个类，也可以是一个函数
// 抽象部分可以是一个接口，也可以是一个抽象类

// 实现接口
class Implementor
{
public:
    virtual void OperationImp() = 0;
};

// 具体实现
class ConcreteImplementorA : public Implementor
{
public:
    void OperationImp()
    {
        cout << "ConcreteImplementorA::OperationImp()" << endl;
    }
};

// 具体实现
class ConcreteImplementorB : public Implementor
{
public:
    void OperationImp()
    {
        cout << "ConcreteImplementorB::OperationImp()" << endl;
    }
};

// 抽象接口
class Abstraction
{
public:
    virtual void Operation() = 0;
};

// 具体
class RefinedAbstraction : public Abstraction
{
public:
    RefinedAbstraction(Implementor *implementor)
    {
        this->implementor = implementor;
    }
    void Operation()
    {
        implementor->OperationImp();
    }
private:
    Implementor *implementor;
};

class Client
{
public:
    void Main()
    {
        Implementor *implementorA = new ConcreteImplementorA();
        Implementor *implementorB = new ConcreteImplementorB();
        Abstraction *abstractionA = new RefinedAbstraction(implementorA);
        Abstraction *abstractionB = new RefinedAbstraction(implementorB);
        abstractionA->Operation();
        abstractionB->Operation();
    }
};

int main()
{
    Client client;
    client.Main();
    return 0;
}