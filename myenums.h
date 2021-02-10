#ifndef MYENUMS_H
#define MYENUMS_H

namespace mynet
{
    /** server */
    enum Server
    {
        Server1 = 1, //!< server 1
        Server2, //!< server 2
        Server3, //!< server 3
        Server4 //!< server 4
    };

    /** client */
    enum Client
    {
        Client1 = 1, //!< client 1
        Client2, //!< client 2
        Client3, //!< client 3
        Client4 //!< client 4
    };

    /** model */
    enum Model
    {
        Server, //!< server
        Client //!< client
    };
}

#endif // MYENUMS_H
