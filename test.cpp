#include <map>
#include <iostream>
#include <string>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <unistd.h>
#include <string.h> 
#include <sys/types.h>

#include <sys/ioctl.h>

#include <net/if.h>

#include <ifaddrs.h>
#include <a.out.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <vector>

#include <chrono>
#include <iostream>
#include <ctime>
#include <ratio>
#include <mutex>
#include <stdio.h>


using namespace std;

void testMap() {
	map<string, string> myMap;

	myMap.insert( pair<string,string>("hej", "da"));
	myMap.insert( pair<string, string>("x", "y"));
	myMap.insert( pair<string, string>("x", "z"));



	map<string, string>::iterator iter;

	for(iter = myMap.begin(); iter != myMap.end(); ++iter) {
		cout << iter->first + " " + iter->second << endl;
	}
}

void testIP() {

    struct ifaddrs* ifas = NULL;
    struct ifaddrs* tempifas = NULL;
    void* tempAddrPtr = NULL;
    getifaddrs(&ifas);

    std::vector<std::string> IPv4list;

    for(tempifas = ifas; tempifas != NULL; tempifas = tempifas->ifa_next)
    {
        if(!tempifas->ifa_addr)
        {
            continue;
        }
        else if(tempifas->ifa_addr->sa_family == AF_INET) //IPv4
        {
            char buff[INET_ADDRSTRLEN];
            tempAddrPtr = &((struct sockaddr_in *)tempifas->ifa_addr)->sin_addr;
            std::string ip = inet_ntop(AF_INET, tempAddrPtr, buff, INET_ADDRSTRLEN);
            if( (static_cast<std::string>(tempifas->ifa_name)).compare("lo") != 0)  //Discard localhost
                IPv4list.push_back(ip);
        }
        /* //If we need IPv6
        else if(tempifas->ifa_addr->sa_family == AF_INET6) //IPv6
        {
            char buff[INET6_ADDSTRLEN];
            tempAddrPtr = &((struct sockaddr_in6 *)tempifas->ifa_addr)->sin6_addr;
            std::string ip = inet_ntop(AF_INET6, tempAddrPtr, buff, INET6_ADDSTRLEN);
        }*/
    }
    if(ifas != NULL) freeifaddrs(ifas);

    //Return the first IPv4 found
    std::string returnAddress = "0.0.0.0";
    if( IPv4list.size() > 0 ) returnAddress = IPv4list.back();

    cout << returnAddress << endl;
}

void testClock() {

	chrono::high_resolution_clock::time_point startTimeStamp = chrono::high_resolution_clock::now();

	int i;
	while(i < 1000000000) {		//takes approx 2.3 seconds on my laptop.
		i++;
	}

	long double total = 0;

	chrono::high_resolution_clock::time_point endTimeStamp = chrono::high_resolution_clock::now();

	chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(endTimeStamp - startTimeStamp);

	total += time_span.count();
	cout << total << endl;



}

int main() {

	testClock();

	return 0;
}

