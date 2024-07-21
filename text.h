#ifndef __TEXT_H__
#define __TEXT_H__
#include "observer.h"
#include "controller.h"

class Text: public Observer {
    Controller *subject;
    int bottom = 7;
    int right = 9;

    public:
        Text(Controller *s);
        void notify() override;
        ~Text();
};

#endif
