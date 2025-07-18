#include <iostream>
using namespace std;

// Talking Behaviour...

class Talkable
{
public:
    virtual string talk()=0;
    virtual ~Talkable(){};
};

class talking : public Talkable
{
private:
    string speech;

public:
    talking(string speech)
    {
        this->speech = speech;
    }

    virtual string talk()
    {
        return speech;
    }
};

class Nontalking : public Talkable
{
private:
    string speech;

public:
    Nontalking(string speech)
    {
        this->speech = speech;
    }

    string talk()
    {
        return speech;
    }
};

// Walking Behaviour..

class Walkable
{
public:
    virtual string walk()=0;
    virtual ~Walkable(){};
};

class walking : public Walkable
{
private:
    string step;

public:
    walking(string step)
    {
        this->step = step;
    }

    string walk()
    {
        return step;
    }
};

class Nonwalking : public Walkable
{
private:
    string step;

public:
    Nonwalking(string step)
    {
        this->step = step;
    }

    string walk()
    {
        return step;
    }
};

// Flying Behaviour..

class Flyable
{
public:
    virtual string fly()=0;
    virtual ~Flyable(){};
};

class flying : public Flyable
{
private:
    string sky;

public:
    flying(string sky)
    {
        this->sky = sky;
    }

    string fly()
    {
        return sky;
    }
};

class Nonflying : public Flyable
{
private:
    string sky;

public:
    Nonflying(string sky)
    {
        this->sky = sky;
    }

    string fly()
    {
        return sky;
    }
};

class Robot
{
protected:
    Talkable *t;
    Walkable *w;
    Flyable *f;

public:
    Robot(Talkable *talkable, Walkable *walkable, Flyable *flyable)
    {
        this->t = talkable;
        this->w = walkable;
        this->f = flyable;
    }
    void talk()
    {
        cout << t->talk();
    }
    void walk()
    {
        cout << w->walk();
    }
    void fly()
    {
        cout << f->fly();
    }
    virtual void projection()=0;
};

class CompanionRobot : public Robot
{
public:
    CompanionRobot(Talkable *talkable, Walkable *walkable, Flyable *flyable) : Robot(talkable, walkable, flyable) {}
    void projection()
    {
        cout << "I am a Companion robot" << endl;
    }
};

class WorkerRobot : public Robot
{
public:
    WorkerRobot(Talkable *talkable, Walkable *walkable, Flyable *flyable) : Robot(talkable, walkable, flyable) {}
    void projection()
    {
        cout << "I am a Worker robot" << endl;
    }
};

int main()
{
    Robot *rb = new CompanionRobot(new talking("I can Talk\n"),
                                   new walking("I can walk\n"),
                                   new flying("I can fly\n"));
    rb->talk();
    rb->walk();
    rb->fly();
    rb->projection();
}