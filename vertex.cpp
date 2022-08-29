#include <iostream>
#include <string>
#include "vertex.h"
using namespace std;


//constructors
Vertex::Vertex()
{
  id = 0;
  value = 0;
}

Vertex::Vertex(int i, int v)
{
  id = i;
  value = v;
}

Vertex::Vertex(const Vertex& vertex_obj)
{
  id = vertex_obj.getid();
  value = vertex_obj.getvalue();
}

Vertex::~Vertex(){}


//getters
int Vertex::getid() const {return id;}
int Vertex::getvalue() const {return value;}


//setters
void Vertex::setid(int i) {id =i;}
void Vertex::setvalue(int v) {value =v;}


//print
void Vertex::print()
{
  cout << "VERTEX CREATED" << endl;
  cout << "vertex id is: " << id << endl;
  cout << "vertex value is: " << value << endl;
  cout << "----------------------------" << endl;
}



