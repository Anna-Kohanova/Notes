#ifndef WINDOW_H
#define WINDOW_H
#include <QtWidgets>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>

class NoteEditor;
class NoteList;
class NoteDataList;
class NoteViewer;

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);
    void setList(NoteDataList *list);

public slots:
    void createNoteEditor();

private:
    QScrollArea *area;
    QPushButton *createNoteEditorButton;
    QLabel *welcomeLabel;
    NoteEditor *noteEditor;
    NoteList *noteList;
};

#endif
