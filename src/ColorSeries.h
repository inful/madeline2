/////////////////////////////////////////////////////////
//
// This file is part of the MADELINE 2 program 
// written by Edward H. Trager, Ritu Khanna and Adrian Marrs
// Copyright (c) 2006 by the
// Regents of the University of Michigan.
// All Rights Reserved.
// 
// The latest version of this program is available from:
// 
//   http://eyegene.ophthy.med.umich.edu/madeline/
//   
// Released under the GNU General Public License.
// A copy of the GPL is included in the distribution
// package of this software, or see:
// 
//   http://www.gnu.org/copyleft/
//   
// ... for licensing details.
// 
/////////////////////////////////////////////////////////

//
// ColorSeries.h  2006.12.01.ET
//

#include <vector>
#include "DrawingColor.h"

#ifndef ColorSeries_INCLUDED
#define ColorSeries_INCLUDED

class ColorSeries{
	
private:
	
	static double _twoSaturations[2];
	static double _threeSaturations[3];
	static double _fourSaturations[4];
	static double _fiveSaturations[5];
	static double *_saturations[6];
	
	unsigned _levels;
	DrawingColor _endColor;
	DrawingColor _startColor;
	
	std::vector<DrawingColor> _colorSeries;
	
public:
	
	ColorSeries(unsigned levels=2,const DrawingColor &endColor=DrawingColor("black","#000"),const DrawingColor &startColor=DrawingColor("white","#fff"));
	
	DrawingColor get(unsigned level) const;
	std::string getColorAtLevel(unsigned level) const;
	std::string reversedSeriesGetColorAtLevel(unsigned level) const;
	bool useBlackInkAtLevel(unsigned level) const;
	bool reversedSeriesUseBlackInkAtLevel(unsigned level) const;
};

#endif
