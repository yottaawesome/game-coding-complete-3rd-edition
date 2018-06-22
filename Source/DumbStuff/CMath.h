#pragma once
//========================================================================
// CMath.h -  useful and fast math functions and approximations
//
//
// Part of the GameCode3 Application
//
// GameCode3 is the sample application that encapsulates much of the source code
// discussed in "Game Coding Complete - 3rd Edition" by Mike McShaffry, published by
// Charles River Media. ISBN-10: 1-58450-680-6   ISBN-13: 978-1-58450-680-5
//
// If this source code has found it's way to you, and you think it has helped you
// in any way, do the author a favor and buy a new copy of the book - there are 
// detailed explanations in it that compliment this code well. Buy a copy at Amazon.com
// by clicking here: 
//    http://www.amazon.com/gp/product/1584506806?ie=UTF8&tag=gamecodecompl-20&linkCode=as2&camp=1789&creative=390957&creativeASIN=1584506806
//
// There's a companion web site at http://www.mcshaffry.com/GameCode/
// 
// The source code is managed and maintained through Google Code: http://gamecode3.googlecode.com/svn/trunk/
//
// (c) Copyright 2009 Michael L. McShaffry
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License v2
// as published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//
//========================================================================


//========================================================================
//  Content References in Game Coding Complete 3rd Edition
// 
// class CRandom			- Chapter 3, pages 73-74
//
//========================================================================

//========================================================================
//
//  Original Code written at Compulsive Development
//
//========================================================================


//--------------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------------

#include <functional>
#include <vector>
//--------------------------------------------------------------------------------
// Defines
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------

/* Period parameters */  
#define CMATH_N 624
#define CMATH_M 397
#define CMATH_MATRIX_A 0x9908b0df   /* constant vector a */
#define CMATH_UPPER_MASK 0x80000000 /* most significant w-r bits */
#define CMATH_LOWER_MASK 0x7fffffff /* least significant r bits */

/* Tempering parameters */   
#define CMATH_TEMPERING_MASK_B 0x9d2c5680
#define CMATH_TEMPERING_MASK_C 0xefc60000
#define CMATH_TEMPERING_SHIFT_U(y)  (y >> 11)
#define CMATH_TEMPERING_SHIFT_S(y)  (y << 7)
#define CMATH_TEMPERING_SHIFT_T(y)  (y << 15)
#define CMATH_TEMPERING_SHIFT_L(y)  (y >> 18)

class CRandom
{
private:
	// DATA
	unsigned int		rseed;
	unsigned int		rseed_sp;
	unsigned long mt[CMATH_N]; /* the array for the state vector  */
	int mti; /* mti==N+1 means mt[N] is not initialized */

	// FUNCTIONS
public:
	CRandom(void);	

	unsigned int	Random( unsigned int n );
	float			Random( );
	void			SetRandomSeed(unsigned int n);
	unsigned int	GetRandomSeed(void);
	void			Randomize(void);
};



struct Point
{
	int x, y;
	Point() { x = y = 0; }
	Point(int _x, int _y) { x = _x; y = _y; }
};

typedef std::vector<Point> Poly;


class CMath
{
	// DATA
private:
	static const unsigned short angle_to_sin[90];

public:
	static CRandom		random;

	// FUNCTIONS
public:
	static int				Cos(short angle, int length);
	static int				Sin(short angle, int length);
	static unsigned int		Sqrt( unsigned int n );
	static void				InterpolateLine(int *x, int *y, int end_x, int end_y, int step_size);
	static unsigned short	GetAngle(int x, int y);
	static bool PointInPoly( Point const &test, const Poly & polygon);
	static bool				PointInPoly
							(
								int const			x,
								int const			y,
								int const * const	vertex,
								int const			nvertex
							);
	static RECT				BoundingBox
							( 
								const POINT &pt1,
								const POINT &pt2,
								const POINT &pt3,
								const POINT &pt4
							);
	static RECT				BoundingBox
							(
								const POINT *verts,
								const unsigned int nverts
							);
	static float const		GetDistanceBetween(POINT const & pt1, POINT const & pt2);

	// Used to determine the bounding box for a range of point-like objects.
	// This includes POINTS, CPoints, and VertexUV to name a few.
	// This works on any range which includes all STL containers as well as C style arrays.
	// See BoundingBox(const POINT*, const unsigned int) in cpp for example usage.
	template <typename PointType>
	class BoundingBoxFinder : std::unary_function<PointType, void>
	{
	public:
		void operator()(PointType const & item)
		{
			if (mBoundingBox.invalid())
			{
				RECT initialValue = { item.x, item.y, item.x, item.y };
				mBoundingBox = initialValue;
			}
			else
			{
				mBoundingBox->left = std::min(mBoundingBox->left, item.x);
				mBoundingBox->top = std::min(mBoundingBox->top, item.y);
				mBoundingBox->right = std::max(mBoundingBox->right, item.x);
				mBoundingBox->bottom = std::max(mBoundingBox->bottom, item.y);
			}
		}

		RECT const & BoundingBox() { return *mBoundingBox; }

	private:
		optional<RECT> mBoundingBox;
	};


};

#define	DONT_INTERSECT    0
#define	DO_INTERSECT      1
#define COLLINEAR         2

struct LineSegment
{
	CPoint m_begin, m_end;
	LineSegment(const CPoint &begin, const CPoint &end) { m_begin=begin; m_end=end; }
	LineSegment() { m_begin = m_end = CPoint(0,0); }
};


int lines_intersect( CPoint one,   /* First line segment */
					 CPoint two,

					CPoint three,   /* Second line segment */
					CPoint four,

					CPoint &result
               );

bool Intersect(const CRect &rect, const CPoint &center, double const radius);

float WrapPi( float wrapMe );  // wraps angle so it's between -PI and PI
float AngleDiff( float lhs, float rhs );
Vec3 GetVectorFromYRotation(float angleRadians);
float GetYRotationFromVector(const Vec3& lookAt);


//--------------------------------------------------------------------------------
// EOF



