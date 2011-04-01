//***************************************************************************//
// Surface Class Implementation
//
// Created Nov 12, 2005
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

//***************************************************************************//
#include "Surface.hpp"
#include "Material.hpp"
#include "Texture.hpp"
//***************************************************************************//

//***************************************************************************//
namespace HabuTech
{
  //-------------------------------------------------------------------------//
  Surface::Surface()
  {
    this->mpActiveMaterial = new class Material("DEFAULT");
    this->mvMaterials.push_back(this->mpActiveMaterial);
  }
  //-------------------------------------------------------------------------//

  //-------------------------------------------------------------------------//
  Surface::~Surface()
  {
    for(unsigned long ulIndex = 0UL; ulIndex < this->mvMaterials.size(); ulIndex++)
    {
      if(this->mvMaterials[ulIndex] != NULL)
      {
        delete this->mvMaterials[0];
        this->mvMaterials[0] = NULL;
      }
    }
    this->mvMaterials.clear();

  }
  //-------------------------------------------------------------------------//

  //-------------------------------------------------------------------------//
  void Surface::RenderMaterial()
  {
    if(this->mpActiveMaterial)
      this->mpActiveMaterial->Render();
    else if(this->mvMaterials.size() > 0)
    {
      this->mpActiveMaterial = mvMaterials[0];
      this->mpActiveMaterial->Render();
    }
  }
  //-------------------------------------------------------------------------//

  //-------------------------------------------------------------------------//
  void Surface::RenderTextures()
  {

    for(unsigned long ulIndex = 0UL; ulIndex < this->mvTextures.size(); ulIndex++)
    {
      this->mvTextures[ulIndex]->Render();
    }
  }
  //-------------------------------------------------------------------------//

  //-------------------------------------------------------------------------//
  bool Surface::AddMaterial(class Material* pMaterial)
  {
    bool bReturnValue = false;
    if(pMaterial)
    {
      this->mvMaterials.push_back(pMaterial);
      mpActiveMaterial = pMaterial;
      bReturnValue = true;
    }
    return bReturnValue;
  }
  //-------------------------------------------------------------------------//

  //-------------------------------------------------------------------------//
  bool Surface::AddTexture(class Texture* pTexture)
  {
    bool bReturnValue = false;
    if(pTexture)
    {
      this->mvTextures.push_back(pTexture);
      bReturnValue = true;
    }
    return bReturnValue;
  }
  //-------------------------------------------------------------------------//

  //-------------------------------------------------------------------------//
  void Surface::Render()
  {
    this->RenderTextures();
    this->RenderMaterial();
  }
  //-------------------------------------------------------------------------//
} // End of namespace HabuTech
//***************************************************************************//