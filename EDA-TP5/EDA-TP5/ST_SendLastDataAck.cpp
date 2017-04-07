#include <stdio.h>
#include "ST_SendLastDataAck.hpp"

using namespace std;

genericState* ST_SendLastDataAck :: on_SendAck(genericEvent* ev)
{
    cout << "Previous state: Waiting to send last data ACK" << endl << "Event received: send last data ACK. Last data ACK was sent" << endl << "New state: Idle" << endl << endl;
    return ((genericState*) new ST_ReceiveLastDataAck());
};
