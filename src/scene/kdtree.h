#pragma once
#include <la.h>
#include <scene/photon.h>

class KDNode
{
public:
    KDNode();
    ~KDNode();

    KDNode* leftChild;
    KDNode* rightChild;
    unsigned int axis; // Which axis split this node represents
    glm::vec3 minCorner, maxCorner; // The world-space bounds of this node
    std::vector<Photon> particles; // A collection of pointers to the particles contained in this node.
};

class KDTree
{
public:
    KDTree();
    ~KDTree();
    void build(const std::vector<Photon> *points);
    void clear();

    void particlesInSphere(glm::vec3 c, float r, std::vector<Photon *> *buffer); // Returns all the points contained within a sphere with center c and radius r

    KDNode* root;
    glm::vec3 minCorner, maxCorner; // For visualization purposes

    //recursor used in building
    KDNode* recursive(int dir,
                      int min,
                      int max,
                      const std::vector<Photon> *points);

    //ADDED ones

    //used to store sorted ID in xyz axis
    std::vector<int> xsorted;
    std::vector<int> ysorted;
    std::vector<int> zsorted;

    //store KD tree
    std::vector<KDNode> tree;

    //Iterate Function for KD-Scearch!
    void scan(std::vector<Photon*>* buffer, KDNode* p, glm::vec3 c, float r);


};
