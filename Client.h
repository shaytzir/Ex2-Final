//
// Created by shay on 12/6/17.
//

#ifndef EX2_CLIENT_H
#define EX2_CLIENT_H

class Client {
public:
    Client(const char *serverIP, int serverPort);
    void connectToServer();
    int sendExercise(int arg1, char op, int arg2);
private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};


#endif //EX2_CLIENT_H
