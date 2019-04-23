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

void loadVertex( string line, vertex& ver ){ 
            std::string buffer;
	    cout << " Buffer is: " << buffer << endl; 
            size_t pos = 0;

            pos = buffer.find(",") != std::string::npos; 
            buffer = buffer.substr( 0, pos );
            ver.x =  atoi(buffer.c_str());
	    cout << ver.x << endl; 
            buffer.erase( 0, pos + 1 );

            pos = buffer.find(",") != std::string::npos;
            buffer = buffer.substr( 0, pos );
            ver.y =  atoi(buffer.c_str());
	    cout << ver.y << endl; 
            buffer.erase( 0, pos + 1 );

            pos = buffer.find(",") != std::string::npos;
            buffer = buffer.substr( 0, pos );
            ver.z =  atoi(buffer.c_str());
	    cout << ver.z << endl; 
            buffer.erase( 0, pos + 1 );
}

void loadVerticesFileData( char* fileName ){ 
	
	fstream file( fileName, ios::in ); 
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

