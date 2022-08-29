#ifndef ABSTRACT_H
#define ABSTRACT_H

#include "vertex.h"
#include "edge.h"


class Graph{

public:
  Graph();
  virtual ~Graph();

  virtual bool addVertex(Vertex& v)=0;
  virtual bool removeVertex (Vertex& v)=0;
  virtual bool addEdge(Edge& e)=0;
  virtual bool remove(Edge& e)=0;
  virtual bool searchVertexValue(const int v)=0;
  virtual bool searchEdge(const int e)=0;
  virtual void display() const = 0;
  virtual bool clean() = 0;
  virtual void displayPathLoop(int, int, bool[], int[], int&) =0;
  virtual void displayPath (int, int) =0;
};
#endif
