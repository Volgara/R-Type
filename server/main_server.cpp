#include <iostream>
#include "Server.hpp"

int main()
{
    RTypeServer::Server *serv = new RTypeServer::Server();

    serv->configure();
    serv->run();
    return(0);
}
