#ifndef OBJECTS_H
#define OBJECTS_H


class objects {
private:
    int x;
    int y;
    int rotation;       // rotation in degrees

public:
    objects(int x, int y, int rotation);

    virtual void move() = 0;
};

class player : public objects {
private:

};


#define PLAYER_STEP 5


#define rotation_shorten(x) (x<0?x+360:(x>=360?x-360:x))


#endif
