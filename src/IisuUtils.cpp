#include "IisuUtils.h"


ofVec3f IisuUtils::iisuPointToOF( Vector3 point )
{
	ofVec3f vector = ofVec3f( (( point.x +1.0f )/2.0f ) * ofGetWidth() ,ofGetHeight() +- ( ( point.z +1.0f ) /2.0f ) * ofGetHeight() ,  point.y ) ; 
	return vector ; 
}

ofVec3f IisuUtils::iisuPointToOF( Vector3 point , ofVec3f range ) 
{
	ofVec3f vector = ofVec3f( (( point.x +1.0f )/2.0f ) * range.x , ( ( point.z +1.0f ) /2.0f ) * range.y ,  point.y * range.z ) ; 
	return vector ; 
}

ofVec3f IisuUtils::iisuPosition3DToOfxScreen( Vector3 IisuPosition , ofRectangle bounds , bool mirrorX , bool mirrorY )
{
	ofVec3f screenPosition ; 
	float factorX = ( mirrorX == true ) ? -2 : 2 ; 
	float factorY = ( mirrorY == true ) ? -2 : 2 ; 
		
	screenPosition.x = bounds.x + ( ( ( IisuPosition.x + 1 ) / factorX ) * bounds.width );
	screenPosition.y = bounds.y + ( bounds.height -( ( IisuPosition.z + 1 ) / factorY ) * bounds.height ) ; 
	screenPosition.z = IisuPosition.y; 
		
	return screenPosition ;
}

ofVec3f IisuUtils::iisuPosition3DToOfxScreen( Vector3 IisuPosition , ofPoint scale , bool mirrorX , bool mirrorY )
{
	ofVec3f screenPosition ; 
	float factorX = ( mirrorX == true ) ? -1 : 1 ; 
	float factorY = ( mirrorY == true ) ? -1 : 1 ; 
		
	screenPosition.x = ( IisuPosition.x * factorX ) * scale.x ;
	screenPosition.y = ( IisuPosition.z * factorY ) * scale.y ;  
	screenPosition.z = IisuPosition.y * scale.z ; 
		
	return screenPosition ;
}
//ofVec3f IIsuPosition3DToOfxScreen(  Vector3 iisuPosition , float paddingRatio = 0.0f , bool bMirror = true , bool bKeepWithinBounds = true ) ; 
		
ofVec3f  IisuUtils::iisuPosition3DToOfxScreen ( Vector3 iisuPosition , float paddingRatio  , bool bMirror , bool bKeepWithinBounds ) 
{
	ofVec3f loc = ofVec3f ( iisuPosition.x , iisuPosition.y , iisuPosition.z ) ; 
	float mirrorFactor = 1 ; 
	if ( bMirror == true ) 
		mirrorFactor = -1 ; 


	ofVec3f desiredLoc = ofVec3f ( ofMap( mirrorFactor * loc.x , -paddingRatio , paddingRatio , ofGetWidth() * -paddingRatio , ofGetWidth() * ( 1 + paddingRatio ) ) , 
								   ofMap( mirrorFactor * loc.z , -paddingRatio , paddingRatio , ofGetHeight() * -paddingRatio , ofGetHeight() * ( 1 + paddingRatio ) ) ,
								   iisuPosition.y ) ; 
	if ( bKeepWithinBounds )
	{
		if ( desiredLoc.x > ofGetWidth() ) 
			desiredLoc.x = ofGetWidth() ; 
		if ( desiredLoc.x < 0 ) 
			desiredLoc.x = 0 ; 
		if ( desiredLoc.y < 0 ) 
			desiredLoc.y = 0 ; 
		if ( desiredLoc.y > ofGetHeight() ) 
			desiredLoc.y = ofGetHeight() ; 
	}

	return desiredLoc ; 
}

ofVec2f  IisuUtils::iisuPosition2DToOfxScreen ( Vector2 iisuPosition , float paddingRatio  , bool bMirror , bool bKeepWithinBounds ) 
{
	ofVec2f loc = ofVec3f ( iisuPosition.x , iisuPosition.y ) ; 
	float mirrorFactor = 1 ; 
	if ( bMirror == true ) 
		mirrorFactor = -1 ; 


	ofVec2f desiredLoc = ofVec2f ( ofMap( mirrorFactor * loc.x , -paddingRatio , paddingRatio , ofGetWidth() * -paddingRatio , ofGetWidth() * ( 1 + paddingRatio ) ) , 
								   ofMap( mirrorFactor * loc.y , -paddingRatio , paddingRatio , ofGetHeight() * -paddingRatio , ofGetHeight() * ( 1 + paddingRatio ) )  ) ; 
	if ( bKeepWithinBounds )
	{
		if ( desiredLoc.x > ofGetWidth() ) 
			desiredLoc.x = ofGetWidth() ; 
		if ( desiredLoc.x < 0 ) 
			desiredLoc.x = 0 ; 
		if ( desiredLoc.y < 0 ) 
			desiredLoc.y = 0 ; 
		if ( desiredLoc.y > ofGetHeight() ) 
			desiredLoc.y = ofGetHeight() ; 
	}

	return desiredLoc ; 
}

Vector2 IisuUtils::normalize2DPoint( Vector2 v , float w , float h , bool bMirrorX , bool bMirrorY ) 
{
	float newX = v.x / w ; 
	if ( bMirrorX == true ) 
		newX = 1.0f - newX ; 

	float newY = v.y / h ; 
	if ( bMirrorY == true ) 
		newY = 1.0f - newY ; 

	return Vector2( newX , newY ) ;  
}
