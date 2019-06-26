//
// Created by Kevinlinpr on 2019/6/26.
//

#ifndef STLLEARN_ADJACENCYMATRIX_H
#define STLLEARN_ADJACENCYMATRIX_H
const int MaxVertexNum = 100;
typedef char VertexType;
typedef int EdgeType;
typedef struct{
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexnum,arcnum;
}AdjacencyMatrixGraphic;
#endif //STLLEARN_ADJACENCYMATRIX_H
