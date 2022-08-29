#include <iostream>
#include <list>
#include <string>
#include "vertex.h"
#include "edge.h"
#include "abstract.h"
#include "undirected.h"
#include "directed.h"
using namespace std;


//INTERACTIVE MAIN
int main()
{

string graph;
cout << "choose your type of graph (directed/undirected): ";
cin >> graph;




if(graph == "undirected")
{
int vertices_loop;
int vertex_count =0;
int edge_count =0;

Vertex *vertex_ptr = new Vertex[40];
Edge *edge_ptr = new Edge[40];
undirected_graph *und_graph_ptr = new undirected_graph();



for(int i=0; i < 100; i++)
{
  int choice;
  cout << "Select what you would like to do" << endl;
  cout << "[1] : add vertices" << endl;
  cout << "[2] : add edge" << endl;
  cout << "[3] : remove vertex" << endl;
  cout << "[4] : remove edge" << endl;
  cout << "[5] : search edge" << endl;
  cout << "[6] : search vertex value" << endl;
  cout << "[7] : display graph" << endl;
  cout << "[8] : display path given a starting and end vertex" << endl;
  cout << "[9] : purge everything" << endl;
  cout << "[10] : display graph with OPERATOR OVERLOADING" << endl;
  cout << "[11] : terminate program" << endl;
  cin >> choice;


  switch(choice){

    case 1:
      cout << "---------- VERTEX INITIALIZER STEP ----------" << endl;
      cout << "How many vertices would you like to add in your graph: ";
      cin >>  vertices_loop;
      cout << endl;


      for(int i =0; i < vertices_loop; i++)
      {
        int id, value;
        cout << "for vertex #" << vertex_count << " enter ID: ";
        cin >> id;
        cout << "for vertex #" << vertex_count << " enter value: ";
        cin >> value;
     
        vertex_ptr[vertex_count].setid(id);
        vertex_ptr[vertex_count].setvalue(value);
        if(und_graph_ptr->addVertex(vertex_ptr[vertex_count]) == true)
        {
          cout << endl;
          vertex_count++;
        }
      }
      und_graph_ptr->display();
      cout << endl << endl;
      break;

    

    case 2:

      if(vertex_count > 1)
      {
        int id1, id2, weight;
  
        cout << "---------- EDGE INITIALIZER STEP ----------" << endl;
        cout << "Enter weight: ";
        cin >> weight;
        edge_ptr[edge_count].setweight(weight);
        
        cout << "Enter the ID of the starting Vertex:  " ;
        cin >> id1;
        cout << "Enter the ID of the ending Vertex:  " ;
        cin >> id2;

        for(int i =0; i < vertex_count; i++) // set start vertex
        {
          if(vertex_ptr[i].getid() == id1)
          edge_ptr[edge_count].setV1(vertex_ptr[i]);
        }
        for(int i =0; i < vertex_count; i++) // set end vertex
        {
          if(vertex_ptr[i].getid() == id2)
          edge_ptr[edge_count].setV2(vertex_ptr[i]);
        }
  
        if (und_graph_ptr->addEdge(edge_ptr[edge_count]) == true) // increase edge counter
        {
          edge_count++;
        }

        und_graph_ptr->display();
        cout << endl << endl;
      }
    break;



    case 3:
      int id_rmv;

      cout << "---------- VERTEX REMOVAL STEP ----------" << endl;
      cout << "Enter the ID of the Vertex you would like to remove:  " ;
      cin >> id_rmv;

      for(int i =0; i < vertex_count; i++)
      {
        if(vertex_ptr[i].getid() == id_rmv)
        {
          und_graph_ptr->removeVertex(vertex_ptr[i]);
          for(int j =i; j < vertex_count-1; j++)
          {
            vertex_ptr[j] = vertex_ptr[j+1];
          }
          vertex_count--;
          
          und_graph_ptr->display();
          cout << endl << endl;
        }
      }
    break;
  
   

    case 4:
      int weight_rmv;

      cout << "---------- EDGE REMOVAL STEP ----------" << endl;
      cout << "Enter the WEIGHT of the EDGE you would like to remove:  " ;
      cin >> weight_rmv;

      for(int i =0; i < edge_count; i++)
      {
        if(edge_ptr[i].getweight() == weight_rmv)
        {
          und_graph_ptr->remove(edge_ptr[i]);
          for(int j =i; j < edge_count-1; j++)
          {
            edge_ptr[j] = edge_ptr[j+1];
          }
          edge_count--;
          
          und_graph_ptr->display();
          cout << endl << endl;
        }
      }
    break;



    case 5:
      int weight_search;

      cout << "---------- EDGE SEARCH ----------" << endl;
      cout << "Enter the WEIGHT of the EDGE you would like to search:  " ;
      cin >> weight_search;

      und_graph_ptr->searchEdge(weight_search);
      cout << endl << endl;
    break;



    case 6:
      int value_search;

      cout << "---------- VALUE SEARCH ----------" << endl;
      cout << "Enter the VALUE you would like to search:  " ;
      cin >> value_search;

      und_graph_ptr->searchVertexValue(value_search);
      cout << endl << endl;
    break;



    case 7:
      und_graph_ptr->display();
    break;



    case 8:
      int start, end;

      cout << "---------- PATH ----------" << endl;
      cout << "Enter VERTEX ID you would like to start the path from: ";
      cin >> start;

      cout << "Enter VERTEX ID you would like to end the path at: ";
      cin >> end;

      und_graph_ptr->displayPath(start, end);
      cout << endl << endl;
    break;



    case 9:
      und_graph_ptr->clean();
    break;


    case 10:
      cout << *und_graph_ptr;
    break;
          
          
          
    case 11:
      cout << "PROGRAM TERMINATED" << endl;
      exit(1);
    break;



    default:
    cout << "INVALID CHOICE" << endl << endl;
  }
}
}


//--------------------------------------------------------------------------
    if(graph == "directed")
    {
    int vertices_loop;
    int vertex_count =0;
    int edge_count =0;

    Vertex *vertex_ptr = new Vertex[40];
    Edge *edge_ptr = new Edge[40];
    directed_graph *graph_ptr = new directed_graph();



    for(int i=0; i < 100; i++)
    {
      int choice;
      cout << "Select what you would like to do" << endl;
      cout << "[1] : add vertices" << endl;
      cout << "[2] : add edge" << endl;
      cout << "[3] : remove vertex" << endl;
      cout << "[4] : remove edge" << endl;
      cout << "[5] : search edge" << endl;
      cout << "[6] : search vertex value" << endl;
      cout << "[7] : display graph" << endl;
      cout << "[8] : display path given a starting and end vertex" << endl;
      cout << "[9] : purge everything" << endl;
      cout << "[10] : terminate program" << endl;
      cin >> choice;


      switch(choice){

        case 1:
          cout << "---------- VERTEX INITIALIZER STEP ----------" << endl;
          cout << "How many vertices would you like to add in your graph: ";
          cin >>  vertices_loop;
          cout << endl;


          for(int i =0; i < vertices_loop; i++)
          {
            int id, value;
            cout << "for vertex #" << vertex_count << " enter ID: ";
            cin >> id;
            cout << "for vertex #" << vertex_count << " enter value: ";
            cin >> value;
         
            vertex_ptr[vertex_count].setid(id);
            vertex_ptr[vertex_count].setvalue(value);
            if(graph_ptr->addVertex(vertex_ptr[vertex_count]) == true)
            {
              cout << endl;
              vertex_count++;
            }
          }
          graph_ptr->display();
          cout << endl << endl;
          break;

        

        case 2:

          if(vertex_count > 1)
          {
            int id1, id2, weight;
      
            cout << "---------- EDGE INITIALIZER STEP ----------" << endl;
            cout << "Enter weight: ";
            cin >> weight;
            edge_ptr[edge_count].setweight(weight);
            
            cout << "Enter the ID of the starting Vertex:  " ;
            cin >> id1;
            cout << "Enter the ID of the ending Vertex:  " ;
            cin >> id2;

            for(int i =0; i < vertex_count; i++) // set start vertex
            {
              if(vertex_ptr[i].getid() == id1)
              edge_ptr[edge_count].setV1(vertex_ptr[i]);
            }
            for(int i =0; i < vertex_count; i++) // set end vertex
            {
              if(vertex_ptr[i].getid() == id2)
              edge_ptr[edge_count].setV2(vertex_ptr[i]);
            }
      
            if (graph_ptr->addEdge(edge_ptr[edge_count]) == true) // increase edge counter
            {
              edge_count++;
            }

            graph_ptr->display();
            cout << endl << endl;
          }
        break;



        case 3:
          int id_rmv;

          cout << "---------- VERTEX REMOVAL STEP ----------" << endl;
          cout << "Enter the ID of the Vertex you would like to remove:  " ;
          cin >> id_rmv;

          for(int i =0; i < vertex_count; i++)
          {
            if(vertex_ptr[i].getid() == id_rmv)
            {
              graph_ptr->removeVertex(vertex_ptr[i]);
              for(int j =i; j < vertex_count-1; j++)
              {
                vertex_ptr[j] = vertex_ptr[j+1];
              }
              vertex_count--;
              
              graph_ptr->display();
              cout << endl << endl;
            }
          }
        break;
      
       

        case 4:
          int weight_rmv;

          cout << "---------- EDGE REMOVAL STEP ----------" << endl;
          cout << "Enter the WEIGHT of the EDGE you would like to remove:  " ;
          cin >> weight_rmv;

          for(int i =0; i < edge_count; i++)
          {
            if(edge_ptr[i].getweight() == weight_rmv)
            {
              graph_ptr->remove(edge_ptr[i]);
              for(int j =i; j < edge_count-1; j++)
              {
                edge_ptr[j] = edge_ptr[j+1];
              }
              edge_count--;
              
              graph_ptr->display();
              cout << endl << endl;
            }
          }
        break;



        case 5:
          int weight_search;

          cout << "---------- EDGE SEARCH ----------" << endl;
          cout << "Enter the WEIGHT of the EDGE you would like to search:  " ;
          cin >> weight_search;

          graph_ptr->searchEdge(weight_search);
          cout << endl << endl;
        break;



        case 6:
          int value_search;

          cout << "---------- VALUE SEARCH ----------" << endl;
          cout << "Enter the VALUE you would like to search:  " ;
          cin >> value_search;

          graph_ptr->searchVertexValue(value_search);
          cout << endl << endl;
        break;



        case 7:
          graph_ptr->display();
        break;



        case 8:
          int start, end;

          cout << "---------- PATH ----------" << endl;
          cout << "Enter VERTEX ID you would like to start the path from: ";
          cin >> start;

          cout << "Enter VERTEX ID you would like to end the path at: ";
          cin >> end;

          graph_ptr->displayPath(start, end);
          cout << endl << endl;
        break;



        case 9:
          graph_ptr->clean();
        break;



        case 10:
          cout << "PROGRAM TERMINATED" << endl;
          exit(1);
        break;



        default:
        cout << "INVALID CHOICE" << endl << endl;
      }
    }
    }

    
else
    cout << "Enter (directed or undirected) and run program again" << endl;
    


    
// ALTERNATIVE MAIN STATIC
/*
int main()
{

//create vertices
  Vertex *ptr0 = new Vertex(0, 100);
  Vertex *ptr1 = new Vertex(1, 200);
  Vertex *ptr2 = new Vertex(2, 300);
  Vertex *ptr3 = new Vertex(3, 400);
  cout << "------------------------------- RUN ALL FUNCTIONS -------------------------------" << endl;


//create edges
  Edge *edgeptr1 = new Edge(*ptr1, *ptr3, 111);
  Edge *edgeptr2 = new Edge(*ptr2, *ptr1, 222);
  Edge *edgeptr3 = new Edge(*ptr1, *ptr2, 333);
  Edge *edgeptr4 = new Edge(*ptr0, *ptr1, 444);
  Edge *edgeptr5 = new Edge(*ptr0, *ptr3, 555);
  Edge *edgeptr6 = new Edge(*ptr2, *ptr3, 666);
  cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

  
//create graph object
  undirected_graph *graphptr1 = new undirected_graph();

//add vertices
  cout << endl << "++++++++++++++++++++++++" << endl;
  cout << "ADD VERTICES " << endl;
  graphptr1->addVertex(*ptr0);
  graphptr1->addVertex(*ptr1);
  graphptr1->addVertex(*ptr2);
  graphptr1->addVertex(*ptr3);

// add edges
  cout << endl << "++++++++++++++++++++++++" << endl;
  cout << "ADD EDGES " << endl;
  graphptr1->addEdge(*edgeptr1);
  graphptr1->addEdge(*edgeptr2);
  graphptr1->addEdge(*edgeptr3);
  graphptr1->addEdge(*edgeptr4);
  graphptr1->addEdge(*edgeptr5);
  graphptr1->addEdge(*edgeptr6);
  
//display
  cout << endl;
  graphptr1->display();
  cout << endl;
  
  graphptr1->displayPath(0,3);
  graphptr1->remove(*edgeptr1);
  graphptr1->displayPath(0,3);


return 0;
}
*/
    
return 0;
}
