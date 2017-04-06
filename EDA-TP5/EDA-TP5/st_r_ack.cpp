#include "st_r_ack.hpp"	/* cambiarle el nombre de st_r_ack  a st_r_data_ack. queda mucho mas claro */

using namespace std;

genericState* st_r_ack::on_s_wrq(genericEvent* ev) { return nullptr; };
genericState* st_r_ack::on_s_rrq(genericEvent* ev) { return nullptr; };
genericState* st_r_ack::on_r_wrq_ack(genericEvent* ev) { return nullptr; };
genericState* st_r_ack::on_s_data(genericEvent* ev) { return nullptr; };
genericState* st_r_ack::on_r_data(genericEvent* ev) { return nullptr; };
genericState* st_r_ack::on_s_data_ack(genericEvent* ev) { return nullptr; };
genericState* st_r_ack::on_r_data_ack(genericEvent* ev)
{
	cout << "Previous state: waiting to receive data paquet ACK" << endl;
	cout << "An was received" << endl;
	cout << "Current state: waiting to send data paquet" << endl << endl;
	return ((genericState*) new st_s_data());
};
genericState* st_r_ack::on_s_last_data(genericEvent* ev) { return nullptr; };
genericState* st_r_ack::on_r_last_data(genericEvent* ev) { return nullptr; };
genericState* st_r_ack::on_timeout(genericEvent* ev)
{
	cout << "Previous state: waiting to receive data paquet ACK" << endl;
	cout << "Timeout was reached, WRQ was resent" << endl;			/* solo con escribir que se reenvio alcanza no? */
	cout << "Current state: waiting to receive WRQ ACK" << endl << endl;
	return ((genericState*) new st_r_ack);
};
