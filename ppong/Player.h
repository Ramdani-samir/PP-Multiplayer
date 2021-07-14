#ifndef PLAYER_H
#define PLAYER_H

class Player
{

public :

    string palyername = " ";
    float player_pos_X = 0;
    float player_pos_Y = 0;
    int screenX = 0;
    int screenY = 0;
    
public:
    Player();
    virtual ~Player();
    
    void Run();
    bool collisionWith(void);
    void goToPosition(float, float);
    void DrawPlayer();
    
};

#endif // PLAYER_H
