#include "vertex.h"
#include "edge.h"
#include "abstract.h"
using namespace std;

class undirected_graph: public Graph{

private:
  Vertex **vertex_ptr;
  Edge **edge_ptr;
  int number_of_vertices;
  int number_of_edges;

public:
  undirected_graph();
  virtual ~undirected_graph();

  // Vertex and Edge manipulation
  virtual bool addVertex(Vertex&);
  virtual bool removeVertex (Vertex&);
  virtual bool addEdge(Edge&);
  virtual bool remove(Edge&);
  virtual bool searchVertexValue(const int);
  virtual bool searchEdge(const int);
  virtual void display() const;
  virtual bool clean();
  virtual void displayPathLoop(int, int, bool[], int[], int&);
  virtual void displayPath (int, int);
    
  //operator overlaoding
  friend ostream& operator<<(ostream& output, const undirected_graph &G1 );
};

