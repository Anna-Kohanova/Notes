#ifndef NOTELIST_H
#define NOTELIST_H

#include <QtWidgets>

class Window;
class NoteEditor;
class NoteViewer;
class NoteData;
class NoteDataList;

class NoteList : public QWidget
{
    Q_OBJECT
public:
    NoteList(QWidget *parent = 0);
    void setList(NoteDataList *list);
    void addNote(NoteViewer *noteViewer);

public slots:
    void updateList();
    void deleteNote(NoteData *noteData, int id);
    void editNote(NoteData *noteData);

signals:
    void changeId();
    void edit(NoteData *noteData);

private:
    Window *window;
    QVBoxLayout *listLayout;
    NoteDataList *list;
    NoteViewer *noteViewer;
};

#endif // NOTELIST_H
