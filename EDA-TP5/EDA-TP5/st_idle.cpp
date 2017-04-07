#include <stdio.h>
#include "st_idle.hpp"

using namespace std;

genericState* ST_Idle::on_SendWRQ(genericEvent *ev)
{
    cout << "Previous state: idle" << endl << "Event received: s_wrq, an WRQ was sent" << endl << "New state: ReceiveWRQAck" << endl << endl;
    return ((genericState*) new ST_ReceiveWRQAck());
};
genericState* ST_Idle::on_SendRRQ(genericEvent *ev)
{
    cout << "Previous state: idle" << endl << "Event received: s_rrq, an RRQ was sent" << endl << "New state: ReceiveFirstData" << endl << endl;
    return ((genericState*) new ST_ReceiveFirstData());
};
