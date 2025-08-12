#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// abstract Observer class: subscriber->
class Isubscriber
{
public:
    virtual void update() = 0;
};

// abstarct Observable class: channel->
class Ichannel
{
public:
    virtual void subscribe(Isubscriber *s) = 0;
    virtual void unsubscribe(Isubscriber *s) = 0;
    virtual void NotifySubscriber() = 0;
};

// Concrete class for the Ichannel interface
class channel : public Ichannel
{
private:
    vector<Isubscriber *> subscribers; // list of suscriber of a particular youtube channel:
    string name;
    string latest_Video;

public:
    channel(const string &name)
    {
        this->name = name;
    }
    virtual void subscribe(Isubscriber *s)
    {
        if (find(subscribers.begin(), subscribers.end(), s) == subscribers.end())
        {
            subscribers.push_back(s);
            cout << "Subscriber added" << endl;
        }
    }
    virtual void unsubscribe(Isubscriber *s)
    {
        auto it = find(subscribers.begin(), subscribers.end(), s);
        if (it != subscribers.end())
        {
            subscribers.erase(it);
            cout << "Subscriber removed" << endl;
        }
    }
    virtual void NotifySubscriber()
    {
        for (Isubscriber *s : subscribers)
        {
            s->update();
        }
    }
    virtual void uploadVideo(const string &title)
    {
        latest_Video = title;
        cout << "\n"
             << name << "uploaded \"" << title << "\"\n";
        NotifySubscriber();
    }
    string getVideo()
    {
        return "Checkout our new Video:" + latest_Video + "\n";
    }
};

class Subscriber : public Isubscriber
{
private:
    channel *c;
    string name;

public:
    Subscriber(channel *ch, const string &name)
    {
        this->c = ch;
        this->name = name;
    }

    void update()
    {
        string s = c->getVideo();
        cout << s;
    }
};

int main()
{
    channel *c = new channel("Codeforce");
    Subscriber *s1 = new Subscriber(c, "s1");
    Subscriber *s2 = new Subscriber(c, "s2");
    c->subscribe(s1);
    c->subscribe(s2);
    c->uploadVideo("array to string 1st");
    c->unsubscribe(s2);
    c->uploadVideo("array to string 2nd");

    return 0;
}
