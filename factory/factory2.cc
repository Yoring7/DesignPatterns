/*
 * @Author: yoring7 yoring7
 * @Date: 2022-05-22 23:03:07
 * @LastEditors: yoring7 yoring7
 * @LastEditTime: 2022-05-22 23:23:46
 * @FilePath: /DesignPatterns/factory/factory2.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>
using namespace std;
// 抽象工厂模式

// 首先提供产品接口
class Shape
{
public:
    virtual void draw() = 0;
};

// 具体产品
class Circle : public Shape
{
public:
    void draw() override
    {
        cout << "Circle::draw()" << endl;
    }
};

// 具体产品
class Rectangle : public Shape
{
public:
    void draw() override
    {
        cout << "Rectangle::draw()" << endl;
    }
};

// 工厂接口
class ShapeFactory
{
public:
    virtual Shape *createShape() = 0;
};

// 具体工厂
class CircleFactory : public ShapeFactory
{
public:
    Shape *createShape() override
    {
        return new Circle();
    }
};

class RectangleFactory : public ShapeFactory
{
public:
    Shape *createShape() override
    {
        return new Rectangle();
    }
};

class ShapeFactoryProducer
{
public:
    // 静态工厂方法
    static ShapeFactory *getFactory(string shapeType)
    {
        if (shapeType == "Circle")
        {
            return new CircleFactory();
        }
        else if (shapeType == "Rectangle")
        {
            return new RectangleFactory();
        }
        return nullptr;
    }
};

class Client
{
public:
    void drawShapes(ShapeFactory *factory)
    {
        Shape *shape = factory->createShape();
        shape->draw();
    }
};

int main()
{
    Client client;
    // 首先用工厂产生器产生工厂
    ShapeFactory *factory = ShapeFactoryProducer::getFactory("Circle");
    client.drawShapes(factory);
    factory = ShapeFactoryProducer::getFactory("Rectangle");
    client.drawShapes(factory);
    // Client::drawShapes(factory);

    /**
     * @brief  访问静态成员
     * 可以用ClassName::MemberName,
     * 也可以用ClassName.MemberNme,
     * 但最好用前者，因为很容易就可以判定成员是静态成员。
     * 访问实例成员
     * 只能用ClassName.MemberName,
     * 不能用ClassName::MemberName.
     */
    return 0;
}

