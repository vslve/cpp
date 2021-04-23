#ifndef POINT_H
#define POINT_H

class Point
{
    public:
        Point();
        Point(int x, int y);
        void setXY(int x, int y);
        int getX();
        int getY();
        double getDistance(Point &point);

    protected:
        int x_;
        int y_;
};

class PointZ : public Point
{
    public:
        PointZ();
        PointZ(int x, int y, int z);
        void setXYZ(int x, int y, int z);
        int getZ();
        double getDistance(PointZ &point);

    private:
        int z_;
};


#endif //POINT_H
