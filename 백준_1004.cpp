#include <iostream>
#include <cmath>

struct Planet{
    int x, y, r = 0;
    bool isIn_start = false;
    bool isIn_end = false;
    void isInside_start(int x, int y){
        if (pow(this->x - x, 2) + pow(this->y - y, 2) < pow(this->r, 2))
        {
            this->isIn_start = true;
        }
    }
    void isInside_end(int x, int y){
        if (pow(this->x - x, 2) + pow(this->y - y, 2) < pow(this->r, 2))
        {
            this->isIn_end = true;
        }
    }
};

struct Point{
    int x, y = 0;
};

int main() {

    int T = 0; 
    std::cin >> T; 
    while( 0 < T)
    {
        Point start, end = {0, 0};
        std::cin >> start.x >> start.y >> end.x >> end.y;
        int planetNum = 0; 
        std::cin >> planetNum;
        Planet* planets = new Planet[planetNum];
        for(int i = 0; i < planetNum; i++)
        {
            std::cin >> planets[i].x >> planets[i].y >> planets[i].r;
            planets[i].isInside_start(start.x, start.y);
            planets[i].isInside_end(end.x, end.y);
        }
        int count = 0;
        for (int i = 0 ; i < planetNum; i++)
        {
            if(planets[i].isIn_start != planets[i].isIn_end)
            {
                count++;
            }
        }

        std::cout << count << std::endl;
        T--;
    }
    return 0;
}


