#ifndef INTENTION_H
#define INTENTION_H

class Sender;

class Intention{
    protected:
        

    public:
        Intention();
        virtual void execute(Sender& game) = 0;

};

#endif
