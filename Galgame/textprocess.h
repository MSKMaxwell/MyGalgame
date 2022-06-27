#ifndef TEXTPROCESS_H
#define TEXTPROCESS_H

#include <QStringList>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <map>

using namespace std;

class TextProcess
{

public:
    int CharaID,CharaFace,SceneID;
    QString CharaName,SceneName,CharaTalk;
    unordered_map<int,QString>::iterator CharaPici;
    unordered_map<int,QString>::iterator CharaFacePici;
    TextProcess();
    TextProcess(const QString&);// 读入脚本内容并存储起来
    ~TextProcess();
    bool ReadText();// 逐行展示脚本
    QString ReadText(int nowlinenum);// 返回单行脚本
    void InitRes();
    int nowlinenum;
private:
    QFile File;
    QStringList alltxt;
    QStringList::Iterator i;
    QString nowlinetxt;
    QTextStream in;
    QTextStream strin;
    unordered_map<int,QString> CharaPic;
    unordered_map<int,QString> CharaFacePic;
    unordered_map<int,QString> ScenePic;

};

#endif // TEXTPROCESS_H
