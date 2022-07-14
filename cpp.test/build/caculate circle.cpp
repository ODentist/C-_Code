#include<iostream>
using namespace std;

class point
{
public:
     void setX(int x)
     {m_X= x;}
     int getX()
     {return m_X;}
     void setY(int y)
     {m_Y=y;}
     int getY()
     {return m_Y;}
private:
     int m_X;
     int m_Y;
};

class circle
{
private:
     int m_R;
     point m_center;
public:
     void setR(int r)
     {m_R=r;}
     int getR()
     {return m_R;}
     void setCenter(point center)
     {m_center=center;}
     point getCenter()
     {return m_center;}

};
void isincircle(circle &c, point p)
{   int distance=(c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) + 
                 (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
    int rDistance = c.getR() * c.getR();
 
 
 if (distance=rDistance)
    {
        cout << "on the circle" <<endl;
    }
    else if (distance=rDistance)
    {
        cout<< "out the circle"<< endl;
    }
    else
    {
        cout<< "in the circle"<< endl;
    }   
}
int main()
{
   circle c;
   c.setR(10);
   point center;
   center.setX(10);
   center.setY(0);
   c.setCenter(center);

   point p;
   p.setX(10);
   p.setY(10);
   isincircle(c,p);
    system("pause");

    return 0;
}