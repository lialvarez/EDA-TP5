#include"allStates.hpp"


using namespace std;

genericState* st_idle::on_s_wrq(genericEvent* ev)
{
	cout << "Previous state: Idle" << endl;
	cout << "A WRQ was sent" << endl;
	cout << "Current state: waiting to receive WRQ ACK" << endl << endl;
	return ((genericState*) new st_r_wrq_ack());
};
 genericState* st_idle::on_s_rrq(genericEvent* ev)
{
	cout << "Previous state: Idle" << endl;
	cout << "A RRQ was sent" << endl;
	cout << "Current state: aiting to receive first data paquet" << endl << endl;
	return ((genericState*) new st_r_first_data());
};
genericState* st_idle::on_r_wrq_ack(genericEvent* ev) { return nullptr; };
genericState* st_idle::on_s_data(genericEvent* ev) { return nullptr; };
genericState* st_idle::on_r_data(genericEvent* ev) { return nullptr; };
genericState* st_idle::on_s_data_ack(genericEvent* ev) { return nullptr; };
genericState* st_idle::on_r_data_ack(genericEvent* ev) { return nullptr; };
genericState* st_idle::on_s_last_data(genericEvent* ev) { return nullptr; };
genericState* st_idle::on_r_last_data(genericEvent* ev) { return nullptr; };
genericState* st_idle::on_timeout(genericEvent* ev) { return nullptr; };
