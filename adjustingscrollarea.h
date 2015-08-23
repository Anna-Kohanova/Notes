#ifndef ADJUSTINGSCROLLAREA_H
#define ADJUSTINGSCROLLAREA_H

#include <QScrollArea>

class AdjustingScrollArea : public QScrollArea {
    bool eventFilter(QObject * obj, QEvent * ev) {
        if (obj == widget()) {
            setMaximumWidth(width() - viewport()->width() + widget()->width());
        }
        return QScrollArea::eventFilter(obj, ev);
    }

public:
    void setWidget(QWidget *w) {
        QScrollArea::setWidget(w);
        w->installEventFilter(this);
    }
};

#endif // ADJUSTINGSCROLLAREA_H
