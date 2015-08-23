#ifndef NOTEDATA_H
#define NOTEDATA_H

#include <QString>

class NoteDataList;
class NoteViewer;

class NoteData
{
private:
    QString text;
    int id;

public:
    void setText(QString text);
    void setId(int id);
    QString getText();
    int getId();
};

#endif // NOTEDATA_H
