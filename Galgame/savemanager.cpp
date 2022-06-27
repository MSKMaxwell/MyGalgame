#include "savemanager.h"

SaveManager::SaveManager()
{

}

SaveManager::SaveManager(QString _Filedir)
    :Filedir(_Filedir)
{
    QFile File(Filedir);
    QTextStream in(&File);
    while(!in.atEnd())
    {
        int slot,nowlinenum;
        in >> slot >> nowlinenum;
        Saves.insert(make_pair(slot,nowlinenum));
    }
}

void SaveManager::Save(int slot,int nowlinenum)
{
    map<int,int>::iterator i = Saves.find(slot);
    i->second = nowlinenum;
    QFile File(Filedir);
    QTextStream out(&File);
    for(i = Saves.begin();i != Saves.end();++i)
    {
        out << slot << " " << nowlinenum << "\n";
    }
    return;
}

int SaveManager::Load(int slot)
{
    map<int,int>::iterator i;
    i = Saves.find(slot);
    if(i != Saves.end())
    {
        if(i->second != -1)
        return Saves.find(slot)->second;
        else
            return 0;
    }
    else
        return -1;
}
