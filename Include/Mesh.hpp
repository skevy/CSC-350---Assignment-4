//***************************************************************************//
// Mesh Class Interface
//
// Created: July 08, 2005
// By: Jeremy M Miller
//
// Copyright (c) 2005-2010 Jeremy M Miller.  All rights reserved.
// This source code module, and all information, data, and algorithms
// associated with it, are part of BlueHabu technology (tm).
//
// Usage of HabuGraphics is subject to the appropriate license agreement.
// A proprietary/commercial licenses are available.
//                 
// HabuGraphics is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// HabuGraphics is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with HabuGraphics.  If not, see <http://www.gnu.org/licenses/>.
//***************************************************************************//

#ifndef HABU_GRAPHICS_MESH_HPP
#define HABU_GRAPHICS_MESH_HPP

//***************************************************************************//
// System includes
#include <string>
#include <vector>
//***************************************************************************//

//***************************************************************************//
// Local Includes
#include "Object.hpp"
//***************************************************************************//

//***************************************************************************//
namespace HabuTech
{
  //*************************************************************************//
  const unsigned char MAX_NUMBER_OF_LODS = 10;
  //*************************************************************************//

  //*************************************************************************//
  // Mesh class manages polygons that describe the mesh.
  class Mesh : public Object
  {
  private:
    //***********************************************************************//
    //-----------------------------------------------------------------------//
    class Scene* mpScene;
    //-----------------------------------------------------------------------//

    //-----------------------------------------------------------------------//
    unsigned long mulNumberOfFaces;
    unsigned long mulNumberOfVertices;
    unsigned long mulNumberOfIndices;
    //-----------------------------------------------------------------------//

    //-----------------------------------------------------------------------//
    unsigned int muiVertexBufferID;
    unsigned int muiIndexBufferID;
    //-----------------------------------------------------------------------//

    //-----------------------------------------------------------------------//
    class Surface* mpSurface;
    //-----------------------------------------------------------------------//

    //-----------------------------------------------------------------------//
    class Vertex* mpVertexArray;
    unsigned long* mpIndexArray;
    //-----------------------------------------------------------------------//

    //-----------------------------------------------------------------------//
    bool mbWireFrame;
    //-----------------------------------------------------------------------//
    //***********************************************************************//
  protected:
    //***********************************************************************//
    //***********************************************************************//
  public:
    //***********************************************************************//
    //-----------------------------------------------------------------------//
    // This constructor sets all member data to zero
    Mesh(const std::string& rstrName, class Scene* const pScene);
    virtual ~Mesh();
    //-----------------------------------------------------------------------//

    //-----------------------------------------------------------------------//
    bool Load(std::ifstream& ifs);
    //-----------------------------------------------------------------------//

    //-----------------------------------------------------------------------//
    void Position(float fX, float fY, float fZ);
    //-----------------------------------------------------------------------//

    //-----------------------------------------------------------------------//
    // Renders the mesh
    virtual void Render();
    //-----------------------------------------------------------------------//

    void SetLOD(unsigned long ulLOD);
    void SetWireframe(bool bWireframe) { mbWireFrame = bWireframe; }
    //***********************************************************************//
  }; // End of class Mesh : public Object
  //*************************************************************************//
} // End of namespace HabuTech
//***************************************************************************//
#endif HABU_GRAPHICS_MESH_HPP