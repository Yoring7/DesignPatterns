#include<iostream>
#include<string>
using namespace std;

// 桥接模式

// 绘图接口
class DrawAPI
{
public:
    virtual void DrawCircle(double x, double y, double radius) = 0;
};

// 具体绘图类
class RedCircle : public DrawAPI
{
public:
    void DrawCircle(double x, double y, double radius) override
    {
        cout << "Drawing Circle[ color: red, x: " << x << ", y: " << y << ", radius: " << radius << " ]" << endl;
    }
};

class GreenCircle : public DrawAPI
{
public:
    void DrawCircle(double x, double y, double radius) override
    {
        cout << "Drawing Circle[ color: green, x: " << x << ", y: " << y << ", radius: " << radius << " ]" << endl;
    }
};

// 抽象类
class Shape
{
public:
    Shape(DrawAPI *drawAPI)
    {
        this->drawAPI = drawAPI;
    }
    virtual void Draw() = 0;
protected:
    DrawAPI *drawAPI;
};

// 具体类
class CircleShape : public Shape
{
public:
    // 首先构造父类再传参
    CircleShape(double x, double y, double radius, DrawAPI *drawAPI) : Shape(drawAPI)
    {
        this->x = x;
        this->y = y;
        this->radius = radius;
    }
    // 重写父类的Draw()
    void Draw() override
    {
        drawAPI->DrawCircle(x, y, radius);
    }
private:
    double x;
    double y;
    double radius;
    // DrawAPI *drawAPI;
};


int main()
{
    Shape *circleShape = new CircleShape(1, 2, 3, new GreenCircle());
    circleShape->Draw();
    Shape *shape = new CircleShape(1, 2, 3, new GreenCircle());
    shape->Draw();
    return 0;
}
