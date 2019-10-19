#pragma once

struct pressKey
{
    char getPressKey()
    {
        char c = _key;
        _key = '\0';
        return c;
    }
    void setPressKey(char c)
    {
        _key = c;
    }
private:
    char _key;
};

void keyPress();
void display();
void player_run();
void enemys_run();