#include "notedatalist.h"
#include "notedata.h"

class NoteData;
class NoteDataList;

void NoteDataList::addNoteData(NoteData &noteData)
{
    data.push_back(noteData);
}

NoteData& NoteDataList::getLastNote()
{
    return data.last();
}

void NoteDataList::deleteNoteData(NoteData *noteData)
{
    data.erase(noteData);
}

/*NoteData& NoteDataList::getNoteById(int id)
{
     //return data.at(id);
}*/
