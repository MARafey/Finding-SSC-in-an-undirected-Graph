#include <iostream>  //standard libray for c++ usage
#include<fstream>   //used for file handling
#include<string>
#include"Header.h"
using namespace std;

int main()
{

     long max_size = 0;

     int number1, number2;  //reading the numbers from text file

     int max = 0;  //finding the largest number within the text file

     node_0<int>* data = new node_0<int>; //saving the data from file into queue for further use

     fstream file;

     file.open("web-Google.txt");


     if (file.is_open())
     {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
          cout << "[TEXT FILE HAS BEEN OPENED]\n";
          cout << "[NODES BEING TAKEN FROM FILE] : ";
          while (file >> number1, file >> number2) {

               //finding the maximum number with the text file by comparison
               if (max < number1)
               {
                    max = number1;
               }
               if (max < number2)
               {
                    max = number2;
               }
               //pushing each node recived from text file into the stack
               insert(data, number1, number2);
          }
          file.close();
          cout << "[NODES HHAVE BEEN REMOVED AND FILE IS CLOSED] \n";


          cout << "[GRAPH IS BEING CREATED] : ";
           SLink_List<int>* graph = creating_graph(data, max);
          //  cout << "-----------------------" << endl;
          cout << "[GRAPH CREATHED USING AGENTCY LIST]  \n";
         
          // display_Graph(reverse_graph, max);
          bool* already_visited = new bool[max + 1] {false};
          stack<int>* to_be_retuned = new stack<int>;

          cout << "[DEPTH FIRST SEATCH HAS BEGUN] : ";
          for (int i = 0; i < max+1   ; i++)
          {
               if (already_visited[i] == false)
               {
                    Depth_first_Search(i, max, graph, already_visited, to_be_retuned);
               }
          }
          cout << "[DEPTH FIRST SEATCH ENDED] \n";
          int SCC = 0;

          cout << "[GRAPH IS BEING REVERSED] : ";
          SLink_List<int>* reverse_graph = reverse_of_graph(graph, max);
          cout << "[GRAPH HAS BEEN REVERSE] \n";

          bool* rev_visited = new bool[max + 1] {false};

          cout << "[STRONGLY CONNECTED COMPONENTS ARE BEING CALCULATED] : \n";
          while (!to_be_retuned->empty())
          {
               long temp_size = 0;
               int temp = to_be_retuned->top();
               to_be_retuned->pop();
               if (!rev_visited[temp])
               {
                    SCC++;
                    revDFS(temp, max, reverse_graph, rev_visited,temp_size);
                    if (temp_size > max_size)
                    {
                         max_size = temp_size;
                    }
               }
          }
          cout << "The total number of Strongly Connected Components are : " << SCC << endl;
          cout << "The size of Largest SCC : " << max_size << endl;
          cout << "[PROGRAM HAS ENDED] : \n";


         // system("pause");
     }
}