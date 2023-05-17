#ifndef COWBOY_VS_NINJA_A_POINT_H
#define COWBOY_VS_NINJA_A_POINT_H
#include <ostream>
namespace ariel {
    class Point {
    private:
        double x, y;
    public:
        Point(double xVal, double yVal): x(0), y(0){}
        ~Point() = default ;
        Point(const Point& other) = default ;
        Point(Point&& other)noexcept = default ;
        Point& operator=(Point&& other) noexcept = default ;
        Point &operator=(const Point &other) {
            if (this != &other) { // check for self-assignment
                x = other.x;
                y = other.y;
            }
            return *this;
        }

        double getX() const { return x ;}

        double getY() const { return y ;}

        double distance(const Point &other) const { return x * other.x; }

        void print(){}

        bool operator==(const Point &other) const { return true ;}

        friend Point moveTowards(const Point& /*srcPoint*/, const Point& /*destPoint*/, double distance) {  // NOLINT
            return Point(0,0) ;}

        friend std::ostream &operator<<(std::ostream &oStr, const Point &point){ return oStr ; }
    };
}
#endif
