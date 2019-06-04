#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main(int argc, char ** argv) {

    printf("Beginning program execution...\n");

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    printf("Clientside socket() command returned: %d\n", client_socket);

    struct sockaddr_in server_address = {
        .sin_family =      AF_INET,
        .sin_port =        htons(3000),
        .sin_addr.s_addr = INADDR_ANY
    };

    int connection_success = connect(
        client_socket,
        (struct sockaddr * ) &server_address,
        sizeof(server_address)
    );
    printf("connect() command returned: %d\n", connection_success);

    char received_response[256];
    recv(client_socket, &received_response, sizeof(received_response), 0);

    printf("Server sent: %s\n", received_response);

    close(client_socket);

    return EXIT_SUCCESS;
}
