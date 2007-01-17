 /////////////////////////////////////////////////////////
//
// This file is part of the MADELINE 2 program 
// written by Edward H. Trager and Ritu Khanna
// Copyright (c) 2005 by the
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

#ifndef SVG_INCLUDED
#define SVG_INCLUDED

#include "DrawingMetrics.h"
#include <cmath>
#include <sstream>

class SVG{
	
private:
	
public:
	SVG() {}
	
	// Drawing Methods:
	void startGroup(std::ostringstream& os,const std::string& cssClass=std::string(""),const std::string& id=std::string(""));
	void endGroup(std::ostringstream& os);
	void drawTitle(std::ostringstream& os,const std::string title){
		os << title;
	}
	void drawLine(std::ostringstream& os,double x1,double y1,double x2,double y2,const std::string& cssClass=std::string(""),const std::string& id=std::string(""));
	void drawHorizontalLine(std::ostringstream& os,double y,double x1,double x2,const std::string& cssClass=std::string(""),const std::string& id=std::string(""));
	void drawVerticalLine(std::ostringstream& os,double x,double y1,double y2,const std::string & cssClass=std::string(""), const std::string & id=std::string(""));
	void drawPolyline(std::ostringstream& os,const std::string points,const std::string& cssClass=std::string(""),const std::string& id=std::string(""));
	void drawText(std::ostringstream& os,double x,double y,std::string text,const std::string&  cssClass=std::string(""),const std::string& id=std::string(""));
	void drawRectangle(std::ostringstream& os,double x,double y,double width,double height,const std::string& cssClass=std::string(""),const std::string& id=std::string(""),const std::string& style=std::string(""));
	
	//
	// Low level methods for drawing individuals:
	//
	void drawMaleIcon(std::ostringstream& os,double x, double y, const std::string &id = std::string(""), const std::string &cssClass = std::string(""));
	void drawFemaleIcon(std::ostringstream& os,double x, double y, const std::string &id = std::string(""), const std::string &cssClass = std::string(""));
	void drawGenderUnknownIcon(std::ostringstream& os,double x, double y, const std::string &id = std::string(""), const std::string &cssClass = std::string(""));
	void drawIconForNoChildren(std::ostringstream& os,double x, double y);
	void drawIconForInfertility(std::ostringstream& os,double x, double y);
	void drawIconForAbortedPregnancy(std::ostringstream& os,double x, double y, const std::string &id = std::string(""), const std::string &cssClass = std::string(""));
	
	
};

#endif
