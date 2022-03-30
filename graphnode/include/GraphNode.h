//
// Created by saso on 22/01/2022.
//

#ifndef HASHGRAPH_GRAPHNODE_H
#define HASHGRAPH_GRAPHNODE_H

#include <vector>
#include <iostream>
#include <memory>
#include "GraphNodeStatus.h"

template<typename T>
class GraphNode {
public:

    explicit GraphNode(T key);

    T getKey() const;

    std::vector<std::weak_ptr<GraphNode<T>>> getEdges();

    bool hasEdge(T key);

    bool hasEdge(const GraphNode<T> &targetNode);

    bool addEdge(std::shared_ptr<GraphNode<T>> targetNode);

    void eraseEdges() {
        edges.clear();
    }

    GraphNodeStatus getNodeStatus() const;

    void setNodeStatus(GraphNodeStatus nodeStatus);

    bool operator==(GraphNode *rhs) const {
        return key == rhs->key;
    }

    std::vector<std::weak_ptr<GraphNode<T>>> *getEdgesPtr();

private:
    T key;
    std::vector<std::weak_ptr<GraphNode<T>>> edges;
    GraphNodeStatus nodeStatus;
};


#endif //HASHGRAPH_GRAPHNODE_H
