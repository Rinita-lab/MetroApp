#include <iostream>
#include <list>
#include <unordered_map>
#include <set>
#include <vector>

#include <map>
#include<limits.h>
#include <algorithm>
using namespace std;
class Graph
{
public:
    unordered_map<string, list<pair<string, pair<int, int>>>> adjList;
    set<string> st;
    int edges=0;
    map<string, int> MyMap;

    void addEdge(string u, string v, int dist, int cost)
    {
        adjList[u].push_back({v, {dist, cost}});
        adjList[v].push_back({u, {dist, cost}});
        st.insert(u);
        st.insert(v);
    }
    void printStations(){
        for(auto i:st){
            cout<<i<<endl;
        }
      cout<<endl;
    }
    void nodeMapping(unordered_map<string, list<pair<string, pair<int, int>>>> adjList){

        int count=0;
        for(auto i:adjList){
            MyMap.insert({i.first,count});
            count++;
        }
    }

    void dijkstraValue(string s, string d, int n, int e, unordered_map<string, list<pair<string, pair<int, int>>>> adjList){
      set<pair<int,string>>mySet;
      //vector<int>dist(n, INT_MAX);
      mySet.insert({0,s});
      vector<int> distance(n+1, INT_MAX);
      vector<string>parent(n+1, "");
      distance[MyMap.at(s)]=0;

      while(!mySet.empty()){
        auto it=*(mySet.begin());
        string node=it.second;
        int nodeDist=it.first;
        mySet.erase(it);
        for(auto i:adjList[node]){
          string adjNode=i.first;
          int adjNodeDist=i.second.first;
          //int adjNodeCost=i.second.second;
          if(adjNodeDist+nodeDist<distance[MyMap.at(adjNode)]){
            distance[MyMap.at(adjNode)]=adjNodeDist+nodeDist;
            parent[MyMap.at(adjNode)]=node; 
            mySet.insert({distance[MyMap.at(adjNode)], adjNode});
          }
        }
      }
      if(distance[MyMap.at(d)]==INT_MAX){
        cout<<"No Path Found Between Your Source and Destination"<<endl;
        cout<<endl;
      }
      else{
        cout<<"Shortest Distance Between "<<s<<" and "<<d<<" is: "<<distance[MyMap.at(d)]<<endl;
      }
      cout<<endl;
      cout<<endl;

    }

    void dijkstraCostValue(string s, string d, int n, int e, unordered_map<string, list<pair<string, pair<int, int>>>> adjList){
      set<pair<int,string>>mySet;
      //vector<int>dist(n, INT_MAX);
      mySet.insert({0,s});
      vector<int> distance(n+1, INT_MAX);
      vector<string>parent(n+1, "");
      distance[MyMap.at(s)]=0;

      while(!mySet.empty()){
        auto it=*(mySet.begin());
        string node=it.second;
        int nodeDist=it.first;
        mySet.erase(it);
        for(auto i:adjList[node]){
          string adjNode=i.first;
          //int adjNodeDist=i.second.first;
          int adjNodeCost=i.second.second;
          if(adjNodeCost+nodeDist<distance[MyMap.at(adjNode)]){
            distance[MyMap.at(adjNode)]=adjNodeCost+nodeDist;
            parent[MyMap.at(adjNode)]=node; 
            mySet.insert({distance[MyMap.at(adjNode)], adjNode});
          }
        }
      }
      if(distance[MyMap.at(d)]==INT_MAX){
        cout<<"No Path Found Between Your Source and Destination"<<endl;
        cout<<endl;
      }
      else{
        cout<<"Least Cost To Travel Between "<<s<<" and "<<d<<" is: Rs. "<<distance[MyMap.at(d)]<<endl;
      }
      cout<<endl;
      cout<<endl;



    }

    void dijkstra(string s, string d, int n, int e, unordered_map<string, list<pair<string, pair<int, int>>>> adjList){
      set<pair<int,string>>mySet;
      //vector<int>dist(n, INT_MAX);
      mySet.insert({0,s});
      vector<int> distance(n+1, INT_MAX);
      vector<string>parent(n+1, "");
      distance[MyMap.at(s)]=0;

      while(!mySet.empty()){
        auto it=*(mySet.begin());
        string node=it.second;
        int nodeDist=it.first;
        mySet.erase(it);
        for(auto i:adjList[node]){
          string adjNode=i.first;
          int adjNodeDist=i.second.first;
          //int adjNodeCost=i.second.second;
          if(adjNodeDist+nodeDist<distance[MyMap.at(adjNode)]){
            distance[MyMap.at(adjNode)]=adjNodeDist+nodeDist;
            parent[MyMap.at(adjNode)]=node; 
            mySet.insert({distance[MyMap.at(adjNode)], adjNode});
          }
        }
      }
      if(distance[MyMap.at(d)]==INT_MAX){
        cout<<"No Path Found Between Your Source and Destination"<<endl;
        cout<<endl;
      }
      vector<string>path;
      string temp=d;
      path.push_back(temp);
      while(parent[MyMap.at(temp)]!=""){
        path.push_back(parent[MyMap.at(temp)]);
        temp=parent[MyMap.at(temp)];
      }
      //path.push_back(s);
      reverse(path.begin(), path.end());
      for(auto i:path){
        cout<<i<<" -> ";
      }
      cout<<endl;
      cout<<endl;


    }

    void dijkstraCost(string s, string d, int n, int e, unordered_map<string, list<pair<string, pair<int, int>>>> adjList){
      set<pair<int,string>>mySet;
      //vector<int>dist(n, INT_MAX);
      mySet.insert({0,s});
      vector<int> distance(n+1, INT_MAX);
      vector<string>parent(n+1, "");
      distance[MyMap.at(s)]=0;

      while(!mySet.empty()){
        auto it=*(mySet.begin());
        string node=it.second;
        int nodeDist=it.first;
        mySet.erase(it);
        for(auto i:adjList[node]){
          string adjNode=i.first;
          //int adjNodeDist=i.second.first;
          int adjNodeCost=i.second.second;
          if(adjNodeCost+nodeDist<distance[MyMap.at(adjNode)]){
            distance[MyMap.at(adjNode)]=adjNodeCost+nodeDist;
            parent[MyMap.at(adjNode)]=node; 
            mySet.insert({distance[MyMap.at(adjNode)], adjNode});
          }
        }
      }
      if(distance[MyMap.at(d)]==INT_MAX){
        cout<<"No Path Found Between Your Source and Destination"<<endl;
        cout<<endl;
      }
      vector<string>path;
      string temp=d;
      path.push_back(temp);
      while(parent[MyMap.at(temp)]!=""){
        path.push_back(parent[MyMap.at(temp)]);
        temp=parent[MyMap.at(temp)];
      }
      //path.push_back(s);
      reverse(path.begin(), path.end());
      for(auto i:path){
        cout<<i<<" -> ";
      }
      cout<<endl;
      cout<<endl;


    }

    void shortestValue(string src, string dest){
        int n = st.size();
        int e = edges;
        nodeMapping(adjList);
        dijkstraValue(src,dest,n, e, adjList);
    }
    void shortestCostValue(string src, string dest){
        int n = st.size();
        int e = edges;
        nodeMapping(adjList);
        dijkstraCostValue(src,dest,n, e, adjList);
    }

    void shortestPath(string src, string dest){
        int n = st.size();
        int e = edges;
        nodeMapping(adjList);
        dijkstra(src,dest,n, e, adjList);
    }
    void shortestCostPath(string src, string dest){
      int n = st.size();
      int e = edges;
      nodeMapping(adjList);
      dijkstraCost(src,dest,n, e, adjList);
    }

    void printAdjacencyList(){
        for(auto node: adjList){
            cout<<node.first<<"->";
            for(auto neighbour:node.second){
                cout<<"("<<neighbour.first<<","<<neighbour.second.first<<","<<neighbour.second.second<<"),";
                edges++;
            }
            cout<<endl;
        }
    }
};
int main(){
    Graph g;
    g.addEdge("Dakshineshwar","DumDum",10,5);
    g.addEdge("DumDum","Airport",20,8);
    g.addEdge("DumDum","Esplanade",55,30);
    g.addEdge("Esplanade","ParkStreet",5,2);
    g.addEdge("Airport","ParkStreet",80,45);
    g.addEdge("Airport","NewTown",25,17);
    g.addEdge("ParkStreet","NewTown",33,21);
    g.addEdge("ParkStreet","SectorV",32,20);
    g.addEdge("NewTown","SectorV",8,3);
    g.addEdge("NewTown","Sealdah",39,15);
    g.addEdge("SectorV","Sealdah",43,18);
    cout<<endl;
    //g.printAdjacencyList();
    cout<<endl;
    cout<<endl;
    cout<<"----------Welcome to the Metro App----------"<<endl;
    cout<<"\n***********************************************************\n"<<endl;
    while(true){
      cout<<"--------These are Your list of Actions--------"<<endl;
      cout<<"1. LIST ALL THE STATIONS IN THE MAP"<<endl;
      cout<<"2. GET SHORTEST DISTANCE FROM A 'SOURCE' STATION TO 'DESTINATION' STATION"<<endl;
      cout<<"3. GET LEAST COST TO TRAVEL FROM A 'SOURCE' STATION TO 'DESTINATION' STATION"<<endl;
      cout<<"4. GET SHORTEST PATH (DISTANCE WISE) TO REACH FROM A 'SOURCE' STATION TO 'DESTINATION' STATION"<<endl;
      cout<<"5. GET SHORTEST PATH (COST WISE) TO REACH FROM A 'SOURCE' STATION TO 'DESTINATION' STATION"<<endl;
      cout<<"6. EXIT"<<endl;

      cout<<"ENTER YOUR CHOICE FROM THE ABOVE LIST (1 to 6):";
      int choice;
      cin>>choice;
      cout<<"\n***********************************************************\n"<<endl;
      if(choice==6){
        cout<<"Exiting the App"<<endl;
        //return 0;
        break;
      }
      string src;
      string dest;
      if(choice!=1){
        cout<<"Enter the Source Station:";
        
        cin>>src;
        cout<<"Enter the Destination Station:";
        
        cin>>dest;
        cout<<endl;
        cout<<endl;
      }
      
      switch(choice){

        case 1:
          cout<<"List of Stations in the Map:"<<endl;
          g.printStations();
          cout<<endl<<endl;
          break;

        case 2:

          cout<<"Shortest Distance from a Source Station To Destination Station:"<<endl;
          g.shortestValue(src, dest);
          break;

        case 3:
          cout<<"Least Cost To Travel From a Source Station To Destination Station:"<<endl;
          g.shortestCostValue(src, dest);
          break;

        case 4:
          cout<<"Shortest Path To Reach From Source Station To Destination Station (Distance Wise):"<<endl;
          g.shortestPath(src,dest);
          break;

        case 5:
          cout<<"Shortest Path To Reach From Source Station To Destination Station (Cost Wise):"<<endl;
          g.shortestCostPath(src,dest);
          break;

        default:
          cout<<"Please enter a valid option! "<<endl;
          cout<<"The options you can choose are from 1 to 6. "<<endl;
          cout<<endl;
          cout<<endl;
      }
    }

}