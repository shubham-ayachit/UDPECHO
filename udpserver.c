#include<sys/socket.h>
#include<stdio.h>

int main(int argc, char **argv) {
        int sockfd;
        struct sockaddr_in servaddr, cliaddr;

        sockfd = Socket(AF_INET, SOCK_DGRAM, 0);

        bzero(&servaddr, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sinaddr.s_addr = htonl(INADDR_ANY);
        servaddr.sin_port = htons(8089);

        Bind(sockfd, (SOCKADDR *) &servaddr, sizeof(servaddr));
        dg_echo(sockfd, (SOCKADDR *) &cliaddr, sizeof(cliaddr));
}

void dg_echo(int sockfd, struct SOCKADDR *pcliaddr, socklen_t clilen) {
        int n;
        socklen_t len;
        char mesg[5000];

}
