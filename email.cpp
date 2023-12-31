#include <SFML/Network.hpp>
#include <iostream>

int main() {
    // Replace these values with your SMTP server details and email credentials
    const std::string smtpServer = "your_smtp_server";
    const unsigned short smtpPort = 587;  // Change the port if necessary
    const std::string username = "your_email@gmail.com";
    const std::string password = "your_email_password";
    const std::string recipient = "recipient_email@example.com";
    const std::string subject = "Test Subject";
    const std::string body = "Test Body";

    // Create an SMTP connection
    sf::TcpSocket socket;
    if (socket.connect(smtpServer, smtpPort) != sf::Socket::Done) {
        std::cerr << "Failed to connect to SMTP server" << std::endl;
        return 1;
    }

    // Receive the welcome message
    char buffer[1024];
    std::size_t received;
    if (socket.receive(buffer, sizeof(buffer), received) != sf::Socket::Done) {
        std::cerr << "Failed to receive welcome message" << std::endl;
        return 1;
    }

    // Send EHLO command
    if (socket.send("EHLO example.com\r\n", 15) != sf::Socket::Done) {
        std::cerr << "Failed to send EHLO command" << std::endl;
        return 1;
    }

    // Receive the response
    if (socket.receive(buffer, sizeof(buffer), received) != sf::Socket::Done) {
        std::cerr << "Failed to receive response to EHLO command" << std::endl;
        return 1;
    }

    // Send STARTTLS command (if your SMTP server supports it)
    if (socket.send("STARTTLS\r\n", 10) != sf::Socket::Done) {
        std::cerr << "Failed to send STARTTLS command" << std::endl;
        return 1;
    }

    // Receive the response
    if (socket.receive(buffer, sizeof(buffer), received) != sf::Socket::Done) {
        std::cerr << "Failed to receive response to STARTTLS command" << std::endl;
        return 1;
    }

    // Encrypt the connection (if your SMTP server supports STARTTLS)
    sf::TlsSocket tlsSocket;
    tlsSocket.setRemoteAddress(socket.getRemoteAddress());
    tlsSocket.setRemotePort(socket.getRemotePort());
    if (tlsSocket.handshake() != sf::Socket::Done) {
        std::cerr << "Failed to establish TLS connection" << std::endl;
        return 1;
    }

    // Send authentication and email content
    if (tlsSocket.send("AUTH LOGIN\r\n", 11) != sf::Socket::Done ||
        tlsSocket.send(sf::base64::encode(username) + "\r\n", username.length() + 2) != sf::Socket::Done ||
        tlsSocket.send(sf::base64::encode(password) + "\r\n", password.length() + 2) != sf::Socket::Done ||
        tlsSocket.send("MAIL FROM: <" + username + ">\r\n", username.length() + 18) != sf::Socket::Done ||
        tlsSocket.send("RCPT TO: <" + recipient + ">\r\n", recipient.length() + 14) != sf::Socket::Done ||
        tlsSocket.send("DATA\r\n", 6) != sf::Socket::Done ||
        tlsSocket.send("Subject: " + subject + "\r\n\r\n" + body + "\r\n.\r\n", subject.length() + body.length() + 12) != sf::Socket::Done) {
        std::cerr << "Failed to send email" << std::endl;
        return 1;
    }

    // Close the connection
    tlsSocket.disconnect();

    std::cout << "Email sent successfully!" << std::endl;

    return 0;
}
