#include "sosPredicatesImpl.h"


//given a vertex from intersection, returns the epsilon coefficient of a given coordinate
//coord may be 0,1 or 2
//epsCoefficient may be 0, 1, 2 or 3
VertCoord SosPredicatesImpl::getEpsCoefficientsVertexFromIntersection(const VertexFromIntersection &v0, int epsCoefficient,int coord) const {
	assert(coord<=2);
	assert(epsCoefficient<=3);

	int meshId = v0.getMeshOfTriangleDefiningVertex();

	const VertCoord &v0t0x = getCoordinates( *(v0.triangle.getInputVertex(0)) )[0];
	const VertCoord &v0t1x = getCoordinates( *(v0.triangle.getInputVertex(1)) )[0];
	const VertCoord &v0t2x = getCoordinates( *(v0.triangle.getInputVertex(2)) )[0];
	const VertCoord &v0r0x = getCoordinates(v0.edge[0])[0];
	const VertCoord &v0r1x = getCoordinates(v0.edge[1])[0];
	const VertCoord &v0t0y = getCoordinates( *(v0.triangle.getInputVertex(0)) )[1];
	const VertCoord &v0t1y = getCoordinates( *(v0.triangle.getInputVertex(1)) )[1];
	const VertCoord &v0t2y = getCoordinates( *(v0.triangle.getInputVertex(2)) )[1];
	const VertCoord &v0r0y = getCoordinates(v0.edge[0])[1];
	const VertCoord &v0r1y = getCoordinates(v0.edge[1])[1];
	const VertCoord &v0t0z = getCoordinates( *(v0.triangle.getInputVertex(0)) )[2];
	const VertCoord &v0t1z = getCoordinates( *(v0.triangle.getInputVertex(1)) )[2];
	const VertCoord &v0t2z = getCoordinates( *(v0.triangle.getInputVertex(2)) )[2];
	const VertCoord &v0r0z = getCoordinates(v0.edge[0])[2];
	const VertCoord &v0r1z = getCoordinates(v0.edge[1])[2];

	if(meshId==0) {
		if(coord=0) {
			switch(epsCoefficient) {
				case 0: return (v0r0z*v0r1x*(-(v0t1y*v0t2x) + v0t0y*(-v0t1x + v0t2x) + v0t0x*(v0t1y - v0t2y) + v0t1x*v0t2y) + v0r1x*(v0t0z*v0t1y*v0t2x - v0t0y*v0t1z*v0t2x - v0t0z*v0t1x*v0t2y + v0t0x*v0t1z*v0t2y + v0t0y*v0t1x*v0t2z - v0t0x*v0t1y*v0t2z + v0r0y*(-(v0t0x*v0t1z) + v0t0z*(v0t1x - v0t2x) + v0t1z*v0t2x + v0t0x*v0t2z - v0t1x*v0t2z)) + v0r0x*(-(v0t0z*v0t1y*v0t2x) + v0t0y*v0t1z*v0t2x + v0t0z*v0t1x*v0t2y - v0t0x*v0t1z*v0t2y + v0r1z*(-(v0t0x*v0t1y) + v0t0y*(v0t1x - v0t2x) + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) - v0t0y*v0t1x*v0t2z + v0t0x*v0t1y*v0t2z + v0r1y*(-(v0t0z*v0t1x) + v0t0x*v0t1z + v0t0z*v0t2x - v0t1z*v0t2x - v0t0x*v0t2z + v0t1x*v0t2z)))/(v0r0y*v0t0z*v0t1x - v0r1y*v0t0z*v0t1x - v0r0x*v0t0z*v0t1y + v0r1x*v0t0z*v0t1y - v0r0y*v0t0x*v0t1z + v0r1y*v0t0x*v0t1z + v0r0x*v0t0y*v0t1z - v0r1x*v0t0y*v0t1z - v0r0y*v0t0z*v0t2x + v0r1y*v0t0z*v0t2x + v0r0y*v0t1z*v0t2x - v0r1y*v0t1z*v0t2x + v0r0x*v0t0z*v0t2y - v0r1x*v0t0z*v0t2y - v0r0x*v0t1z*v0t2y + v0r1x*v0t1z*v0t2y + v0r1z*(v0t0y*v0t1x - v0t0x*v0t1y - v0t0y*v0t2x + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) + v0r0z*(v0t0x*v0t1y - v0t1y*v0t2x + v0t0y*(-v0t1x + v0t2x) - v0t0x*v0t2y + v0t1x*v0t2y) + v0r0y*v0t0x*v0t2z - v0r1y*v0t0x*v0t2z - v0r0x*v0t0y*v0t2z + v0r1x*v0t0y*v0t2z - v0r0y*v0t1x*v0t2z + v0r1y*v0t1x*v0t2z + v0r0x*v0t1y*v0t2z - v0r1x*v0t1y*v0t2z);
				case 1: return (v0r1z*(v0t0y*v0t1x - v0t0x*v0t1y - v0t0y*v0t2x + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) + v0r0z*(v0t0x*v0t1y - v0t1y*v0t2x + v0t0y*(-v0t1x + v0t2x) - v0t0x*v0t2y + v0t1x*v0t2y) + (v0r0y - v0r1y)*(v0t0z*v0t1x - v0t0x*v0t1z - v0t0z*v0t2x + v0t1z*v0t2x + v0t0x*v0t2z - v0t1x*v0t2z))/(v0r0y*v0t0z*v0t1x - v0r1y*v0t0z*v0t1x - v0r0x*v0t0z*v0t1y + v0r1x*v0t0z*v0t1y - v0r0y*v0t0x*v0t1z + v0r1y*v0t0x*v0t1z + v0r0x*v0t0y*v0t1z - v0r1x*v0t0y*v0t1z - v0r0y*v0t0z*v0t2x + v0r1y*v0t0z*v0t2x + v0r0y*v0t1z*v0t2x - v0r1y*v0t1z*v0t2x + v0r0x*v0t0z*v0t2y - v0r1x*v0t0z*v0t2y - v0r0x*v0t1z*v0t2y + v0r1x*v0t1z*v0t2y + v0r1z*(v0t0y*v0t1x - v0t0x*v0t1y - v0t0y*v0t2x + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) + v0r0z*(v0t0x*v0t1y - v0t1y*v0t2x + v0t0y*(-v0t1x + v0t2x) - v0t0x*v0t2y + v0t1x*v0t2y) + v0r0y*v0t0x*v0t2z - v0r1y*v0t0x*v0t2z - v0r0x*v0t0y*v0t2z + v0r1x*v0t0y*v0t2z - v0r0y*v0t1x*v0t2z + v0r1y*v0t1x*v0t2z + v0r0x*v0t1y*v0t2z - v0r1x*v0t1y*v0t2z);
				case 2: return ((v0r0x - v0r1x)*(v0t0z*(v0t1x - v0t2x) + v0t1z*v0t2x - v0t1x*v0t2z + v0t0x*(-v0t1z + v0t2z)))/(-(v0r0y*v0t0z*v0t1x) + v0r1y*v0t0z*v0t1x + v0r0x*v0t0z*v0t1y - v0r1x*v0t0z*v0t1y + v0r0y*v0t0x*v0t1z - v0r1y*v0t0x*v0t1z - v0r0x*v0t0y*v0t1z + v0r1x*v0t0y*v0t1z + v0r0y*v0t0z*v0t2x - v0r1y*v0t0z*v0t2x - v0r0y*v0t1z*v0t2x + v0r1y*v0t1z*v0t2x - v0r0x*v0t0z*v0t2y + v0r1x*v0t0z*v0t2y + v0r0x*v0t1z*v0t2y - v0r1x*v0t1z*v0t2y + v0r0z*(-(v0t0x*v0t1y) + v0t0y*(v0t1x - v0t2x) + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) + v0r1z*(-(v0t0y*v0t1x) + v0t0x*v0t1y + v0t0y*v0t2x - v0t1y*v0t2x - v0t0x*v0t2y + v0t1x*v0t2y) - v0r0y*v0t0x*v0t2z + v0r1y*v0t0x*v0t2z + v0r0x*v0t0y*v0t2z - v0r1x*v0t0y*v0t2z + v0r0y*v0t1x*v0t2z - v0r1y*v0t1x*v0t2z - v0r0x*v0t1y*v0t2z + v0r1x*v0t1y*v0t2z);
				case 3: return ((v0r0x - v0r1x)*(v0t0y*(v0t1x - v0t2x) + v0t1y*v0t2x - v0t1x*v0t2y + v0t0x*(-v0t1y + v0t2y)))/(v0r0y*v0t0z*v0t1x - v0r1y*v0t0z*v0t1x - v0r0x*v0t0z*v0t1y + v0r1x*v0t0z*v0t1y - v0r0y*v0t0x*v0t1z + v0r1y*v0t0x*v0t1z + v0r0x*v0t0y*v0t1z - v0r1x*v0t0y*v0t1z - v0r0y*v0t0z*v0t2x + v0r1y*v0t0z*v0t2x + v0r0y*v0t1z*v0t2x - v0r1y*v0t1z*v0t2x + v0r0x*v0t0z*v0t2y - v0r1x*v0t0z*v0t2y - v0r0x*v0t1z*v0t2y + v0r1x*v0t1z*v0t2y + v0r1z*(v0t0y*v0t1x - v0t0x*v0t1y - v0t0y*v0t2x + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) + v0r0z*(v0t0x*v0t1y - v0t1y*v0t2x + v0t0y*(-v0t1x + v0t2x) - v0t0x*v0t2y + v0t1x*v0t2y) + v0r0y*v0t0x*v0t2z - v0r1y*v0t0x*v0t2z - v0r0x*v0t0y*v0t2z + v0r1x*v0t0y*v0t2z - v0r0y*v0t1x*v0t2z + v0r1y*v0t1x*v0t2z + v0r0x*v0t1y*v0t2z - v0r1x*v0t1y*v0t2z);
			}
		} else if (coord=1) {
			switch(epsCoefficient) {
				case 0: return (v0r0z*v0r1y*(-(v0t1y*v0t2x) + v0t0y*(-v0t1x + v0t2x) + v0t0x*(v0t1y - v0t2y) + v0t1x*v0t2y) + v0r0y*(-(v0t0z*v0t1y*v0t2x) + v0t0y*v0t1z*v0t2x + v0t0z*v0t1x*v0t2y - v0t0x*v0t1z*v0t2y + v0r1z*(-(v0t0x*v0t1y) + v0t0y*(v0t1x - v0t2x) + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) - v0t0y*v0t1x*v0t2z + v0t0x*v0t1y*v0t2z + v0r1x*(v0t0z*v0t1y - v0t0y*v0t1z - v0t0z*v0t2y + v0t1z*v0t2y + v0t0y*v0t2z - v0t1y*v0t2z)) + v0r1y*(v0t0z*v0t1y*v0t2x - v0t0y*v0t1z*v0t2x - v0t0z*v0t1x*v0t2y + v0t0x*v0t1z*v0t2y + v0t0y*v0t1x*v0t2z - v0t0x*v0t1y*v0t2z + v0r0x*(v0t0y*v0t1z - v0t1z*v0t2y + v0t0z*(-v0t1y + v0t2y) - v0t0y*v0t2z + v0t1y*v0t2z)))/(v0r0y*v0t0z*v0t1x - v0r1y*v0t0z*v0t1x - v0r0x*v0t0z*v0t1y + v0r1x*v0t0z*v0t1y - v0r0y*v0t0x*v0t1z + v0r1y*v0t0x*v0t1z + v0r0x*v0t0y*v0t1z - v0r1x*v0t0y*v0t1z - v0r0y*v0t0z*v0t2x + v0r1y*v0t0z*v0t2x + v0r0y*v0t1z*v0t2x - v0r1y*v0t1z*v0t2x + v0r0x*v0t0z*v0t2y - v0r1x*v0t0z*v0t2y - v0r0x*v0t1z*v0t2y + v0r1x*v0t1z*v0t2y + v0r1z*(v0t0y*v0t1x - v0t0x*v0t1y - v0t0y*v0t2x + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) + v0r0z*(v0t0x*v0t1y - v0t1y*v0t2x + v0t0y*(-v0t1x + v0t2x) - v0t0x*v0t2y + v0t1x*v0t2y) + v0r0y*v0t0x*v0t2z - v0r1y*v0t0x*v0t2z - v0r0x*v0t0y*v0t2z + v0r1x*v0t0y*v0t2z - v0r0y*v0t1x*v0t2z + v0r1y*v0t1x*v0t2z + v0r0x*v0t1y*v0t2z - v0r1x*v0t1y*v0t2z);
				case 1: return  ((v0r0y - v0r1y)*(v0t0z*(v0t1y - v0t2y) + v0t1z*v0t2y - v0t1y*v0t2z + v0t0y*(-v0t1z + v0t2z)))/(v0r0y*v0t0z*v0t1x - v0r1y*v0t0z*v0t1x - v0r0x*v0t0z*v0t1y + v0r1x*v0t0z*v0t1y - v0r0y*v0t0x*v0t1z + v0r1y*v0t0x*v0t1z + v0r0x*v0t0y*v0t1z - v0r1x*v0t0y*v0t1z - v0r0y*v0t0z*v0t2x + v0r1y*v0t0z*v0t2x + v0r0y*v0t1z*v0t2x - v0r1y*v0t1z*v0t2x + v0r0x*v0t0z*v0t2y - v0r1x*v0t0z*v0t2y - v0r0x*v0t1z*v0t2y + v0r1x*v0t1z*v0t2y + v0r1z*(v0t0y*v0t1x - v0t0x*v0t1y - v0t0y*v0t2x + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) + v0r0z*(v0t0x*v0t1y - v0t1y*v0t2x + v0t0y*(-v0t1x + v0t2x) - v0t0x*v0t2y + v0t1x*v0t2y) + v0r0y*v0t0x*v0t2z - v0r1y*v0t0x*v0t2z - v0r0x*v0t0y*v0t2z + v0r1x*v0t0y*v0t2z - v0r0y*v0t1x*v0t2z + v0r1y*v0t1x*v0t2z + v0r0x*v0t1y*v0t2z - v0r1x*v0t1y*v0t2z);
				case 2: return  (v0r1z*(-(v0t0x*v0t1y) + v0t0y*(v0t1x - v0t2x) + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) + v0r0z*(v0t0x*v0t1y - v0t1y*v0t2x + v0t0y*(-v0t1x + v0t2x) - v0t0x*v0t2y + v0t1x*v0t2y) + (v0r0x - v0r1x)*(v0t0y*v0t1z - v0t1z*v0t2y + v0t0z*(-v0t1y + v0t2y) - v0t0y*v0t2z + v0t1y*v0t2z))/(v0r0y*v0t0z*v0t1x - v0r1y*v0t0z*v0t1x - v0r0x*v0t0z*v0t1y + v0r1x*v0t0z*v0t1y - v0r0y*v0t0x*v0t1z + v0r1y*v0t0x*v0t1z + v0r0x*v0t0y*v0t1z - v0r1x*v0t0y*v0t1z - v0r0y*v0t0z*v0t2x + v0r1y*v0t0z*v0t2x + v0r0y*v0t1z*v0t2x - v0r1y*v0t1z*v0t2x + v0r0x*v0t0z*v0t2y - v0r1x*v0t0z*v0t2y - v0r0x*v0t1z*v0t2y + v0r1x*v0t1z*v0t2y + v0r1z*(v0t0y*v0t1x - v0t0x*v0t1y - v0t0y*v0t2x + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) + v0r0z*(v0t0x*v0t1y - v0t1y*v0t2x + v0t0y*(-v0t1x + v0t2x) - v0t0x*v0t2y + v0t1x*v0t2y) + v0r0y*v0t0x*v0t2z - v0r1y*v0t0x*v0t2z - v0r0x*v0t0y*v0t2z + v0r1x*v0t0y*v0t2z - v0r0y*v0t1x*v0t2z + v0r1y*v0t1x*v0t2z + v0r0x*v0t1y*v0t2z - v0r1x*v0t1y*v0t2z);
				case 3: return  ((v0r0y - v0r1y)*(v0t0y*(v0t1x - v0t2x) + v0t1y*v0t2x - v0t1x*v0t2y + v0t0x*(-v0t1y + v0t2y)))/(v0r0y*v0t0z*v0t1x - v0r1y*v0t0z*v0t1x - v0r0x*v0t0z*v0t1y + v0r1x*v0t0z*v0t1y - v0r0y*v0t0x*v0t1z + v0r1y*v0t0x*v0t1z + v0r0x*v0t0y*v0t1z - v0r1x*v0t0y*v0t1z - v0r0y*v0t0z*v0t2x + v0r1y*v0t0z*v0t2x + v0r0y*v0t1z*v0t2x - v0r1y*v0t1z*v0t2x + v0r0x*v0t0z*v0t2y - v0r1x*v0t0z*v0t2y - v0r0x*v0t1z*v0t2y + v0r1x*v0t1z*v0t2y + v0r1z*(v0t0y*v0t1x - v0t0x*v0t1y - v0t0y*v0t2x + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) + v0r0z*(v0t0x*v0t1y - v0t1y*v0t2x + v0t0y*(-v0t1x + v0t2x) - v0t0x*v0t2y + v0t1x*v0t2y) + v0r0y*v0t0x*v0t2z - v0r1y*v0t0x*v0t2z - v0r0x*v0t0y*v0t2z + v0r1x*v0t0y*v0t2z - v0r0y*v0t1x*v0t2z + v0r1y*v0t1x*v0t2z + v0r0x*v0t1y*v0t2z - v0r1x*v0t1y*v0t2z);
			}
		} else {
			switch(epsCoefficient) {
				assert(coord=2);
				case 0: return (v0r0z*(-(v0t0z*v0t1y*v0t2x) + v0t0y*v0t1z*v0t2x + v0t0z*v0t1x*v0t2y - v0t0x*v0t1z*v0t2y - v0t0y*v0t1x*v0t2z + v0t0x*v0t1y*v0t2z + v0r1y*(v0t0x*v0t1z - v0t1z*v0t2x + v0t0z*(-v0t1x + v0t2x) - v0t0x*v0t2z + v0t1x*v0t2z) + v0r1x*(v0t0z*v0t1y - v0t0y*v0t1z - v0t0z*v0t2y + v0t1z*v0t2y + v0t0y*v0t2z - v0t1y*v0t2z)) + v0r1z*(v0t0z*v0t1y*v0t2x - v0t0y*v0t1z*v0t2x - v0t0z*v0t1x*v0t2y + v0t0x*v0t1z*v0t2y + v0t0y*v0t1x*v0t2z - v0t0x*v0t1y*v0t2z + v0r0y*(-(v0t0x*v0t1z) + v0t0z*(v0t1x - v0t2x) + v0t1z*v0t2x + v0t0x*v0t2z - v0t1x*v0t2z) + v0r0x*(-(v0t0z*v0t1y) + v0t0y*v0t1z + v0t0z*v0t2y - v0t1z*v0t2y - v0t0y*v0t2z + v0t1y*v0t2z)))/(v0r0y*v0t0z*v0t1x - v0r1y*v0t0z*v0t1x - v0r0x*v0t0z*v0t1y + v0r1x*v0t0z*v0t1y - v0r0y*v0t0x*v0t1z + v0r1y*v0t0x*v0t1z + v0r0x*v0t0y*v0t1z - v0r1x*v0t0y*v0t1z - v0r0y*v0t0z*v0t2x + v0r1y*v0t0z*v0t2x + v0r0y*v0t1z*v0t2x - v0r1y*v0t1z*v0t2x + v0r0x*v0t0z*v0t2y - v0r1x*v0t0z*v0t2y - v0r0x*v0t1z*v0t2y + v0r1x*v0t1z*v0t2y + v0r1z*(v0t0y*v0t1x - v0t0x*v0t1y - v0t0y*v0t2x + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) + v0r0z*(v0t0x*v0t1y - v0t1y*v0t2x + v0t0y*(-v0t1x + v0t2x) - v0t0x*v0t2y + v0t1x*v0t2y) + v0r0y*v0t0x*v0t2z - v0r1y*v0t0x*v0t2z - v0r0x*v0t0y*v0t2z + v0r1x*v0t0y*v0t2z - v0r0y*v0t1x*v0t2z + v0r1y*v0t1x*v0t2z + v0r0x*v0t1y*v0t2z - v0r1x*v0t1y*v0t2z);
				case 1: return  ((v0r0z - v0r1z)*(v0t0z*(v0t1y - v0t2y) + v0t1z*v0t2y - v0t1y*v0t2z + v0t0y*(-v0t1z + v0t2z)))/(v0r0y*v0t0z*v0t1x - v0r1y*v0t0z*v0t1x - v0r0x*v0t0z*v0t1y + v0r1x*v0t0z*v0t1y - v0r0y*v0t0x*v0t1z + v0r1y*v0t0x*v0t1z + v0r0x*v0t0y*v0t1z - v0r1x*v0t0y*v0t1z - v0r0y*v0t0z*v0t2x + v0r1y*v0t0z*v0t2x + v0r0y*v0t1z*v0t2x - v0r1y*v0t1z*v0t2x + v0r0x*v0t0z*v0t2y - v0r1x*v0t0z*v0t2y - v0r0x*v0t1z*v0t2y + v0r1x*v0t1z*v0t2y + v0r1z*(v0t0y*v0t1x - v0t0x*v0t1y - v0t0y*v0t2x + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) + v0r0z*(v0t0x*v0t1y - v0t1y*v0t2x + v0t0y*(-v0t1x + v0t2x) - v0t0x*v0t2y + v0t1x*v0t2y) + v0r0y*v0t0x*v0t2z - v0r1y*v0t0x*v0t2z - v0r0x*v0t0y*v0t2z + v0r1x*v0t0y*v0t2z - v0r0y*v0t1x*v0t2z + v0r1y*v0t1x*v0t2z + v0r0x*v0t1y*v0t2z - v0r1x*v0t1y*v0t2z);
				case 2: return  ((v0r0z - v0r1z)*(v0t0z*(v0t1x - v0t2x) + v0t1z*v0t2x - v0t1x*v0t2z + v0t0x*(-v0t1z + v0t2z)))/(-(v0r0y*v0t0z*v0t1x) + v0r1y*v0t0z*v0t1x + v0r0x*v0t0z*v0t1y - v0r1x*v0t0z*v0t1y + v0r0y*v0t0x*v0t1z - v0r1y*v0t0x*v0t1z - v0r0x*v0t0y*v0t1z + v0r1x*v0t0y*v0t1z + v0r0y*v0t0z*v0t2x - v0r1y*v0t0z*v0t2x - v0r0y*v0t1z*v0t2x + v0r1y*v0t1z*v0t2x - v0r0x*v0t0z*v0t2y + v0r1x*v0t0z*v0t2y + v0r0x*v0t1z*v0t2y - v0r1x*v0t1z*v0t2y + v0r0z*(-(v0t0x*v0t1y) + v0t0y*(v0t1x - v0t2x) + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) + v0r1z*(-(v0t0y*v0t1x) + v0t0x*v0t1y + v0t0y*v0t2x - v0t1y*v0t2x - v0t0x*v0t2y + v0t1x*v0t2y) - v0r0y*v0t0x*v0t2z + v0r1y*v0t0x*v0t2z + v0r0x*v0t0y*v0t2z - v0r1x*v0t0y*v0t2z + v0r0y*v0t1x*v0t2z - v0r1y*v0t1x*v0t2z - v0r0x*v0t1y*v0t2z + v0r1x*v0t1y*v0t2z);
				case 3: return  (v0r0y*(-(v0t0x*v0t1z) + v0t0z*(v0t1x - v0t2x) + v0t1z*v0t2x + v0t0x*v0t2z - v0t1x*v0t2z) + v0r1y*(v0t0x*v0t1z - v0t1z*v0t2x + v0t0z*(-v0t1x + v0t2x) - v0t0x*v0t2z + v0t1x*v0t2z) + (v0r0x - v0r1x)*(v0t0y*v0t1z - v0t1z*v0t2y + v0t0z*(-v0t1y + v0t2y) - v0t0y*v0t2z + v0t1y*v0t2z))/(v0r0y*v0t0z*v0t1x - v0r1y*v0t0z*v0t1x - v0r0x*v0t0z*v0t1y + v0r1x*v0t0z*v0t1y - v0r0y*v0t0x*v0t1z + v0r1y*v0t0x*v0t1z + v0r0x*v0t0y*v0t1z - v0r1x*v0t0y*v0t1z - v0r0y*v0t0z*v0t2x + v0r1y*v0t0z*v0t2x + v0r0y*v0t1z*v0t2x - v0r1y*v0t1z*v0t2x + v0r0x*v0t0z*v0t2y - v0r1x*v0t0z*v0t2y - v0r0x*v0t1z*v0t2y + v0r1x*v0t1z*v0t2y + v0r1z*(v0t0y*v0t1x - v0t0x*v0t1y - v0t0y*v0t2x + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) + v0r0z*(v0t0x*v0t1y - v0t1y*v0t2x + v0t0y*(-v0t1x + v0t2x) - v0t0x*v0t2y + v0t1x*v0t2y) + v0r0y*v0t0x*v0t2z - v0r1y*v0t0x*v0t2z - v0r0x*v0t0y*v0t2z + v0r1x*v0t0y*v0t2z - v0r0y*v0t1x*v0t2z + v0r1y*v0t1x*v0t2z + v0r0x*v0t1y*v0t2z - v0r1x*v0t1y*v0t2z);
			}
		}
	} else {
		if(coord=0) {
			switch(epsCoefficient) {
				case 0: return (v0r0z*v0r1x*(-(v0t1y*v0t2x) + v0t0y*(-v0t1x + v0t2x) + v0t0x*(v0t1y - v0t2y) + v0t1x*v0t2y) + v0r1x*(v0t0z*v0t1y*v0t2x - v0t0y*v0t1z*v0t2x - v0t0z*v0t1x*v0t2y + v0t0x*v0t1z*v0t2y + v0t0y*v0t1x*v0t2z - v0t0x*v0t1y*v0t2z + v0r0y*(-(v0t0x*v0t1z) + v0t0z*(v0t1x - v0t2x) + v0t1z*v0t2x + v0t0x*v0t2z - v0t1x*v0t2z)) + v0r0x*(-(v0t0z*v0t1y*v0t2x) + v0t0y*v0t1z*v0t2x + v0t0z*v0t1x*v0t2y - v0t0x*v0t1z*v0t2y + v0r1z*(-(v0t0x*v0t1y) + v0t0y*(v0t1x - v0t2x) + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) - v0t0y*v0t1x*v0t2z + v0t0x*v0t1y*v0t2z + v0r1y*(-(v0t0z*v0t1x) + v0t0x*v0t1z + v0t0z*v0t2x - v0t1z*v0t2x - v0t0x*v0t2z + v0t1x*v0t2z)))/(v0r0y*v0t0z*v0t1x - v0r1y*v0t0z*v0t1x - v0r0x*v0t0z*v0t1y + v0r1x*v0t0z*v0t1y - v0r0y*v0t0x*v0t1z + v0r1y*v0t0x*v0t1z + v0r0x*v0t0y*v0t1z - v0r1x*v0t0y*v0t1z - v0r0y*v0t0z*v0t2x + v0r1y*v0t0z*v0t2x + v0r0y*v0t1z*v0t2x - v0r1y*v0t1z*v0t2x + v0r0x*v0t0z*v0t2y - v0r1x*v0t0z*v0t2y - v0r0x*v0t1z*v0t2y + v0r1x*v0t1z*v0t2y + v0r1z*(v0t0y*v0t1x - v0t0x*v0t1y - v0t0y*v0t2x + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) + v0r0z*(v0t0x*v0t1y - v0t1y*v0t2x + v0t0y*(-v0t1x + v0t2x) - v0t0x*v0t2y + v0t1x*v0t2y) + v0r0y*v0t0x*v0t2z - v0r1y*v0t0x*v0t2z - v0r0x*v0t0y*v0t2z + v0r1x*v0t0y*v0t2z - v0r0y*v0t1x*v0t2z + v0r1y*v0t1x*v0t2z + v0r0x*v0t1y*v0t2z - v0r1x*v0t1y*v0t2z);
				case 1: return ((v0r0x - v0r1x)*(v0t0z*(v0t1y - v0t2y) + v0t1z*v0t2y - v0t1y*v0t2z + v0t0y*(-v0t1z + v0t2z)))/(-(v0r0y*v0t0z*v0t1x) + v0r1y*v0t0z*v0t1x + v0r0x*v0t0z*v0t1y - v0r1x*v0t0z*v0t1y + v0r0y*v0t0x*v0t1z - v0r1y*v0t0x*v0t1z - v0r0x*v0t0y*v0t1z + v0r1x*v0t0y*v0t1z + v0r0y*v0t0z*v0t2x - v0r1y*v0t0z*v0t2x - v0r0y*v0t1z*v0t2x + v0r1y*v0t1z*v0t2x - v0r0x*v0t0z*v0t2y + v0r1x*v0t0z*v0t2y + v0r0x*v0t1z*v0t2y - v0r1x*v0t1z*v0t2y + v0r0z*(-(v0t0x*v0t1y) + v0t0y*(v0t1x - v0t2x) + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) + v0r1z*(-(v0t0y*v0t1x) + v0t0x*v0t1y + v0t0y*v0t2x - v0t1y*v0t2x - v0t0x*v0t2y + v0t1x*v0t2y) - v0r0y*v0t0x*v0t2z + v0r1y*v0t0x*v0t2z + v0r0x*v0t0y*v0t2z - v0r1x*v0t0y*v0t2z + v0r0y*v0t1x*v0t2z - v0r1y*v0t1x*v0t2z - v0r0x*v0t1y*v0t2z + v0r1x*v0t1y*v0t2z);
				case 2: return  ((v0r0x - v0r1x)*(v0t0z*(v0t1x - v0t2x) + v0t1z*v0t2x - v0t1x*v0t2z + v0t0x*(-v0t1z + v0t2z)))/(v0r0y*v0t0z*v0t1x - v0r1y*v0t0z*v0t1x - v0r0x*v0t0z*v0t1y + v0r1x*v0t0z*v0t1y - v0r0y*v0t0x*v0t1z + v0r1y*v0t0x*v0t1z + v0r0x*v0t0y*v0t1z - v0r1x*v0t0y*v0t1z - v0r0y*v0t0z*v0t2x + v0r1y*v0t0z*v0t2x + v0r0y*v0t1z*v0t2x - v0r1y*v0t1z*v0t2x + v0r0x*v0t0z*v0t2y - v0r1x*v0t0z*v0t2y - v0r0x*v0t1z*v0t2y + v0r1x*v0t1z*v0t2y + v0r1z*(v0t0y*v0t1x - v0t0x*v0t1y - v0t0y*v0t2x + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) + v0r0z*(v0t0x*v0t1y - v0t1y*v0t2x + v0t0y*(-v0t1x + v0t2x) - v0t0x*v0t2y + v0t1x*v0t2y) + v0r0y*v0t0x*v0t2z - v0r1y*v0t0x*v0t2z - v0r0x*v0t0y*v0t2z + v0r1x*v0t0y*v0t2z - v0r0y*v0t1x*v0t2z + v0r1y*v0t1x*v0t2z + v0r0x*v0t1y*v0t2z - v0r1x*v0t1y*v0t2z);
				case 3: return  -(((v0r0x - v0r1x)*(v0t0y*(v0t1x - v0t2x) + v0t1y*v0t2x - v0t1x*v0t2y + v0t0x*(-v0t1y + v0t2y)))/(v0r0y*v0t0z*v0t1x - v0r1y*v0t0z*v0t1x - v0r0x*v0t0z*v0t1y + v0r1x*v0t0z*v0t1y - v0r0y*v0t0x*v0t1z + v0r1y*v0t0x*v0t1z + v0r0x*v0t0y*v0t1z - v0r1x*v0t0y*v0t1z - v0r0y*v0t0z*v0t2x + v0r1y*v0t0z*v0t2x + v0r0y*v0t1z*v0t2x - v0r1y*v0t1z*v0t2x + v0r0x*v0t0z*v0t2y - v0r1x*v0t0z*v0t2y - v0r0x*v0t1z*v0t2y + v0r1x*v0t1z*v0t2y + v0r1z*(v0t0y*v0t1x - v0t0x*v0t1y - v0t0y*v0t2x + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) + v0r0z*(v0t0x*v0t1y - v0t1y*v0t2x + v0t0y*(-v0t1x + v0t2x) - v0t0x*v0t2y + v0t1x*v0t2y) + v0r0y*v0t0x*v0t2z - v0r1y*v0t0x*v0t2z - v0r0x*v0t0y*v0t2z + v0r1x*v0t0y*v0t2z - v0r0y*v0t1x*v0t2z + v0r1y*v0t1x*v0t2z + v0r0x*v0t1y*v0t2z - v0r1x*v0t1y*v0t2z));
			}
		} else if (coord=1) {	
			switch(epsCoefficient) {
				case 0: return (v0r0z*v0r1y*(-(v0t1y*v0t2x) + v0t0y*(-v0t1x + v0t2x) + v0t0x*(v0t1y - v0t2y) + v0t1x*v0t2y) + v0r0y*(-(v0t0z*v0t1y*v0t2x) + v0t0y*v0t1z*v0t2x + v0t0z*v0t1x*v0t2y - v0t0x*v0t1z*v0t2y + v0r1z*(-(v0t0x*v0t1y) + v0t0y*(v0t1x - v0t2x) + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) - v0t0y*v0t1x*v0t2z + v0t0x*v0t1y*v0t2z + v0r1x*(v0t0z*v0t1y - v0t0y*v0t1z - v0t0z*v0t2y + v0t1z*v0t2y + v0t0y*v0t2z - v0t1y*v0t2z)) + v0r1y*(v0t0z*v0t1y*v0t2x - v0t0y*v0t1z*v0t2x - v0t0z*v0t1x*v0t2y + v0t0x*v0t1z*v0t2y + v0t0y*v0t1x*v0t2z - v0t0x*v0t1y*v0t2z + v0r0x*(v0t0y*v0t1z - v0t1z*v0t2y + v0t0z*(-v0t1y + v0t2y) - v0t0y*v0t2z + v0t1y*v0t2z)))/(v0r0y*v0t0z*v0t1x - v0r1y*v0t0z*v0t1x - v0r0x*v0t0z*v0t1y + v0r1x*v0t0z*v0t1y - v0r0y*v0t0x*v0t1z + v0r1y*v0t0x*v0t1z + v0r0x*v0t0y*v0t1z - v0r1x*v0t0y*v0t1z - v0r0y*v0t0z*v0t2x + v0r1y*v0t0z*v0t2x + v0r0y*v0t1z*v0t2x - v0r1y*v0t1z*v0t2x + v0r0x*v0t0z*v0t2y - v0r1x*v0t0z*v0t2y - v0r0x*v0t1z*v0t2y + v0r1x*v0t1z*v0t2y + v0r1z*(v0t0y*v0t1x - v0t0x*v0t1y - v0t0y*v0t2x + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) + v0r0z*(v0t0x*v0t1y - v0t1y*v0t2x + v0t0y*(-v0t1x + v0t2x) - v0t0x*v0t2y + v0t1x*v0t2y) + v0r0y*v0t0x*v0t2z - v0r1y*v0t0x*v0t2z - v0r0x*v0t0y*v0t2z + v0r1x*v0t0y*v0t2z - v0r0y*v0t1x*v0t2z + v0r1y*v0t1x*v0t2z + v0r0x*v0t1y*v0t2z - v0r1x*v0t1y*v0t2z);
				case 1: return -(((v0r0y - v0r1y)*(v0t0z*(v0t1y - v0t2y) + v0t1z*v0t2y - v0t1y*v0t2z + v0t0y*(-v0t1z + v0t2z)))/(v0r0y*v0t0z*v0t1x - v0r1y*v0t0z*v0t1x - v0r0x*v0t0z*v0t1y + v0r1x*v0t0z*v0t1y - v0r0y*v0t0x*v0t1z + v0r1y*v0t0x*v0t1z + v0r0x*v0t0y*v0t1z - v0r1x*v0t0y*v0t1z - v0r0y*v0t0z*v0t2x + v0r1y*v0t0z*v0t2x + v0r0y*v0t1z*v0t2x - v0r1y*v0t1z*v0t2x + v0r0x*v0t0z*v0t2y - v0r1x*v0t0z*v0t2y - v0r0x*v0t1z*v0t2y + v0r1x*v0t1z*v0t2y + v0r1z*(v0t0y*v0t1x - v0t0x*v0t1y - v0t0y*v0t2x + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) + v0r0z*(v0t0x*v0t1y - v0t1y*v0t2x + v0t0y*(-v0t1x + v0t2x) - v0t0x*v0t2y + v0t1x*v0t2y) + v0r0y*v0t0x*v0t2z - v0r1y*v0t0x*v0t2z - v0r0x*v0t0y*v0t2z + v0r1x*v0t0y*v0t2z - v0r0y*v0t1x*v0t2z + v0r1y*v0t1x*v0t2z + v0r0x*v0t1y*v0t2z - v0r1x*v0t1y*v0t2z));
				case 2: return ((v0r0y - v0r1y)*(v0t0z*(v0t1x - v0t2x) + v0t1z*v0t2x - v0t1x*v0t2z + v0t0x*(-v0t1z + v0t2z)))/(v0r0y*v0t0z*v0t1x - v0r1y*v0t0z*v0t1x - v0r0x*v0t0z*v0t1y + v0r1x*v0t0z*v0t1y - v0r0y*v0t0x*v0t1z + v0r1y*v0t0x*v0t1z + v0r0x*v0t0y*v0t1z - v0r1x*v0t0y*v0t1z - v0r0y*v0t0z*v0t2x + v0r1y*v0t0z*v0t2x + v0r0y*v0t1z*v0t2x - v0r1y*v0t1z*v0t2x + v0r0x*v0t0z*v0t2y - v0r1x*v0t0z*v0t2y - v0r0x*v0t1z*v0t2y + v0r1x*v0t1z*v0t2y + v0r1z*(v0t0y*v0t1x - v0t0x*v0t1y - v0t0y*v0t2x + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) + v0r0z*(v0t0x*v0t1y - v0t1y*v0t2x + v0t0y*(-v0t1x + v0t2x) - v0t0x*v0t2y + v0t1x*v0t2y) + v0r0y*v0t0x*v0t2z - v0r1y*v0t0x*v0t2z - v0r0x*v0t0y*v0t2z + v0r1x*v0t0y*v0t2z - v0r0y*v0t1x*v0t2z + v0r1y*v0t1x*v0t2z + v0r0x*v0t1y*v0t2z - v0r1x*v0t1y*v0t2z);
				case 3: return -(((v0r0y - v0r1y)*(v0t0y*(v0t1x - v0t2x) + v0t1y*v0t2x - v0t1x*v0t2y + v0t0x*(-v0t1y + v0t2y)))/(v0r0y*v0t0z*v0t1x - v0r1y*v0t0z*v0t1x - v0r0x*v0t0z*v0t1y + v0r1x*v0t0z*v0t1y - v0r0y*v0t0x*v0t1z + v0r1y*v0t0x*v0t1z + v0r0x*v0t0y*v0t1z - v0r1x*v0t0y*v0t1z - v0r0y*v0t0z*v0t2x + v0r1y*v0t0z*v0t2x + v0r0y*v0t1z*v0t2x - v0r1y*v0t1z*v0t2x + v0r0x*v0t0z*v0t2y - v0r1x*v0t0z*v0t2y - v0r0x*v0t1z*v0t2y + v0r1x*v0t1z*v0t2y + v0r1z*(v0t0y*v0t1x - v0t0x*v0t1y - v0t0y*v0t2x + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) + v0r0z*(v0t0x*v0t1y - v0t1y*v0t2x + v0t0y*(-v0t1x + v0t2x) - v0t0x*v0t2y + v0t1x*v0t2y) + v0r0y*v0t0x*v0t2z - v0r1y*v0t0x*v0t2z - v0r0x*v0t0y*v0t2z + v0r1x*v0t0y*v0t2z - v0r0y*v0t1x*v0t2z + v0r1y*v0t1x*v0t2z + v0r0x*v0t1y*v0t2z - v0r1x*v0t1y*v0t2z));
			}
		} else {
			assert(coord=2);	
			switch(epsCoefficient) {
				case 0: return (v0r0z*(-(v0t0z*v0t1y*v0t2x) + v0t0y*v0t1z*v0t2x + v0t0z*v0t1x*v0t2y - v0t0x*v0t1z*v0t2y - v0t0y*v0t1x*v0t2z + v0t0x*v0t1y*v0t2z + v0r1y*(v0t0x*v0t1z - v0t1z*v0t2x + v0t0z*(-v0t1x + v0t2x) - v0t0x*v0t2z + v0t1x*v0t2z) + v0r1x*(v0t0z*v0t1y - v0t0y*v0t1z - v0t0z*v0t2y + v0t1z*v0t2y + v0t0y*v0t2z - v0t1y*v0t2z)) + v0r1z*(v0t0z*v0t1y*v0t2x - v0t0y*v0t1z*v0t2x - v0t0z*v0t1x*v0t2y + v0t0x*v0t1z*v0t2y + v0t0y*v0t1x*v0t2z - v0t0x*v0t1y*v0t2z + v0r0y*(-(v0t0x*v0t1z) + v0t0z*(v0t1x - v0t2x) + v0t1z*v0t2x + v0t0x*v0t2z - v0t1x*v0t2z) + v0r0x*(-(v0t0z*v0t1y) + v0t0y*v0t1z + v0t0z*v0t2y - v0t1z*v0t2y - v0t0y*v0t2z + v0t1y*v0t2z)))/(v0r0y*v0t0z*v0t1x - v0r1y*v0t0z*v0t1x - v0r0x*v0t0z*v0t1y + v0r1x*v0t0z*v0t1y - v0r0y*v0t0x*v0t1z + v0r1y*v0t0x*v0t1z + v0r0x*v0t0y*v0t1z - v0r1x*v0t0y*v0t1z - v0r0y*v0t0z*v0t2x + v0r1y*v0t0z*v0t2x + v0r0y*v0t1z*v0t2x - v0r1y*v0t1z*v0t2x + v0r0x*v0t0z*v0t2y - v0r1x*v0t0z*v0t2y - v0r0x*v0t1z*v0t2y + v0r1x*v0t1z*v0t2y + v0r1z*(v0t0y*v0t1x - v0t0x*v0t1y - v0t0y*v0t2x + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) + v0r0z*(v0t0x*v0t1y - v0t1y*v0t2x + v0t0y*(-v0t1x + v0t2x) - v0t0x*v0t2y + v0t1x*v0t2y) + v0r0y*v0t0x*v0t2z - v0r1y*v0t0x*v0t2z - v0r0x*v0t0y*v0t2z + v0r1x*v0t0y*v0t2z - v0r0y*v0t1x*v0t2z + v0r1y*v0t1x*v0t2z + v0r0x*v0t1y*v0t2z - v0r1x*v0t1y*v0t2z);
				case 1: return ((v0r0z - v0r1z)*(v0t0z*(v0t1y - v0t2y) + v0t1z*v0t2y - v0t1y*v0t2z + v0t0y*(-v0t1z + v0t2z)))/(-(v0r0y*v0t0z*v0t1x) + v0r1y*v0t0z*v0t1x + v0r0x*v0t0z*v0t1y - v0r1x*v0t0z*v0t1y + v0r0y*v0t0x*v0t1z - v0r1y*v0t0x*v0t1z - v0r0x*v0t0y*v0t1z + v0r1x*v0t0y*v0t1z + v0r0y*v0t0z*v0t2x - v0r1y*v0t0z*v0t2x - v0r0y*v0t1z*v0t2x + v0r1y*v0t1z*v0t2x - v0r0x*v0t0z*v0t2y + v0r1x*v0t0z*v0t2y + v0r0x*v0t1z*v0t2y - v0r1x*v0t1z*v0t2y + v0r0z*(-(v0t0x*v0t1y) + v0t0y*(v0t1x - v0t2x) + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) + v0r1z*(-(v0t0y*v0t1x) + v0t0x*v0t1y + v0t0y*v0t2x - v0t1y*v0t2x - v0t0x*v0t2y + v0t1x*v0t2y) - v0r0y*v0t0x*v0t2z + v0r1y*v0t0x*v0t2z + v0r0x*v0t0y*v0t2z - v0r1x*v0t0y*v0t2z + v0r0y*v0t1x*v0t2z - v0r1y*v0t1x*v0t2z - v0r0x*v0t1y*v0t2z + v0r1x*v0t1y*v0t2z);
				case 2: return ((v0r0z - v0r1z)*(v0t0z*(v0t1x - v0t2x) + v0t1z*v0t2x - v0t1x*v0t2z + v0t0x*(-v0t1z + v0t2z)))/(v0r0y*v0t0z*v0t1x - v0r1y*v0t0z*v0t1x - v0r0x*v0t0z*v0t1y + v0r1x*v0t0z*v0t1y - v0r0y*v0t0x*v0t1z + v0r1y*v0t0x*v0t1z + v0r0x*v0t0y*v0t1z - v0r1x*v0t0y*v0t1z - v0r0y*v0t0z*v0t2x + v0r1y*v0t0z*v0t2x + v0r0y*v0t1z*v0t2x - v0r1y*v0t1z*v0t2x + v0r0x*v0t0z*v0t2y - v0r1x*v0t0z*v0t2y - v0r0x*v0t1z*v0t2y + v0r1x*v0t1z*v0t2y + v0r1z*(v0t0y*v0t1x - v0t0x*v0t1y - v0t0y*v0t2x + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) + v0r0z*(v0t0x*v0t1y - v0t1y*v0t2x + v0t0y*(-v0t1x + v0t2x) - v0t0x*v0t2y + v0t1x*v0t2y) + v0r0y*v0t0x*v0t2z - v0r1y*v0t0x*v0t2z - v0r0x*v0t0y*v0t2z + v0r1x*v0t0y*v0t2z - v0r0y*v0t1x*v0t2z + v0r1y*v0t1x*v0t2z + v0r0x*v0t1y*v0t2z - v0r1x*v0t1y*v0t2z);
				case 3: return ((v0r0z - v0r1z)*(v0t0y*(v0t1x - v0t2x) + v0t1y*v0t2x - v0t1x*v0t2y + v0t0x*(-v0t1y + v0t2y)))/(-(v0r0y*v0t0z*v0t1x) + v0r1y*v0t0z*v0t1x + v0r0x*v0t0z*v0t1y - v0r1x*v0t0z*v0t1y + v0r0y*v0t0x*v0t1z - v0r1y*v0t0x*v0t1z - v0r0x*v0t0y*v0t1z + v0r1x*v0t0y*v0t1z + v0r0y*v0t0z*v0t2x - v0r1y*v0t0z*v0t2x - v0r0y*v0t1z*v0t2x + v0r1y*v0t1z*v0t2x - v0r0x*v0t0z*v0t2y + v0r1x*v0t0z*v0t2y + v0r0x*v0t1z*v0t2y - v0r1x*v0t1z*v0t2y + v0r0z*(-(v0t0x*v0t1y) + v0t0y*(v0t1x - v0t2x) + v0t1y*v0t2x + v0t0x*v0t2y - v0t1x*v0t2y) + v0r1z*(-(v0t0y*v0t1x) + v0t0x*v0t1y + v0t0y*v0t2x - v0t1y*v0t2x - v0t0x*v0t2y + v0t1x*v0t2y) - v0r0y*v0t0x*v0t2z + v0r1y*v0t0x*v0t2z + v0r0x*v0t0y*v0t2z - v0r1x*v0t0y*v0t2z + v0r0y*v0t1x*v0t2z - v0r1y*v0t1x*v0t2z - v0r0x*v0t1y*v0t2z + v0r1x*v0t1y*v0t2z);
			}
		}
	}
}
