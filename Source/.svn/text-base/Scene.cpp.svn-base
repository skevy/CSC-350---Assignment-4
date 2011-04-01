//***************************************************************************//
// Scene Class Implementation
//
// Created Sept 04, 2005
// By: Jeremy M Miller
//
// Copyright (c) 2005-2010  Jeremy M Miller.  All rights reserved.
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
// System Includes
#include <assert.h>

#include <fstream>
#include <string>
#include <sstream>
//***************************************************************************//

//***************************************************************************//
// Platform Includes
#include <Windows.h>
#include <GL\GL.h>
#include <GL\GLU.h>
//***************************************************************************//

//***************************************************************************//
// Local Includes
#include "Camera.hpp"
#include "Light.hpp"
#include "Mesh.hpp"
#include "Material.hpp"
#include "Scene.hpp"
#include "Texture.hpp"
#include "TGA.hpp"
//***************************************************************************//

//***************************************************************************//
using namespace std;
//***************************************************************************//

//***************************************************************************//
#define SCENE_LABEL    "Scene"
#define LIGHT_LABEL    "Light"
#define MATERIAL_LABEL "Material"
#define TEXTURE_LABEL  "Texture"
#define MESH_LABEL     "Mesh"
#define CAMERA_LABEL   "Camera"
#define NAME_LABEL     "Name"
#define TYPE_LABEL     "Type"
//***************************************************************************//

//***************************************************************************//
namespace HabuTech
{
  //*************************************************************************//
  Scene::Scene(class Graphics* pGraphics)
  {
    mpGraphics = pGraphics;
  }
  //*************************************************************************//

  //*************************************************************************//
  Scene::~Scene()
  {
  }
  //*************************************************************************//

  //*************************************************************************//
  bool Scene::Load(std::ifstream& ifs)
  {
    bool bReturnValue = false;
    assert(ifs.is_open());

    if(!ifs.is_open())
      return bReturnValue;

    unsigned long ulLightCount = 0UL;

    while(!ifs.eof())
    {
      string strLine;
      getline(ifs, strLine);
      stringstream sstmLine(strLine);
      string strType;
      sstmLine >> strType;
      if(strType == CAMERA_LABEL)
      {
        // Get Camera Name
        string strName;
        sstmLine >> strName;
        class Camera* pCamera = this->CreateCamera(strName);
        if(!pCamera->Load(ifs))
        {
          this->DestroyCamera(strName);
        }
        // TODO Make sure each scene has at least one mesh, one camera and one light
        bReturnValue = true;
      }
      else if(strType == LIGHT_LABEL)
      {
        // Get Light Name
        string strName;
        sstmLine >> strName;
        enum LightID eID;
        if(ulLightCount == 0)
          eID = LIGHT_ID_0;
        else if(ulLightCount == 1)
          eID = LIGHT_ID_1;
        else if(ulLightCount == 2)
          eID = LIGHT_ID_2;
        else if(ulLightCount == 3)
          eID = LIGHT_ID_3;
        else if(ulLightCount == 4)
          eID = LIGHT_ID_4;
        else if(ulLightCount == 5)
          eID = LIGHT_ID_5;
        else if(ulLightCount == 6)
          eID = LIGHT_ID_6;
        else if(ulLightCount == 7)
          eID = LIGHT_ID_7;
        else 
          eID = LIGHT_ID_COUNT;
        ulLightCount++;
        assert(eID != LIGHT_ID_COUNT);
        if(eID != LIGHT_ID_COUNT)
        {
          class Light* pLight = this->CreateLight(strName, eID);
          if(!pLight->Load(ifs))
          {
            this->DestroyLight(strName);
          }
          // TODO Make sure each scene has at least one mesh, one camera and one light
          bReturnValue = true;
        }
      }
      else if(strType == MATERIAL_LABEL)
      {
        // Get Material Name
        string strName;
        sstmLine >> strName;
        class Material* pMaterial = new Material(strName);
        if(pMaterial->Load(ifs))
        {
          this->mvMaterials.push_back(pMaterial);
          // TODO Make sure each scene has at least one mesh, one camera and one light
          bReturnValue = true;
        }
        else
          delete pMaterial;
      }
      else if(strType == MESH_LABEL)
      {
        // Get Mesh Name
        string strName;
        sstmLine >> strName;
        class Mesh* pMesh = new Mesh(strName, this);
        if(pMesh->Load(ifs))
        {
          this->mvMeshes.push_back(pMesh);
          // TODO Make sure each scene has at least one mesh, one camera and one light
          bReturnValue = true;
        }
        else
          delete pMesh;
      }
      else if(strType == TEXTURE_LABEL)
      {
        string strTextureType;
        sstmLine >> strTextureType;
        string strName;
        sstmLine >> strName;
        class TGA* pTexture;
        if(strTextureType == "TGA") {
          pTexture = new TGA(strName);
        }
        
        if(pTexture->Load(ifs))
        {
          this->mvTextures.push_back(pTexture);
          bReturnValue = true;
        }
        else
          delete pTexture;
      }
    }

    return bReturnValue;
  }
  //*************************************************************************//

  //*************************************************************************//
  void Scene::Render()
  {
    this->mpActiveCamera->Render();

    for(unsigned short i = 0; i < mvMeshes.size(); i++)
    {
      mvMeshes[i]->Render();
    }
  }
  //*************************************************************************//

  //*************************************************************************//
  bool Scene::SetupCamera()
  {
    bool bReturnValue = true;
    // Camera constructor will setup a default parameters for the camera. There 
    // is no need to call LoadDefaults again.
    class Camera* pCamera = this->CreateCamera(static_cast<string>("DEFAULT_CAM"));
    this->mvCameras.push_back(pCamera);
    this->mpActiveCamera = pCamera;
    return bReturnValue;
  }
  //*************************************************************************//

  //*************************************************************************//
  bool Scene::SetupLight()
  {
    bool bReturnValue = true;
    /// \todo does nothing.  Relys on OGL default lighting

    return bReturnValue;
  }
  //*************************************************************************//

  //*************************************************************************//
  class Mesh* const Scene::CreateMesh(const std::string& rstrName)
  {
    // TODO check for name confilcts
    class Mesh* pTempMesh = new class Mesh(rstrName, this);
    this->mvMeshes.push_back(pTempMesh);
    return pTempMesh;
  }
  //*************************************************************************//

  //*************************************************************************//
  void Scene::DestroyMesh(const std::string& rstrName)
  {

  }
  //*************************************************************************//

  //*************************************************************************//
  void Scene::DestroyMesh(class Mesh** ppMesh)
  {

  }
  //*************************************************************************//

  //*************************************************************************//
  class Mesh* const Scene::GetMesh(const std::string& rstrName)
  {
    // TODO Make this quicker
    for(unsigned long i = 0; i < this->mvMeshes.size(); i++)
    {
      if(this->mvMeshes[i]->Name() == rstrName)
        return this->mvMeshes[i];
    }
    return NULL;
  }
  //*************************************************************************//

  //*************************************************************************//
  class Camera* const Scene::CreateCamera(const std::string& rstrName)
  {
    class Camera* pTempCamera = new class Camera(rstrName, this);
    this->mvCameras.push_back(pTempCamera);
    this->mpActiveCamera = pTempCamera;
    return pTempCamera;
  }
  //*************************************************************************//

  //*************************************************************************//
  void Scene::DestroyCamera(const std::string& rstrName)
  {

  }
  //*************************************************************************//

  //*************************************************************************//
  void Scene::DestroyCamera(class Camera** ppCamera)
  {

  }
  //*************************************************************************//

  //*************************************************************************//
  class Camera* const Scene::GetCamera(const std::string& rstrName)
  {
    // TODO Make this quicker
    for(unsigned long i = 0; i < this->mvCameras.size(); i++)
    {
      if(this->mvCameras[i]->Name() == rstrName)
        return this->mvCameras[i];
    }
    return NULL;
  }
  //*************************************************************************//

  //*************************************************************************//
  class Camera* const Scene::GetActiveCamera()
  {
    return this->mpActiveCamera;
  }
  //*************************************************************************//

  //*************************************************************************//
  class Light* const Scene::CreateLight(const std::string& rstrName, enum LightID eLightID)
  {
    class Light* pTempLight = new class Light(rstrName, eLightID);
    this->mvLights.push_back(pTempLight);
    return pTempLight;
  }
  //*************************************************************************//

  //*************************************************************************//
  void Scene::DestroyLight(const std::string& rstrName)
  {

  }
  //*************************************************************************//

  //*************************************************************************//
  void Scene::DestroyLight(class Light** ppLight)
  {

  }
  //*************************************************************************//

  //*************************************************************************//
  class Light* const Scene::GetLight(const std::string& rstrName)
  {
    // TODO Make this quicker
    for(unsigned long i = 0; i < this->mvLights.size(); i++)
    {
      if(this->mvLights[i]->Name() == rstrName)
        return this->mvLights[i];
    }
    return NULL;
  }
  //*************************************************************************//

  //*************************************************************************//
  class Material* const Scene::GetMaterial(const std::string& rstrName)
  {
    // TODO Make this quicker
    for(unsigned long i = 0; i < this->mvMaterials.size(); i++)
    {
      if(this->mvMaterials[i]->Name() == rstrName)
        return this->mvMaterials[i];
    }
    return NULL;
  }
  //*************************************************************************//
  
  class Texture* const Scene::GetTexture(const std::string& rstrName)
  {
    for(unsigned long i = 0; i < this->mvTextures.size(); i++)
    {
      if(this->mvTextures[i]->Name() == rstrName)
        return this->mvTextures[i];
    }
    return NULL;
  }
  
}
//***************************************************************************//