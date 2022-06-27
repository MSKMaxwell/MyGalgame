#ifndef SAVEMANAGER_H
#define SAVEMANAGER_H

#include <QString>
#include <map>
#include <QFile>
#include <QTextStream>

using namespace std;

// 对指定格式的存档文件进行的读写操作类
class SaveManager
{
private:
    map<int,int> Saves;
    QString Filedir;
public:
    SaveManager();
    SaveManager(QString Filedir);
    void Save(int,int);
    int Load(int);
};

#endif // SAVEMANAGER_H
