//
// Created by Kevinlinpr on 2019/6/26.
//

#ifndef STLLEARN_ADJACENCYLIST_H
#define STLLEARN_ADJACENCYLIST_H

#include "AdjacencyMatrix.h"
typedef struct ArcNode{
    int adjvex;
    struct ArcNode* next;
}ArcNode;
typedef struct VNode{
    VertexType data;
    ArcNode* first;
}VNode,AdjList[MaxVertexNum];
typedef struct{
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;
#endif //STLLEARN_ADJACENCYLIST_H
