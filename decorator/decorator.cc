/*
 * @Author: Yoring
 * @Date: 2022-05-21 23:33:23
 * @LastEditors: louyuqian louyuqian@hopechart.com
 * @LastEditTime: 2022-05-22 10:54:18
 * @FilePath: \factory\decorator\decorator.cc
 * @Description: 
 * 
 * Copyright (c) 2022 by louyuqian louyuqian@hopechart.com, All Rights Reserved. 
 */
#include<iostream>
#include<string>
using namespace std;

// 装饰器模式

// 抽象形状类(接口)
class Shape
{
public:
    virtual void draw() = 0;
};

// 具体形状类
class Rectangle : public Shape
{
public:
    void draw() override
    {
        std::cout << "Rectangle::draw()" << std::endl;
    }
};

// 具体形状类
class Circle : public Shape
{
public:
    void draw() override
    {
        std::cout << "Circle::draw()" << std::endl;
    }
};

// 抽象装饰类
// 内部包含一个原对象的指针，方便拓展新方法
// 实质上就是继承了原类（是为了在原接口的基础上添加方法）
// 并且包含原类的对象
class ShapeDecorator : public Shape
{
public:
    ShapeDecorator(Shape *decoratedShape)
    {
        this->shape = decoratedShape;
    }
    // virtual void draw() = 0;
protected:
    Shape *shape;
};


// 具体装饰类
class RedShapeDecorator : public ShapeDecorator
{
public:
    // 必须调用父类的构造函数，调用方法如下
    RedShapeDecorator(Shape *decoratedShape) : ShapeDecorator(decoratedShape)
    {
    }
    void draw() override
    {
        shape->draw();
        setRedBorder(shape);
    }
private:
    void setRedBorder(Shape *shape)
    {
        std::cout << "RedShapeDecorator::setRedBorder()" << std::endl;
    }
};

int main()
{
    Shape *circle = new Circle();
    Shape *redCircle = new RedShapeDecorator(circle);
    redCircle->draw();
    delete circle;
    delete redCircle;
    return 0;
}