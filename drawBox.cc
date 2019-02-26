#ifndef DRAWBOX
#define DRAWBOX

#include "includes.h"
#include "structs.h"


void drawBox( struct box *face )
{
    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_FILL);

    for(int j=0;j<6;j++)
    {

        glColor3f(face[j].color.red,
                  face[j].color.green,
                  face[j].color.blue);

        glBegin(GL_POLYGON);
        for (int i=0;i<4;i++)
        {
            glVertex3f(face[j].point[i].x,
                       face[j].point[i].y,
                       face[j].point[i].z);
        }
        glEnd();
    }


}

#endif
