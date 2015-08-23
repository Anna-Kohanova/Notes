#ifndef NOTEVIEWER_H
#define NOTEVIEWER_H

#include <QWidget>
#include <QtWidgets>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>

#include "notedata.h"

class NoteData;
class NoteDataList;
class NoteList;
class NoteEditor;

class NoteViewer : public QWidget
{
    Q_OBJECT

public:
    NoteViewer(NoteData& data, QWidget *parent = 0);

public slots:
    void editNote();
    void deleteNote();

signals:
    void noteDeletedFromList(NoteData *noteData, int id);
    void changeId();
    void noteEdited(NoteData *noteData);

private:
    QGridLayout *noteLayout;
    QScrollArea *scrollArea;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QTextEdit *noteText;
    QLabel *time;
    NoteEditor *noteEditor;
    NoteDataList *noteDataList;

    NoteData& noteData;
};

#endif // NOTEVIEWER_H
