#include <QtWidgets>
#include <QBrush>
#include <QPalette>
#include "window.h"
#include "notelist.h"

#include "notedata.h"
#include "notedatalist.h"

class NoteData;
class NoteDataList;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    NoteDataList *list = new NoteDataList;

    Window *window = new Window();
    window->setList(list);

    QBrush br(Qt::TexturePattern);
    br.setTextureImage(QImage("D:/untitled/3.jpg"));
    QPalette *plt = new QPalette();
    plt->setBrush(QPalette::Background, br);
    window->setPalette(*plt);

    window->show();
    return a.exec();
}
