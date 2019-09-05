#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define h_addr h_addr_list[0]

/*
struct hostent {
    char  *h_name;
    char  **h_aliases;
    int   h_addrtype;
    int   h_length;
    char  **h_addr_list;
};

#define h_addr h_addr_list[0]
*/

int main(int argc, char ** argv) {

    printf("Beginning program execution...\n");

    /* Error check the command line */
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <domain_name>\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Get the host info */
    struct hostent * h = gethostbyname(argv[1]);
    if (h == NULL) {
        herror("gethostbyname(): ");
        return EXIT_FAILURE;
    } else {
        printf("gethostbyname() is OK.\n");
    }

    char * host_name = h->h_name;
    char * ip_address = inet_ntoa(*((struct in_addr *)h->h_addr));
    int address_length = h->h_length;
    char ** other_names = h->h_aliases;
    char ** other_ips = h->h_addr_list;

    printf("The hostname is %s\n", host_name);
    printf("The IP address is %s\n", ip_address);
    printf("The address length is %d\n", address_length);

    printf("Sniffing other names...\n");

    int i = 0;
    while (other_names[i] != NULL) {
        printf("Alias number %d for %s is: %s\n", i, argv[1], other_names[i]);
        i++;
    }

    printf("Sniffing other IP's...\n");

    int j = 0;
    while (other_ips[j] != NULL) {
        char * current_ip = inet_ntoa(*((struct in_addr *)(other_ips[j])));
        printf("IP number %d for %s is: %s\n", j, argv[1], current_ip);
        j++;
    }

    return EXIT_SUCCESS;
}
