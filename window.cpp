#include <QtWidgets>
#include <QLabel>
#include "window.h"
#include "noteeditor.h"
#include "notedatalist.h"
#include "notelist.h"
#include "noteviewer.h"
#include "adjustingscrollarea.h"

class NoteDataList;
class NoteEditor;
class NoteList;
class NoteViewer;

Window::Window(QWidget *parent) :
    QWidget(parent)
{
    setMinimumSize(480, 530);
    setMaximumSize(480, 530);

    setWindowTitle(tr("Notes"));
    setWindowIcon(QIcon(QPixmap("D:/untitled/11.ico")));

    welcomeLabel = new QLabel;
    welcomeLabel->setText(tr("<font size=30><b>Welcome to the Notes!</b></font>"));

    createNoteEditorButton = new QPushButton(tr("Create a new note"));
    createNoteEditorButton->setToolTip(tr("Create a new note"));
    createNoteEditorButton->setFixedSize(450, 70);

    noteEditor = new NoteEditor();
    noteEditor->hide();

    noteList = new NoteList;

    area = new AdjustingScrollArea;
    area->hide();

    QGridLayout *windowLayout = new QGridLayout;
    windowLayout->addWidget(welcomeLabel, 0, 0, Qt::AlignCenter);
    windowLayout->addWidget(createNoteEditorButton, 1, 0, Qt::AlignTop);
    windowLayout->addWidget(noteEditor, 2, 0);
    windowLayout->addWidget(area, 3, 0);
    area->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
    area->setStyleSheet("QScrollArea { border: 2px solid grey }");
    area->setWidget(noteList);
    setLayout(windowLayout);

    connect(createNoteEditorButton, SIGNAL(clicked()), this, SLOT(createNoteEditor()));
    connect(noteEditor, SIGNAL(noteAddedToList()), noteList, SLOT(updateList()));
    connect(noteList, SIGNAL(changeId()), noteEditor, SLOT(change()));
    connect(noteList, SIGNAL(edit(NoteData*)), noteEditor, SLOT(edit(NoteData*)));
}

void Window::setList(NoteDataList *list)
{
    noteEditor->setList(list);
    noteList->setList(list);
}

void Window::createNoteEditor()
{
    noteEditor->show();
    area->show();
    createNoteEditorButton->hide();
    welcomeLabel->hide();
}
