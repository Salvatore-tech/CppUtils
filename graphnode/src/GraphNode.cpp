//
// Created by saso on 22/01/2022.
//

#include "../include/GraphNode.h"

template
class GraphNode<int>;

template<typename T>
GraphNode<T>::GraphNode(T key) : key(key), nodeStatus(unreachable) {}

template<typename T>
T GraphNode<T>::getKey() const {
    return key;
}

template<typename T>
std::vector<std::weak_ptr<GraphNode<T>>> GraphNode<T>::getEdges() {
    return edges;
}

template<typename T>
std::vector<std::weak_ptr<GraphNode<T>>> *GraphNode<T>::getEdgesPtr() {
    return &edges;
}

template<typename T>
bool GraphNode<T>::addEdge(std::shared_ptr<GraphNode<T>> targetNode) {
    int index = 0;
    if (targetNode.get() == this) // Self loop
        return false;
    for (auto &edge: edges) {
        if (auto tempSharedPtr = edge.lock()) {
            if (tempSharedPtr->getKey() == targetNode->getKey()) {
//                std::cout << "[Duplicate edge] " << getKey() << " already has the edge towards " << targetNode->getKey()
//                          << std::endl;
                return false;
            }
        } else {
            edges.erase(edges.begin() + index); // Erasing an expired weak pointer
        }
        index++;
    }
    edges.push_back(targetNode);
    return true;
}

template<typename T>
bool GraphNode<T>::hasEdge(T keyOfTheEdge) {
    return hasEdge(GraphNode<T>(keyOfTheEdge));
}

template<typename T>
bool GraphNode<T>::hasEdge(const GraphNode<T> &targetNode) {
    for (const auto &edge: edges) {
        if (const auto observe = edge.lock()) {
            if (observe->getKey() == targetNode.getKey())
                return true;
        }
    }
    return false;
}

template<typename T>
GraphNodeStatus GraphNode<T>::getNodeStatus() const {
    return nodeStatus;
}

template<typename T>
void GraphNode<T>::setNodeStatus(GraphNodeStatus nodeStatus) {
    this->nodeStatus = nodeStatus;
}




