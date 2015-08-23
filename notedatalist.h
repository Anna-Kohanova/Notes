#ifndef NOTEDATALIST_H
#define NOTEDATALIST_H

#include <QString>
#include <QTextEdit>
#include <QVector>

#include "notedata.h"

class NoteData;

class NoteDataList
{
private:
  //  QVector<NoteData> data;

public:
    QVector<NoteData> data;
    void addNoteData(NoteData &noteData);
    void deleteNoteData(NoteData *noteData);

    NoteData& getLastNote();
    //NoteData& getNoteById(int id);
};

#endif // NOTEDATALIST_H
