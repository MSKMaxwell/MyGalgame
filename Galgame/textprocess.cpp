#include "textprocess.h"

TextProcess::TextProcess()
{
    nowlinenum = 0;
}

TextProcess::TextProcess(const QString& FilePath)
    :File(QFile(FilePath)),in(QTextStream(&File))
{
    InitRes();
    File.open(QFile::OpenModeFlag::ReadOnly | QIODevice::Text);
    while(!in.atEnd())
    {
        alltxt << in.readLine();
    }
    File.close();
    i = alltxt.begin();
}

bool TextProcess::ReadText()
{
    if((*i)[0] == '/')// 表示脚本已到结尾
    {
        return false;
    }
    else
    {
        strin.setString(i,QTextStream::OpenModeFlag::ReadOnly);
        strin >> nowlinenum >> CharaID >> CharaName >> CharaFace >> SceneID >> SceneName >> CharaTalk;
        ++i;
        CharaFacePici = CharaFacePic.find(CharaID);
        CharaPici = CharaPic.find(CharaID);
    }
    return true;
}

QString TextProcess::ReadText(int _nowlinenum)
{
    QStringList::iterator it;
    it = alltxt.begin();
    for(int j = 0;j < _nowlinenum;++j)
    {
        ++it;
    }
    return *it;
}

TextProcess::~TextProcess()
{
}

void TextProcess::InitRes()// 在程序开始时事先载入资源文件以及对应脚本中的键值，一边快速查找和根据需要变换
{
    CharaFacePic.insert(pair<int,QString>(0,":/Res/Ying.jpg"));
    CharaFacePic.insert(pair<int,QString>(1,":/Res/Kokomi.jpg"));
    CharaPic.insert(pair<int,QString>(0,":/Res/Lumine.png"));
    CharaPic.insert(pair<int,QString>(1,":/Res/Kokomi1.png"));
}
