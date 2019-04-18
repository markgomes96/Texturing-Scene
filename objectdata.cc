#ifndef OBJECTDATA_CC
#define OBJECTDATA_CC
#include "includes.h"
#include "game.h"

#include <iostream> 
#include <fstream> 
#include <string> 
extern Game g; 
using namespace std; 

void loadVertex( string buffer, vertex& ver ){ 

	    string token; 
            size_t pos = 0;
	    buffer.erase(0,1); 
            pos = buffer.find(",");
            token = buffer.substr( 0, pos );
            ver.x =  atof(token.c_str());
	    cout << ver.x << endl; 
            buffer.erase( 0, pos + 1 );

            pos = buffer.find(",");
            token = buffer.substr( 0, pos );
            ver.y =  atof(token.c_str());
	    cout << ver.y << endl; 
            buffer.erase( 0, pos + 1 );

            pos = buffer.find(",");
            token = buffer.substr( 0, pos );
            ver.z =  atof(token.c_str());
	    cout << ver.z << endl; 
            buffer.erase( 0, pos + 1 );
}

void loadVerticesFileData( char* fileName ){ 
	
	fstream file( fileName, ios::in ); 
	if( file.good() ) cout << "File is good" << endl; 
	object o; 
	vertex v; 
	string buffer; 
	while( getline( file, buffer ) ){ 
	  if( buffer[0] == 'v' ){ 
	  	loadVertex( buffer, v ); 
		o.vertices.push_back( v ); 
	  } else if( buffer[0] == '#' ){ 
	  	g.SceneObjects.push_back( o );     
	  }
	}
}

#endif
