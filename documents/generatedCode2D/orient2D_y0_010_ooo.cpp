#include "sosPredicatesImpl.h"

int SosPredicatesImpl::orient2D_y0_010(const InputVertex &v0, const InputVertex &v1, const InputVertex &v2) const{


/*****************************************************/
const VertCoord &iv0x = getCoordinates(v0)[0];
const VertCoord &iv0y = getCoordinates(v0)[1];
const VertCoord &iv0z = getCoordinates(v0)[2];

const VertCoord &iv1x = getCoordinates(v1)[0];
const VertCoord &iv1y = getCoordinates(v1)[1];
const VertCoord &iv1z = getCoordinates(v1)[2];

const VertCoord &iv2x = getCoordinates(v2)[0];
const VertCoord &iv2y = getCoordinates(v2)[1];
const VertCoord &iv2z = getCoordinates(v2)[2];

/*****************************************************/
/*****************************************************/
/*****************************************************/
/*****************************************************/
/*****************************************************/
/*****************************************************/
/*****************************************************/
VertCoord ans_1 = -(iv0z*(-iv0x + iv2x)) + iv1z*(-iv0x + iv2x) - iv0x*(iv0z - iv2z) + iv1x*(iv0z - iv2z);
 
if(sgn(ans_1) != 0) return sgn(ans_1);

/*****************************************************/
/*****************************************************/
/*****************************************************/
/*****************************************************/
VertCoord ans_2 = iv0z - iv2z;
 
if(sgn(ans_2) != 0) return sgn(ans_2);

/*****************************************************/
/*****************************************************/
/*****************************************************/
/*****************************************************/
VertCoord ans_3 = 0;
 
if(sgn(ans_3) != 0) return sgn(ans_3);

/*****************************************************/
/*****************************************************/
/*****************************************************/
/*****************************************************/
VertCoord ans_4 = -iv0x + iv2x;
 
if(sgn(ans_4) != 0) return sgn(ans_4);

/*****************************************************/
/*****************************************************/


 return 0; 

 } 
