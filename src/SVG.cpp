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
//
// 2006.12.29.RK

//
// SVG.cpp
//

#include "SVG.h"

//
// drawLine:
//
void SVG::drawLine(std::ostringstream& os, double x1,double y1,double x2,double y2,const std::string& cssClass,const std::string& id){
	
	os  << "  <line x1=\"" << x1 << "\" y1=\"" << y1 << "\" x2=\"" << x2 << "\" y2=\"" << y2 << "\" />\n";
	
}

//
// drawHorizontalLine:
//
void SVG::drawHorizontalLine(std::ostringstream& os,double y, double x1, double x2,const std::string& cssClass,const std::string& id){
	
	 os << "  <line x1=\"" << x1 << "\" y1=\"" << y << "\" x2=\"" << x2 << "\" y2=\"" << y << "\" />\n";
	
}

//
// drawVerticalLine:
//
void SVG::drawVerticalLine(std::ostringstream& os,double x, double y1, double y2,const std::string & cssClass, const std::string & id){
	
	os << "  <line ";
	if(cssClass != std::string("") ) os << "class=\"" << cssClass <<"\" ";
	if(id        != std::string("") ) os << "id=\""    << id    <<"\" ";
	os << "x1=\"" << x << "\" y1=\"" << y1 << "\" x2=\"" << x << "\" y2=\"" << y2 << "\" />\n";
	
}

//
// drawPolyline:
//
void SVG::drawPolyline(std::ostringstream& os,const std::string points,const std::string& cssClass,const std::string& id){
	
	os << "  <polyline points=\"" << points << "\" ";
	if(id        != std::string("") ) os << "id=\""    << id    <<"\" ";
	if(cssClass     != std::string("") ) os << "class=\""    << cssClass    <<"\" ";
	os << " />\n";
	
}

//
// drawText:
//
void SVG::drawText(std::ostringstream& os,double x,double y,std::string text,const std::string& cssClass,const std::string& id){
	
	os << "  <text x=\"" << x << "\" y=\"" << y << "\" text-anchor=\"middle\" ";
	if(cssClass!="") os << " class=\"" << cssClass << "\" ";
	os << ">" << text << "</text>\n";
	
}

//
// drawRectangle:
//
void SVG::drawRectangle(std::ostringstream& os,double x,double y,double width,double height,const std::string& cssClass,const std::string& id,const std::string& style){
	
	os  << "  <rect  x=\"" << x << "\" y=\"" << y << "\" width=\"" << width << "\" height=\"" << height << "\" ";
	if(style != std::string("")) os << "style=\"" << style << "\" ";
	if(cssClass != std::string("")) os << "class=\"" << cssClass << "\" ";
	os << " />\n";
	
}

//
// startGroup:
//
void SVG::startGroup(std::ostringstream& os,const std::string& cssClass,const std::string& id){
	
	os << "  <g"; 
	if(cssClass!=std::string("")) os << " class=\"" << cssClass << "\"";
	os << ">\n";
	
}

//
// endGroup:
//
void SVG::endGroup(std::ostringstream& os){
	
	os << "  </g>\n";
	
}

//
// drawMaleIcon()
//
void SVG::drawMaleIcon(std::ostringstream& os,double x, double y, const std::string &id, const std::string &cssClass){
	
	double d = DrawingMetrics::getIconDiameter();
	double r = 0.5 * d;
	x -= r;
	y -= r;
	os << "  <rect x=\"" << x << "\" y=\"" << y << "\" width=\"" << d << "\" height=\"" << d << "\"";
	if(id.size()   ) os << " id=\"" << id << "\"";
	if(cssClass.size()) os << " class=\"" << cssClass << "\"";
	os << "/>\n";
	
	
}

//
// drawFemaleIcon()
//
void SVG::drawFemaleIcon(std::ostringstream& os,double x, double y, const std::string &id, const std::string &cssClass){
	
	os << "<circle cx=\"" << x << "\" cy=\"" << y << "\" r=\"" << DrawingMetrics::getIconRadius() << "\"";
	if(id.size()   ) os << " id=\"" << id << "\"";
	if(cssClass.size()) os << " class=\"" << cssClass << "\"";
	os << "/>\n";
	
}


//
// drawGenderUnknownIcon()
//
void SVG::drawGenderUnknownIcon(std::ostringstream& os,double x, double y, const std::string &id, const std::string &cssClass){
	
	double r = DrawingMetrics::getIconRadius();
	double d = 2.0 * r / M_SQRT2;
	y -= r;
	os << "<path d=\"M " << x << " " << y;
	os << " l " << -d << " " << d;
	os << " " << d << " " << d;
	os << " " << d << " " << -d;
	os << " z\"";
	if(id.size()   ) os << " id=\"" << id << "\"";
	if(cssClass.size()) os << " class=\"" << cssClass << "\"";
	os << "/>\n";
	
}

//
// drawIconForNoChildren()
//
void SVG::drawIconForNoChildren(std::ostringstream& os,double x, double y){
	
	double d = DrawingMetrics::getIconDiameter();
	double r = 0.5 * d;
	x -= r;
	y -= r;
	double x2 = x+d;
	
	os << "<line x1=\"" << x << "\" y1=\"" << y << "\" x2=\"" << x2 << "\" y2=\"" << y << "\" class=\"solid\" />\n";
	
}

//
// drawIconForInfertility()
//
void SVG::drawIconForInfertility(std::ostringstream& os,double x, double y){
	
	double d = DrawingMetrics::getIconDiameter();
	double r = 0.5 * d;
	x -= r;
	y -= r;
	double x2 = x+d;
	
	os << "<line x1=\"" << x << "\" y1=\"" << y << "\" x2=\"" << x2 << "\" y2=\"" << y << "\" class=\"solid\" />\n";
	// Create 2nd line:
	y+= 1.0*DrawingMetrics::getScalingFactor();
	os << "<line x1=\"" << x << "\" y1=\"" << y << "\" x2=\"" << x2 << "\" y2=\"" << y << "\" class=\"solid\" />\n";
	
}

//
// drawIconForAbortedPregnancy
// 
void SVG::drawIconForAbortedPregnancy(std::ostringstream& os,double x, double y, const std::string &id, const std::string &cssClass){
	
	double r = DrawingMetrics::getIconRadius();
	y -= r;
	r*=M_SQRT2;
	
	os << "<path d=\"M " << x << " " << y;
	os << " l " << -r << " " << r;
	os << " " << 2.0*r << " " << 0;
	os << " z\"";
	if(id.size()   ) os << " id=\"" << id << "\"";
	if(cssClass.size()) os << " class=\"" << cssClass << "\"";
	os << "/>\n";
	
}

//
// drawAdoptedIn: - Draws brackets around an individual like this: [ ]
//                - Conforms to PSTF (Bennet et al.)
//
void SVG::drawAdoptedIn(std::ostringstream& os,double x,double y,bool widerMargin){
	
	double d = DrawingMetrics::getIconDiameter();
	double r = 0.5 * d;
	double t = DrawingMetrics::getVerticalTick();
	double v = d+t+t;
	
	x -= r;
	if(widerMargin) x -= 2*t;
	y -= r;
	y -= t;
	
	os << "<path d=\"M " << x << " " << y;
	os << " l " << -t << " " << 0;
	os << " "   <<  0 << " " << v;
	os << " "   <<  t << " " << 0;
	os << "\" class=\"solid\" />\n";
	
	x += d;
	if(widerMargin) x += 4*t;
	
	os << "<path d=\"M " << x << " " << y;
	os << " l " <<  t << " " << 0;
	os << " "   <<  0 << " " << v;
	os << " "   << -t << " " << 0;
	os << "\" class=\"solid\" />\n";
	
}

//
// drawAdoptedOut: - Draws brackets around an individual like this: ] [
//                 - This is intentionally different from the PSTF
//                   (Bennet et al.) recommendations.
//
void SVG::drawAdoptedOut(std::ostringstream& os,double x,double y,bool widerMargin){
	
	double d = DrawingMetrics::getIconDiameter();
	double r = 0.5 * d;
	double t = DrawingMetrics::getVerticalTick();
	double v = d+2*t;
	
	x -= r;
	x -= 2*t;
	if(widerMargin) x -= 2*t;
	
	y -= r;
	y -= t;
	
	os << "<path d=\"M " << x << " " << y;
	os << " l " <<  t << " " << 0;
	os << " "   <<  0 << " " << v;
	os << " "   <<  -t << " " << 0;
	os << "\" class=\"solid\" />\n";
	
	x += d;
	x += 4*t;
	if(widerMargin) x += 4*t;
	
	os << "<path d=\"M " << x << " " << y;
	os << " l " << -t << " " << 0;
	os << " "   <<  0 << " " << v;
	os << " "   <<  t << " " << 0;
	os << "\"  class=\"solid\" />\n";
	
}

//
// drawMiniMaleIcon: - Draws a miniature-sized male icon
//                     to indicate gender of terminated or aborted pregnancies
//                     - Not part of PSTF recommendation
//
void SVG::drawMiniMaleIcon(std::ostringstream& os,double x,double y){
	
	double r  = DrawingMetrics::getIconRadius();
	double hr = 0.5*r;
	
	x -= hr;
	y += hr;
	y += DrawingMetrics::getVerticalTick();
	
	os << "<path d=\"M " << x << " " << y;
	os << " l " <<  0 << " " << r;
	os << " "   <<  r << " " << 0;
	os << " "   <<  0 << " " << -r;
	os << " z ";
	os << "\" class=\"solid\" />\n";
	
}

//
// drawMiniFemaleIcon: - Draws a miniature-sized female icon
//                       to indicate gender of terminated or aborted pregnancies
//                     - Not part of PSTF recommendation
//
void SVG::drawMiniFemaleIcon(std::ostringstream& os,double x,double y){
	
	double r  = DrawingMetrics::getIconRadius();
	double hr = 0.5*r;
	
	y += r;
	y += DrawingMetrics::getVerticalTick();
	
	os << "<circle cx=\"" << x << "\" cy=\"" << y << "\" r=\"" << hr << "\"";
	os << " class=\"solid\" />\n";
	
}

//
// drawMiniCircle: - Draws a small filled circle indicating carrier status
//
void SVG::drawMiniCircle(std::ostringstream& os,double x,double y){
	
	double r  = DrawingMetrics::getIconRadius();
	double hr = 0.25*r;
	
	os << "<circle cx=\"" << x << "\" cy=\"" << y << "\" r=\"" << hr << "\"";
	os << " class=\"filled\" />\n";
	
}

