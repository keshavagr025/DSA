#include <istream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

void printItineray(  unordered_map<string, string> tickets){

    //finding starting point

    unordered_set<string> to;

    for(pair<string, string> ticket : tickets){ //from --> to 
        to.insert(ticket.second);
    }

    string start = "";
    for(pair<string, string> ticket : tickets){ //ticket.first --> from
        if(to.find(ticket.first) == to.end()){ // starting point
            start = ticket.first;
        }
    }

    //plan print
    cout << start << "->";
    while(tickets.count(start)){
        cout << tickets[start] << "->";
        start = tickets[start];
    }

    cout << "Destination\n";
}


int main(){
    unordered_map<string, string> tickets;

    tickets["chennai"] = "Bengaluru";
    tickets["Mumbai"] = "Delhi";
    tickets["Goa"] = "chennai";
    tickets["Delhi"] = "Goa";


    printItineray(tickets);
    return 0;
}