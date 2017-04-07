#include <stdio.h>
#include "ST_ReceiveWRQAck.hpp"

using namespace std;

genericState* ST_ReceiveWRQAck :: on_ReceiveAck(genericEvent* ev)
{
    cout << "Previous state: Waiting to receive WRQ ACK" << endl << "Event received: received ACK" << endl << "New state: Waiting to send data" << endl << endl;
    return ((genericState*) new ST_SendData());
};
genericState* ST_ReceiveWRQAck :: on_timeout(genericEvent* ev)
{
    cout << "Previous state: Waiting to receive WRQ ACK" << endl << "Event received: timeout. WRQ was resent" << endl << "New state: Waiting to receive WRQ ACK" << endl << endl;
    return ((genericState*) new ST_ReceiveWRQAck());
};
