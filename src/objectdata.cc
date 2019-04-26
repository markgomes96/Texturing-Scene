#ifndef OBJECTDATA_CC
#define OBJECTDATA_CC
#include "includes.h"
#include "game.h"

#include <iostream> 
#include <fstream> 
#include <string> 
extern Game g; 
using namespace std; 

void getObjectData(int index)
{
        return objectList[index];
}

/* 
 * The function, loadVerticesFileData( char* ) is going to be the function that 
 * loads the actual object info into the Game object. 
 *
 * Essentially, the scraping script needs to be called to generate the vertices info 
 * file. This script can be called once, and once the vertices file exists, it does 
 * not need to be called again unless new objects are added. So, no need to internally 
 * call the script function in any of the game processes. 
 *
 * Going back to the loadVerticesFileData( char* ): 
 * 	char* references the vertices file. 
 * 	This function will read in the file and insert those objects into the Game g 
 * 	SceneObjects vector of type 'object'
 */

/* Helper function to read in the vertices file */ 
/*void loadVertex( string line, vertex& ver ){ 
            std::string buffer;
            size_t pos = 0;

            pos = buffer.find(",") != std::string::npos; 
            buffer = buffer.substr( 0, pos );
            ver.x =  atoi(buffer.c_str());
	    //cout << ver.x << endl; 
            buffer.erase( 0, pos + 1 );

            pos = buffer.find(",") != std::string::npos;
            buffer = buffer.substr( 0, pos );
            ver.y =  atoi(buffer.c_str());
	    //cout << ver.y << endl; 
            buffer.erase( 0, pos + 1 );

            pos = buffer.find(",") != std::string::npos;
            buffer = buffer.substr( 0, pos );
            ver.z =  atoi(buffer.c_str());
	    //cout << ver.z << endl; 
            buffer.erase( 0, pos + 1 );
}*/ 

/* Read in the vertices file and load them into the game object. This function should be 
 * called only ONCE -- probably somewhere in init. 
 */
/*void loadVerticesFileData( char* fileName ){ 
	
	fstream file( fileName, ios::in ); 
	polygon p; 
	vertex v; 
	string buffer; 
	while( getline( file, buffer ) ){ 
	  if( buffer[0] == 'v' ){ 
	  	loadVertex( buffer, v ); 
		p.vertices.push_back( v ); 
	  } else if( buffer[0] == '#' ){ 
	  	g.SceneObjects.push_back( p );     
	  }
	}
}*/ 

#endif

