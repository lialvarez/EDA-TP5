#include "st_s_data.hpp"

using namespace std;

genericState* st_s_data::on_s_wrq(genericEvent* ev) { return nullptr; };
genericState* st_s_data::on_s_rrq(genericEvent* ev) { return nullptr; };
genericState* st_s_data::on_r_wrq_ack(genericEvent* ev) { return nullptr; };
genericState* st_s_data::on_s_data(genericEvent* ev) { return nullptr; };
genericState* st_s_data::on_r_data(genericEvent* ev) { return nullptr; };
genericState* st_s_data::on_s_data_ack(genericEvent* ev)
{
	cout << "Previous state: waiting to send data paquet" << endl;
	cout << "A data paquet was sent" << endl;
	cout << "Current state: waiting to receive data paquet ACK" << endl << endl;
	return ((genericState*) new st_r_ack());
};
genericState* st_s_data::on_r_data_ack(genericEvent* ev) { return nullptr; };
genericState* st_s_data::on_s_last_data(genericEvent* ev)
{
	cout << "Previous state: waiting to send data paquet" << endl;
	cout << "The last data paquet was sent" << endl;
	cout << "Current state: waiting to receive the last data paquet ACK" << endl << endl;
	return ((genericState*) new st_r_last_data_ack);
};
genericState* st_s_data::on_r_last_data(genericEvent* ev) { return nullptr; };
genericState* st_s_data::on_timeout(genericEvent* ev) { return nullptr; };

