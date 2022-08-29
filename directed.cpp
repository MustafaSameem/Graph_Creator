#include <iostream>
#include <list>
#include <string>
#include "directed.h"
using namespace std;


directed_graph::directed_graph()
{
  number_of_vertices =0;
  number_of_edges =0;
  vertex_ptr = new Vertex*[40];
  edge_ptr = new Edge*[40];

  for(int i =0; i < 40; i++)
    {
      vertex_ptr[i] = nullptr;
      edge_ptr[i] = nullptr;
    }
}
//destructor
directed_graph::~directed_graph(){}


// modifiers
bool directed_graph::addVertex(Vertex& v) //done
{
  for(int i =0; i < number_of_vertices; i++) // check for duplicate vertex
  {
    if(vertex_ptr[i]->getid() == v.getid())
    {
    cout << "vertex with id: " << v.getid() << " could not be added again because it exists already" << endl;
    return false;
    }
  }

  if(number_of_vertices < 40) // add vertex if no duplicate
  {
    vertex_ptr[number_of_vertices] = new Vertex(v);
    number_of_vertices++;
    
    cout << "Vertex with id: " << v.getid() << " successfully added" << endl;
    return true;
  }
  return false;
}


bool directed_graph::removeVertex(Vertex &v) //done
{
  if(number_of_vertices > 0)
  {
  for(int i=0; i < number_of_vertices; i++)
    {
      if(vertex_ptr[i]->getid() == v.getid())
        {
        for(int j=i; j < number_of_vertices-1; j++)
          {
            vertex_ptr[j] = vertex_ptr[j+1];
          }
          cout << "Vertex with id: " << v.getid() << " successfully removed" << endl;
          number_of_vertices--;
        }
    
        for(int i =0; i < number_of_edges; i++) // removes edge(s) associated to vertex
        {
          if(edge_ptr[i]->getidstart() == v.getid() || edge_ptr[i]->getidend() == v.getid())
          {
            cout << "Edge associated to vertex with weight: " << edge_ptr[i]->getweight() << " successfully removed" << endl;
            for(int j=i; j < number_of_edges-1; j++)
            {
              edge_ptr[j] = edge_ptr[j+1];
            }
            number_of_edges--;
          }
        }
    }
  return true;
  }

  else
  return false;
}


bool directed_graph::addEdge(Edge& e) //done
{
  for(int i =0; i < number_of_edges; i++) // check for duplicate vertex
    {
      if(edge_ptr[i]->getweight() == e.getweight())
      {
      cout << "edge with weight: " << e.getweight() << " could not be added again because it exists already" << endl;
      return false;
      }
    }

  if(number_of_edges < 40)
  {
    edge_ptr[number_of_edges] = new Edge(e);
    number_of_edges++;
    
    cout << "Edge with weight: " << e.getweight() << " successfully added" << endl;
    return true;
  }
  return false;
}


bool directed_graph::remove(Edge &e) //done
{
  for(int i=0; i < number_of_edges; i++)
    {
      if(edge_ptr[i]->getweight() == e.getweight())
      {
        for(int j=i; j < number_of_edges-1; j++)
          {
            edge_ptr[j] = edge_ptr[j+1];
          }
          number_of_edges--;
          cout << "Edge with weight: " << e.getweight() << " successfully removed" << endl;
        return true;
      }
    }
  cout << "|| Cant remove EDGE with weight: " << e.getweight() << " because it does not exist ||" << endl;
  return false;
}


bool directed_graph::searchVertexValue(const int v)
{
  for(int i =0; i < number_of_vertices; i++)
    {
      if(vertex_ptr[i]->getvalue() == v)
      {
        cout << "VERTEX searched with value: " << v << " is present" << endl;
        return true;
      }
    }
  cout << "VERTEX with value: " << v << " is not present" << endl;
  return false;
}


bool directed_graph::searchEdge(const int e) //done
{
  for(int i=0; i < number_of_edges; i++)
    {
      if(edge_ptr[i]->getweight() == e)
      {
        cout << "EDGE searched with weight: " << e << " is present" << endl;
        return true;
      }
    }
  cout << "EDGE with weight: " << e << "is not present" << endl;
  return false;
}


void directed_graph::display() const
{
  cout << "------------------ PRINT-------------------" << endl << "VERTICES: ";
  for(int i =0; i < number_of_vertices; i++)
    {
      cout << "(" << vertex_ptr[i]->getid() << ") ";
    }
  cout << endl << "EDGES: ";
  for(int i =0; i < number_of_edges; i++)
    {
      cout << "[" << edge_ptr[i]->getidstart() << "," << edge_ptr[i]->getidend() << "] ";
    }
    cout << endl << "-------------------------------------" << endl;
}


bool directed_graph::clean()
{
  if(number_of_vertices > 0)
  {
  for(int i =0; i < number_of_vertices; i++)
    {
      vertex_ptr[i] = nullptr;
      number_of_vertices=0;
    }
  for(int i =0; i < number_of_edges; i++)
    {
      edge_ptr[i] = nullptr;
      number_of_edges=0;
    }
    cout << "purge complete" << endl;
    return true;
  }
  
  else
  cout << "graph is empty"  << endl;
  return false;
}


// path algorithm
void directed_graph::displayPath(int start, int end)
{
    bool* visit = new bool[number_of_vertices];
 
    int* path = new int[number_of_vertices];
    int path_counter = 0;
 
    for (int i = 0; i < number_of_vertices; i++)
    visit[i] = 0;
 
    displayPathLoop(start, end, visit, path, path_counter);
}


void directed_graph::displayPathLoop(int start1, int end1, bool visit[], int path[], int& path_counter)
{
  list<int>* adj = new list<int>[number_of_vertices];

  for(int i=0; i < number_of_edges; i++)
    {
      adj[edge_ptr[i]->getidstart()].push_back(edge_ptr[i]->getidend());
    }

    visit[start1] = 1;
    path[path_counter] = start1;
    path_counter++;
 
    if (start1 == end1)
    {
      for (int i = 0; i < path_counter; i++)
        cout << path[i] << " -> ";
        cout << endl;
    }

    else
    {
        list<int>::iterator j;
        for (j = adj[start1].begin(); j != adj[start1].end(); ++j)
            
        if (!visit[*j])
        displayPathLoop(*j, end1, visit, path, path_counter);
    }
    path_counter--;
    visit[start1] = 0;
}
