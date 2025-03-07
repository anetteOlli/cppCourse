#include <boost/asio.hpp>
#include <iostream>

using namespace std;
using namespace boost::asio::ip;

//Assigment 6, B, main.cpp

/*
OPPGAVETEKST:
Oppgave 2 - Ta utgangspunkt i example6 og lag en enkel web-server som svarer på følgende GET forespørsler:
GET / HTTP/1.1
I en nettleser (http://localhost:8080) skal følgende tekst vises: Dette er hovedsiden
GET /en_side HTTP/1.1
I en nettleser (http://localhost:8080/en_side) skal følgende tekst vises: Dette er en side
Andre forespørsler skal gi status koden 404 Not Found
*/

class EchoServer {
private:
    class Connection {
    public:
        tcp::socket socket;
        Connection(boost::asio::io_service &io_service) : socket(io_service) {}
    };

    boost::asio::io_service io_service;

    tcp::endpoint endpoint;
    tcp::acceptor acceptor;

    void handle_request(shared_ptr<Connection> connection) {
        auto read_buffer = make_shared<boost::asio::streambuf>();
        // Read from client until end of get-request. Get request should always end with two new lines.
        async_read_until(connection->socket, *read_buffer, "\r\n\r\n",
                         [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
                             // If not error:
                             if (!ec) {
                                 // Retrieve message from client as string:
                                 istream read_stream(read_buffer.get());
                                 std::string message;
                                 getline(read_stream, message);
                                 message.pop_back(); // Remove "\r" at the end of message

                                 // Close connection when "exit" is retrieved from client
                                 if (message == "exit")
                                     return;


                                 cout << "Message from a connected client: " << message << endl;

                                 auto write_buffer = make_shared<boost::asio::streambuf>();
                                 ostream write_stream(write_buffer.get());

                                 const string payload_error = "<!DOCTYPE html><HTML><body><H1> Siden finnes ikke </h1></body></HTML>\r\n\r\n";
                                 const string response_error = "HTTP/1.1 404 Not Found\\r\\nContent-Type: text/html\\r\\ncharset=UTF-8\\r\\nContent-length: " + std::to_string((int) payload_error.length()) + "\r\n\r\n" + payload_error;;
                                 const string payload_hovedsiden = "<!DOCTYPE html><HTML><body><H1> Dette er hovedsiden </h1></body></HTML>\r\n\r\n";
                                 const string total_hovedsiden = "HTTP/1.1 200 OK\\r\\nContent-Type: text/html\\r\\ncharset=UTF-8\\r\\nContent-length: " + std::to_string((int) payload_hovedsiden.length()) + "\r\n\r\n" + payload_hovedsiden;


                                 const string payload_en_side = "<!DOCTYPE html><HTML><body><H1> Dette er en side </h1></body></HTML>\r\n\r\n";
                                 const string total_en_side = "HTTP/1.1 200 OK\\r\\nContent-Type: text/html\\r\\ncharset=UTF-8\\r\\nContent-length: " + std::to_string((int) payload_en_side.length()) + "\r\n\r\n" + payload_en_side;

                                 if (message == "GET / HTTP/1.1"){
                                     write_stream << total_hovedsiden;

                                 }else if (message == "GET /en_side HTTP/1.1"){
                                     write_stream << total_en_side;

                                 }else{
                                     write_stream << response_error;

                                 }


                                 // Write to client
                                 async_write(connection->socket, *write_buffer,
                                             [this, connection, write_buffer](const boost::system::error_code &ec, size_t) {});
                             }
                         });
    }

    void accept() {
        // The (client) connection is added to the lambda parameter and handle_request
        // in order to keep the object alive for as long as it is needed.
        auto connection = make_shared<Connection>(io_service);

        // Accepts a new (client) connection. On connection, immediately start accepting a new connection
        acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
            accept();
            // If not error:
            if (!ec) {
                handle_request(connection);
            }
        });
    }

public:
    EchoServer() : endpoint(tcp::v4(), 8080), acceptor(io_service, endpoint) {}

    void start() {
        accept();

        io_service.run();
    }
};

int main() {
    EchoServer echo_server;

    cout << "Starting echo server" << endl
         << "Connect in a terminal with: telnet localhost 8080. Type 'exit' to end connection." << endl;

    echo_server.start();
}
