// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

// *****************************************************************************
// <ProjectName> ENigMA </ProjectName>
// <Description> Extended Numerical Multiphysics Analysis </Description>
// <HeadURL> $HeadURL$ </HeadURL>
// <LastChangedDate> $LastChangedDate$ </LastChangedDate>
// <LastChangedRevision> $LastChangedRevision$ </LastChangedRevision>
// <Author> Billy Araujo </Author>
// *****************************************************************************

#include "gtest/gtest.h"

#include "TypeDef.hpp"

#include "MshTriangleMesher.hpp"
#include "PdeField.hpp"
#include "PosGmsh.hpp"

using namespace ENigMA::mesh;
using namespace ENigMA::post;
using namespace ENigMA::pde;

class CTestMshTriangleMesher : public ::testing::Test {
protected:

    virtual void SetUp() {

    }

    virtual void TearDown() {

    }

};

TEST_F(CTestMshTriangleMesher, mesh1) {

    CMshMesh<decimal> anEdgeMesh;

    CMshNode<decimal> aNode1;
    CMshNode<decimal> aNode2;
    CMshNode<decimal> aNode3;
    CMshNode<decimal> aNode4;
    CMshNode<decimal> aNode5;
    CMshNode<decimal> aNode6;
    CMshNode<decimal> aNode7;
    CMshNode<decimal> aNode8;

    aNode1 << 2.0270543283699989, 1.3490401401130008, 0;
    aNode2 << 2.0270543283699989, 2.6634868158110017, 0;
    aNode3 << 1.3698309905200003, 2.0062634779620012, 0;
    aNode4 << 2.6842776662166674, 2.0062634779620012, 0;
    aNode5 << 2.0270543284199927, 3.8490399419350005, 0;
    aNode6 << 2.0270543251100004, 0.16347718345100049, 0;
    aNode7 << 3.8698309905200001, 2.0062634779619994, 0;
    aNode8 << 0.18427766621999805, 2.0062634779619994, 0;

    anEdgeMesh.addNode(1, aNode1);
    anEdgeMesh.addNode(2, aNode2);
    anEdgeMesh.addNode(3, aNode3);
    anEdgeMesh.addNode(4, aNode4);
    anEdgeMesh.addNode(5, aNode5);
    anEdgeMesh.addNode(6, aNode6);
    anEdgeMesh.addNode(7, aNode7);
    anEdgeMesh.addNode(8, aNode8);

    CMshElement<decimal> anElement1(ET_BEAM);
    CMshElement<decimal> anElement2(ET_BEAM);
    CMshElement<decimal> anElement3(ET_BEAM);
    CMshElement<decimal> anElement4(ET_BEAM);
    CMshElement<decimal> anElement5(ET_BEAM);
    CMshElement<decimal> anElement6(ET_BEAM);
    CMshElement<decimal> anElement7(ET_BEAM);
    CMshElement<decimal> anElement8(ET_BEAM);

    // 1 1 0 1 3
    anElement1.addNodeId(1);
    anElement1.addNodeId(3);

    // 2 1 0 3 2
    anElement2.addNodeId(3);
    anElement2.addNodeId(2);

    // 3 1 0 2 4
    anElement3.addNodeId(2);
    anElement3.addNodeId(4);

    // 4 1 0 4 1
    anElement4.addNodeId(4);
    anElement4.addNodeId(1);

    // 5 1 0 7 5
    anElement5.addNodeId(7);
    anElement5.addNodeId(5);

    // 6 1 0 6 7
    anElement6.addNodeId(6);
    anElement6.addNodeId(7);

    // 7 1 0 8 6
    anElement7.addNodeId(8);
    anElement7.addNodeId(6);

    // 8 1 0 5 8
    anElement8.addNodeId(5);
    anElement8.addNodeId(8);

    anEdgeMesh.addElement(1, anElement1);
    anEdgeMesh.addElement(2, anElement2);
    anEdgeMesh.addElement(3, anElement3);
    anEdgeMesh.addElement(4, anElement4);
    anEdgeMesh.addElement(5, anElement5);
    anEdgeMesh.addElement(6, anElement6);
    anEdgeMesh.addElement(7, anElement7);
    anEdgeMesh.addElement(8, anElement8);

    EXPECT_EQ(8, anEdgeMesh.nbElements());

    CMshTriangleMesher<decimal> aTriangleMesher;
    std::vector<CGeoCoordinate<decimal>> sInteriorPoints;

    anEdgeMesh.generateFaces(1E-3);
    aTriangleMesher.remesh(anEdgeMesh, 1.0);
    
    aTriangleMesher.generate(anEdgeMesh, 99, sInteriorPoints, 1.0, 0.1, 10.0, 1E-3);

    CMshMesh<decimal> aSurfaceMesh;
    aSurfaceMesh = aTriangleMesher.mesh();

    CPdeField<decimal> T;
    CPosGmsh<decimal> aPosGmsh;

    T.setMesh(anEdgeMesh);
    aPosGmsh.save(T, "tri_edge1.msh", "beams");

    T.setMesh(aSurfaceMesh);
    aPosGmsh.save(T, "tri_surface1.msh", "tris");

    EXPECT_EQ(16, anEdgeMesh.nbElements());
    EXPECT_EQ(16, aSurfaceMesh.nbElements());

}

TEST_F(CTestMshTriangleMesher, mesh2) {

    CMshMesh<decimal> anEdgeMesh;

    CMshNode<decimal> aNode1;
    aNode1 << 0.0, 0.0, 0.0;
    anEdgeMesh.addNode(0, aNode1);

    CMshNode<decimal> aNode2;
    aNode2 << 1.0, 0.0, 0.0;
    anEdgeMesh.addNode(1, aNode2);

    CMshNode<decimal> aNode3;
    aNode3 << 1.0, 1.0, 0.0;
    anEdgeMesh.addNode(2, aNode3);

    CMshNode<decimal> aNode4;
    aNode4 << 0.0, 1.0, 0.0;
    anEdgeMesh.addNode(3, aNode4);

    CMshElement<decimal> anElement1(ET_BEAM);
    anElement1.addNodeId(0);
    anElement1.addNodeId(1);
    anEdgeMesh.addElement(0, anElement1);

    CMshElement<decimal> anElement2(ET_BEAM);
    anElement2.addNodeId(1);
    anElement2.addNodeId(2);
    anEdgeMesh.addElement(1, anElement2);

    CMshElement<decimal> anElement3(ET_BEAM);
    anElement3.addNodeId(2);
    anElement3.addNodeId(3);
    anEdgeMesh.addElement(2, anElement3);

    CMshElement<decimal> anElement4(ET_BEAM);
    anElement4.addNodeId(3);
    anElement4.addNodeId(0);
    anEdgeMesh.addElement(3, anElement4);

    EXPECT_EQ(4, anEdgeMesh.nbElements());

    CMshTriangleMesher<decimal> aTriangleMesher;
    std::vector<CGeoCoordinate<decimal>> sInteriorPoints;

    anEdgeMesh.generateFaces(1E-3);
    aTriangleMesher.remesh(anEdgeMesh, 0.1);

    CPdeField<decimal> T;
    CPosGmsh<decimal> aPosGmsh;

    T.setMesh(anEdgeMesh);
    aPosGmsh.save(T, "tri_edge2.msh", "beams");

    aTriangleMesher.generate(anEdgeMesh, 999, sInteriorPoints, 0.1, 0.01, 1.0, 1E-3);

    EXPECT_EQ(40, anEdgeMesh.nbElements());

    CMshMesh<decimal> aSurfaceMesh;
    aSurfaceMesh = aTriangleMesher.mesh();

    T.setMesh(aSurfaceMesh);
    aPosGmsh.save(T, "tri_surface2.msh", "tris");

    EXPECT_EQ(262, aSurfaceMesh.nbElements());

}

TEST_F(CTestMshTriangleMesher, mesh3) {

    CMshMesh<decimal> anEdgeMesh;

    CMshNode<decimal> aNode1;
    aNode1 << 0.0, 0.0, 0.0;
    anEdgeMesh.addNode(0, aNode1);

    CMshNode<decimal> aNode2;
    aNode2 << 1.0, 0.0, 0.0;
    anEdgeMesh.addNode(1, aNode2);

    CMshNode<decimal> aNode3;
    aNode3 << 1.0, 1.0, 0.0;
    anEdgeMesh.addNode(2, aNode3);

    CMshNode<decimal> aNode4;
    aNode4 << 0.0, 1.0, 0.0;
    anEdgeMesh.addNode(3, aNode4);

    CMshNode<decimal> aNode5;
    aNode5 << 0.3, 0.3, 0.0;
    anEdgeMesh.addNode(4, aNode5);

    CMshNode<decimal> aNode6;
    aNode6 << 0.3, 0.6, 0.0;
    anEdgeMesh.addNode(5, aNode6);

    CMshNode<decimal> aNode7;
    aNode7 << 0.6, 0.6, 0.0;
    anEdgeMesh.addNode(6, aNode7);

    CMshNode<decimal> aNode8;
    aNode8 << 0.6, 0.3, 0.0;
    anEdgeMesh.addNode(7, aNode8);

    CMshElement<decimal> anElement1(ET_BEAM);
    anElement1.addNodeId(0);
    anElement1.addNodeId(1);
    anEdgeMesh.addElement(0, anElement1);

    CMshElement<decimal> anElement2(ET_BEAM);
    anElement2.addNodeId(1);
    anElement2.addNodeId(2);
    anEdgeMesh.addElement(1, anElement2);

    CMshElement<decimal> anElement3(ET_BEAM);
    anElement3.addNodeId(2);
    anElement3.addNodeId(3);
    anEdgeMesh.addElement(2, anElement3);

    CMshElement<decimal> anElement4(ET_BEAM);
    anElement4.addNodeId(3);
    anElement4.addNodeId(0);
    anEdgeMesh.addElement(3, anElement4);

    CMshElement<decimal> anElement5(ET_BEAM);
    anElement5.addNodeId(4);
    anElement5.addNodeId(5);
    anEdgeMesh.addElement(4, anElement5);

    CMshElement<decimal> anElement6(ET_BEAM);
    anElement6.addNodeId(5);
    anElement6.addNodeId(6);
    anEdgeMesh.addElement(5, anElement6);

    CMshElement<decimal> anElement7(ET_BEAM);
    anElement7.addNodeId(6);
    anElement7.addNodeId(7);
    anEdgeMesh.addElement(6, anElement7);

    CMshElement<decimal> anElement8(ET_BEAM);
    anElement8.addNodeId(7);
    anElement8.addNodeId(4);
    anEdgeMesh.addElement(7, anElement8);

    EXPECT_EQ(8, anEdgeMesh.nbElements());

    CMshTriangleMesher<decimal> aTriangleMesher;
    std::vector<CGeoCoordinate<decimal>> sInteriorPoints;

    anEdgeMesh.generateFaces(1E-3);
    aTriangleMesher.remesh(anEdgeMesh, 0.1);

    CPdeField<decimal> T;
    CPosGmsh<decimal> aPosGmsh;

    T.setMesh(anEdgeMesh);
    aPosGmsh.save(T, "tri_edge3.msh", "beams");

    aTriangleMesher.generate(anEdgeMesh, 999, sInteriorPoints, 0.1, 0.01, 10.0, 1E-3);

    EXPECT_EQ(52, anEdgeMesh.nbElements());

    CMshMesh<decimal> aSurfaceMesh;
    aSurfaceMesh = aTriangleMesher.mesh();

    T.setMesh(aSurfaceMesh);
    aPosGmsh.save(T, "tri_surface3.msh", "tris");

    EXPECT_EQ(238, aSurfaceMesh.nbElements());

}

TEST_F(CTestMshTriangleMesher, mesh4) {

    CMshMesh<decimal> anEdgeMesh;

    CMshNode<decimal> aNode1;
    CMshNode<decimal> aNode2;
    CMshNode<decimal> aNode3;
    CMshNode<decimal> aNode4;
    CMshNode<decimal> aNode5;
    CMshNode<decimal> aNode6;

    aNode1 << 0.0387116, 0, 0;
    aNode2 << 0.0387116, 0.203556, 0;
    aNode3 << 0.0387116, 0.101778, 0;
    aNode4 << 0.000482906, 0.203556, 0;
    aNode5 << -2.09856e-021, -7.06226e-019, 0;
    aNode6 << 0.000250622, 0.101778, 0;

    anEdgeMesh.addNode(1, aNode1);
    anEdgeMesh.addNode(2, aNode2);
    anEdgeMesh.addNode(3, aNode3);
    anEdgeMesh.addNode(4, aNode4);
    anEdgeMesh.addNode(5, aNode5);
    anEdgeMesh.addNode(6, aNode6);

    CMshElement<decimal> anElement1(ET_BEAM);
    CMshElement<decimal> anElement2(ET_BEAM);
    CMshElement<decimal> anElement3(ET_BEAM);
    CMshElement<decimal> anElement4(ET_BEAM);
    CMshElement<decimal> anElement5(ET_BEAM);
    CMshElement<decimal> anElement6(ET_BEAM);

    anElement1.addNodeId(1);
    anElement1.addNodeId(3);
    anEdgeMesh.addElement(1, anElement1);

    anElement2.addNodeId(3);
    anElement2.addNodeId(2);
    anEdgeMesh.addElement(2, anElement2);

    anElement3.addNodeId(2);
    anElement3.addNodeId(4);
    anEdgeMesh.addElement(3, anElement3);

    anElement4.addNodeId(4);
    anElement4.addNodeId(6);
    anEdgeMesh.addElement(4, anElement4);

    anElement5.addNodeId(6);
    anElement5.addNodeId(5);
    anEdgeMesh.addElement(5, anElement5);

    anElement6.addNodeId(5);
    anElement6.addNodeId(1);
    anEdgeMesh.addElement(6, anElement6);

    EXPECT_EQ(6, anEdgeMesh.nbElements());

    CMshTriangleMesher<decimal> aTriangleMesher;
    std::vector<CGeoCoordinate<decimal>> sInteriorPoints;

    anEdgeMesh.generateFaces(1E-3);
    aTriangleMesher.remesh(anEdgeMesh, 2.0);

    CPdeField<decimal> T;
    CPosGmsh<decimal> aPosGmsh;

    T.setMesh(anEdgeMesh);
    aPosGmsh.save(T, "tri_edge4.msh", "beams");

    aTriangleMesher.generate(anEdgeMesh, 99, sInteriorPoints, 2.0, 0.1, 10.0, 1E-3);

    EXPECT_EQ(6, anEdgeMesh.nbElements());

    CMshMesh<decimal> aSurfaceMesh;
    aSurfaceMesh = aTriangleMesher.mesh();

    aTriangleMesher.flipEdges(aSurfaceMesh);
    aTriangleMesher.relaxNodes(aSurfaceMesh);

    T.setMesh(aSurfaceMesh);
    aPosGmsh.save(T, "tri_surface4.msh", "tris");

    EXPECT_EQ(4, aSurfaceMesh.nbElements());

}

TEST_F(CTestMshTriangleMesher, mesh5) {

    CMshMesh<decimal> anEdgeMesh;

    CMshNode<decimal> aNode1(0, 0, 0);
    CMshNode<decimal> aNode2(100, 0, 0);
    CMshNode<decimal> aNode3(100, 100, 0);
    CMshNode<decimal> aNode4(0, 100, 0);
    CMshNode<decimal> aNode5(10, 0, 0);
    CMshNode<decimal> aNode6(28, 40, 0);
    CMshNode<decimal> aNode7(28, 0, 0);
    CMshNode<decimal> aNode8(40, 0, 0);
    CMshNode<decimal> aNode9(58, 52, 0);
    CMshNode<decimal> aNode10(58, 0, 0);
    CMshNode<decimal> aNode11(50, 88, 0);
    CMshNode<decimal> aNode12(79, 65, 0);

    anEdgeMesh.addNode(1, aNode1);
    anEdgeMesh.addNode(2, aNode2);
    anEdgeMesh.addNode(3, aNode3);
    anEdgeMesh.addNode(4, aNode4);
    anEdgeMesh.addNode(5, aNode5);
    anEdgeMesh.addNode(6, aNode6);
    anEdgeMesh.addNode(7, aNode7);
    anEdgeMesh.addNode(8, aNode8);
    anEdgeMesh.addNode(9, aNode9);
    anEdgeMesh.addNode(10, aNode10);
    anEdgeMesh.addNode(11, aNode11);
    anEdgeMesh.addNode(12, aNode12);

    CMshElement<decimal> anElement1(ET_BEAM);
    CMshElement<decimal> anElement2(ET_BEAM);
    CMshElement<decimal> anElement3(ET_BEAM);
    CMshElement<decimal> anElement4(ET_BEAM);
    CMshElement<decimal> anElement5(ET_BEAM);
    CMshElement<decimal> anElement6(ET_BEAM);
    CMshElement<decimal> anElement7(ET_BEAM);
    CMshElement<decimal> anElement8(ET_BEAM);
    CMshElement<decimal> anElement9(ET_BEAM);
    CMshElement<decimal> anElement10(ET_BEAM);
    CMshElement<decimal> anElement11(ET_BEAM);
    CMshElement<decimal> anElement12(ET_BEAM);

    anElement1.addNodeId(4);
    anElement1.addNodeId(1);
    anEdgeMesh.addElement(1, anElement1);

    anElement2.addNodeId(1);
    anElement2.addNodeId(5);
    anEdgeMesh.addElement(2, anElement2);

    anElement3.addNodeId(5);
    anElement3.addNodeId(6);
    anEdgeMesh.addElement(3, anElement3);

    anElement4.addNodeId(6);
    anElement4.addNodeId(7);
    anEdgeMesh.addElement(4, anElement4);

    anElement5.addNodeId(7);
    anElement5.addNodeId(8);
    anEdgeMesh.addElement(5, anElement5);

    anElement6.addNodeId(8);
    anElement6.addNodeId(9);
    anEdgeMesh.addElement(6, anElement6);

    anElement7.addNodeId(9);
    anElement7.addNodeId(10);
    anEdgeMesh.addElement(7, anElement7);

    anElement8.addNodeId(10);
    anElement8.addNodeId(2);
    anEdgeMesh.addElement(8, anElement8);

    anElement9.addNodeId(2);
    anElement9.addNodeId(3);
    anEdgeMesh.addElement(9, anElement9);

    anElement10.addNodeId(3);
    anElement10.addNodeId(4);
    anEdgeMesh.addElement(10, anElement10);

    anElement11.addNodeId(11);
    anElement11.addNodeId(12);
    anEdgeMesh.addElement(12, anElement11);

    anElement12.addNodeId(12);
    anElement12.addNodeId(11);
    anEdgeMesh.addElement(13, anElement12);

    EXPECT_EQ(12, anEdgeMesh.nbElements());

    CMshTriangleMesher<decimal> aTriangleMesher;
    std::vector<CGeoCoordinate<decimal>> sInteriorPoints;

    anEdgeMesh.generateFaces(1E-3);

    anEdgeMesh.node(5).x() = 20;
    anEdgeMesh.node(8).x() = 50;

    aTriangleMesher.remesh(anEdgeMesh, 10);

    CPdeField<decimal> T;
    CPosGmsh<decimal> aPosGmsh;

    T.setMesh(anEdgeMesh);
    aPosGmsh.save(T, "tri_edge5.msh", "beams");

    aTriangleMesher.generate(anEdgeMesh, 999, sInteriorPoints, 10.0, 1.0, 100.0, 1E-3);

    EXPECT_EQ(64, anEdgeMesh.nbElements());

    CMshMesh<decimal> aSurfaceMesh;
    aSurfaceMesh = aTriangleMesher.mesh();

    T.setMesh(aSurfaceMesh);
    aPosGmsh.save(T, "tri_surface5.msh", "tris");

    EXPECT_EQ(246, aSurfaceMesh.nbElements());

}

TEST_F(CTestMshTriangleMesher, mesh6) {

    CMshMesh<decimal> anEdgeMesh;

    CMshNode<decimal> aNode1(0, 0, 0);
    CMshNode<decimal> aNode2(100, 0, 0);
    CMshNode<decimal> aNode3(100, 100, 0);
    CMshNode<decimal> aNode4(0, 100, 0);
    CMshNode<decimal> aNode5(28, 0, 0);
    CMshNode<decimal> aNode6(28, 40, 0);
    CMshNode<decimal> aNode7(28, 0, 0);
    CMshNode<decimal> aNode8(58, 0, 0);
    CMshNode<decimal> aNode9(58, 52, 0);
    CMshNode<decimal> aNode10(58, 0, 0);
    CMshNode<decimal> aNode11(50, 88, 0);
    CMshNode<decimal> aNode12(79, 65, 0);

    anEdgeMesh.addNode(1, aNode1);
    anEdgeMesh.addNode(2, aNode2);
    anEdgeMesh.addNode(3, aNode3);
    anEdgeMesh.addNode(4, aNode4);
    anEdgeMesh.addNode(5, aNode5);
    anEdgeMesh.addNode(6, aNode6);
    anEdgeMesh.addNode(7, aNode7);
    anEdgeMesh.addNode(8, aNode8);
    anEdgeMesh.addNode(9, aNode9);
    anEdgeMesh.addNode(10, aNode10);
    anEdgeMesh.addNode(11, aNode11);
    anEdgeMesh.addNode(12, aNode12);

    CMshElement<decimal> anElement1(ET_BEAM);
    CMshElement<decimal> anElement2(ET_BEAM);
    CMshElement<decimal> anElement3(ET_BEAM);
    CMshElement<decimal> anElement4(ET_BEAM);
    CMshElement<decimal> anElement5(ET_BEAM);
    CMshElement<decimal> anElement6(ET_BEAM);
    CMshElement<decimal> anElement7(ET_BEAM);
    CMshElement<decimal> anElement8(ET_BEAM);
    CMshElement<decimal> anElement9(ET_BEAM);
    CMshElement<decimal> anElement10(ET_BEAM);
    CMshElement<decimal> anElement11(ET_BEAM);
    CMshElement<decimal> anElement12(ET_BEAM);

    anElement1.addNodeId(4);
    anElement1.addNodeId(1);
    anEdgeMesh.addElement(1, anElement1);

    anElement2.addNodeId(1);
    anElement2.addNodeId(5);
    anEdgeMesh.addElement(2, anElement2);

    anElement3.addNodeId(5);
    anElement3.addNodeId(8);
    anEdgeMesh.addElement(3, anElement3);

    anElement4.addNodeId(8);
    anElement4.addNodeId(2);
    anEdgeMesh.addElement(4, anElement4);

    anElement5.addNodeId(2);
    anElement5.addNodeId(3);
    anEdgeMesh.addElement(5, anElement5);

    anElement6.addNodeId(3);
    anElement6.addNodeId(4);
    anEdgeMesh.addElement(6, anElement6);

    anElement7.addNodeId(6);
    anElement7.addNodeId(7);
    anEdgeMesh.addElement(7, anElement7);

    anElement8.addNodeId(7);
    anElement8.addNodeId(6);
    anEdgeMesh.addElement(8, anElement8);

    anElement9.addNodeId(9);
    anElement9.addNodeId(10);
    anEdgeMesh.addElement(9, anElement9);

    anElement10.addNodeId(10);
    anElement10.addNodeId(9);
    anEdgeMesh.addElement(10, anElement10);

    anElement11.addNodeId(11);
    anElement11.addNodeId(12);
    anEdgeMesh.addElement(12, anElement11);

    anElement12.addNodeId(12);
    anElement12.addNodeId(11);
    anEdgeMesh.addElement(13, anElement12);

    EXPECT_EQ(12, anEdgeMesh.nbElements());

    CMshTriangleMesher<decimal> aTriangleMesher;
    std::vector<CGeoCoordinate<decimal>> sInteriorPoints;

    anEdgeMesh.node(6).z() = 10;
    anEdgeMesh.node(7).z() = 10;

    anEdgeMesh.node(9).z() = 10;
    anEdgeMesh.node(10).z() = 10;

    anEdgeMesh.node(11).z() = 10;
    anEdgeMesh.node(12).z() = 10;

    anEdgeMesh.generateFaces(1E-3);

    anEdgeMesh.node(6).z() = 0;
    anEdgeMesh.node(7).z() = 0;

    anEdgeMesh.node(9).z() = 0;
    anEdgeMesh.node(10).z() = 0;

    anEdgeMesh.node(11).z() = 0;
    anEdgeMesh.node(12).z() = 0;

    aTriangleMesher.remesh(anEdgeMesh, 10);

    anEdgeMesh.mergeNodes(1E-3);

    CPdeField<decimal> T;
    CPosGmsh<decimal> aPosGmsh;

    T.setMesh(anEdgeMesh);
    aPosGmsh.save(T, "tri_edge6.msh", "beams");

    aTriangleMesher.generate(anEdgeMesh, 999, sInteriorPoints, 10.0, 1.0, 50.0, 1E-3);

    EXPECT_EQ(66, anEdgeMesh.nbElements());

    CMshMesh<decimal> aSurfaceMesh;
    aSurfaceMesh = aTriangleMesher.mesh();

    T.setMesh(aSurfaceMesh);
    aPosGmsh.save(T, "tri_surface6.msh", "tris");

    EXPECT_EQ(254, aSurfaceMesh.nbElements());

}

TEST_F(CTestMshTriangleMesher, mesh7) {

    CMshMesh<decimal> anEdgeMesh;

    CMshNode<decimal> aNode1;
    CMshNode<decimal> aNode2;
    CMshNode<decimal> aNode3;
    CMshNode<decimal> aNode4;
    CMshNode<decimal> aNode5;
    CMshNode<decimal> aNode6;
    CMshNode<decimal> aNode7;
    CMshNode<decimal> aNode8;
    CMshNode<decimal> aNode9;
    CMshNode<decimal> aNode10;
    CMshNode<decimal> aNode11;
    CMshNode<decimal> aNode12;
    CMshNode<decimal> aNode13;

    aNode1 << -1.5, 0.1124999970197678, 0;
    aNode2 << -1.5, -0.1124999970197678, 0;
    aNode3 << -0.8500000238418579, -0.1124999970197678, 0;
    aNode4 << -0.2000000029802322, -0.1124999970197678, 0;
    aNode5 << -0.2000000029802322, -0.5125000476837158, 0;
    aNode6 << -0.8499999642372131, -0.5125000476837158, 0;
    aNode7 << -1.5, -0.5125000476837158, 0;
    aNode8 << -1.5, -0.7375000715255737, 0;
    aNode9 << -0.75, -0.7375000715255737, 0;
    aNode10 << 0, -0.7375000715255737, 0;
    aNode11 << 0, -0.3125000298023224, 0;
    aNode12 << 0, 0.1124999970197678, 0;
    aNode13 << -0.75, 0.1124999970197678, 0;

    anEdgeMesh.addNode(1, aNode1);
    anEdgeMesh.addNode(2, aNode2);
    anEdgeMesh.addNode(3, aNode3);
    anEdgeMesh.addNode(4, aNode4);
    anEdgeMesh.addNode(5, aNode5);
    anEdgeMesh.addNode(6, aNode6);
    anEdgeMesh.addNode(7, aNode7);
    anEdgeMesh.addNode(8, aNode8);
    anEdgeMesh.addNode(9, aNode9);
    anEdgeMesh.addNode(10, aNode10);
    anEdgeMesh.addNode(11, aNode11);
    anEdgeMesh.addNode(12, aNode12);
    anEdgeMesh.addNode(13, aNode13);

    for (int i = 0; i < 13; i++)
    {
        CMshElement<decimal> anElement(ET_BEAM);
        anElement.addNodeId(i + 1);
        if (i != 12)
            anElement.addNodeId(i + 2);
        else
            anElement.addNodeId(1);
        anEdgeMesh.addElement(i + 1, anElement);
    }

    anEdgeMesh.mergeNodes(0.02);
    anEdgeMesh.generateFaces(0.02);

    CMshTriangleMesher<decimal> aTriangleMesher;
    std::vector<CGeoCoordinate<decimal>> sInteriorPoints;

    aTriangleMesher.remesh(anEdgeMesh, 0.8);
    aTriangleMesher.generate(anEdgeMesh, 99, sInteriorPoints, 0.8, 0.8, 0.8 * 2.0, 0.02);

    CPdeField<decimal> T;
    CPosGmsh<decimal> aPosGmsh;

    T.setMesh(anEdgeMesh);
    aPosGmsh.save(T, "tri_edge7.msh", "beams");

    CMshMesh<decimal> aSurfaceMesh;
    aSurfaceMesh = aTriangleMesher.mesh();

    T.setMesh(aSurfaceMesh);
    aPosGmsh.save(T, "tri_surface7.msh", "tris");

    EXPECT_EQ(11, aSurfaceMesh.nbElements());

}

TEST_F(CTestMshTriangleMesher, mesh8) {

    CMshMesh<decimal> anEdgeMesh;

    CMshNode<decimal> aNode1;
    CMshNode<decimal> aNode2;
    CMshNode<decimal> aNode3;
    CMshNode<decimal> aNode4;
    CMshNode<decimal> aNode5;
    CMshNode<decimal> aNode6;
    CMshNode<decimal> aNode7;
    CMshNode<decimal> aNode8;
    CMshNode<decimal> aNode9;
    CMshNode<decimal> aNode10;
    CMshNode<decimal> aNode11;
    CMshNode<decimal> aNode12;
    CMshNode<decimal> aNode13;
    CMshNode<decimal> aNode14;
    CMshNode<decimal> aNode15;
    CMshNode<decimal> aNode16;
    CMshNode<decimal> aNode17;
    CMshNode<decimal> aNode18;
    CMshNode<decimal> aNode19;
    CMshNode<decimal> aNode20;
    CMshNode<decimal> aNode21;
    CMshNode<decimal> aNode22;
    CMshNode<decimal> aNode23;
    CMshNode<decimal> aNode24;
    CMshNode<decimal> aNode25;
    CMshNode<decimal> aNode26;
    CMshNode<decimal> aNode27;
    CMshNode<decimal> aNode28;
    CMshNode<decimal> aNode29;
    CMshNode<decimal> aNode30;

    aNode1 << 0,0,0;
    aNode2 << 0,-0.777239978313446,0;
    aNode3 << 3.993843078613281,-0.777239978313446,0;
    aNode4 << 7.987682342529297,-0.777239978313446,0;
    aNode5 << 11.98152160644531,-0.777239978313446,0;
    aNode6 << 15.97536468505859,-0.777239978313446,0;
    aNode7 << 19.96920776367188,-0.777239978313446,0;
    aNode8 << 23.96305084228516,-0.777239978313446,0;
    aNode9 << 27.95688629150391,-0.777239978313446,0;
    aNode10 << 31.95072937011719,-0.777239978313446,0;
    aNode11 << 35.94457244873047,-0.777239978313446,0;
    aNode12 << 39.93840789794922,-0.777239978313446,0;
    aNode13 << 43.9322509765625,-0.777239978313446,0;
    aNode14 << 47.92609405517578,-0.777239978313446,0;
    aNode15 << 51.91993713378906,-0.777239978313446,0;
    aNode16 << 55.91377258300781,-0.777239978313446,0;
    aNode17 << 55.91377258300781,0,0;
    aNode18 << 51.91993713378906,0,0;
    aNode19 << 47.92609405517578,0,0;
    aNode20 << 43.9322509765625,0,0;
    aNode21 << 39.93840789794922,0,0;
    aNode22 << 35.94457244873047,0,0;
    aNode23 << 31.95072937011719,0,0;
    aNode24 << 27.95688629150391,0,0;
    aNode25 << 23.96304321289062,0,0;
    aNode26 << 19.96920013427734,0,0;
    aNode27 << 15.97536468505859,0,0;
    aNode28 << 11.98152160644531,0,0;
    aNode29 << 7.987678527832031,0,0;
    aNode30 << 3.993843078613281,0,0;

    anEdgeMesh.addNode(1, aNode1);
    anEdgeMesh.addNode(2, aNode2);
    anEdgeMesh.addNode(3, aNode3);
    anEdgeMesh.addNode(4, aNode4);
    anEdgeMesh.addNode(5, aNode5);
    anEdgeMesh.addNode(6, aNode6);
    anEdgeMesh.addNode(7, aNode7);
    anEdgeMesh.addNode(8, aNode8);
    anEdgeMesh.addNode(9, aNode9);
    anEdgeMesh.addNode(10, aNode10);
    anEdgeMesh.addNode(11, aNode11);
    anEdgeMesh.addNode(12, aNode12);
    anEdgeMesh.addNode(13, aNode13);
    anEdgeMesh.addNode(14, aNode14);
    anEdgeMesh.addNode(15, aNode15);
    anEdgeMesh.addNode(16, aNode16);
    anEdgeMesh.addNode(17, aNode17);
    anEdgeMesh.addNode(18, aNode18);
    anEdgeMesh.addNode(19, aNode19);
    anEdgeMesh.addNode(20, aNode20);
    anEdgeMesh.addNode(21, aNode21);
    anEdgeMesh.addNode(22, aNode22);
    anEdgeMesh.addNode(23, aNode23);
    anEdgeMesh.addNode(24, aNode24);
    anEdgeMesh.addNode(25, aNode25);
    anEdgeMesh.addNode(26, aNode26);
    anEdgeMesh.addNode(27, aNode27);
    anEdgeMesh.addNode(28, aNode28);
    anEdgeMesh.addNode(29, aNode29);
    anEdgeMesh.addNode(30, aNode30);

    for (int i = 0; i < 30; i++)
    {
        CMshElement<decimal> anElement(ET_BEAM);
        anElement.addNodeId(i + 1);
        if (i != 29)
            anElement.addNodeId(i + 2);
        else
            anElement.addNodeId(1);
        anEdgeMesh.addElement(i + 1, anElement);
    }

    anEdgeMesh.mergeNodes(0.02);
    anEdgeMesh.generateFaces(0.02);

    CMshTriangleMesher<decimal> aTriangleMesher;
    std::vector<CGeoCoordinate<decimal>> sInteriorPoints;

    aTriangleMesher.remesh(anEdgeMesh, 4.0);
    aTriangleMesher.generate(anEdgeMesh, 99, sInteriorPoints, 4.0, 4.0, 4.0 * 2.0, 0.02);

    CPdeField<decimal> T;
    CPosGmsh<decimal> aPosGmsh;

    T.setMesh(anEdgeMesh);
    aPosGmsh.save(T, "tri_edge8.msh", "beams");

    CMshMesh<decimal> aSurfaceMesh;
    aSurfaceMesh = aTriangleMesher.mesh();

    T.setMesh(aSurfaceMesh);
    aPosGmsh.save(T, "tri_surface8.msh", "tris");

    EXPECT_EQ(28, aSurfaceMesh.nbElements());

}

TEST_F(CTestMshTriangleMesher, mesh9) {

    CMshMesh<decimal> anEdgeMesh;

    CMshNode<decimal> aNode1(0, 0, 0);
    CMshNode<decimal> aNode2(100, 0, 0);
    CMshNode<decimal> aNode3(100, 100, 0);
    CMshNode<decimal> aNode4(0, 100, 0);

    anEdgeMesh.addNode(1, aNode1);
    anEdgeMesh.addNode(2, aNode2);
    anEdgeMesh.addNode(3, aNode3);
    anEdgeMesh.addNode(4, aNode4);

    CMshElement<decimal> anElement1(ET_BEAM);
    CMshElement<decimal> anElement2(ET_BEAM);
    CMshElement<decimal> anElement3(ET_BEAM);
    CMshElement<decimal> anElement4(ET_BEAM);

    anElement1.addNodeId(1);
    anElement1.addNodeId(2);
    anEdgeMesh.addElement(1, anElement1);

    anElement2.addNodeId(2);
    anElement2.addNodeId(3);
    anEdgeMesh.addElement(2, anElement2);

    anElement3.addNodeId(3);
    anElement3.addNodeId(4);
    anEdgeMesh.addElement(3, anElement3);

    anElement4.addNodeId(4);
    anElement4.addNodeId(1);
    anEdgeMesh.addElement(4, anElement4);

    // Inner circle
    decimal r = 5;
    const decimal pi = std::acos(-1.0);

    for (Integer i = 0; i < 16; i++)
    {
        CMshNode<decimal> aNode(60 + r * cos(2 * pi - i * 2 * pi / 16), 60 + r * sin(2 * pi - i * 2 * pi / 16), 0);
        anEdgeMesh.addNode(5 + i, aNode);

        CMshElement<decimal> anElement(ET_BEAM);

        if (i < 15)
        {
            anElement.addNodeId(5 + i);
            anElement.addNodeId(5 + i + 1);
        }
        else
        {
            anElement.addNodeId(5 + i);
            anElement.addNodeId(5 + 0);
        }

        anEdgeMesh.addElement(5 + i, anElement);

    }

    anEdgeMesh.mergeNodes(1E-2);
    anEdgeMesh.generateFaces(1E-2);

    CMshTriangleMesher<decimal> aTriangleMesher;
    std::vector<CGeoCoordinate<decimal>> sInteriorPoints;

    aTriangleMesher.remesh(anEdgeMesh, 2.0);
    aTriangleMesher.generate(anEdgeMesh, 9999, sInteriorPoints, 2.0, 0.1, 10.0, 1E-4);

    CPdeField<decimal> T;
    CPosGmsh<decimal> aPosGmsh;

    T.setMesh(anEdgeMesh);
    aPosGmsh.save(T, "tri_edge9.msh", "beams");

    CMshMesh<decimal> aSurfaceMesh;
    aSurfaceMesh = aTriangleMesher.mesh();

    T.setMesh(aSurfaceMesh);
    aPosGmsh.save(T, "tri_surface9.msh", "tris");

    EXPECT_EQ(6940, aSurfaceMesh.nbElements());

}
