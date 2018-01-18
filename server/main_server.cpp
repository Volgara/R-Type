#include <iostream>
#include "Server.hpp"

int main()
{
    RType::Server *serv = new RType::Server();

    serv->configure();
    serv->run();
    return(0);
}
