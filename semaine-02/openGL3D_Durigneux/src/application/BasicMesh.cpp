#include "BasicMesh.h"
#include "ObjLoader.h"
#include <vector>
#include <iostream>

using namespace std;
using namespace p3d;

BasicMesh::~BasicMesh() {
    glDeleteBuffers(1,&_attributeBuffer);
    glDeleteBuffers(1,&_elementBuffer);
}


BasicMesh::BasicMesh() {
    _attributeBuffer=0;
    _elementBuffer=0;
}







void BasicMesh::initTetrahedron() {

    /*
    std::vector<float> position={
        -1,0,-1, // V0
        1,0,-1,  // V1
        0,1,1,  // V2

        -1,0,-1, // V0
        0,1,1,  // V2
        0,-1,1,  // V3

        -1,0,-1, // V0
        1,0,-1,  // V1
        0,-1,1,  // V3

        1,0,-1,  // V1
        0,1,1,  // V2
        0,-1,1  // V3
    };


    std::vector<float>  color={
        1,0,0,
        1,0,0,
        1,0,0,
        0,1,0,
        0,1,0,
        0,1,0,
        0,0,1,
        0,0,1,
        0,0,1,
        0,1,1,
        0,1,1,
        0,1,1
    };

    _element={
        0,1,2,3,4,5,6,7,8,9,10,11
    };




    //q10
    position={
        -20,0,-10, // V0
        10,0,-10,  // V1
        0,10,-30,  // V2
        0,-20,-30  // V3
    };

    color={
        1,0,0, // rouge
        0,1,0, // vert
        0,0,1, // bleu
        0,1,1  // magenta
    };

    // index for 4 triangles
    _element={
        0,1,2,0,2,3,0,1,3,1,2,3
    };


    _attribute.clear();
    for(unsigned int i=0;i<position.size()/3;++i) {

        _attribute.push_back(position[i*3+0]);
        _attribute.push_back(position[i*3+1]);
        _attribute.push_back(position[i*3+2]);



        _attribute.push_back(color[i*3+0]);
        _attribute.push_back(color[i*3+1]);
        _attribute.push_back(color[i*3+2]);

    }
    */
}


void BasicMesh::initObj(const ObjLoader &obj) {
    _attribute.clear();
    _element.clear();

    // initialisation de _attribute :
    // - obj.nbFace() = nombre de triangles
    // - obj.positionVertex(i,j) = position du j-ème sommet dans le i-ème triangle (de type Vector3)
    // - obj.normalVertex(i,j) = normale du j-ème sommet dans le i-ième triangle (de type Vector3)
    for(unsigned int i=0;i<obj.nbFace();++i) {
        for(unsigned int j=0;j<3;++j) {

            // Q17
            Vector3 position = obj.positionVertex(i,j);
            Vector3 normale = obj.normalVertex(i,j);

            _attribute.push_back(position.x());
            _attribute.push_back(position.y());
            _attribute.push_back(position.z());

            //  cout << position.x() << " " << position.y() << " " << position.z() << " " << endl;

            // Q18
            /*
            _attribute.push_back((normale.x()+1.0)/2.0);
            _attribute.push_back((normale.y()+1.0)/2.0);
            _attribute.push_back((normale.z()+1.0)/2.0);
            */

            // Q23
            _attribute.push_back(normale.x());
            _attribute.push_back(normale.y());
            _attribute.push_back(normale.z());
        }
    }


}

void BasicMesh::initBuffer() {
    glGenBuffers(1,&_attributeBuffer);
    glBindBuffer(GL_ARRAY_BUFFER,_attributeBuffer);
    glBufferData(GL_ARRAY_BUFFER,_attribute.size()*sizeof(float),_attribute.data(),GL_STATIC_DRAW);


    glGenBuffers(1,&_elementBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,_elementBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,_element.size()*sizeof(unsigned int),_element.data(),GL_STATIC_DRAW);

}

void BasicMesh::initVAO() {

    glGenVertexArrays(1,&_vao);
    glBindVertexArray(_vao);


    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,_elementBuffer);


    glBindBuffer(GL_ARRAY_BUFFER,_attributeBuffer);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6*sizeof(float),0);


    glBindBuffer(GL_ARRAY_BUFFER,_attributeBuffer);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6 * sizeof(float),(GLvoid*) (3 * sizeof(float)));


    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

}

void BasicMesh::initDraw() {
    initBuffer();
    initVAO();
}


void BasicMesh::draw() {
    glBindVertexArray(_vao);

    //glDrawElements(GL_TRIANGLES,_element.size(),GL_UNSIGNED_INT,(const GLvoid *)(0*sizeof(GLuint)));
    //q17
    glDrawArrays(GL_TRIANGLES,0,_attribute.size()/6);

    glBindVertexArray(0);
}


void BasicMesh::updateBuffer() {

}

