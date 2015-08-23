#include <QtWidgets>
#include <QDate>
#include <QPalette>

#include "noteviewer.h"
#include "notedata.h"
#include "notedatalist.h"
#include "noteeditor.h"
#include "notelist.h"

class NoteList;
class NoteViewer;
class NoteEditor;
class NoteData;
class NoteDataList;

NoteViewer::NoteViewer(NoteData& data, QWidget *parent) :
    QWidget(parent), noteData(data)
{
    this->noteData = noteData;

    setFixedSize(410, 100);

    editButton = new QPushButton(tr("Edit"));
    deleteButton = new QPushButton(tr("Delete"));

    noteText = new QTextEdit;
    noteText->setText(this->noteData.getText());
    noteText->setReadOnly(true);
    noteText->setStyleSheet("border: 1px solid grey");

    time = new QLabel;
    time->setText(QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss"));
    QFont font = time->font();
    font.setPointSize(12);
    time->setFont(font);

    noteLayout = new QGridLayout;
    noteLayout->addWidget(noteText, 0, 0, 1, 3);
    noteLayout->addWidget(editButton, 1, 1);
    noteLayout->addWidget(deleteButton, 1, 2);
    noteLayout->addWidget(time, 1, 0);
    setLayout(noteLayout);

    connect(editButton, SIGNAL(clicked()), this, SLOT(editNote()));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteNote()));
}

void NoteViewer::editNote()
{
    emit noteEdited(&noteData);
    deleteNote();
}

void NoteViewer::deleteNote()
{
    int id = 0;
    id = noteData.getId();
    emit noteDeletedFromList(&noteData, id);
}
