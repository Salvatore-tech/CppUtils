#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <set>
#include <random>

using namespace std;


int main(int argc, char **argv) {
    std::map<int, bool> nodes;
    std::vector<int> vectorOfKeys;
    ofstream outputFile("output_graph.txt");
    srand(time(nullptr));

    if (!outputFile.is_open()) {
        cout << "Error creating the file!\n";
        return -1;
    }

    if (argc != 4) {
        cout << "Usage: ./graphGenerator numberOfNodes numberOfEdges percentageOfConnectedNodes\n";
        return -1;
    }

    int nodeNo = atoi(argv[1]);
    int edgeNo = atoi(argv[2]);
    int percentageOfConnectedNodes = atoi(argv[3]);
    int remainingEdgesToWrite = edgeNo;

    // Write the header to the file
    outputFile << nodeNo << " " << edgeNo << endl;

    vectorOfKeys.reserve(nodeNo);
    int maxValue = 0;
    cout << "Insert the greatest value allowed to generate: ";
    cin >> maxValue;

    std::uniform_int_distribution<int> uniformIntDistribution(1, maxValue);
    std::random_device seed;     // only used once to initialise (seed) engine
    std::mt19937 randomEngine(seed());    // random-number engine used (Mersenne-Twister in this case)


    int sourceNode = 0;

    for (int i = 0; i < nodeNo; i++) { // Generate unique nodes in [1..maxValue]
        int newNode = uniformIntDistribution(randomEngine);

        while (nodes.contains(newNode))
            newNode = uniformIntDistribution(randomEngine);

        nodes.insert(make_pair(newNode, false));
        vectorOfKeys.emplace_back(newNode);
    }

    std::uniform_int_distribution<int> uniformIndexDistribution(0, vectorOfKeys.size() - 1);


    int connectedToSource = std::ceil((float) (nodeNo * percentageOfConnectedNodes) / 100.0);
    for (int i = 0; i < connectedToSource; i++) {
        auto targetNode = nodes.find(vectorOfKeys.at(uniformIndexDistribution(randomEngine)));
        while (targetNode->second)
            targetNode = nodes.find((vectorOfKeys.at(uniformIndexDistribution(randomEngine))));

        outputFile << sourceNode << " " << targetNode->first << endl;
        targetNode->second = true;
        remainingEdgesToWrite--;
    }

    for (auto &sourceNode: nodes) {
        if (!sourceNode.second) {
            auto targetNode = nodes.find(vectorOfKeys.at(uniformIndexDistribution(randomEngine)));
            while (sourceNode.first == targetNode->first)
                targetNode = nodes.find(vectorOfKeys.at(uniformIndexDistribution(randomEngine)));
            outputFile << sourceNode.first << " " << targetNode->first << endl;
            sourceNode.second = true;
            targetNode->second = true;
            remainingEdgesToWrite--;

        }
    }

    while (remainingEdgesToWrite > 0) {
        int sourceNode = vectorOfKeys.at(uniformIndexDistribution(randomEngine));
        int targetNode = vectorOfKeys.at(uniformIndexDistribution(randomEngine));

        while (sourceNode == targetNode)
            sourceNode = vectorOfKeys.at(uniformIndexDistribution(randomEngine));

        outputFile << sourceNode << " " << targetNode << endl;
        remainingEdgesToWrite--;
    }

    return 0;
}
