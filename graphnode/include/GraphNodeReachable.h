//
// Created by saso on 18/02/2022.
//

#ifndef GRAPHNODE_GRAPHNODEREACHABLE_H
#define GRAPHNODE_GRAPHNODEREACHABLE_H

#include "GraphNode.h"

template<typename T>
class GraphNodeReachable : public GraphNode<T>{
public:
    GraphNodeReachable(T key);

    bool isReachable() const;

    void setIsReachable(bool isReachable);

private:
    bool reachable;
};




#endif //GRAPHNODE_GRAPHNODEREACHABLE_H
