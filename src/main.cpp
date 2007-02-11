
#include <iostream>
#include <fstream>
#include <sstream>

#include "CLP.h"
#include "Version.h"
#include "Debug.h"
#include "Parser.h"
#include "DataTable.h"
#include "PedigreeSet.h"
#include "Data.h"
#include "DrawingMetrics.h"
#include "utility.h"

int main( int argc, char *argv[] ){
	
	std::ifstream labelreader;
	std::vector<std::string> showColumns; // vector containing field labels that need to be displayed on the pedigree
	CLP clp;
	// ABCDEFGH:
	clp.addSwitch("--bw","-b","Print pedigrees in black and white");
	clp.addSwitch("--color","-c","Print pedigrees in color");
	clp.addSwitch("--debug","-d","Print run-time progress messages");
	clp.addSwitch("--embedded","-e","Produce an XML file that can be embedded in another XML document");
	clp.addSwitch("--font","-f","Font to be used for the display of Pedigree labels",1);
	clp.addSwitch("--font-size","-z","Font size to be used for the display of Pedigree labels",1);
	clp.addSwitch("--help","-h","Print this help and exit");
	// IJKLMNOP:
	clp.addSwitch("--labels","-l","Path to the file that has a list of labels to be displayed on the Pedigree",1);
	clp.addSwitch("--Labels","-L","Specify labels to be displayed on the Pedigree using a single string containing space-delimited labels",1);
	clp.addSwitch("--outputprefix","-o","Specify output file name prefix",1);
	// RSTUVWXYZ:
	clp.addSwitch("--sort","-s","Field based on which siblings are sorted",1);
	clp.addSwitch("--version","-v","Print version and exit");
	clp.addUsage("madeline2 [option]... [file]...\n\nIf input file is remote, specify the file\nname starting with 'http://' or 'https://'.\nTo retrieve the data from a mysql database use\n'mysql://[host:port/]username:passwd@database:table'");
	
	if(clp.parse(argc,argv)){
		// No error, process the switches
		if(clp.hasSwitchSet("--help")){
			clp.printHelp();
			return 0;
		}
		if(clp.hasSwitchSet("--version")){
			Version ver("MiniMadeline","1");
			ver.printVersion();
			return 0;
		}
		if(clp.hasSwitchSet("--debug")){
				std::cout << "Switch DEBUG is set" << std::endl;
				Debug::DEBUG=true;
		}
		if(clp.hasSwitchSet("--font-size")){
			std::string fontSizeArgument = clp.getSwitchArgument("--font-size",1);
			if(fontSizeArgument != "."){
				double fontSize;
				std::stringstream sstr(fontSizeArgument);
				sstr >> fontSize;
				DrawingMetrics::setFontSize(fontSize);
			}
		}
		if(clp.hasSwitchSet("--font")){
			std::string fontFamily = clp.getSwitchArgument("--font",1);
			if(fontFamily != ".")
				DrawingMetrics::setFontFamily(fontFamily);
		}
		
		//
		// Set drawing metrics for embedded drawings:
		//
		if( clp.hasSwitchSet("--embedded")){
			DrawingMetrics::setEmbeddedState(true);
		}
		
		//
		// Handle a file containing a list of labels, one per line:
		//
		if(clp.hasSwitchSet("--labels") ){
			std::string labelarg = clp.getSwitchArgument("-l",1);
			std::cout << "Labels are in an external file " << labelarg << std::endl;
			
			// Read the labels to be displayed on the pedigree
			labelreader.open(labelarg.c_str());
			std::string label;
			while(getline(labelreader,label))
			{
				//
				// Trim extra white space from labels:
				//
				
				showColumns.push_back(Data::trim(label));
			}
			labelreader.clear();
			labelreader.close();
		}
			
		//
		// Handle a string containing labels to be tokenized
		// and used as the labels on the pedigree drawing:
		//
		if(clp.hasSwitchSet("--Labels")){
			std::string labelString = clp.getSwitchArgument("--Labels",1);
			showColumns = split(labelString);
		}
		
		//
		// Handle specification of a file name prefix:
		//
		if(clp.hasSwitchSet("--outputprefix")){
			DrawingMetrics::setDrawingFileNamePrefix( clp.getSwitchArgument("--outputprefix",1) );
		}
		
		//
		// Handle specification of a file name prefix:
		//
		if(clp.hasSwitchSet("--bw")){
			DrawingMetrics::setBlackAndWhite(true);
		}
		//
		// Handle specification of a file name prefix:
		//
		if(clp.hasSwitchSet("--color")){
			DrawingMetrics::setColor(true);
		}
		
		///////////////////////
		//
		// MAIN PROCESSING:
		//
		///////////////////////
		
		
		//
		// DEBUGGING: Show column information
		//
		std::cout << "ShowColumns is " << std::endl;
		for(unsigned i=0;i<showColumns.size();i++){
			std::cout << showColumns[i] << "      ";
		}
		std::cout << "Total: " << showColumns.size() <<  std::endl;
		std::vector<std::string> arguments = clp.getArguments();
		
		//
		// The parser holds the DataTables:
		//
		Parser dataTableParser;
		
		//
		// Read data tables from disk files:
		//
		for(unsigned i=0;i<arguments.size();i++){
			
			dataTableParser.readFile(arguments[i]);
		}
		//
		// Read data tables from network files:
		//
		std::vector<std::string> networkarguments = clp.getNetworkArguments();
		for(unsigned i=0;i<networkarguments.size();i++){
			dataTableParser.readNetworkFile(networkarguments[i]);
		}
		
		//
		// Read data from a mysql database table:
		//
		#ifdef MYSQLPP
		if(clp.hasMysqlArguments()){
			std::vector<std::string> mysqlarguments = clp.getMysqlArguments();
			dataTableParser.connectMysql(mysqlarguments[0],mysqlarguments[1],mysqlarguments[2],mysqlarguments[3],mysqlarguments[4]);
			dataTableParser.readMysql(mysqlarguments[5]);
		}
		#endif
		//
		// Process data tables read by the parser
		//
		DataTable *dataTable;
		for( int j=0 ; j < dataTableParser.getNumberOfTables() ; j++ ){
			
			PedigreeSet pedigreeSet;
			
			dataTable = dataTableParser.getTable(j);
			
			// DEBUG:
			//dataTable->display();
			
			//
			// Tell user the type of table:
			//
			std::cout << "Table " << (j+1) << " is a " << dataTable->getTableTypeAsString() << " table." << std::endl;
		
			//
			// Draw pedigrees
			//
			if( dataTable->getTableType() == DataTable::PEDIGREE ){
				
				// Pedigree table
				dataTable->toggleColumnsForPedigree(showColumns);
				
				
				std::string sortField = "";
				
				if(clp.hasSwitchSet("-s")){
					sortField = clp.getSwitchArgument("-s",1);
				}
				
				pedigreeSet.addPedigreesFromDataTable(dataTable,j,sortField);
				pedigreeSet.draw(dataTable);
			}
		}
		
		
	}
	
	return 0;
	
}

