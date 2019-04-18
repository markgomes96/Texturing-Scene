#include <iostream> 
#include <stdio.h> 
#include <stdlib.h>
#include <fstream> 
#include <sstream> 
#include <string> 
#include <algorithm> 
using namespace std; 

void writeVertices( fstream& file, string line ){ 
	unsigned first = line.find('(') + 1; 
	unsigned last  = line.find(')'); 
	string verts = line.substr( first, last-first ); 
	verts.erase(std::remove (verts.begin(), verts.end(), ' '), verts.end());
	string towrite = "v " + verts; 
	file << towrite.c_str() << '\n'; 
}

void scrape( fstream& in, fstream& out ){ 
	string buffer;
        while( getline( in, buffer ) ){
                stringstream ss( buffer );

                //Comment Line 
                if( buffer[0] == '/' && buffer[1] == '/' ){
                    out << ss.rdbuf() << '\n';
		//Comment Line 
		} else if ( buffer.find("/*") != string::npos ){ 
		    out << ss.rdbuf() << '\n'; 
		//Vertex in line 
                } else if( buffer.find("glVertex") != string::npos ) {
                    writeVertices( out, buffer );
		//The end of the vertices point -- the # denotes the end of a set of vertices 
                } else if( buffer.find("glEnd") != string::npos ) {
                    out << '\n' << '#' <<endl;
                } 
        }
}

int main( int argc, char* argv[] ){ 

	fstream in1( "levelCreate.cc", ios::in ); 
	fstream out( "vertices", ios::out ); 
	fstream in2( "drawCase.cc", ios::in ); 
	scrape( in1, out );
	scrape( in2, out ); 
}
