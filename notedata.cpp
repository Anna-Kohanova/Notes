#include "notedata.h"

void NoteData::setText(QString text)
{
    this->text = text;
}

QString NoteData::getText()
{
    return this->text;
}

void NoteData::setId(int id)
{
    this->id = id;
}

int NoteData::getId()
{
    return this->id;
}
