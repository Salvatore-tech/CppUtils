//
// Created by saso on 18/02/2022.
//

#include "../include/GraphNodeReachable.h"

template
class GraphNodeReachable<int>;

template<typename T>
GraphNodeReachable<T>::GraphNodeReachable(T key):GraphNode<T>(key) {
    reachable = false;
}

template<typename T>
bool GraphNodeReachable<T>::isReachable() const {
    return reachable;
}

template<typename T>
void GraphNodeReachable<T>::setIsReachable(bool isReachable) {
    GraphNodeReachable::reachable = isReachable;
}
