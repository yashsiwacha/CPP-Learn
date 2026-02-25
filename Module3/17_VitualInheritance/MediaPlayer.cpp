#include <iostream>

// Interface 1: playback behavior contract.
class Playable
{
public:
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual ~Playable() = default;
};

// Interface 2: recording behavior contract.
class Recordable
{
public:
    virtual void record() = 0;
    virtual void stop() = 0;
    virtual ~Recordable() = default;
};

// One class implementing both interfaces.
class MediaPlayer : public Playable, public Recordable
{
public:
    void play() override
    {
        std::cout << "MediaPlayer: Playing media..." << std::endl;
    }

    void pause() override
    {
        std::cout << "MediaPlayer: Paused playback." << std::endl;
    }

    void record() override
    {
        std::cout << "MediaPlayer: Recording started..." << std::endl;
    }

    void stop() override
    {
        std::cout << "MediaPlayer: Recording stopped." << std::endl;
    }
};

int main()
{
    MediaPlayer mp;

    // Polymorphism through Playable API.
    Playable *p = &mp;
    p->play();
    p->pause();

    // Polymorphism through Recordable API.
    Recordable *r = &mp;
    r->record();
    r->stop();

    return 0;
}
