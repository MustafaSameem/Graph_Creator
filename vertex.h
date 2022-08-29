#ifndef VERTEX_H
#define VERTEX_H


class Vertex{

private:
  int id;
  int value;

public:
  Vertex();
  Vertex(int,int);
  Vertex(const Vertex&);
  ~Vertex();

  int getid() const;
  int getvalue() const;

  void setid(int);
  void setvalue(int);

  void print();
};
#endif
