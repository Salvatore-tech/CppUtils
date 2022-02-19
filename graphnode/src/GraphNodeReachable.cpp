//
// Created by saso on 18/02/2022.
//

#include "../include/GraphNodeReachable.h"

template
class GraphNodeReachable<int>;

template<typename T>
GraphNodeReachable<T>::GraphNodeReachable(T key):GraphNode<T>(key) {
    isReachable = false;
}

template<typename T>
bool GraphNodeReachable<T>::isReachable1() const {
    return isReachable;
}

template<typename T>
void GraphNodeReachable<T>::setIsReachable(bool isReachable) {
    GraphNodeReachable::isReachable = isReachable;
}
