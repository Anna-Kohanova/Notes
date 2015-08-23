#include <QtWidgets>
#include <QString>

#include "noteeditor.h"
#include "window.h"
#include "notelist.h"
#include "notedata.h"
#include "notedatalist.h"
#include "noteviewer.h"

class NoteList;
class NoteViewer;
class NoteDataList;
class Window;

NoteEditor::NoteEditor(QWidget *parent) :
    QWidget(parent)
{
    id = 0;
    setMaximumSize(450, 150);
    int noteEditorWidth = 450;
    int noteEditorHeight = 200;

    noteEditText = new QTextEdit;
    noteEditText->setStyleSheet("border: 2px solid grey");

    saveButton = new QPushButton(tr("Save"));
    saveButton->setToolTip(tr("Save note"));

    saveButton->setFixedSize(noteEditorWidth / 2, noteEditorHeight / 8);
    saveButton->setEnabled(false);

    noteEditorLayout = new QGridLayout;
    noteEditorLayout->addWidget(noteEditText, 0, 0);
    noteEditorLayout->addWidget(saveButton, 1, 0, Qt::AlignRight);
    setLayout(noteEditorLayout);

    connect(saveButton, SIGNAL(clicked()), this, SLOT(saveNote()));
    connect(noteEditText, SIGNAL(textChanged()), this, SLOT(textChange()));
}

void NoteEditor::textChange()
{
    QString text = noteEditText->toPlainText();
    if (text.isEmpty())
    {
        saveButton->setEnabled(false);
    }
    else
    {
        saveButton->setDisabled(false);
    }
}

void NoteEditor::setList(NoteDataList *list)
{
    this->list = list;
}

void NoteEditor::saveNote()
{
    d = new NoteData();
    d->setText(noteEditText->toPlainText());
    d->setId(id);
    noteEditText->clear();
    list->addNoteData(*d);
    id++;

    emit noteAddedToList();
}

void NoteEditor::change()
{
    id--;
    d->setId(id);
}

void NoteEditor::edit(NoteData *noteData)
{
    noteEditText->setText(noteData->getText());
}

