#include <math.h>
#define PI 3.141592653589793

namespace conceptarchitect::shapes
{

    enum ShapeType
    {
        Circle,
        Triangle,
        Rectangle
    };

    class Shape
    {
        ShapeType type;
        double radius;
        double width, height;
        double s1,s2,s3;

    public:
        Shape(double radius)
        {
            type = ShapeType::Circle;
            this->radius = radius;
        }

        Shape(double width, double height)
        {
            type = ShapeType::Rectangle;
            this->width = width;
            this->height = height;
        }

        Shape(double s1,double s2,double s3)
        {
            type=ShapeType::Triangle;
            this->s1=s1;
            this->s2=s2;
            this->s3=s3;
        }

        double perimeter()
        {
            double p = 0;
            switch (type)
            {
            case ShapeType::Circle:
                p = 2 * PI * radius;
                break;
            case ShapeType::Rectangle:
                p = 2 * (width + height);
            case ShapeType::Triangle:
                p=s1+s2+s3;
            }
            return p;
        }

        double area()
        {
            double a = 0;
            if (type == ShapeType::Circle)
                a = PI * radius * radius;
            if(type==ShapeType::Triangle)
            {
                double s=perimeter()/2;
                a=sqrt(s*(s-s1)*(s-s2)*(s-s3));
            }
            else
                a = width * height;

            return a;
        }

        void draw()
        {
            if (type == ShapeType::Circle)
                cout << "Circle(" << radius << ")" << endl;
            else if (type == ShapeType::Triangle)
                 cout<<"Triangle<"<<s1<<","<<s2<<","<<s3<<">"<<endl;
            else
                cout << "Rectangle[" << width << "," << height << "]" << endl;
        }
    };
}