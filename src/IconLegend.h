//////////////////////////////////////////////////////////
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

#ifndef ICONLEGEND_INCLUDED
#define ICONLEGEND_INCLUDED

#include "DrawingMetrics.h"
#include "DrawingLabelManager.h"
#include "DrawingCanvas.h"
#include "SVG.h"
#include "Utf8String.h"
#include "UniqueList.h"
#include "Legend.h"

class IconLegend : public Legend{
	
private:
	const DataTable * _ppedigreeTable;
	
public:
	
	IconLegend() { _width=_height=0;}
	void setPedigreeTable(const DataTable *const pedigreeTable){
		
		_ppedigreeTable = pedigreeTable;
		
	}
	
	void draw(std::ostringstream& os,SVG* psvg,DrawingLabelManager* plm,const double x,const double y){
		
		double lineHeight = DrawingMetrics::getLineHeight();
		double labelMargin = DrawingMetrics::getLabelMargin();
		unsigned sections = _ppedigreeTable->getIconColumnCount();
		double ystt = y;
		double xstt = x - DrawingMetrics::getHorizontalInterval() + labelMargin;
		//_width  = DrawingMetrics::getIconInterval()  + 2*labelMargin;
		
		_width = DrawingMetrics::getIconInterval();
		_height = (sections) * lineHeight + (sections+1)*labelMargin;
		// Wrap icon labels in a group:
		psvg->startGroup(os,"legend");
		for(unsigned i=0;i<sections;i++){
			//
			// Get the data column of the ith icon column:
			//
			DataColumn * pDC = _ppedigreeTable->getColumn( _ppedigreeTable->getIconColumnIndex(i) );
			//
			// Get the UniqueList for this column:
			//
			const UniqueList * pUL = pDC->getUniqueList();
			//std::cout << " pUL has missing " << pUL->getCountMissing() << std::endl;
			//
			// What is the level and label in the UniqueList corresponding to the data value
			// for this individual?
			//
			std::string label = _ppedigreeTable->getColumn( _ppedigreeTable->getIconColumnIndex(i) )->getName();
			psvg->drawText(os,x,ystt, plm->fitStringToLabelWidth( label ) );
			ystt += labelMargin;
			std::vector<std::string> labels = pUL->getLabels();
			unsigned levelsCount = labels.size();
			//
			// Get the color series corresponding to this icon column:
			//
			ColorSeries *pCS;
			if(sections == 1){
				if(DrawingMetrics::getColor()) pCS = _ppedigreeTable->getColorSeriesFromStack(i);
				else                       pCS =   _ppedigreeTable->getBlackAndWhiteSeriesFromStack(i);
			}else if(DrawingMetrics::getBlackAndWhite()) pCS=_ppedigreeTable->getBlackAndWhiteSeriesFromStack(i);
			else                                     pCS = _ppedigreeTable->getColorSeriesFromStack(i);
			//
			// Assume reversed for now:
			//
			bool reversed=true;
			std::string textClass;
			// Check if there exists a missing level
			if(pUL->getCountMissing()){
				levelsCount++;
				// push the missing label:
				labels.push_back(".");
			}
			double ytemp;
			for(unsigned j=0;j<levelsCount;j++){
				if(pCS->reversedSeriesUseBlackInkAtLevel(j)) textClass = "blackInkLetter_1";
				else textClass="whiteInkLetter_1";
				std::string style = "fill:" + (reversed?pCS->reversedSeriesGetColorAtLevel(j):pCS->getColorAtLevel(j)) + ";";
				psvg->drawRectangle(os,xstt,ystt,_width-2*labelMargin,lineHeight,"","",style);
				ytemp = ystt+lineHeight/2;
				if(j < levelsCount - 1) ytemp +=  DrawingMetrics::getYMaximum()/2;
				else if(!pUL->getCountMissing()) ytemp += DrawingMetrics::getYMaximum()/2;
				psvg->drawText(os,x,ytemp, plm->fitStringToLabelWidth( labels[j] ),textClass );
				ystt += lineHeight;
				_height += lineHeight;
			}
			ystt+=lineHeight;
		}
		psvg->endGroup(os);
	}
};

#endif
