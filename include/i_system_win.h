#ifndef I_SYSTEM_WIN_H
#define I_SYSTEM_WIN_H

#include <QtCore>
#include <QtGui>
#include <QApplication>
#include <QWidget>


extern "C"
{

typedef enum
{
  ev_keydown,
  ev_keyup,
  ev_mouse,
  ev_joystick
} evtype_t;

// Event structure.
typedef struct
{
  evtype_t  type;
  int       data1;    // keys / mouse/joystick buttons
  int       data2;    // mouse/joystick x move
  int       data3;    // mouse/joystick y move
} event_t;

void D_PostEvent(event_t* ev);
}

extern unsigned char* pb;
extern unsigned char* pl;

class DoomWindow : public QWidget
{
    protected:
    void paintEvent(QPaintEvent *event) override
    {
        QPainter p(this);

        QImage i((uchar*)pb, 240, 160, QImage::Format_Indexed8);
        i.setColorCount(256);

        for(int p = 0; p < 256; p++)
        {

            i.setColor(p, qRgb(pl[3*p],pl[(3*p)+1], pl[(3*p)+2]));
        }

        p.drawImage(this->rect(), i, i.rect());
    }

    void keyPressEvent(QKeyEvent *event) override
    {
        event_t ev;

        ev.type = ev_keydown;

        ev.data1 = 0;

        if(event->key() == Qt::Key_Escape)
            ev.data1 = 27;

        if(event->key() == Qt::Key_Return)
            ev.data1 = 13;

        if(event->key() == Qt::Key_Up)
            ev.data1 = 0xad;

        if(event->key() == Qt::Key_Down)
            ev.data1 = 0xaf;

        if(event->key() == Qt::Key_Left)
            ev.data1 = 0xac;

        if(event->key() == Qt::Key_Right)
            ev.data1 = 0xae;

        if(event->key() == Qt::Key_Tab)
            ev.data1 = 9;

        if(event->key() == Qt::Key_Y)
            ev.data1 = 'y';

        if(event->key() == Qt::Key_Space)
            ev.data1 = ' ';

        if(event->key() == Qt::Key_Control)
            ev.data1 = (0x80+0x1d);

        if(event->key() == Qt::Key_1)
            ev.data1 = '1';

        if(event->key() == Qt::Key_2)
            ev.data1 = '2';

        if(event->key() == Qt::Key_3)
            ev.data1 = '3';

        if(event->key() == Qt::Key_4)
            ev.data1 = '4';

        if(event->key() == Qt::Key_5)
            ev.data1 = '5';

        if(event->key() == Qt::Key_6)
            ev.data1 = '6';

        if(event->key() == Qt::Key_7)
            ev.data1 = '7';

        if(event->key() == Qt::Key_8)
            ev.data1 = '8';

        ev.data2 = 0;
        ev.data3 = 0;

        if(ev.data1 != 0)
            D_PostEvent(&ev);
    }

    void keyReleaseEvent(QKeyEvent *event) override
    {
        event_t ev;

        ev.type = ev_keyup;

        ev.data1 = 0;

        if(event->key() == Qt::Key_Escape)
            ev.data1 = 27;

        if(event->key() == Qt::Key_Enter)
            ev.data1 = 13;

        if(event->key() == Qt::Key_Up)
            ev.data1 = 0xad;

        if(event->key() == Qt::Key_Down)
            ev.data1 = 0xaf;

        if(event->key() == Qt::Key_Left)
            ev.data1 = 0xac;

        if(event->key() == Qt::Key_Right)
            ev.data1 = 0xae;

        if(event->key() == Qt::Key_Tab)
            ev.data1 = 9;

        if(event->key() == Qt::Key_Y)
            ev.data1 = 'y';

        if(event->key() == Qt::Key_Space)
            ev.data1 = ' ';

        if(event->key() == Qt::Key_Control)
            ev.data1 = (0x80+0x1d);

        if(event->key() == Qt::Key_1)
            ev.data1 = '1';

        if(event->key() == Qt::Key_2)
            ev.data1 = '2';

        if(event->key() == Qt::Key_3)
            ev.data1 = '3';

        if(event->key() == Qt::Key_4)
            ev.data1 = '4';

        if(event->key() == Qt::Key_5)
            ev.data1 = '5';

        if(event->key() == Qt::Key_6)
            ev.data1 = '6';

        if(event->key() == Qt::Key_7)
            ev.data1 = '7';

        if(event->key() == Qt::Key_8)
            ev.data1 = '8';

        ev.data2 = 0;
        ev.data3 = 0;

        if(ev.data1 != 0)
            D_PostEvent(&ev);
    }
};

#endif // I_SYSTEM_WIN_H