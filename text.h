#ifndef __TEXT_H__
#define __TEXT_H__
#include "observer.h"
#include "controller.h"

class Text: public Observer {
    Controller *subject;
    int bottom = 8;
    int right = 8;

    public:
        Text(Controller *s);
        void notify(Move move) override;
        void initNotify() override;
        ~Text();
};

#endif
