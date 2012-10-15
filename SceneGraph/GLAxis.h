#ifndef GLAXIS_H
#define GLAXIS_H

#include <SceneGraph/GLObject.h>

namespace SceneGraph
{

///////////////////////////////////////////////////////////////////////////////
class GLAxis : public GLObject
{
public:

    GLAxis(float axisSize = 1.0f)
        : GLObject("Axis"), m_axisSize(axisSize)
    {
        m_bPerceptable = false;
    }

    static inline void DrawAxis(float size = 1.0f)
    {
        // draw axis
        glBegin(GL_LINES);
        glColor4f(1, 0, 0, 1);
        glVertex3d(0, 0, 0);
        glVertex3d(size, 0, 0);

        glColor4f(0, 1, 0, 1);
        glVertex3d(0, 0, 0);
        glVertex3d(0, size, 0);

        glColor4f(0, 0, 1, 1);
        glVertex3d(0, 0, 0);
        glVertex3d(0, 0, size);
        glEnd();
    }

    void DrawCanonicalObject()
    {
        glPushAttrib(GL_ENABLE_BIT | GL_LINE_BIT);
        glDisable( GL_LIGHTING );
        DrawAxis(m_axisSize);
        glPopAttrib();
    }

protected:
    float m_axisSize;
};

} // SceneGraph

#endif // GLAXIS_H
