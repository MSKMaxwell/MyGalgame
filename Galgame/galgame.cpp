#include "galgame.h"

Galgame::Galgame()
{

}

Galgame::~Galgame()
{

}



Galgame::Galgame(QString ScriptPath)
    :Script(TextProcess(ScriptPath))
{
}

void Galgame::SaveGame(int nowlinenum)
{
    // ...
}

int Galgame::LoadGame()
{
    // ...
    return -1;
}

bool Galgame::NextTalk()
{
    if(Script.ReadText())
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Galgame::SetGameStatus(Galgame::GameStatus _Status)
{
    Status = _Status;
}

Galgame::GameStatus Galgame::GetGameStatus()
{
    return Status;
}
