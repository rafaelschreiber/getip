/*
 * Author:      Rafael Schreiber
 * Desc:        Returns the external IP-Address
 * Date:        04-04-2018
 * Filename:    getip.cpp
 * Comment:     Thanks to the ipinfo.io API for fetching the IP-Address
 */


#include <cstdio>
#include <fstream>
#include <string>

using namespace std;


void checkCurl(){
    if (system("which curl > /dev/null 2>&1") != 0){
        printf("Curl isn't installed. Please install curl\n");
        exit(1);
    } else {
        return;
    }
}

void delIP(){
    system("rm -f ~/.ip.tmp 2>&1");
}


void createIP(){
    int status = system("curl -s ipinfo.io/ip > ~/.ip.tmp 2>&1");
    if (status != 0){
        printf("Cant establish connection\n");
        exit(1);
    }
}


string getIP(){
    string home = getenv("HOME");
    string path = home + "/.ip.tmp";
    ifstream ipFile(path);
    string ip;
    ipFile >> ip;
    ipFile.close();
    return ip;
}


int main(){
    checkCurl(); // checks if curl is installed
    delIP(); // deletes the temporary file if it still exists
    createIP(); // fetch the ip address and stores it in a temporary file
    printf("%s\n", getIP().c_str()); // print out the ip
    delIP(); // deletes the temporary file
    return 0;
}
