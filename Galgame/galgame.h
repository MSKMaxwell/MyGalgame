#ifndef GALGAME_H
#define GALGAME_H
#include "textprocess.h"
#include "savemanager.h"


using namespace std;

class Galgame
{
    friend class TextProcess;
public:
    enum GameStatus {MainPage,Playing,History,Suspend};
    TextProcess Script;
    Galgame();
    Galgame(QString);
    ~Galgame();
    void SetGameStatus(GameStatus);
    void SaveGame(int nowlinenum);
    int LoadGame();
    GameStatus GetGameStatus();
    bool NextTalk();
   private:
    int nowline;
    GameStatus Status;

};

#endif // GALGAME_H
