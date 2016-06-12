#include "messagespooler.h"

MessageSpooler::MessageSpooler(ActiveClientList *client_list) {
    m_active_client_list = client_list;
}



MessageSpooler::~MessageSpooler() {

}



bool MessageSpooler::putNewMessage(const Message &message) {

}
