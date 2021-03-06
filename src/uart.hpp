#ifndef _UART_H_
#define _UART_H_

#include <string>
#include <vector>

class Uart{
    public:
    Uart(std::string port, int baud_rate);
    ~Uart();

    bool openFile(void);
    bool closeFile(void);
    bool initPort(void);
    int recv(char * rev_buf, int data_len);
    int send(char * send_buf, int data_len);
    int send(std::vector<char> send_list);

    int logging_level;

    private:
    void logging(std::string str);
    void errorOut(std::string str);

    enum PortStatus{
        NO_SETTINGS,
        NOT_INIT,
        INITED
    };
    int file_descriptor;
    std::string port;
    int baud_rate;
    int flow_ctl;
    int databits;
    int stopbits;
    int parity;
    enum PortStatus port_status;
};

#endif
