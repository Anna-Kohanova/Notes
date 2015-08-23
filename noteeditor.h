#ifndef NOTEEDITOR_H
#define NOTEEDITOR_H

#include <QWidget>
#include <QtWidgets>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>
#include <QString>
#include "QVector"

class NoteList;
class NoteData;
class NoteViewer;
class NoteDataList;
class Window;

class NoteEditor : public QWidget
{
    Q_OBJECT

public:
    NoteEditor(QWidget *parent = 0);
    QPushButton *saveButton;
    QTextEdit *noteEditText;
    QLineEdit *lineEdit;

    void setList(NoteDataList *list);
    void setText(QString &text);

    int id;

public slots:
    void textChange();
    void saveNote();
    void change();
    void edit(NoteData *noteData);

signals:
    void noteAddedToList();

private:
    NoteList *noteList;
    NoteData *noteData;
    NoteDataList *list;
    NoteViewer *noteViewer;
    NoteEditor *noteEditor;
    Window *window;
    NoteData *d;
    QTextEdit *tx;

    QGridLayout *noteEditorLayout;
};

#endif // NOTEEDITOR_H
