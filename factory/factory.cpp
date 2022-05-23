
#include <iostream>
#include <string>
using namespace std;
// 抽象工厂模式

// 首先提供产品接口
// 抽象产品类A（接口）
class AbstractProductA
{
public:
    virtual void Show() = 0;
};

// 抽象产品类B（接口）
class AbstractProductB
{
public:
    virtual void Show() = 0;
};

// 具体产品类A1（实现）
class ProductA1 : public AbstractProductA
{
public:
    void Show()
    {
        std::cout << "ProductA1" << std::endl;
    }
};

// 具体产品类A2
class ProductA2 : public AbstractProductA
{
public:
    void Show()
    {
        std::cout << "ProductA2" << std::endl;
    }
};

// 具体产品类B1（实现）
class ProductB1 : public AbstractProductB
{
public:
    void Show()
    {
        std::cout << "ProductB1" << std::endl;
    }
};

// 具体产品类B2
class ProductB2 : public AbstractProductB
{
public:
    void Show()
    {
        std::cout << "ProductB2" << std::endl;
    }
};

// 定义一个抽象工厂类，提供一个接口，用于创建一个产品对象
class AbstractFactory
{
public:
    virtual AbstractProductA *CreateProductA(string productA) = 0;
    virtual AbstractProductB *CreateProductB(string productB) = 0;
};


// 具体工厂类1
class ConcreteFactoryA : public AbstractFactory
{
public:
    // 创建产品A
    AbstractProductA *CreateProductA(string productA)
    {
        if (productA == "A1")
        {
            return new ProductA1();
        }
        else if (productA == "A2")
        {
            return new ProductA2();
        }
        else
        {
            return NULL;
        }
    }
    // 创建产品B
    AbstractProductB *CreateProductB(string productB)
    {
        return NULL;
    }
};

// 具体工厂类2
class ConcreteFactoryB : public AbstractFactory
{
public:
    // 创建产品A
    AbstractProductA *CreateProductA(string productA)
    {
        return NULL;
    }
    // 创建产品B
    AbstractProductB *CreateProductB(string productB)
    {
        if (productB == "B1")
        {
            return new ProductB1();
        }
        else if (productB == "B2")
        {
            return new ProductB2();
        }
        else
        {
            return NULL;
        }
    }
};


// 工厂生成器
class FactoryProducer
{
public:
    AbstractFactory *CreateFactory(string factory)
    {
        if (factory == "A")
        {
            return new ConcreteFactoryA();
        }
        else if (factory == "B")
        {
            return new ConcreteFactoryB();
        }
        else
        {
            return NULL;
        }
    }
};

// 客户端
class Client
{
public:
    void Main()
    {
        // 工厂生成器
        FactoryProducer factoryProducer;
        // 工厂A
        AbstractFactory *factoryA = factoryProducer.CreateFactory("A");
        // 工厂B
        AbstractFactory *factoryB = factoryProducer.CreateFactory("B");

        // 创建产品A
        AbstractProductA *productA = factoryA->CreateProductA("A1");
        productA->Show();
        AbstractProductA *productA2 = factoryA->CreateProductA("A2");
        productA2->Show();

        // 创建产品B
        AbstractProductB *productB = factoryB->CreateProductB("B1");
        productB->Show();
    }
};

int main()
{
    Client client;
    client.Main();
    return 0;
}
