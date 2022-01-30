#include<sys/socket.h>
#include<stdin.h>

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in servaddr;

    if(argc != 2) {
        exit(ERROR_FAILURE);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8089);
    Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    sockfd = Socket(AF_INET, SOCK_DGRAM, 0);

    dg_cli(stdin, sockfd, (SOCKADDR *) &servaddr, sizeof(servaddr));

    exit(0);
}

void dg_cli(File *fp, int sockfd, const SOCKADDR *pservaddr, servlen) {
    int n;
    char sendline[5000], recvline[5000+1];

    while(fgets(sendline, 5000, fp) != NULL) {
        sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen);

        n = recvfrom(sockfd, recvline, 5000, 0, NULL, NULL);
        fputs(recvline, stdout);
    }
}