#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main(int argc, char ** argv) {

    char server_message[256] = "You have reached the server";

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address = {
        .sin_family =      AF_INET,
        .sin_port =        htons(3000),
        .sin_addr.s_addr = INADDR_ANY
    };

    int bind_success = bind(
        server_socket,
        (struct sockaddr *) &server_address,
        sizeof(server_address)
    );
    if (bind_success != 0) {
        printf("Server failed to bind\n");
        return EXIT_FAILURE;
    }

    listen(server_socket, 8);

    int client_socket = accept(
        server_socket,
        NULL,
        NULL
    );

    send(client_socket, server_message, sizeof(server_message), 0);

    close(client_socket);

    return EXIT_SUCCESS;
}
