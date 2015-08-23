#include <QScrollArea>
#include <QVector>

#include "notedata.h"
#include "notedatalist.h"
#include "notelist.h"
#include "noteeditor.h"
#include "noteviewer.h"
#include "window.h"

class NoteViewer;
class NoteData;
class NoteDataList;

NoteList::NoteList(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(450, 100);
    listLayout = new QVBoxLayout;
    listLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
}

void NoteList::setList(NoteDataList *list)
{
    this->list = list;
}

void NoteList::updateList()
{
    noteViewer = new NoteViewer(list->getLastNote());
    connect(noteViewer, SIGNAL(noteDeletedFromList(NoteData*, int)), this, SLOT(deleteNote(NoteData*, int)));
    connect(noteViewer,SIGNAL(noteEdited(NoteData*)), this, SLOT(editNote(NoteData*)));
    this->addNote(noteViewer);
}

void NoteList::editNote(NoteData *noteData)
{
  emit edit(noteData);
}

void NoteList::deleteNote(NoteData *noteData, int id)
{
    QVector<NoteData>::iterator i;
    for (i = list->data.begin(); i != list->data.end(); ++i)
    {
        if (id == i->getId())
        {
            QVector<NoteData>::iterator iter;
            for (iter = i + 1; iter !=list->data.end(); ++iter)
            {
                iter->setId(iter->getId()-1);
            }
        }
    }

    this->list->deleteNoteData(noteData);

    QLayoutItem *child = listLayout->takeAt(id);
    QWidget* noteViewer = child->widget();
    while ((child = listLayout->takeAt(id)) != 0) {
        delete child;
    }
    delete noteViewer;

    emit changeId();
}

void NoteList::addNote(NoteViewer *noteViewer)
{
    listLayout->addWidget(noteViewer, 0, Qt::AlignTop);
    setLayout(listLayout);
}
