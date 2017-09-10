#include <QCoreApplication>
#include <iostream>
#include <vector>
#include "../coordiantescontainer.h"
#include "../coordinates.h"

double getForce(int a)
{
    if(a == 0) return 0;

    return (1/(double)a) - (1 / ((double)a * (double)a));
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Coordinates c1(100, 100);
    c1.dX = 0;
    c1.dY = 0;

    Coordinates c2(200, 200);
    c2.dX = 0;
    c2.dY = 0;

    Coordinates c3(300, 300);
    c3.dX = 0;
    c3.dY = 0;

    Coordinates c4(400, 400);
    c4.dX = 0;
    c4.dY = 0;
    std::cout << c1.dX << std::endl;
   /*
    int l = Coordinates::lengthBetweenTwoPoints(c1, c2);
        double f = getForce(l);

        //std::cout << "x - " << c1.m_x << std::endl;

        c1.dX = (f * (c2.getX() - c1.getX())/l) * 5;
        c1.dY = (f * (c2.getY() - c1.getY())/l) * 5;

        std::cout << "x - " << c1.dX << std::endl;
        */

    CoordiantesContainer::Instance().setCoordinates(1, c1);
    CoordiantesContainer::Instance().setCoordinates(2, c2);
    CoordiantesContainer::Instance().setCoordinates(3, c3);
    CoordiantesContainer::Instance().setCoordinates(4, c4);

    std::map<int, Coordinates> s = CoordiantesContainer::Instance().getContainer();
    std::map<int, Coordinates> s2 = CoordiantesContainer::Instance().getContainer();


    std::map<int, Coordinates>::iterator it;
    for(it = s.begin(); it != s.end(); ++it)
    {
        std::vector<int> buf;
        std::map<int, Coordinates>::iterator it1;
        for(it1 = s.begin(); it1 != s.end(); ++it1)
        {
            int l = Coordinates::lengthBetweenTwoPoints(it->second, it1->second);
            double f = getForce(l);

            Coordinates c1 = it->second;
            Coordinates c2 = it1->second;
            //std::cout << "x - " << c1.m_x << std::endl;
            if(l == 0) continue;

            c1.dX = (f * ((double)c2.getX() - (double)c1.getX())/l) * 5;
            c1.dY = (f * (c2.getY() - c1.getY())/l) * 5;


            //std::cout << "x - " << c1.m_x << std::endl;
            //std::cout << "y - " << c1.m_y << std::endl;

            c2.dX = (f * (c1.getX() - c2.getX())/l) * 5;
            c2.dY = (f * (c1.getY() - c2.getY())/l) * 5;


            c1.m_x += c1.dX;
            c1.m_y += c1.dY;
            c2.m_x += c2.dX;
            c2.m_y += c2.dY;

            std::cout << "x - " << c1.m_x << std::endl;
            it->second = c1;
            it1->second = c2;
            CoordiantesContainer::Instance().updateItem(it->first, c1);
            CoordiantesContainer::Instance().updateItem(it1->first, c2);
        }
    }

    Coordinates r = CoordiantesContainer::Instance().getCoordinates(1);
    std::cout << "x - " << r.getX() << std::endl;
    return a.exec();
}
