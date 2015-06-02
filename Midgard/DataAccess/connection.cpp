#include "connection.h"
connection::connection(){

}

void connection::goRun()
{
    ServerSocket server(port);
    ServerSocket socketToConnect;

    try
    {
        server.accept(socketToConnect);
        try{
            while (true){

                string data;
                socketToConnect >> data;
                socketToConnect << (LogicFacade::getInstance()->receiveDataFromSocket(data));
                sleep(3);

            }
        }
        catch (SocketException&) {

        }
    }
    catch (SocketException& e)
    {
             cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }
}
