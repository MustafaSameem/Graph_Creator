#include <iostream>
#include <string>
#include "edge.h"
#include "vertex.h"
using namespace std;

//constructors
Edge::Edge()
{
  weight = 0;
  start = new Vertex();
  end = new Vertex();
}

Edge::Edge(Vertex v1, Vertex v2, int w)
{
  weight = w;
  start = new Vertex(v1.getid(), v1.getvalue());
  end = new Vertex(v2.getid(), v2.getvalue());
}

Edge::Edge(const Edge& edge_obj)
{
  weight = edge_obj.getweight();
  start = new Vertex(edge_obj.getidstart(), edge_obj.getvaluestart());
  end = new Vertex(edge_obj.getidend(), edge_obj.getvalueend());
}

Edge::~Edge()
{
  delete start;
  delete end;
}


//getters
int Edge::getweight() const {return weight;}

int Edge::getidstart() const {return start->getid();}
int Edge::getvaluestart() const {return start->getvalue();}

int Edge::getidend() const {return end->getid();}
int Edge::getvalueend() const {return end->getvalue();}


//setters
void Edge::setEdge(int i1, int v1, int i2, int v2, int w)
{
  weight = w;
  start = new Vertex(i1, v1);
  end = new Vertex(i2, v2);
}

void Edge::setV1(Vertex v1)
{
  start = new Vertex(v1.getid(), v1.getvalue());
}

void Edge::setV2(Vertex v2)
{
  end = new Vertex(v2.getid(), v2.getvalue());
}


void Edge::setweight(int w) {weight = w;}


//print
void Edge::print()
{
  cout << "EDGE CREATED" << endl;
  cout << "weight is: " << weight << endl;
  cout << "start vertex is: (" << getidstart() << "," << getvaluestart() << ")" << endl;
  cout << "end vertex is: (" << getidend() << "," << getvalueend() << ")" << endl;
  cout << "--------------------------------------" << endl;
}
