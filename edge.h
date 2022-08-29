#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"

class Edge{

private:
  int weight;
  Vertex *start;
  Vertex *end;

public:
  Edge();
  Edge(Vertex, Vertex, int);
  Edge(const Edge&);
  ~Edge();

  int getweight() const;
 
  int getidstart() const;
  int getidend() const;
  int getvaluestart() const;
  int getvalueend() const;

  void setV1(Vertex);
  void setV2(Vertex);
  void setEdge(int,int,int,int,int);
  void setweight(int);

  void print();
};

#endif
